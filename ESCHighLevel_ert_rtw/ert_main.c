/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "ESCHighLevel.h"              /* Model's header file */

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_; /* Real-time model */
static DW rtDW;                        /* Observable states */

/* '<Root>/whlspd' */
static real_T rtU_whlspd[4];

/* '<Root>/acc_x' */
static real_T rtU_acc_x;

/* '<Root>/cur_mc_pressure' */
static real_T rtU_cur_mc_pressure;

/* '<Root>/cur_wc_pressure' */
static real_T rtU_cur_wc_pressure[4];

/* '<Root>/abs_para' */
static real32_T rtU_abs_para[8];

/* '<Root>/abs_use_external_para' */
static int32_T rtU_abs_use_external_para;

/* '<Root>/steer_wheel_angle' */
static real_T rtU_steering_wheel_angle_origin;

/* '<Root>/est_veh_spd' */
static real_T rtY_est_veh_spd;

/* '<Root>/des_wc_pressure' */
static int32_T rtY_des_wc_pressure[4];

/* '<Root>/abs_valve_state' */
static int32_T rtY_abs_valve_state[4];

/* '<Root>/valve_control_mode' */
static int32_T rtY_valve_control_mode[4];

/* '<Root>/slip_rate' */
static real_T rtY_slip_rate[4];

/* '<Root>/delta_slip_rate' */
static real_T rtY_delta_slip_rate[4];

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  ESCHighLevel_step(rtM, rtU_whlspd, rtU_acc_x, rtU_cur_mc_pressure,
                    rtU_cur_wc_pressure, rtU_abs_para, rtU_abs_use_external_para,
                    &rtY_est_veh_spd, rtY_abs_valve_state, rtY_slip_rate,
                    rtY_delta_slip_rate);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  rtM->dwork = &rtDW;

  /* Initialize model */
  ESCHighLevel_initialize(rtM);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.008 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(rtM);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(rtM) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Disable rt_OneStep here */
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
