/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F18855
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "WiFly.h"
#include <stdbool.h>
#include <string.h>

/*
                         Main application
 */

#define SSID_NAME   "A&Y"
#define SSID_PASS   "Kuw@it2017"
#define TCP_SERVER  "192.168.0.23"
#define TCP_PORT     1337

#define COMMAND_MAX_LENGTH 32

void waitingForWiFly(void){
    D3_Toggle();
    D4_Toggle();
}

void CMD_ENABLE_RELAY(void){
    D2_SetHigh();
    printf("Enabling the relay!\r\n");
    return;
}
void CMD_DISABLE_RELAY(void){
    D2_SetLow();
    printf("Disabling the relay :(\r\n");
    return;
}
void CMD_ADCC_GET(void){
    uint16_t res;
    res = ADCC_GetSingleConversion(POT);
    printf("ADC=%i\r\n", res);
    return;
}


// NEW THING ---------------------------------
void CMD_ParseExec(uint8_t *command){
    if(strcmp(command, "DayMode\r\n") == 0){
        CMD_ENABLE_RELAY();
        return;
    }
    else if(strcmp(command, "NightMode\r\n") == 0){
        CMD_DISABLE_RELAY();
        return;
    }
    else if(strcmp(command, "ManualMode\r\n") == 0){
        CMD_ADCC_GET();
        return;
    }
        
}

void DayMode(void){
    D2_SetHigh();
    printf("Enabling the relay!\r\n");
    return;
}
void NightMode(void){
    D2_SetLow();
    printf("Disabling the relay :(\r\n");
    return;
}
void ManualMode(uint8_t *command){
    uint16_t res = command;
    printf("ADC=%i\r\n", res);
    return;
}



//--------------------------------------------

void CMD_Check(uint8_t *command){
    static uint8_t i = 0;
    if(EUSART_DataReady){
        command[i] = EUSART_Read();
        command[i+1] = 0;
        if(command[i] == '\n'){
            i = 0;
            printf("Found command: %s\r\n", command);
            CMD_ParseExec(command);
            while(EUSART_DataReady){
                EUSART_Read();
            }
            return;
        } else {
        } 
        if(++i > (COMMAND_MAX_LENGTH - 2)){
            printf("Max Reached!\r\n");
            i = (COMMAND_MAX_LENGTH - 2);
        }
    }
}

void listening_to_18855(void){
    MODE_SELECT_SetHigh();
}

void listening_to_WiFly(void){
    MODE_SELECT_SetLow();
}

void main(void)
{
    uint8_t command[COMMAND_MAX_LENGTH] = {0};

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    listening_to_18855();
    printf("\r\nInitializing WiFly...\r\n");
    D3_SetHigh();
    WiFly_RegisterWaitCallback(waitingForWiFly);
    WiFly_InitializeAsHost(TCP_SERVER, TCP_PORT, SSID_NAME, SSID_PASS);
    D3_SetLow();
    D4_SetLow();
    printf("\n\n\n\rClick S1 to transmit data\r\n");
    
    listening_to_WiFly();
    while (1)
    {
        // Add your application code
        CMD_Check(command);
    }
}
/**
 End of File
*/