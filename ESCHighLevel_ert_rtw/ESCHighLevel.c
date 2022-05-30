/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ESCHighLevel.c
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

#include "ESCHighLevel.h"
#include "ESCHighLevel_private.h"

/* Named constants for Chart: '<S8>/State Machine' */
#define IN_Keep_Pressure               ((uint8_T)1U)
#define IN_Reduce_Pressure             ((uint8_T)2U)
#define IN_Set_Pressure                ((uint8_T)3U)

/*
 * System initialize for atomic system:
 *    '<S1>/SingleWheelStateMachine'
 *    '<S1>/SingleWheelStateMachine1'
 *    '<S1>/SingleWheelStateMachine2'
 *    '<S1>/SingleWheelStateMachine3'
 */
void SingleWheelStateMachine_Init(real_T *rty_wc_p_des, int32_T *rty_abs_state)
{
  /* SystemInitialize for Chart: '<S8>/State Machine' */
  *rty_wc_p_des = 0.0;
  *rty_abs_state = 0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/SingleWheelStateMachine'
 *    '<S1>/SingleWheelStateMachine1'
 *    '<S1>/SingleWheelStateMachine2'
 *    '<S1>/SingleWheelStateMachine3'
 */
void SingleWheelStateMachine(real_T rtu_set_p, real_T rtu_wc_p_cur, real_T rtu_u,
  real_T rtu_slip_rate, const real32_T rtu_abs_para[5], int32_T
  rtu_external_para, real_T *rty_wc_p_des, int32_T *rty_abs_state,
  DW_SingleWheelStateMachine *localDW)
{
  real_T k;
  real_T rtb_Switch_d5_idx_0;
  real_T rtb_Switch_d5_idx_1;
  real_T rtb_Switch_d5_idx_2;
  real_T rtb_Switch_d5_idx_4;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   */
  if (rtu_external_para > 0) {
    rtb_Switch_d5_idx_0 = rtu_abs_para[0];
    rtb_Switch_d5_idx_1 = rtu_abs_para[1];
    rtb_Switch_d5_idx_2 = rtu_abs_para[2];

    /* MATLAB Function: '<S8>/CalLockCriterion' */
    k = rtu_abs_para[3];
    rtb_Switch_d5_idx_4 = rtu_abs_para[4];
  } else {
    rtb_Switch_d5_idx_0 = 0.05;
    rtb_Switch_d5_idx_1 = 0.05;
    rtb_Switch_d5_idx_2 = 0.15;

    /* MATLAB Function: '<S8>/CalLockCriterion' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant2'
     */
    k = 0.006;
    rtb_Switch_d5_idx_4 = 0.006;
  }

  /* End of Switch: '<S8>/Switch' */

  /* MATLAB Function: '<S8>/CalLockCriterion' incorporates:
   *  Delay: '<S8>/Delay'
   *  Delay: '<S8>/Delay1'
   */
  if (localDW->Delay1_DSTATE == 2) {
    k = rtb_Switch_d5_idx_4;
  }

  k = (rtu_slip_rate - localDW->Delay_DSTATE[0]) - k;

  /* Chart: '<S8>/State Machine' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   */
  if (localDW->is_active_c20_ESCHighLevel == 0U) {
    localDW->is_active_c20_ESCHighLevel = 1U;
    localDW->is_c20_ESCHighLevel = IN_Set_Pressure;
    *rty_abs_state = 1;
    *rty_wc_p_des = rtu_set_p;
  } else {
    switch (localDW->is_c20_ESCHighLevel) {
     case IN_Keep_Pressure:
      if ((rtu_slip_rate >= rtb_Switch_d5_idx_2) && (k >= 0.0)) {
        localDW->is_c20_ESCHighLevel = IN_Reduce_Pressure;
        *rty_abs_state = 3;
        *rty_wc_p_des = 0.0;
      } else if (rtu_slip_rate < rtb_Switch_d5_idx_0) {
        localDW->is_c20_ESCHighLevel = IN_Set_Pressure;
        *rty_abs_state = 1;
        *rty_wc_p_des = rtu_set_p;
      } else {
        *rty_abs_state = 2;
        *rty_wc_p_des = rtu_wc_p_cur;
      }
      break;

     case IN_Reduce_Pressure:
      if (rtu_slip_rate < rtb_Switch_d5_idx_0) {
        localDW->is_c20_ESCHighLevel = IN_Set_Pressure;
        *rty_abs_state = 1;
        *rty_wc_p_des = rtu_set_p;
      } else {
        *rty_abs_state = 3;
        *rty_wc_p_des = 0.0;
      }
      break;

     default:
      /* case IN_Set_Pressure: */
      if ((rtu_slip_rate >= rtb_Switch_d5_idx_1) && (rtu_u >= 2.7777777777777777)
          && (k >= 0.0)) {
        localDW->is_c20_ESCHighLevel = IN_Keep_Pressure;
        *rty_abs_state = 2;
        *rty_wc_p_des = rtu_wc_p_cur;
      } else {
        *rty_abs_state = 1;
        *rty_wc_p_des = rtu_set_p;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/State Machine' */

  /* Update for Delay: '<S8>/Delay1' */
  localDW->Delay1_DSTATE = *rty_abs_state;

  /* Update for Delay: '<S8>/Delay' */
  localDW->Delay_DSTATE[0] = localDW->Delay_DSTATE[1];
  localDW->Delay_DSTATE[1] = localDW->Delay_DSTATE[2];
  localDW->Delay_DSTATE[2] = localDW->Delay_DSTATE[3];
  localDW->Delay_DSTATE[3] = rtu_slip_rate;
}

/* System initialize for atomic system: */
void MovingAverage1_Init(DW_MovingAverage1 *localDW)
{
  g_dsp_internal_SlidingWindowAve *iobj_0;

  /* Start for MATLABSystem: '<Root>/Moving Average1' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
  iobj_0 = localDW->obj.pStatistic;
  if (iobj_0->isInitialized == 1) {
    iobj_0->pCumSum = 0.0;
    iobj_0->pCumSumRev[0] = 0.0;
    iobj_0->pCumSumRev[1] = 0.0;
    iobj_0->pCumRevIndex = 1.0;
    iobj_0->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
}

/* Output and update for atomic system: */
void MovingAverage1(real_T rtu_0, DW_MovingAverage1 *localDW)
{
  g_dsp_internal_SlidingWindowAve *obj;
  real_T csumrev[2];
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;

  /* MATLABSystem: '<Root>/Moving Average1' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<Root>/Moving Average1' */
  localDW->MovingAverage1_p = 0.0;

  /* MATLABSystem: '<Root>/Moving Average1' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 2.0) {
    cumRevIndex = 2.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    csumrev[0] += csumrev[1];
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<Root>/Moving Average1' */
    localDW->MovingAverage1_p = z / 3.0;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

/* Model step function */
void ESCHighLevel_step(RT_MODEL *const rtM, real_T rtU_whlspd[4], real_T
  rtU_acc_x, real_T rtU_cur_mc_pressure, real_T rtU_cur_wc_pressure[4], real32_T
  rtU_abs_para[8], int32_T rtU_abs_use_external_para, real_T *rtY_est_veh_spd,
  int32_T rtY_abs_valve_state[4], real_T rtY_slip_rate[4], real_T
  rtY_delta_slip_rate[4])
{
  DW *rtDW = rtM->dwork;

  /* local block i/o variables */
  real_T rtb_Switch_o[4];
  real_T rtb_Gain5[4];
  real_T rtb_TmpSignalConversionAtSlipRa[4];
  real_T rtb_Switch1;
  real_T rtb_mc_pressure;
  int32_T rtb_abs_state;
  int32_T rtb_abs_state_e;
  int32_T rtb_abs_state_n;
  int32_T rtb_out_state;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_abs_is_on;

  /* Gain: '<Root>/Gain5' incorporates:
   *  Inport: '<Root>/whlspd'
   */
  rtb_Gain5[0] = 0.376 * rtU_whlspd[0];
  rtb_Gain5[1] = 0.376 * rtU_whlspd[1];
  rtb_Gain5[2] = 0.376 * rtU_whlspd[2];
  rtb_Gain5[3] = 0.376 * rtU_whlspd[3];

  /* SignalConversion generated from: '<Root>/SlipRateCalFunc' */
  rtb_TmpSignalConversionAtSlipRa[0] = rtb_Gain5[3];
  rtb_TmpSignalConversionAtSlipRa[1] = rtb_Gain5[0];
  rtb_TmpSignalConversionAtSlipRa[2] = rtb_Gain5[1];
  rtb_TmpSignalConversionAtSlipRa[3] = rtb_Gain5[2];

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/cur_mc_pressure'
   */
  if (rtU_cur_mc_pressure > 10.0) {
    rtb_mc_pressure = 10.0;
  } else if (rtU_cur_mc_pressure < -0.5) {
    rtb_mc_pressure = -0.5;
  } else {
    rtb_mc_pressure = rtU_cur_mc_pressure;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   */
  if (rtU_abs_use_external_para > 0) {
    rtb_Switch1 = rtU_abs_para[7];
  } else {
    rtb_Switch1 = 0.8;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* RelationalOperator: '<Root>/Relational Operator' */
  rtb_RelationalOperator = (rtb_mc_pressure > rtb_Switch1);

  /* Delay: '<Root>/Delay' */
  rtb_abs_is_on = rtDW->Delay_DSTATE;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   */
  if (rtU_abs_use_external_para > 0) {
    rtb_Switch1 = rtU_abs_para[5];
  } else {
    rtb_Switch1 = 40.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay2'
   */
  if (rtDW->Delay_DSTATE) {
    rtb_out_state = 1;
    if ((rtDW->counter < rtb_Switch1) && (rtDW->counter > 0.0)) {
      rtDW->counter++;
    } else {
      rtDW->counter = 0.0;
    }
  } else if (!rtDW->Delay2_DSTATE) {
    if ((rtDW->counter < rtb_Switch1) && (rtDW->counter > 0.0)) {
      rtb_out_state = 1;
      rtDW->counter++;
    } else {
      rtDW->counter = 0.0;
      rtb_out_state = 0;
    }
  } else {
    rtDW->counter = 1.0;
    rtb_out_state = 1;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outputs for Atomic SubSystem: '<Root>/VehSpdEstFunc' */
  /* Outport: '<Root>/est_veh_spd' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Boolean'
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   *  Inport: '<Root>/acc_x'
   */
  *rtY_est_veh_spd = VehSpdEstFunction(rtb_Gain5[3], rtb_Gain5[0], rtb_Gain5[1],
    rtb_Gain5[2], rtb_RelationalOperator, rtU_acc_x, rtb_out_state != 0,
    rtU_abs_use_external_para, rtU_abs_para[6], &rtDW->VehSpdEstFunc);

  /* End of Outputs for SubSystem: '<Root>/VehSpdEstFunc' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Outport: '<Root>/est_veh_spd'
   */
  rtb_Gain5[0] = *rtY_est_veh_spd;
  rtb_Gain5[1] = *rtY_est_veh_spd;
  rtb_Gain5[2] = *rtY_est_veh_spd;
  rtb_Gain5[3] = *rtY_est_veh_spd;

  /* Outputs for Atomic SubSystem: '<Root>/SlipRateCalFunc' */
  SlipRateCalFunc(rtb_TmpSignalConversionAtSlipRa, rtb_Gain5, rtb_Switch_o);

  /* End of Outputs for SubSystem: '<Root>/SlipRateCalFunc' */
  MovingAverage1(rtb_Switch_o[1], &rtDW->MovingAverage2);

  /* Outputs for Atomic SubSystem: '<S1>/SingleWheelStateMachine1' */
  /* Inport: '<Root>/cur_wc_pressure' incorporates:
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   *  Outport: '<Root>/est_veh_spd'
   */
  SingleWheelStateMachine(rtb_mc_pressure, rtU_cur_wc_pressure[0],
    *rtY_est_veh_spd, rtDW->MovingAverage2.MovingAverage1_p, &rtU_abs_para[0],
    rtU_abs_use_external_para, &rtb_Switch1, &rtb_abs_state_e,
    &rtDW->SingleWheelStateMachine1);

  /* End of Outputs for SubSystem: '<S1>/SingleWheelStateMachine1' */
  MovingAverage1(rtb_Switch_o[2], &rtDW->MovingAverage3);

  /* Outputs for Atomic SubSystem: '<S1>/SingleWheelStateMachine2' */
  /* Inport: '<Root>/cur_wc_pressure' incorporates:
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   *  Outport: '<Root>/est_veh_spd'
   */
  SingleWheelStateMachine(rtb_mc_pressure, rtU_cur_wc_pressure[1],
    *rtY_est_veh_spd, rtDW->MovingAverage3.MovingAverage1_p, &rtU_abs_para[0],
    rtU_abs_use_external_para, &rtb_Switch1, &rtb_abs_state_n,
    &rtDW->SingleWheelStateMachine2);

  /* End of Outputs for SubSystem: '<S1>/SingleWheelStateMachine2' */
  MovingAverage1(rtb_Switch_o[3], &rtDW->MovingAverage4);

  /* Outputs for Atomic SubSystem: '<S1>/SingleWheelStateMachine3' */
  /* Inport: '<Root>/cur_wc_pressure' incorporates:
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   *  Outport: '<Root>/est_veh_spd'
   */
  SingleWheelStateMachine(rtb_mc_pressure, rtU_cur_wc_pressure[2],
    *rtY_est_veh_spd, rtDW->MovingAverage4.MovingAverage1_p, &rtU_abs_para[0],
    rtU_abs_use_external_para, &rtb_Switch1, &rtb_abs_state,
    &rtDW->SingleWheelStateMachine3);

  /* End of Outputs for SubSystem: '<S1>/SingleWheelStateMachine3' */
  MovingAverage1(rtb_Switch_o[0], &rtDW->MovingAverage1_p);

  /* Outputs for Atomic SubSystem: '<S1>/SingleWheelStateMachine' */
  /* Inport: '<Root>/cur_wc_pressure' incorporates:
   *  Inport: '<Root>/abs_para'
   *  Inport: '<Root>/abs_use_external_para'
   *  Outport: '<Root>/est_veh_spd'
   */
  SingleWheelStateMachine(rtb_mc_pressure, rtU_cur_wc_pressure[3],
    *rtY_est_veh_spd, rtDW->MovingAverage1_p.MovingAverage1_p, &rtU_abs_para[0],
    rtU_abs_use_external_para, &rtb_Switch1, &rtb_out_state,
    &rtDW->SingleWheelStateMachine_d);

  /* End of Outputs for SubSystem: '<S1>/SingleWheelStateMachine' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S1>/Constant12'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add2'
   *  Sum: '<S1>/Add3'
   */
  if (rtb_RelationalOperator) {
    rtb_abs_state_e = 2 - rtb_abs_state_e;
    rtb_abs_state_n = 2 - rtb_abs_state_n;
    rtb_abs_state = 2 - rtb_abs_state;
    rtb_out_state = 2 - rtb_out_state;
  } else {
    rtb_abs_state_e = 1;
    rtb_abs_state_n = 1;
    rtb_abs_state = 1;
    rtb_out_state = 1;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Outport: '<Root>/abs_valve_state' */
  rtY_abs_valve_state[0] = rtb_abs_state_e;
  rtY_abs_valve_state[1] = rtb_abs_state_n;
  rtY_abs_valve_state[2] = rtb_abs_state;
  rtY_abs_valve_state[3] = rtb_out_state;

  /* MATLAB Function: '<Root>/CalMaxValveState1' */
  rtb_mc_pressure = 0.0;

  /* Outport: '<Root>/delta_slip_rate' incorporates:
   *  Delay: '<Root>/Delay1'
   *  SignalConversion generated from: '<Root>/Delay1'
   *  Sum: '<Root>/Add1'
   */
  rtY_delta_slip_rate[0] = rtDW->MovingAverage1_p.MovingAverage1_p -
    rtDW->Delay1_DSTATE[0];

  /* MATLAB Function: '<Root>/CalMaxValveState1' */
  if (rtb_abs_state_e < 0.5) {
    rtb_mc_pressure = 1.0;
  }

  /* Outport: '<Root>/delta_slip_rate' incorporates:
   *  Delay: '<Root>/Delay1'
   *  SignalConversion generated from: '<Root>/Delay1'
   *  Sum: '<Root>/Add1'
   */
  rtY_delta_slip_rate[1] = rtDW->MovingAverage2.MovingAverage1_p -
    rtDW->Delay1_DSTATE[1];

  /* MATLAB Function: '<Root>/CalMaxValveState1' */
  if (rtb_abs_state_n < 0.5) {
    rtb_mc_pressure = 1.0;
  }

  /* Outport: '<Root>/delta_slip_rate' incorporates:
   *  Delay: '<Root>/Delay1'
   *  SignalConversion generated from: '<Root>/Delay1'
   *  Sum: '<Root>/Add1'
   */
  rtY_delta_slip_rate[2] = rtDW->MovingAverage3.MovingAverage1_p -
    rtDW->Delay1_DSTATE[2];

  /* MATLAB Function: '<Root>/CalMaxValveState1' */
  if (rtb_abs_state < 0.5) {
    rtb_mc_pressure = 1.0;
  }

  /* Outport: '<Root>/delta_slip_rate' incorporates:
   *  Delay: '<Root>/Delay1'
   *  SignalConversion generated from: '<Root>/Delay1'
   *  Sum: '<Root>/Add1'
   */
  rtY_delta_slip_rate[3] = rtDW->MovingAverage4.MovingAverage1_p -
    rtDW->Delay1_DSTATE[3];

  /* MATLAB Function: '<Root>/CalMaxValveState1' */
  if (rtb_out_state < 0.5) {
    rtb_mc_pressure = 1.0;
  }

  /* Outport: '<Root>/slip_rate' */
  rtY_slip_rate[0] = rtDW->MovingAverage2.MovingAverage1_p;
  rtY_slip_rate[1] = rtDW->MovingAverage3.MovingAverage1_p;
  rtY_slip_rate[2] = rtDW->MovingAverage4.MovingAverage1_p;
  rtY_slip_rate[3] = rtDW->MovingAverage1_p.MovingAverage1_p;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Switch: '<Root>/Switch'
   */
  rtDW->Delay_DSTATE = (rtb_mc_pressure > 0.0);

  /* Update for Delay: '<Root>/Delay2' */
  rtDW->Delay2_DSTATE = rtb_abs_is_on;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  SignalConversion generated from: '<Root>/Delay1'
   */
  for (rtb_abs_state_e = 0; rtb_abs_state_e < 3; rtb_abs_state_e++) {
    rtb_out_state = (rtb_abs_state_e + 1) << 2;
    rtb_abs_state = rtb_abs_state_e << 2;
    rtDW->Delay1_DSTATE[rtb_abs_state] = rtDW->Delay1_DSTATE[rtb_out_state];
    rtDW->Delay1_DSTATE[rtb_abs_state + 1] = rtDW->Delay1_DSTATE[rtb_out_state +
      1];
    rtDW->Delay1_DSTATE[rtb_abs_state + 2] = rtDW->Delay1_DSTATE[rtb_out_state +
      2];
    rtDW->Delay1_DSTATE[rtb_abs_state + 3] = rtDW->Delay1_DSTATE[rtb_out_state +
      3];
  }

  rtDW->Delay1_DSTATE[12] = rtDW->MovingAverage1_p.MovingAverage1_p;
  rtDW->Delay1_DSTATE[13] = rtDW->MovingAverage2.MovingAverage1_p;
  rtDW->Delay1_DSTATE[14] = rtDW->MovingAverage3.MovingAverage1_p;
  rtDW->Delay1_DSTATE[15] = rtDW->MovingAverage4.MovingAverage1_p;

  /* End of Update for Delay: '<Root>/Delay1' */
}

/* Model initialize function */
void ESCHighLevel_initialize(RT_MODEL *const rtM)
{
  DW *rtDW = rtM->dwork;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T rtb_wc_p_des_g;
    int32_T rtb_abs_state;

    /* SystemInitialize for Atomic SubSystem: '<Root>/VehSpdEstFunc' */
    VehSpdEstFunction_Init(&rtDW->VehSpdEstFunc);

    /* End of SystemInitialize for SubSystem: '<Root>/VehSpdEstFunc' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/SingleWheelStateMachine1' */
    SingleWheelStateMachine_Init(&rtb_wc_p_des_g, &rtb_abs_state);

    /* End of SystemInitialize for SubSystem: '<S1>/SingleWheelStateMachine1' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/SingleWheelStateMachine2' */
    SingleWheelStateMachine_Init(&rtb_wc_p_des_g, &rtb_abs_state);

    /* End of SystemInitialize for SubSystem: '<S1>/SingleWheelStateMachine2' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/SingleWheelStateMachine3' */
    SingleWheelStateMachine_Init(&rtb_wc_p_des_g, &rtb_abs_state);

    /* End of SystemInitialize for SubSystem: '<S1>/SingleWheelStateMachine3' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/SingleWheelStateMachine' */
    SingleWheelStateMachine_Init(&rtb_wc_p_des_g, &rtb_abs_state);

    /* End of SystemInitialize for SubSystem: '<S1>/SingleWheelStateMachine' */
    MovingAverage1_Init(&rtDW->MovingAverage2);
    MovingAverage1_Init(&rtDW->MovingAverage3);
    MovingAverage1_Init(&rtDW->MovingAverage4);
    MovingAverage1_Init(&rtDW->MovingAverage1_p);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
