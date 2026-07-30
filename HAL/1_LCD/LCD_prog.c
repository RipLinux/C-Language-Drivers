#include "Bit_Math.h"
#include "Std_Types.h"

#include "DIO_int.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include <avr/delay.h>
#include "LCD_private.h"

static void LCD_voidPutOnBus(u8 u8Char)
{
    // set each value of u8Char to each value of LCD
    DIO_voidSetPinValue(LCD_D0, GET_BIT(u8Char, 0));
    DIO_voidSetPinValue(LCD_D1, GET_BIT(u8Char, 1));
    DIO_voidSetPinValue(LCD_D2, GET_BIT(u8Char, 2));
    DIO_voidSetPinValue(LCD_D3, GET_BIT(u8Char, 3));
    DIO_voidSetPinValue(LCD_D4, GET_BIT(u8Char, 4));
    DIO_voidSetPinValue(LCD_D5, GET_BIT(u8Char, 5));
    DIO_voidSetPinValue(LCD_D6, GET_BIT(u8Char, 6));
    DIO_voidSetPinValue(LCD_D7, GET_BIT(u8Char, 7));

    // activate enable and wait 2 ms
    DIO_voidSetPinValue(LCD_EN, HIGH);
    _delay_ms(2);

    // disactivate enable and wait 2 ms
    DIO_voidSetPinValue(LCD_EN, LOW);
    _delay_ms(2);
}

void LCD_voidInit(void)
{
    // wait 30 ms
    _delay_ms(35);
    // send home command and wait 1 ms
    LCD_voidSendCommand(LCD_HOME);
    _delay_ms(1);    
    // send function set command and wait 1 ms
    LCD_voidSendCommand(LCD_FUNCTIONSET_8BIT);
    _delay_ms(1);
    // send display on/off command and wait 1 ms
    LCD_voidSendCommand(LCD_DISPLAYON);
    _delay_ms(1);
    // send display clear command and wait 1ms 
    LCD_voidSendCommand(LCD_CLEAR);
    _delay_ms(2);
    // send entry mode command and wait 1ms
    LCD_voidSendCommand(LCD_ENTRY_MODE);
    _delay_ms(1);

}

void LCD_voidSendCommand(u8 u8CMD)
{
    // command register
    DIO_voidSetPinValue(LCD_RS, LOW); 
    DIO_voidSetPinValue(LCD_RW, LOW); 

    LCD_voidPutOnBus(u8CMD);
}
void LCD_voidSendData(u8 u8DATA)
{
    // Data register
    DIO_voidSetPinValue(LCD_RS, HIGH); 
    DIO_voidSetPinValue(LCD_RW, LOW); 

    LCD_voidPutOnBus(u8DATA);

}

