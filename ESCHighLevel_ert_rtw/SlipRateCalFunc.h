/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SlipRateCalFunc.h
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

#ifndef RTW_HEADER_SlipRateCalFunc_h_
#define RTW_HEADER_SlipRateCalFunc_h_
#ifndef ESCHighLevel_COMMON_INCLUDES_
#define ESCHighLevel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ESCHighLevel_COMMON_INCLUDES_ */

#include "ESCHighLevel_types.h"

extern void SlipRateCalFunc(const real_T rtu_wheel_speed[4], const real_T
  rtu_wheel_speed_linear[4], real_T rty_slip_rate[4]);

#endif                                 /* RTW_HEADER_SlipRateCalFunc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
