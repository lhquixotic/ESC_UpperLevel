/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VehSpdEstFunction.h
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

#ifndef RTW_HEADER_VehSpdEstFunction_h_
#define RTW_HEADER_VehSpdEstFunction_h_
#ifndef ESCHighLevel_COMMON_INCLUDES_
#define ESCHighLevel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ESCHighLevel_COMMON_INCLUDES_ */

#include "ESCHighLevel_types.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<Root>/VehSpdEstFunc' */
typedef struct {
  real_T MemoryX_DSTATE;               /* '<S25>/MemoryX' */
  real_T Delay1_DSTATE;                /* '<S6>/Delay1' */
  real_T modify_flag;                  /* '<S6>/spdRefCalFunc' */
  boolean_T icLoad;                    /* '<S25>/MemoryX' */
} DW_VehSpdEstFunction;

extern void VehSpdEstFunction_Init(DW_VehSpdEstFunction *localDW);
extern real_T VehSpdEstFunction(real_T rtu_w1, real_T rtu_w2, real_T rtu_w3,
  real_T rtu_w4, boolean_T rtu_brk_flag, real_T rtu_a_x, boolean_T rtu_abs_is_on,
  int32_T rtu_use_external_para, real32_T rtu_modify_factor,
  DW_VehSpdEstFunction *localDW);

#endif                                 /* RTW_HEADER_VehSpdEstFunction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
