m=4617;%m汽车质量
L=4.39 ;  %L前后轴距
a=2.667 ; %a前轴到质心距离
b=4.39-2.667;  %b后轴到质心距离
% k1=-124000*2 ; %k1、k2前轮后轮侧偏刚度
% k2=-124000*2 ; 
k1=-180000;
k2=-275000;
Bf=1.918 ;%Bf、Br前后轮距
Br=1.958 ;
r=0.37 ; %R轮胎半径
Iz=3581.8; %Iz汽车转动惯量
mu=0.7;
beta0=0.01;
beta1=0.05;

%系统控制频率
Ts=0.004;

%% Vehicle Paras
VehParaR = 0.376;    % [m]
VehParaHg = 0.895;
VehParaL = 4.39;
VehPara_b = 4.39-2.667;
VehParaD = 1.958;


%% ABS
AbsLockJudgeThre = 0.006;
AbsLockSlipThre1 = 0.05;
AbsLockSlipThre2 = 0.15;
AbsDelayFuncT = 0.2;
AbsCriDelay = 4;
AbsActSpdThre = 10/3.6;
AbsBrkChkThre = 0.8;
AbsSpdEstRelayT = 40;

%% Steer Para
FrontAngleDeadZone = 0.5*3.14/180;


%TCS启停条件
    slide1=0.05;
    slide2=0.15;
    

%理想车辆模型延时参数
    T0=0.05;
    ks=0.01;
    kv=-0.001;
    ku=-0.001;
    
    omega=10;
    zeta=1;
    ay1=0.7*mu*9.8;
    ay2=0.7*mu*9.8;
%车辆模型判据
    %判据1
    C=0.05;
    %不足与过多判定
    dw=0.005;

% 理想横摆力矩计算
    %非线性权重计算
    e1=0.1; e2=0.2; k_eta=0.8;
    %横摆力矩PI系数
    %kp1=20000;ki1=100;
    kp1=25000;ki1=100;
    kp2=35000;ki2=200;
%理想车速修正系数
    c1=5;
    c2=1;
%AYC电机降扭PID
    kp3=300;
    ki3=50;
