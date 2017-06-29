/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18855
        Driver Version    :  1.02
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATA = 0x08;    
    LATB = 0x02;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISA = 0xB5;
    TRISB = 0xD8;
    TRISC = 0x92;

    /**
    ANSELx registers
    */   
    ANSELC = 0x73;
    ANSELB = 0xAF;
    ANSELA = 0x11;

    /**
    WPUx registers
    */ 
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */   
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    


   
    
    
    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RC0PPS = 0x01;   //RC0->CLC1:CLC1OUT;
    SSP1DATPPSbits.SSP1DATPPS = 0x0C;   //RB4->MSSP1:SDI1;
    SSP1CLKPPSbits.SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCK1;
    RXPPSbits.RXPPS = 0x17;   //RC7->EUSART:RX;
    RC3PPS = 0x14;   //RC3->MSSP1:SCK1;
    CLCIN0PPSbits.CLCIN0PPS = 0x03;   //RA3->CLC3:CLCIN0;
    CLCIN2PPSbits.CLCIN2PPS = 0x0E;   //RB6->CLC3:CLCIN2;
    RB5PPS = 0x15;   //RB5->MSSP1:SDO1;
    T2AINPPSbits.T2AINPPS = 0x13;   //RC3->TMR2:T2IN;
    CLCIN1PPSbits.CLCIN1PPS = 0x12;   //RC2->CLC3:CLCIN1;
    RB0PPS = 0x03;   //RB0->CLC3:CLC3OUT;
    RC6PPS = 0x10;   //RC6->EUSART:TX;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

    GIE = state;
}       

void PIN_MANAGER_IOC(void)
{   

}

/**
 End of File
*/