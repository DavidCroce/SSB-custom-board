/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"
#include "Arduino.h"

/*
 * Pins descriptions
 */

//TCC0 IOSET 6
//TCC1 IOSET 1
//TC0 IOSET 1
//TC1 IOSET 1
//TC2 IOSET 2
//TC3 IOSET 1
//TC4 IOSET 1
const PinDescription g_APinDescription[]=
{
  // 
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)
  { PORTB, 17, PIO_SERCOM, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH4, NOT_ON_TIMER, EXTERNAL_INT_1 }, // RX: SERCOM5/PAD[1]
  { PORTB, 16, PIO_SERCOM, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH5, NOT_ON_TIMER, EXTERNAL_INT_0 }, // TX: SERCOM5/PAD[0]

  // 2..39 - Digital pins
  // ----------------------
  { PORTA, 2, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },
  { PORTA, 3, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },
  { PORTA, 4, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC0_CH0, TC0_CH0, EXTERNAL_INT_4 },
  { PORTA, 5, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC0_CH1, TC0_CH1, EXTERNAL_INT_5 },
  { PORTA, 6, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
  { PORTA, 7, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },
  { PORTA, 12, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_12 },
  { PORTA, 13, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_13 },
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC3_CH0, TC3_CH0, EXTERNAL_INT_14 },
  { PORTA, 15, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC3_CH1, TC3_CH1, EXTERNAL_INT_15 },
  { PORTA, 16, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_0 },
  { PORTA, 17, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_1 },
  { PORTA, 18, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC3_CH0, TC3_CH0, EXTERNAL_INT_2 },
  { PORTA, 19, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC3_CH1, TC3_CH1, EXTERNAL_INT_3 },
  { PORTA, 21, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },
  { PORTA, 22, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC4_CH0, TC4_CH0, EXTERNAL_INT_6 },
  { PORTA, 23, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC4_CH1, TC4_CH1, EXTERNAL_INT_7 },
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },

  { PORTB, 0, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC7_CH0, TC7_CH0, EXTERNAL_INT_0 },
  { PORTB, 1, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC7_CH1, TC7_CH1, EXTERNAL_INT_1 },
  { PORTB, 2, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC6_CH0, TC6_CH0, EXTERNAL_INT_2 },
  { PORTB, 3, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC6_CH1, TC6_CH1, EXTERNAL_INT_3 },
  { PORTB, 4, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },
  { PORTB, 5, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },
  { PORTB, 6, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
  { PORTB, 7, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },
  { PORTB, 8, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC4_CH0, TC4_CH0, EXTERNAL_INT_8 },
  { PORTB, 9, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC4_CH1, TC4_CH1, EXTERNAL_INT_9 },
  { PORTB, 12, PIO_DIGITAL, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 },
  { PORTB, 13, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC4_CH1, TC4_CH1, EXTERNAL_INT_13 },
  { PORTB, 14, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC5_CH0, TC5_CH0, EXTERNAL_INT_14 },
  { PORTB, 15, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC5_CH1, TC5_CH1, EXTERNAL_INT_15 },
  { PORTB, 16, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH5, NOT_ON_TIMER, EXTERNAL_INT_0 },
  { PORTB, 17, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH4, NOT_ON_TIMER, EXTERNAL_INT_1 },
  { PORTB, 22, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC7_CH0, TC7_CH0, EXTERNAL_INT_6 },
  { PORTB, 23, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC7_CH1, TC7_CH1, EXTERNAL_INT_7 },
  { PORTB, 30, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC0_CH0, TC0_CH0, EXTERNAL_INT_14 },
  { PORTB, 31, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC0_CH1, TC0_CH1, EXTERNAL_INT_15 },

  // 40..49 - Analog pins
  // --------------------
  { PORTA,  3, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel1, TC0_CH1, TC0_CH1, EXTERNAL_INT_3 }, // PA03, Analog 
  { PORTA,  4, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4 }, // PA04, Analog 
  { PORTA,  6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6 }, // PA06, Analog 
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7 }, // PA07, Analog 

  { PORTB, 2, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel10, TC6_CH0, TC6_CH0, EXTERNAL_INT_2 }, // PB02, Analog 
  { PORTB, 3, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel11, TC6_CH1, TC6_CH1, EXTERNAL_INT_3 }, // PB03, Analog 
  { PORTB, 4, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel12, TC7_CH0, TC7_CH0, EXTERNAL_INT_4 }, // PB04, Analog 
  { PORTB, 5, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel13, TC7_CH1, TC7_CH1, EXTERNAL_INT_5 }, // PB05, Analog 
  { PORTB, 6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel14, TC6_CH0, TC6_CH0, EXTERNAL_INT_6 }, // PB06, Analog 
  { PORTB, 7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel15, TC6_CH1, TC6_CH1, EXTERNAL_INT_7 }, // PB07, Analog 

  
  // 50..53 - I2C pins (SDA/SCL)
  // ----------------------
  // I2C0
  { PORTB,  8, PIO_ANALOG, PIN_ATTR_PWM_E, ADC_Channel2, TC4_CH0, TC4_CH0, EXTERNAL_INT_8 }, // SDA0: SERCOM4/PAD[0]
  { PORTB,  9, PIO_ANALOG, PIN_ATTR_PWM_E, ADC_Channel3, TC4_CH1, TC4_CH1, EXTERNAL_INT_9 }, // SCL0: SERCOM4/PAD[1]

  // I2C1
  { PORTA, 12, PIO_SERCOM, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_12 }, // SDA1: SERCOM2/PAD[0]
  { PORTA, 13, PIO_SERCOM, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_13 }, // SCL1: SERCOM2/PAD[1]

  // 54..57 - SPI pins for SD card (MOSI, MISO, SCK, CS)
  // ----------------------
  { PORTA, 19, PIO_TIMER_ALT, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, // MOSI: SERCOM1/PAD[3]
  { PORTA, 18, PIO_TIMER_ALT, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH2, TC3_CH0, EXTERNAL_INT_2 }, // MISO: SERCOM1/PAD[2]
  { PORTA, 17, PIO_TIMER_ALT, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, TC3_CH1, EXTERNAL_INT_1 }, // SCK: SERCOM1/PAD[1]
  { PORTA, 16, PIO_TIMER_ALT, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH0, TC2_CH0, EXTERNAL_INT_0 }, // CS: SERCOM1/PAD[0]

  // 58..59 - USB (D-/D+)
  // --------------------
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 27, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP

  // 60..61 - Alternate use of A0 (DAC output)
  // ----------------------
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VOUT0
  { PORTA,  5, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VOUT1

  // 62..67 - QSPI (SCK, CS, IO0, IO1, IO2, IO3)
  // ----------------------
  { PORTB, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 8, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 9, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  // 68..69 - CAN0 (TX/RX)
  // ----------------------
  { PORTA, 22, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // CAN0TX
  { PORTA, 23, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // CAN0RX

  
  // 70..71 - CAN1 (TX/RX)
  // ----------------------
  { PORTB, 14, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // CAN1TX
  { PORTB, 15, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // CAN1RX

  // 72..73 - SWDIO, SWCLK
  // ----------------------
  { PORTA, 30, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SWDIO
  { PORTA, 31, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SWCLK

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TCC3, TCC4, TC0, TC1, TC2, TC3, TC4, TC5 } ;
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TCC3_GCLK_ID, TCC4_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID, TC4_GCLK_ID, TC5_GCLK_ID } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom5, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM5_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM5_3_Handler()
{
  Serial1.IrqHandler();
}

