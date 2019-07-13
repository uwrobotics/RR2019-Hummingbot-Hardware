#ifndef VEHICLE_CONTROLLER_H_
#define VEHICLE_CONTROLLER_H_


#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
/***********************************
 ********* Macro Definition **********
 ***********************************/
// define some common metric uint
typedef int16_t    angle_deg_t; 
typedef uint16_t   pulse_us_t;
typedef int16_t    speed_cm_per_s_t;
typedef int16_t    rf24_joystick_tik_t;
// some conversion unit
// NOTE: change to uint16_t if your processor does not have a FPU, might suffer trimming/truncation error
// NOTE*: please use uint16_t, since float still takes too long to compute
// NOTE: TODO: fixed float should be implemented in order to achieve high speed floating calc.
typedef uint16_t   us_per_deg_t;
typedef uint16_t   us_s_per_mm_t;

typedef enum{
    VC_STATE_UNDEFINED,
    VC_STATE_CONFIGED,
    VC_STATE_INITED,
    VC_STATE_IDLE,
    VC_STATE_RUNNING,
    VC_STATE_NEUTRAL,
    VC_STATE_REVERSING,
    VC_STATE_FAULT,
    VC_STATE_DESTROYED,
} VC_state_E;

typedef enum{
    VC_CHANNEL_NAME_STEERING,
    VC_CHANNEL_NAME_THROTTLE,
    VC_CHANNEL_NAME_COUNT,
    VC_CHANNEL_NAME_ALL,
} VC_channnelName_E;
/*******************************************************************************
 * public functions
 ******************************************************************************/
void VC_Config(void);
VC_state_E VC_getVehicleControllerState(void);

pulse_us_t VC_requestSteering(angle_deg_t reqAng);
pulse_us_t VC_requestThrottle(speed_cm_per_s_t reqSpd);
pulse_us_t VC_doBraking(void);
void VC_joystick_control(rf24_joystick_tik_t steeringAxis, rf24_joystick_tik_t throttleAxis, angle_deg_t* out_convertedAng, speed_cm_per_s_t* out_convertedSpd, pulse_us_t *outAngPW, pulse_us_t *outSpdPW);
VC_state_E VC_getVehicleControllerState(void);
#ifdef __cplusplus
} // extern "C"
#endif
#endif //(VEHICLE_CONTROLLER_H_)
