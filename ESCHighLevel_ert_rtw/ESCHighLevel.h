/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ESCHighLevel.h
 *
 * Code generated for Simulink model 'ESCHighLevel'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon May 30 18:56:02 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ESCHighLevel_h_
#define RTW_HEADER_ESCHighLevel_h_
#include <math.h>
#ifndef ESCHighLevel_COMMON_INCLUDES_
#define ESCHighLevel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ESCHighLevel_COMMON_INCLUDES_ */

#include "ESCHighLevel_types.h"

/* Child system includes */
#include "SlipRateCalFunc.h"
#include "VehSpdEstFunction.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<S1>/SingleWheelStateMachine' */
typedef struct {
  real_T Delay_DSTATE[4];              /* '<S8>/Delay' */
  int32_T Delay1_DSTATE;               /* '<S8>/Delay1' */
  uint8_T is_active_c20_ESCHighLevel;  /* '<S8>/State Machine' */
  uint8_T is_c20_ESCHighLevel;         /* '<S8>/State Machine' */
} DW_SingleWheelStateMachine;

/* Block signals and states (default storage) for system '<Root>/Moving Average1' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<Root>/Moving Average1' */
  real_T MovingAverage1_p;             /* '<Root>/Moving Average1' */
  boolean_T objisempty;                /* '<Root>/Moving Average1' */
} DW_MovingAverage1;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_VehSpdEstFunction VehSpdEstFunc;  /* '<Root>/VehSpdEstFunc' */
  DW_MovingAverage1 MovingAverage4;    /* '<Root>/Moving Average1' */
  DW_MovingAverage1 MovingAverage3;    /* '<Root>/Moving Average1' */
  DW_MovingAverage1 MovingAverage2;    /* '<Root>/Moving Average1' */
  DW_MovingAverage1 MovingAverage1_p;  /* '<Root>/Moving Average1' */
  DW_SingleWheelStateMachine SingleWheelStateMachine3;/* '<S1>/SingleWheelStateMachine3' */
  DW_SingleWheelStateMachine SingleWheelStateMachine2;/* '<S1>/SingleWheelStateMachine2' */
  DW_SingleWheelStateMachine SingleWheelStateMachine1;/* '<S1>/SingleWheelStateMachine1' */
  DW_SingleWheelStateMachine SingleWheelStateMachine_d;/* '<S1>/SingleWheelStateMachine' */
  real_T Delay1_DSTATE[16];            /* '<Root>/Delay1' */
  real_T counter;                      /* '<Root>/MATLAB Function' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  boolean_T Delay2_DSTATE;             /* '<Root>/Delay2' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

/* Model entry point functions */
extern void ESCHighLevel_initialize(RT_MODEL *const rtM);
extern void ESCHighLevel_step(RT_MODEL *const rtM, real_T rtU_whlspd[4], real_T
  rtU_acc_x, real_T rtU_cur_mc_pressure, real_T rtU_cur_wc_pressure[4], real32_T
  rtU_abs_para[8], int32_T rtU_abs_use_external_para, real_T *rtY_est_veh_spd,
  int32_T rtY_abs_valve_state[4], real_T rtY_slip_rate[4], real_T
  rtY_delta_slip_rate[4]);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Conversion' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Conversion' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/G' : Unused code path elimination
 * Block '<S25>/H' : Unused code path elimination
 * Block '<S25>/N' : Unused code path elimination
 * Block '<S25>/P0' : Unused code path elimination
 * Block '<S25>/Q' : Unused code path elimination
 * Block '<S25>/R' : Unused code path elimination
 * Block '<S67>/CheckSignalProperties' : Unused code path elimination
 * Block '<S68>/CheckSignalProperties' : Unused code path elimination
 * Block '<S69>/CheckSignalProperties' : Unused code path elimination
 * Block '<S70>/Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Conversion' : Eliminate redundant data type conversion
 * Block '<S47>/Reshape' : Reshape block reduction
 * Block '<S25>/ReshapeX0' : Reshape block reduction
 * Block '<S25>/Reshapeu' : Reshape block reduction
 * Block '<S25>/Reshapexhat' : Reshape block reduction
 * Block '<S25>/Reshapey' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ESCHighLevel'
 * '<S1>'   : 'ESCHighLevel/AbsConStateMachine'
 * '<S2>'   : 'ESCHighLevel/CalMaxValveState1'
 * '<S3>'   : 'ESCHighLevel/MATLAB Function'
 * '<S4>'   : 'ESCHighLevel/SlipRateCalFunc'
 * '<S5>'   : 'ESCHighLevel/SteeringWheelToFrontWheel'
 * '<S6>'   : 'ESCHighLevel/VehSpdEstFunc'
 * '<S7>'   : 'ESCHighLevel/WhlSpdLinCalFunc'
 * '<S8>'   : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine'
 * '<S9>'   : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine1'
 * '<S10>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine2'
 * '<S11>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine3'
 * '<S12>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine/CalLockCriterion'
 * '<S13>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine/Compare To Constant'
 * '<S14>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine/State Machine'
 * '<S15>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine1/CalLockCriterion'
 * '<S16>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine1/Compare To Constant'
 * '<S17>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine1/State Machine'
 * '<S18>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine2/CalLockCriterion'
 * '<S19>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine2/Compare To Constant'
 * '<S20>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine2/State Machine'
 * '<S21>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine3/CalLockCriterion'
 * '<S22>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine3/Compare To Constant'
 * '<S23>'  : 'ESCHighLevel/AbsConStateMachine/SingleWheelStateMachine3/State Machine'
 * '<S24>'  : 'ESCHighLevel/VehSpdEstFunc/BestWhlSpdEst'
 * '<S25>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter'
 * '<S26>'  : 'ESCHighLevel/VehSpdEstFunc/spdRefCalFunc'
 * '<S27>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL'
 * '<S28>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculateYhat'
 * '<S29>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CovarianceOutputConfigurator'
 * '<S30>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionA'
 * '<S31>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionB'
 * '<S32>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionC'
 * '<S33>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionD'
 * '<S34>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionEnable'
 * '<S35>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionG'
 * '<S36>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionH'
 * '<S37>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionN'
 * '<S38>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionP'
 * '<S39>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionP0'
 * '<S40>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionQ'
 * '<S41>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionR'
 * '<S42>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionReset'
 * '<S43>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionX'
 * '<S44>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionX0'
 * '<S45>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/DataTypeConversionu'
 * '<S46>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/MemoryP'
 * '<S47>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/Observer'
 * '<S48>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/ReducedQRN'
 * '<S49>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/Reset'
 * '<S50>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/Reshapeyhat'
 * '<S51>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/ScalarExpansionP0'
 * '<S52>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/ScalarExpansionQ'
 * '<S53>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/ScalarExpansionR'
 * '<S54>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/UseCurrentEstimator'
 * '<S55>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkA'
 * '<S56>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkB'
 * '<S57>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkC'
 * '<S58>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkD'
 * '<S59>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkEnable'
 * '<S60>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkG'
 * '<S61>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkH'
 * '<S62>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkN'
 * '<S63>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkP0'
 * '<S64>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkQ'
 * '<S65>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkR'
 * '<S66>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkReset'
 * '<S67>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checkX0'
 * '<S68>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checku'
 * '<S69>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/checky'
 * '<S70>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S71>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S72>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S73>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S74>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculatePL/Ground'
 * '<S75>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CalculateYhat/Ground'
 * '<S76>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S77>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S78>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/Observer/MeasurementUpdate'
 * '<S79>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/ReducedQRN/Ground'
 * '<S80>'  : 'ESCHighLevel/VehSpdEstFunc/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S81>'  : 'ESCHighLevel/WhlSpdLinCalFunc/Compare To Constant'
 * '<S82>'  : 'ESCHighLevel/WhlSpdLinCalFunc/WheelCenterSpdCalFunc'
 */
#endif                                 /* RTW_HEADER_ESCHighLevel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
