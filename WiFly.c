/* 
 * File:   RN41.c
 * Author: Garrett Scott (garrett.scott@microchip.com)
 * Summary:    This is the the interface for the RN41 which is the device on the 
 *             Mikro Elektronika Bluetooth Click.
 * 
 * Comments:    
 * Date        Initials    Comments
 * ------------------------------------------------------
 * 2016-06-22  GS          First version
 */


#include "mcc_generated_files/mcc.h"
#include "WiFly.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Clear_RX_Buffer() while(EUSART_DataReady) EUSART_Read(); 
#define CHECKING_RECEIVE_BUFFER_SIZE 32
const uint8_t* hardRebootStr = "*READY*"; // This is 
const uint8_t* softRebootStr = "*Reboot*";
const uint8_t* cmdStr = "CMD";
const uint8_t* endStr = "EXIT";
const uint8_t* aokStr = "AOK\r";
const uint8_t* openStr = "*OPEN*";

bool inCMD;

callbackFunction waitingFn;

// Local function prototypes
void initWaitingFunction(void);
void WiFly_EnterCMDDelay(void);
void WiFly_EnterCMDMode(void);
void WiFly_ExitCMDMode(void);
void WiFly_SendCMD(const uint8_t* cmd);
void WiFly_RebootCMD(void);

void initWaitingFunction(void){ 
    __delay_us(50);
}

/**
 * Waits for the @chkString to be received before continuing
 * 
 * Calls the waitingFN callback while waiting for @chkString
 * @param chkString
 */

void WiFly_CheckInCMD(void){
    if(!inCMD){
        WiFly_EnterCMDMode();
    }
}

void WiFly_SendString(const uint8_t* sendString){
    Clear_RX_Buffer();
    WiFly_CheckInCMD();
    Clear_RX_Buffer();
    printf("%s\r\n", sendString);
}

bool checkRxBuf(uint8_t *rn41RxBuf, const uint8_t* chkString){
    return (strcmp(rn41RxBuf, chkString) == 0); //The last of the response string has been received. 
}

void WiFly_CheckRecv(const uint8_t* chkString){
    uint8_t rn41RxBuf[CHECKING_RECEIVE_BUFFER_SIZE] = {0}; //UART receive buffer for RN41 response compare.
    uint8_t i = 0;
    while (1) {
        while(EUSART_DataReady) {
            //Debug_SetLow();
            rn41RxBuf[i] = EUSART_Read();
            i++;
            if(i > (CHECKING_RECEIVE_BUFFER_SIZE-2) || rn41RxBuf[i-1] == '\n'){
                //Debug_SetHigh();
                if(checkRxBuf(rn41RxBuf, chkString)){
                    return;
                };
                i = 0;
            }
            rn41RxBuf[i+1] = 0;
        } 
        if(checkRxBuf(rn41RxBuf, chkString)){
            return;
        };
        if(!waitingFn){
            waitingFn = initWaitingFunction;
        }
        (*waitingFn)();
    }
}


// Public Functions
void WiFly_EnterCMDMode(void){
    Clear_RX_Buffer();
    __delay_ms(275);
    printf("$$$");
    WiFly_CheckRecv(cmdStr);
    __delay_ms(275);
    inCMD = true;
}

void WiFly_ExitCMDMode(void){
    if(!inCMD){return;}
    WiFly_SendString("exit");
    WiFly_CheckRecv(endStr);
    inCMD = false;
}

void WiFly_SendCMD_SingleArg(const uint8_t* cmdFormat, void* arg){
    WiFly_CheckInCMD();
    Clear_RX_Buffer();
    printf(cmdFormat, arg);
    printf("\r\n");
    WiFly_CheckRecv(aokStr);
}

void WiFly_SendCMD(const uint8_t* cmd){
    WiFly_CheckInCMD();
    WiFly_SendString(cmd);
    WiFly_CheckRecv(aokStr);
}

void WiFly_RebootCMD(void){
    WiFly_CheckInCMD();
    WiFly_SendString("reboot");
    WiFly_CheckRecv(softRebootStr);
    WiFly_CheckRecv(hardRebootStr);
    inCMD = false;
}

void WiFly_RegisterWaitCallback(callbackFunction regFunctionPtr){
    waitingFn = regFunctionPtr;
}

void WiFly_SaveConfig(void){
    WiFly_SendString("save");
    WiFly_RebootCMD();
}

void WiFly_FactoryReset(void){
    Click_RST_SetLow(); //Reset RN41
    inCMD = false;
    __delay_ms(50); 
    Click_RST_SetHigh();
    WiFly_CheckRecv(hardRebootStr);
    
    WiFly_SendString("factory RESET");
    WiFly_RebootCMD();
    WiFly_SendCMD("set uart mode 0x11");
    WiFly_SaveConfig();
}

void WiFly_InitializeAsClient(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password){
    Click_Wake_SetLow();
    WiFly_FactoryReset();
    
    WiFly_SendCMD_SingleArg("set wlan passphrase %s\r\n", password);
    WiFly_SendCMD_SingleArg("set wlan ssid %s\r\n", ssid);
    WiFly_SendCMD("set wlan join 1");
    WiFly_SendString("set ip protocol 08");
    WiFly_SaveConfig();
    WiFly_CheckRecv("IF=UP");
    WiFly_CheckInCMD();
    Clear_RX_Buffer();
    printf("open %s %d\r\n", addr, port);
    WiFly_CheckRecv(openStr);
}

void WiFly_InitializeAsAPAndHost(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password){
    Click_Wake_SetLow();
    __delay_ms(100);
    Click_Wake_SetHigh();
    WiFly_FactoryReset();
    
    WiFly_SendCMD("set wlan join 7");
    WiFly_SendCMD_SingleArg("set apmode ssid %s", ssid);
    WiFly_SendCMD_SingleArg("set apmode passphrase %s", password);
    WiFly_SendCMD("set ip protocol 2");
    WiFly_SendCMD_SingleArg("set ip address %s", addr);
    WiFly_SendCMD_SingleArg("set ip gateway %s", addr);
    WiFly_SendCMD("set ip netmask 255.255.255.0");
    WiFly_SendCMD("set ip dhcp 4");
    WiFly_SendCMD_SingleArg("set ip localport %i", port);
    WiFly_SaveConfig();
    WiFly_EnterCMDMode();
    WiFly_SendString("get ip");
    WiFly_CheckRecv("IF=UP");
    WiFly_ExitCMDMode();
}

void WiFly_InitializeAsHost(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password){
   Click_Wake_SetLow();
    WiFly_FactoryReset();
    
    WiFly_SendCMD_SingleArg("set wlan passphrase %s\r\n", password);
    WiFly_SendCMD_SingleArg("set wlan ssid %s\r\n", ssid);
    WiFly_SendCMD_SingleArg("set ip address %s", addr);
    WiFly_SendCMD_SingleArg("set ip localport %i", port);
    WiFly_SendCMD("set wlan join 1");
    WiFly_SendString("set ip protocol 2");
    WiFly_SaveConfig();
    WiFly_CheckRecv("Associated!");
    WiFly_EnterCMDMode();
    WiFly_SendString("get ip");
    WiFly_CheckRecv("IF=UP");
    WiFly_ExitCMDMode();
}

/**
 End of File
 */