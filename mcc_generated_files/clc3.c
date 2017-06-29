/**
  CLC3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    clc3.c

  @Summary
    This is the generated driver implementation file for the CLC3 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides implementations for driver APIs for CLC3.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18855
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "clc3.h"

/**
  Section: CLC3 APIs
*/

void CLC3_Initialize(void)
{
    // Set the CLC3 to the options selected in the User Interface

    // LC3G1POL inverted; LC3G2POL not_inverted; LC3G3POL not_inverted; LC3G4POL not_inverted; LC3POL not_inverted; 
    CLC3POL = 0x01;

    // LC3D1S PWM6_OUT; 
    CLC3SEL0 = 0x18;

    // LC3D2S SCK from MSSP1; 
    CLC3SEL1 = 0x27;

    // LC3D3S SDO from MSSP1; 
    CLC3SEL2 = 0x26;

    // LC3D4S CLCIN0 (CLCIN0PPS); 
    CLC3SEL3 = 0x00;

    // LC3G1D3N disabled; LC3G1D2N enabled; LC3G1D4N disabled; LC3G1D1T disabled; LC3G1D3T disabled; LC3G1D2T disabled; LC3G1D4T disabled; LC3G1D1N enabled; 
    CLC3GLS0 = 0x05;

    // LC3G2D2N disabled; LC3G2D1N disabled; LC3G2D4N disabled; LC3G2D3N enabled; LC3G2D2T disabled; LC3G2D1T enabled; LC3G2D4T disabled; LC3G2D3T disabled; 
    CLC3GLS1 = 0x12;

    // LC3G3D1N disabled; LC3G3D2N disabled; LC3G3D3N disabled; LC3G3D4N disabled; LC3G3D1T disabled; LC3G3D2T enabled; LC3G3D3T disabled; LC3G3D4T disabled; 
    CLC3GLS2 = 0x08;

    // LC3G4D1N disabled; LC3G4D2N disabled; LC3G4D3N disabled; LC3G4D4N disabled; LC3G4D1T disabled; LC3G4D2T disabled; LC3G4D3T enabled; LC3G4D4T disabled; 
    CLC3GLS3 = 0x20;

    // LC3EN enabled; INTN disabled; INTP disabled; MODE AND-OR; 
    CLC3CON = 0x80;

}

bool CLC3_OutputStatusGet(void)
{
    return(CLC3CONbits.LC3OUT);

}
/**
 End of File
*/
