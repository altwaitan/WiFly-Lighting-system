/* 
 * File:   RN41.h
 * Author: Garrett Scott (garrett.scott@microchip.com)
 *
 * Comments:    
 * Date        Initials    Comments
 * ------------------------------------------------------
 * 2016-06-22  GS          First version
 */

#ifndef RN41_H
#define	RN41_H

#ifdef	__cplusplus
extern "C" {
#endif

// Types
typedef void (*callbackFunction)(void);
    
//Functions
/**
 * Register the function @callback_CMDWait which occurs while waiting for AOK from the RN41
 * 
 * @param callback_CMDWait
 */

void WiFly_RegisterWaitCallback(callbackFunction callback_CMDWait);

void WiFly_InitializeAsClient(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password);
void WiFly_InitializeAsAPAndHost(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password);
void WiFly_InitializeAsHost(uint8_t* addr, uint16_t* port, uint8_t* ssid, uint8_t* password);
void WiFly_FactoryReset(void);

#ifdef	__cplusplus
}
#endif

#endif	/* RN41_H */

