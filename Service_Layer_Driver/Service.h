/*
 * Service.h
 *
 * Created: 24-Jul-21 3:18:03 PM
 *  Author: ayman
 */ 


#ifndef SERVICE_H_
#define SERVICE_H_
//modes
#define INITIAL_MODE       0
#define FIRSTSPEED_MODE    1
#define SECONDSPEED_MODE   2
#define THIRDSPEED_MODE	   3
#define BACKSPEED_MODE	   4
#define MOVE_MODE		   5
#define STOP_MODE		   6
#define LEFT_MODE		   7
#define RIGHT_MODE		   8
//
void Service_vdInit();
void Service_vdFirstSpeed();
void Service_vdSecondSpeed();
void Service_vdThirdSpeed();
void Service_vdBackSpeed();
void Service_vdmove();
void Service_vdmoveLeft();
void Service_vdmoveRight();
void Service_vdstop();
void Service_vdupdate();

#endif /* SERVICE_H_ */