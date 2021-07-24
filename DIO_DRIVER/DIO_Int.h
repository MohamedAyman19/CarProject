/*
 * DIO.h
 *
 * Created: 22-Jul-21 4:14:45 PM
 *  Author: ayman
 */ 

#ifndef DIO_INIT_H
#define DIO_INIT_H

sint8_t DIO_sint8_tSetPortDirection(uint8_t PortID, uint8_t PortDirection);              
sint8_t DIO_sint8_tSetPinDirection(uint8_t PortID,uint8_t PinNumber, uint8_t PinDirection); 
sint8_t DIO_sint8_tWritePortValue(uint8_t PortID, uint8_t PortValue);                  
sint8_t DIO_sint8_tWritePinValue(uint8_t PortID,uint8_t PinNumber, uint8_t PinValue);       
sint8_t DIO_sint8_t_tGetPinValue(uint8_t PortID, uint8_t PinNumber);                       
sint8_t DIO_sint8_tTogglePin(uint8_t PortID,uint8_t PinNumber);                                                        
sint8_t DIO_sint8_tEnPullUpRes(uint8_t PortID,uint8_t PinNumber);                      
sint8_t DIO_sint8_tGetPortValue(uint8_t PortID, uint8_t PinNumber);
// The 4 Ports counted from 0 to 3
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

// Set Port direction as input = 0 or output = 255
#define PORT_INPUT  0
#define PORT_OUTPUT 255

// The 8 Pins counted from 0 to 7
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// Set Pin direction as input = 0 or output = 1
#define PIN_INPUT  0
#define PIN_OUTPUT 1

// Set Pin value as low = 0 or high = 1
#define PIN_LOW  0
//#define DIO_U8_PIN_LOW_LEVEL  0
#define PIN_HIGH 1
// error handling
#define PARAMETER_ERROR -1



#endif /* DIO_INIT_H */