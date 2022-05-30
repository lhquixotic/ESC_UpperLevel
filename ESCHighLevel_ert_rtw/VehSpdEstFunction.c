/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VehSpdEstFunction.c
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

#include "VehSpdEstFunction.h"

/* Include model header file for global data */
#include "ESCHighLevel.h"
#include "ESCHighLevel_private.h"

/* System initialize for atomic system: '<Root>/VehSpdEstFunc' */
void VehSpdEstFunction_Init(DW_VehSpdEstFunction *localDW)
{
  /* InitializeConditions for Delay: '<S25>/MemoryX' */
  localDW->icLoad = true;
}

/* Output and update for atomic system: '<Root>/VehSpdEstFunc' */
real_T VehSpdEstFunction(real_T rtu_w1, real_T rtu_w2, real_T rtu_w3, real_T
  rtu_w4, boolean_T rtu_brk_flag, real_T rtu_a_x, boolean_T rtu_abs_is_on,
  int32_T rtu_use_external_para, real32_T rtu_modify_factor,
  DW_VehSpdEstFunction *localDW)
{
  real_T rty_est_veh_spd_0;
  real_T x[4];
  real_T rtb_best_whl_spd;

  /* MATLAB Function: '<S6>/BestWhlSpdEst' */
  if (rtu_brk_flag) {
    int32_T idx;
    x[0] = rtu_w1;
    x[1] = rtu_w2;
    x[2] = rtu_w3;
    x[3] = rtu_w4;
    if (!rtIsNaN(rtu_w1)) {
      idx = 1;
    } else {
      int32_T k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      rtb_best_whl_spd = rtu_w1;
    } else {
      rtb_best_whl_spd = x[idx - 1];
      while (idx + 1 <= 4) {
        if (rtb_best_whl_spd < x[idx]) {
          rtb_best_whl_spd = x[idx];
        }

        idx++;
      }
    }
  } else {
    rtb_best_whl_spd = (rtu_w1 + rtu_w2) / 2.0;
  }

  /* End of MATLAB Function: '<S6>/BestWhlSpdEst' */

  /* Delay: '<S25>/MemoryX' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (localDW->icLoad) {
    localDW->MemoryX_DSTATE = 0.0;
  }

  /* MATLAB Function: '<S6>/spdRefCalFunc' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Delay: '<S6>/Delay1'
   */
  if (!rtu_brk_flag) {
    localDW->modify_flag = 0.0;
  }

  if ((localDW->modify_flag == 0.0) && rtu_abs_is_on) {
    real_T rtu_use_external_para_0;
    localDW->modify_flag = 1.0;

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    if (rtu_use_external_para > 0) {
      rtu_use_external_para_0 = rtu_modify_factor;
    } else {
      rtu_use_external_para_0 = 0.03;
    }

    /* End of Switch: '<S6>/Switch1' */
    rty_est_veh_spd_0 = (rtu_use_external_para_0 + 1.0) * localDW->Delay1_DSTATE
      + rtu_a_x * 0.008;
  } else {
    rty_est_veh_spd_0 = rtu_a_x * 0.008 + localDW->Delay1_DSTATE;
  }

  /* End of MATLAB Function: '<S6>/spdRefCalFunc' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S27>/KalmanGainM'
   *  Delay: '<S25>/MemoryX'
   *  Product: '<S80>/Product2'
   *  Sum: '<S54>/Add'
   *  Sum: '<S80>/Add1'
   */
  if (!rtu_abs_is_on) {
    /* Outputs for Enabled SubSystem: '<S54>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S80>/Enable'
     */
    rty_est_veh_spd_0 = (rtb_best_whl_spd - localDW->MemoryX_DSTATE) *
      0.7320508075688773 + localDW->MemoryX_DSTATE;

    /* End of Outputs for SubSystem: '<S54>/Enabled Subsystem' */
  }

  /* End of Switch: '<S6>/Switch' */

  /* Update for Delay: '<S25>/MemoryX' incorporates:
   *  Constant: '<S25>/B'
   *  Constant: '<S25>/D'
   *  Constant: '<S27>/KalmanGainL'
   *  Product: '<S47>/B[k]*u[k]'
   *  Product: '<S78>/D[k]*u[k]'
   *  Product: '<S78>/Product3'
   *  Sum: '<S47>/Add'
   *  Sum: '<S78>/Add1'
   *  Sum: '<S78>/Sum'
   */
  localDW->icLoad = false;

  /* Outputs for Enabled SubSystem: '<S47>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S78>/Enable'
   */
  localDW->MemoryX_DSTATE = (rtb_best_whl_spd - (0.0 * rtu_a_x +
    localDW->MemoryX_DSTATE)) * 0.732050807568877 + (0.008 * rtu_a_x +
    localDW->MemoryX_DSTATE);

  /* End of Outputs for SubSystem: '<S47>/MeasurementUpdate' */

  /* Update for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE = rty_est_veh_spd_0;
  return rty_est_veh_spd_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
