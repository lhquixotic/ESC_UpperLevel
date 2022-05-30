/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SlipRateCalFunc.c
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

#include "SlipRateCalFunc.h"

/* Include model header file for global data */
#include "ESCHighLevel.h"
#include "ESCHighLevel_private.h"

/* Output and update for atomic system: '<Root>/SlipRateCalFunc' */
void SlipRateCalFunc(const real_T rtu_wheel_speed[4], const real_T
                     rtu_wheel_speed_linear[4], real_T rty_slip_rate[4])
{
  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Subtract'
   */
  if (rtu_wheel_speed_linear[0] > 1.0) {
    rty_slip_rate[0] = 1.0 / rtu_wheel_speed_linear[0] *
      (rtu_wheel_speed_linear[0] - rtu_wheel_speed[0]);
  } else {
    rty_slip_rate[0] = 0.0;
  }

  if (rtu_wheel_speed_linear[1] > 1.0) {
    rty_slip_rate[1] = 1.0 / rtu_wheel_speed_linear[1] *
      (rtu_wheel_speed_linear[1] - rtu_wheel_speed[1]);
  } else {
    rty_slip_rate[1] = 0.0;
  }

  if (rtu_wheel_speed_linear[2] > 1.0) {
    rty_slip_rate[2] = 1.0 / rtu_wheel_speed_linear[2] *
      (rtu_wheel_speed_linear[2] - rtu_wheel_speed[2]);
  } else {
    rty_slip_rate[2] = 0.0;
  }

  if (rtu_wheel_speed_linear[3] > 1.0) {
    rty_slip_rate[3] = 1.0 / rtu_wheel_speed_linear[3] *
      (rtu_wheel_speed_linear[3] - rtu_wheel_speed[3]);
  } else {
    rty_slip_rate[3] = 0.0;
  }

  /* End of Switch: '<S4>/Switch' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
