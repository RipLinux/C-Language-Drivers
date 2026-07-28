/***************************************/
/******   Author:   Anas         *******/
/******   Time:     07/28/2026   *******/
/******   File:     Program File *******/
/***************************************/
#include <Std_Types.h>
#include <Bit_Math.h>

#include <DIO_private.h>
#include <DIO_int.h>
#include <DIO_config.h>

void DIO_voidInitialization(void)
{
    DDRA = DIO_PORTA_DIRECTIONS;
    DDRB = DIO_PORTB_DIRECTIONS;
    DDRC = DIO_PORTC_DIRECTIONS;
    DDRD = DIO_PORTD_DIRECTIONS;
}

void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction)
{
    if(( PortID < 4 ) && ( PinID < 8 ) && (Direction == OUTPUT || Direction == INPUT )) 
    {
        if(Direction == OUTPUT)
        {
            switch(PortID)
            {
                case PORTA: SET_BIT(DDRA, PinID); break;
                case PORTB: SET_BIT(DDRB, PinID); break;
                case PORTC: SET_BIT(DDRC, PinID); break;
                case PORTD: SET_BIT(DDRD, PinID); break;
            }
        }
        else if(Direction == INPUT)
        {
            switch(PortID)
            {
            case PORTA: CLR_BIT(DDRA, PinID); break;
            case PORTB: CLR_BIT(DDRB, PinID); break;
            case PORTC: CLR_BIT(DDRC, PinID); break;
            case PORTD: CLR_BIT(DDRD, PinID); break;
            }
        }
    }
    else
    {
    
    }
}

void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 Value)
{
    if(( PortID < 4 ) && ( PinID < 8 ) && (Value == HIGH || Value == LOW )) 
    {
        if(Value == HIGH)
        {
            switch(PortID)
            {
                case PORTA: SET_BIT(PORTA, PinID); break;
                case PORTB: SET_BIT(PORTB, PinID); break;
                case PORTC: SET_BIT(PORTC, PinID); break;
                case PORTD: SET_BIT(PORTD, PinID); break;
            }
        }
        else if(Value == LOW)
        {
            switch(PortID)
            {
            case PORTA: CLR_BIT(PORTA, PinID); break;
            case PORTB: CLR_BIT(PORTB, PinID); break;
            case PORTC: CLR_BIT(PORTC, PinID); break;
            case PORTD: CLR_BIT(PORTD, PinID); break;
            }
        }
    }
    else
    {
    
    }
}

u8 DIO_u8GetPinValue(u8 PortID,u8 PinID)
{
    if(( PortID < 4 ) && ( PinID < 8 )) 
    {
         switch(PortID)
        {
            case PORTA: x=GET_BIT(PORTA, PinID); break;
            case PORTB: x=GET_BIT(PORTB, PinID); break;
            case PORTC: x=GET_BIT(PORTC, PinID); break;
            case PORTD: x=GET_BIT(PORTD, PinID); break;
        }
    }
    else
    {
    
    }
    return x;
}

void DIO_voidTogPinValue(u8 PortID,u8 PinID)
{
    if(( PortID < 4 ) && ( PinID < 8 )) 
    {
         switch(PortID)
        {
            case PORTA: x=TOG_BIT(PORTA, PinID); break;
            case PORTB: x=TOG_BIT(PORTB, PinID); break;
            case PORTC: x=TOG_BIT(PORTC, PinID); break;
            case PORTD: x=TOG_BIT(PORTD, PinID); break;
        }
    }
    else
    {
    
    }
}

void DIO_voidSetPortDirection(u8 PortID,u8 Direction)
{
    if(( PortID < 4 ) && (Direction == OUTPUT || Value == INPUT )) 
    {
         switch(PortID)
        {
            case PORTA: DDRA = Direction; break;
            case PORTB: DDRB = Direction; break;
            case PORTC: DDRC = Direction; break;
            case PORTD: DDR = Direction; break;
        }
    }
    else
    {
    
    }
}

void DIO_voidSetPortValue(u8 PortID,u8 Value)
{
    if(( PortID < 4 ) && (Value == HIGH || Value == LOW ) ) 
    {
         switch(PortID)
        {
            case PORTA: PORTA = Value; break;
            case PORTB: PORTB = Value; break;
            case PORTC: PORTC = Value; break;
            case PORTD: PORTD = Value; break;
        }
    }
    else
    {
    
    }
}
