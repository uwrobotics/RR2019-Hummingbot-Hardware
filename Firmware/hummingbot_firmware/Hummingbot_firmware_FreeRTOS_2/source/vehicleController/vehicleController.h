#ifndef VEHICLE_CONTROLLER_H_
#define VEHICLE_CONTROLLER_H_


#include <stdint.h>
#include <stdbool.h>
/***********************************
 ********* Macro Definition **********
 ***********************************/
// define some common metric uint
typedef int16_t    angle_deg_t; 
typedef uint16_t   pulse_us_t;
typedef int16_t    speed_mm_per_s_t;

// some conversion unit
typedef uint16_t   us_per_deg_t;
typedef uint16_t   us_s_per_mm_t;

typedef enum{
    VC_STATE_UNDEFINED,
    VC_STATE_CONFIGED,
    VC_STATE_INITED,
    VC_STATE_IDLE,
    VC_STATE_RUNNING,
    VC_STATE_FAULT,
    VC_STATE_DESTROYED,
} VC_state_E;

typedef enum{
    VC_ERROR_FLAG_STEERING_ERR,
    VC_ERROR_FLAG_THROTTLE_ERR,
    VC_ERROR_FLAG_UNABLE_BRAKING_ERR,
    VC_ERROR_FLAG_UNABLE_FREE_CONTROL_ERR,
} VC_errorFlag_E;

typedef enum{
    VC_CHANNEL_NAME_STEERING,
    VC_CHANNEL_NAME_THROTTLE,
    VC_CHANNEL_NAME_COUNT,
    VC_CHANNEL_NAME_ALL,
} VC_channnelName_E;
/*******************************************************************************
 * public functions
 ******************************************************************************/
void VC_onDestroy(void);
void VC_Config(void);
bool VC_Init(void);
bool VC_Begin(void);

uint16_t VC_getErrorFlags(void);
VC_state_E VC_getVehicleControllerState(void);
void VC_dummyTestRun(void);

bool VC_requestSteering(angle_deg_t reqAng);
bool VC_requestThrottle(speed_mm_per_s_t reqSpd);
bool VC_doBraking(angle_deg_t reqAng);
bool VC_powerOff_FreeWheeling(VC_channnelName_E controller);

bool VC_requestThrottle_raw(pulse_us_t pw_us);
bool VC_requestSteering_raw(pulse_us_t pw_us);

#endif //(VEHICLE_CONTROLLER_H_)
