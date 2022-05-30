/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ESCHighLevel_types.h
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

#ifndef RTW_HEADER_ESCHighLevel_types_h_
#define RTW_HEADER_ESCHighLevel_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_VywbwoSs6z0Z3AW6Nq2eCH
#define struct_tag_VywbwoSs6z0Z3AW6Nq2eCH

struct tag_VywbwoSs6z0Z3AW6Nq2eCH
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[2];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_VywbwoSs6z0Z3AW6Nq2eCH */

#ifndef typedef_g_dsp_internal_SlidingWindowAve
#define typedef_g_dsp_internal_SlidingWindowAve

typedef struct tag_VywbwoSs6z0Z3AW6Nq2eCH g_dsp_internal_SlidingWindowAve;

#endif                             /* typedef_g_dsp_internal_SlidingWindowAve */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_kXGP0IaDlLdwL3QBDwgd6E
#define struct_tag_kXGP0IaDlLdwL3QBDwgd6E

struct tag_kXGP0IaDlLdwL3QBDwgd6E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_SlidingWindowAve *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowAve _pobj0;
};

#endif                                 /* struct_tag_kXGP0IaDlLdwL3QBDwgd6E */

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_kXGP0IaDlLdwL3QBDwgd6E dsp_simulink_MovingAverage;

#endif                                 /* typedef_dsp_simulink_MovingAverage */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_ESCHighLevel_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
