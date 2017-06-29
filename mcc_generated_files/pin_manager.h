/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18855
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT aliases
#define POT_TRIS               TRISAbits.TRISA0
#define POT_LAT                LATAbits.LATA0
#define POT_PORT               PORTAbits.RA0
#define POT_WPU                WPUAbits.WPUA0
#define POT_OD                ODCONAbits.ODCA0
#define POT_ANS                ANSELAbits.ANSA0
#define POT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT_GetValue()           PORTAbits.RA0
#define POT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define POT_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define POT_SetPushPull()    do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT_SetOpenDrain()   do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define POT_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_CS aliases
#define LED_CS_TRIS               TRISAbits.TRISA3
#define LED_CS_LAT                LATAbits.LATA3
#define LED_CS_PORT               PORTAbits.RA3
#define LED_CS_WPU                WPUAbits.WPUA3
#define LED_CS_OD                ODCONAbits.ODCA3
#define LED_CS_ANS                ANSELAbits.ANSA3
#define LED_CS_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED_CS_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED_CS_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED_CS_GetValue()           PORTAbits.RA3
#define LED_CS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED_CS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED_CS_SetPullup()      do { WPUAbits.WPUA3 = 1; } while(0)
#define LED_CS_ResetPullup()    do { WPUAbits.WPUA3 = 0; } while(0)
#define LED_CS_SetPushPull()    do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED_CS_SetOpenDrain()   do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED_CS_SetAnalogMode()  do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED_CS_SetDigitalMode() do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS               TRISAbits.TRISA4
#define D2_LAT                LATAbits.LATA4
#define D2_PORT               PORTAbits.RA4
#define D2_WPU                WPUAbits.WPUA4
#define D2_OD                ODCONAbits.ODCA4
#define D2_ANS                ANSELAbits.ANSA4
#define D2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define D2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define D2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define D2_GetValue()           PORTAbits.RA4
#define D2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define D2_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define D2_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define D2_SetPushPull()    do { ODCONAbits.ODCA4 = 1; } while(0)
#define D2_SetOpenDrain()   do { ODCONAbits.ODCA4 = 0; } while(0)
#define D2_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define D2_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS               TRISAbits.TRISA5
#define D3_LAT                LATAbits.LATA5
#define D3_PORT               PORTAbits.RA5
#define D3_WPU                WPUAbits.WPUA5
#define D3_OD                ODCONAbits.ODCA5
#define D3_ANS                ANSELAbits.ANSA5
#define D3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define D3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define D3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define D3_GetValue()           PORTAbits.RA5
#define D3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define D3_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define D3_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define D3_SetPushPull()    do { ODCONAbits.ODCA5 = 1; } while(0)
#define D3_SetOpenDrain()   do { ODCONAbits.ODCA5 = 0; } while(0)
#define D3_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define D3_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS               TRISAbits.TRISA6
#define D4_LAT                LATAbits.LATA6
#define D4_PORT               PORTAbits.RA6
#define D4_WPU                WPUAbits.WPUA6
#define D4_OD                ODCONAbits.ODCA6
#define D4_ANS                ANSELAbits.ANSA6
#define D4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define D4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define D4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define D4_GetValue()           PORTAbits.RA6
#define D4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define D4_SetPullup()      do { WPUAbits.WPUA6 = 1; } while(0)
#define D4_ResetPullup()    do { WPUAbits.WPUA6 = 0; } while(0)
#define D4_SetPushPull()    do { ODCONAbits.ODCA6 = 1; } while(0)
#define D4_SetOpenDrain()   do { ODCONAbits.ODCA6 = 0; } while(0)
#define D4_SetAnalogMode()  do { ANSELAbits.ANSA6 = 1; } while(0)
#define D4_SetDigitalMode() do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set Click_RST aliases
#define Click_RST_TRIS               TRISBbits.TRISB1
#define Click_RST_LAT                LATBbits.LATB1
#define Click_RST_PORT               PORTBbits.RB1
#define Click_RST_WPU                WPUBbits.WPUB1
#define Click_RST_OD                ODCONBbits.ODCB1
#define Click_RST_ANS                ANSELBbits.ANSB1
#define Click_RST_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Click_RST_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Click_RST_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Click_RST_GetValue()           PORTBbits.RB1
#define Click_RST_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Click_RST_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Click_RST_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define Click_RST_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define Click_RST_SetPushPull()    do { ODCONBbits.ODCB1 = 1; } while(0)
#define Click_RST_SetOpenDrain()   do { ODCONBbits.ODCB1 = 0; } while(0)
#define Click_RST_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define Click_RST_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set Click_Wake aliases
#define Click_Wake_TRIS               TRISBbits.TRISB2
#define Click_Wake_LAT                LATBbits.LATB2
#define Click_Wake_PORT               PORTBbits.RB2
#define Click_Wake_WPU                WPUBbits.WPUB2
#define Click_Wake_OD                ODCONBbits.ODCB2
#define Click_Wake_ANS                ANSELBbits.ANSB2
#define Click_Wake_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define Click_Wake_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define Click_Wake_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define Click_Wake_GetValue()           PORTBbits.RB2
#define Click_Wake_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define Click_Wake_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define Click_Wake_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define Click_Wake_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define Click_Wake_SetPushPull()    do { ODCONBbits.ODCB2 = 1; } while(0)
#define Click_Wake_SetOpenDrain()   do { ODCONBbits.ODCB2 = 0; } while(0)
#define Click_Wake_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define Click_Wake_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()    do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()   do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()   do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()         PORTBbits.RB5
#define RB5_SetDigitalInput()   do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()  do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()     do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()   do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode() do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()    do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()   do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()   do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()         PORTBbits.RB6
#define RB6_SetDigitalInput()   do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()  do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()     do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()   do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode() do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()     do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()   do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode() do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set MODE_SELECT aliases
#define MODE_SELECT_TRIS               TRISCbits.TRISC2
#define MODE_SELECT_LAT                LATCbits.LATC2
#define MODE_SELECT_PORT               PORTCbits.RC2
#define MODE_SELECT_WPU                WPUCbits.WPUC2
#define MODE_SELECT_OD                ODCONCbits.ODCC2
#define MODE_SELECT_ANS                ANSELCbits.ANSC2
#define MODE_SELECT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define MODE_SELECT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define MODE_SELECT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define MODE_SELECT_GetValue()           PORTCbits.RC2
#define MODE_SELECT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define MODE_SELECT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define MODE_SELECT_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define MODE_SELECT_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define MODE_SELECT_SetPushPull()    do { ODCONCbits.ODCC2 = 1; } while(0)
#define MODE_SELECT_SetOpenDrain()   do { ODCONCbits.ODCC2 = 0; } while(0)
#define MODE_SELECT_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define MODE_SELECT_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()     do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()   do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set S2 aliases
#define S2_TRIS               TRISCbits.TRISC5
#define S2_LAT                LATCbits.LATC5
#define S2_PORT               PORTCbits.RC5
#define S2_WPU                WPUCbits.WPUC5
#define S2_OD                ODCONCbits.ODCC5
#define S2_ANS                ANSELCbits.ANSC5
#define S2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define S2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define S2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define S2_GetValue()           PORTCbits.RC5
#define S2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define S2_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define S2_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define S2_SetPushPull()    do { ODCONCbits.ODCC5 = 1; } while(0)
#define S2_SetOpenDrain()   do { ODCONCbits.ODCC5 = 0; } while(0)
#define S2_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define S2_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()     do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()   do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()     do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()   do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/