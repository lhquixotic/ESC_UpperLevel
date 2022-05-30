%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%功能：读取CANpro保存的数据(.csv)并进行解析和曲线绘制
%使用方法：更改file_dir的路径，该路径下存放canpro记录的论文，运行程序即可绘
%图。Index为0表示不绘制该数据，为1表示绘制。
%添加数据步骤：添加ID->初始化index->初始化数组->报文解析->绘图
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 设置
clear;
Xacc_offset = -0.103;  %纵向加速度偏置
Yacc_offset = 0.35;  %横向加速度偏置
YawRate_offset = 5.675e-5;  %横摆角速度偏置
%% 数据处理
%导入数据，逗号分隔
file_location =  'data\0529\test17_steer.csv';
files = dir(file_location);
filenames = {files(:).name}
files_num = size(filenames,2);
len_row_total = 0;
disp('Data Loading ...');
for i = 1:files_num
    fid = fopen( 'data\0529\test17_steer.csv');
    data_pre{i} = textscan(fid,'%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s', 'delimiter', ',');
    
    for j = 2:size(data_pre{i}{1,1},1)
        mid = cell2mat(data_pre{i}{1,11}(j));
        data{i}{1,3}(j) = {mid(2:end-1)};
    end
    data{i}{1,4} = data_pre{i}{1,14};
    data{i}{1,8} = data_pre{i}{1,21};
    len_row_total = len_row_total + size(data_pre{i}{1,1},1);
    fclose(fid);
end

frame_num = len_row_total - files_num;

% ID，首位为0会被省略
ID_acc = "0x322";  %华测RTK加速度
ID_yaw = "0x321";  %华测RTK横摆角速度
ID_imu = "0x2f9";  %博世IMU
ID_vel = "0x327";  %华测RTK绝对速度
ID_wlspd = "0x6";  %轮速
ID_wlraw = "0x5";  %轮速原始电压
ID_return = "0x3";  %滤波压力报文
ID_slip = "0x7";  %滑移率
ID_slipdelta = "0x8";  %滑移率变化率
ID_estvel = "0x4";  %估计车速
ID_steer = "0xc4";  %方向盘转角
ID_exptorque = "0xcff1401";  %驾驶员期望转矩

ID_test = "0x9";  %测试帧

%初始化Index
index1 = 1;
index2 = 1;
index3 = 1;
index4 = 1;
index5 = 1;
index6 = 1;
index7 = 1;
index8 = 1;
index9 = 1;
index10 = 1;
index11 = 1;
index12 = 1;
index13 = 1;
index14 = 1;

StartTime = TimeConvert(data{1}{1,3}(2));

disp('Data Processing ...')
for i = 1:files_num
    len_row = size(data{i}{1,8},1);
    len_col = size(strsplit(cell2mat(data{i}{1,8}(3))),2);
    for j = 2:len_row
        CAN_ID = char(data{i}{1,4}(j));
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        
        if(strcmp(CAN_ID,ID_acc))
            t1(index1,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            temp = CANmsg(1)*4096 + CANmsg(2)*16 + bitand(CANmsg(3),hex2dec('F0'))/16;
            if(CANmsg(1)>=128)
                Yacc_data_zhenzhi(index1,1) = (temp-1048576)/10000*9.8;
            else
                Yacc_data_zhenzhi(index1,1) = temp/10000*9.8;
            end
            temp = bitand(CANmsg(3),hex2dec('0F'))*4096*16 + CANmsg(4)*256 + CANmsg(5);
            if(bitand(CANmsg(3),hex2dec('0F'))>=8)
                Xacc_data_zhenzhi(index1,1) = (temp-1048576)/10000*9.8;
            else
                Xacc_data_zhenzhi(index1,1) = temp/10000*9.8;
            end
            index1 = index1 + 1;
        end
        
        if(strcmp(CAN_ID,ID_yaw))
            t2(index2,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            temp = CANmsg(6)*4096 + CANmsg(7)*16 + bitand(CANmsg(8),hex2dec('F0'))/16;
            if(CANmsg(6)>=128)
                YawRate_data_zhenzhi(index2,1) = (temp-1048576)/10000*(pi/180);
            else
                YawRate_data_zhenzhi(index2,1) = temp/10000*(pi/180);
            end
            index2 = index2 + 1;
        end
        
        if(strcmp(CAN_ID,ID_imu))
            t3(index3,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            
            temp = bitand(CANmsg(3),hex2dec('0F'))*256 + CANmsg(4);
            Xacc_data(index3,1) = (temp - 2048)/475*9.8;
            
            temp = CANmsg(5)*16 + bitand(CANmsg(6),hex2dec('F0'))/16;
            Yacc_data(index3,1) = -(temp - 2048)/475*9.8;
            
            temp = bitand(CANmsg(6),hex2dec('0F'))*256 + CANmsg(7);
            YawRate_data(index3,1) = (temp - 2048)/1230*(pi/180);
            
            index3 = index3 + 1;
        end
        
        if(strcmp(CAN_ID,ID_vel))
            t4(index4,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            temp = CANmsg(7)*256 +CANmsg(8);
            if(CANmsg(7)>=128)
                speed_data_zhenzhi(index4,1) = (temp-65536)/100;
            else
                speed_data_zhenzhi(index4,1) = temp/100;
            end
            index4 = index4 + 1;
        end
        
        if(strcmp(CAN_ID,ID_wlspd))
            t5(index5,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            wheel_speed_data(index5,1) = (256*CANmsg(1) + CANmsg(2))/65535*80;  %轮1：右前，单位rad/s
            wheel_speed_data(index5,2) = (256*CANmsg(3) + CANmsg(4))/65535*80;  %轮2：左右，单位rad/s
            wheel_speed_data(index5,3) = (256*CANmsg(5) + CANmsg(6))/65535*80;  %轮3：右后，单位rad/s
            wheel_speed_data(index5,4) = (256*CANmsg(7) + CANmsg(8))/65535*80;  %轮4：左前，单位rad/s
            index5 = index5 + 1;
        end
        
        if(strcmp(CAN_ID,ID_wlraw))
            t6(index6,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %第1列：时间戳
            wheel_speed_raw(index6,1) = ( CANmsg(2))/256*5;  %轮1：右前，单位V
            wheel_speed_raw(index6,2) = ( CANmsg(4))/256*5;  %轮2：左右，单位V
            wheel_speed_raw(index6,3) = ( CANmsg(6))/256*5;  %轮3：右后，单位V
            wheel_speed_raw(index6,4) = ( CANmsg(8))/256*5;  %轮4：左前，单位V
            index6= index6 + 1;
        end
        
      if (strcmp(CAN_ID,ID_return))  %返回压力滤波报文
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t7(index7,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        pPost_data(index7,1) = (CANmsg(1)/51 - 0.5)*5; %第1列：主缸滤波压力
        pPost_data(index7,2) = (CANmsg(2)/51 - 0.5)*5; %第2列：轮缸1滤波压力
        pPost_data(index7,3) = (CANmsg(3)/51 - 0.5)*5; %第3列：轮缸2滤波压力
        pPost_data(index7,4) = (CANmsg(4)/51 - 0.5)*5; %第4列：轮缸3滤波压力
        pPost_data(index7,5) = (CANmsg(5)/51 - 0.5)*5; %第5列：轮缸4滤波压力
        
        state_data(index7,1) = bitget(CANmsg(6),2)*2 + bitget(CANmsg(6),1) - 1;  %第1列：主管路1控制状态
        state_data(index7,2) = bitget(CANmsg(6),4)*2 + bitget(CANmsg(6),3) - 1;  %第2列：主管路2控制状态        
        state_data(index7,3) = bitget(CANmsg(7),2)*2 + bitget(CANmsg(7),1) - 1;  %第3列：轮缸1状态
        state_data(index7,4) = bitget(CANmsg(7),4)*2 + bitget(CANmsg(7),3) - 1;  %第4列：轮缸2状态
        state_data(index7,5) = bitget(CANmsg(7),6)*2 + bitget(CANmsg(7),5) - 1;  %第5列：轮缸3状态   
        state_data(index7,6) = bitget(CANmsg(7),8)*2 + bitget(CANmsg(7),7) - 1;  %第6列：轮缸4状态   
        index7 = index7 + 1;
      end
      if (strcmp(CAN_ID,ID_slip))  %滑移率
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t8(index8,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        slip_data(index8,1) = (256*CANmsg(1) + CANmsg(2))/65535*2 - 1;
        slip_data(index8,2) = (256*CANmsg(3) + CANmsg(4))/65535*2 - 1;
        slip_data(index8,3) = (256*CANmsg(5) + CANmsg(6))/65535*2 - 1;
        slip_data(index8,4) = (256*CANmsg(7) + CANmsg(8))/65535*2 - 1;
        index8 = index8 + 1;
      end
      if (strcmp(CAN_ID,ID_slipdelta))  %滑移率差分
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t9(index9,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        slipdelta_data(index9,1) = (256*CANmsg(1) + CANmsg(2))/65535*4 - 2;
        slipdelta_data(index9,2) = (256*CANmsg(3) + CANmsg(4))/65535*4 - 2;
        slipdelta_data(index9,3) = (256*CANmsg(5) + CANmsg(6))/65535*4 - 2;
        slipdelta_data(index9,4) = (256*CANmsg(7) + CANmsg(8))/65535*4 - 2;
        index9 = index9 + 1;
      end     
      if (strcmp(CAN_ID,ID_estvel))  %估计车速
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t10(index10,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        estvel_data(index10,1) = (256*CANmsg(6) + CANmsg(7))/65535*60 - 30;
        index10 = index10 + 1;       
      end
      if (strcmp(CAN_ID,ID_steer))  %方向盘转角
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t11(index11,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        steer_data(index11,1) = ((256*CANmsg(1) + CANmsg(2))-32768)/917.34;  %rad，左正右负
        index11 = index11 + 1;       
      end
      if (strcmp(CAN_ID,ID_exptorque))  %驾驶员期望扭矩
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t12(index12,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        exptorque_data(index12,1) = (256*CANmsg(6) + CANmsg(5))*0.25 - 5000;  %期望转矩
        index12 = index12 + 1;       
      end
          
      if (strcmp(CAN_ID,ID_test))  %测试报文
        CANmsg = hex2dec(strsplit(cell2mat(data{i}{1,8}(j))))';
        t14(index14,1) = GetTime(TimeConvert(data{i}{1,3}(j)),StartTime);  %时间戳
        test_data(index14,1) = (256*CANmsg(1) + CANmsg(2))/65535*20 - 10;
        index14 = index14 + 1;
      end
      
    end
end

%% 加偏置
Xacc_data(:,1) = Xacc_data(:,1) + Xacc_offset;
Yacc_data(:,1) = Yacc_data(:,1) + Yacc_offset;
YawRate_data(:,1) = YawRate_data(:,1) + YawRate_offset;

%% 曲线绘制
disp("Start Plotting...");

figure(1); hold on;
plot(t1(:,1),Xacc_data_zhenzhi(:,1));
plot(t3(:,1),Xacc_data(:,1));
title('Xacc'); xlabel('时间/s'); ylabel('Xacc/m/s2');
legend('华测RTK','博世IMU');

figure(2); hold on;
plot(t1(:,1),Yacc_data_zhenzhi(:,1));
plot(t3(:,1),Yacc_data(:,1));
title('Yacc'); xlabel('时间/s'); ylabel('Yacc/m/s2');
legend('华测RTK','博世IMU');

figure(3); hold on;
plot(t2(:,1),YawRate_data_zhenzhi(:,1));
plot(t3(:,1),YawRate_data(:,1));
title('YawRate'); xlabel('时间/s'); ylabel('YawRate/rad/s');
legend('华测RTK','博世IMU');

figure(4); hold on;
plot(t4(:,1),speed_data_zhenzhi(:,1));  %车速真值
plot(t10(:,1),estvel_data(:,1));  %车速估计
plot(t5(:,1),wheel_speed_data(:,1)*0.37,t5(:,1),wheel_speed_data(:,2)*0.37,t5(:,1),wheel_speed_data(:,3)*0.37,t5(:,1),wheel_speed_data(:,4)*0.37);
title('Speed'); xlabel('时间/s'); ylabel('Speed/m/s');
legend('车速真值','车速估计','轮速右前1','轮速左后2','轮速右后3','轮速左前4');

figure(5); hold on;
plot(t5(:,1),wheel_speed_data(:,1),t5(:,1),wheel_speed_data(:,2),t5(:,1),wheel_speed_data(:,3),t5(:,1),wheel_speed_data(:,4));
title('WheelSpeed'); xlabel('时间/s'); ylabel('rad/s');
legend('轮速右前1','轮速左后2','轮速右后3','轮速左前4');

figure(6); hold on;
plot(t6(:,1),wheel_speed_raw(:,1),t6(:,1),wheel_speed_raw(:,2),t6(:,1),wheel_speed_raw(:,3),t6(:,1),wheel_speed_raw(:,4));
title('WheelSpeedRaw'); xlabel('时间/s'); ylabel('Voltage/V');
legend('电压右前1','电压左后2','电压右后3','电压左前4');

figure(7); hold on;
plot(t7(:,1),pPost_data(:,1),t7(:,1),pPost_data(:,2),t7(:,1),pPost_data(:,3),t7(:,1),pPost_data(:,4),t7(:,1),pPost_data(:,5));
title('主缸与轮缸滤波压力-时间曲线'); xlabel('时间/s'); ylabel('压力/Mpa');
axis([-inf,inf,-5,25]);
legend('主缸','轮缸1','轮缸2','轮缸3','轮缸4');

figure(8); hold on;
plot(t7(:,1),state_data(:,1),t7(:,1),state_data(:,2),t7(:,1),state_data(:,3),t7(:,1),state_data(:,4),t7(:,1),state_data(:,5),t7(:,1),state_data(:,6));
title('主管路与轮缸控制状态'); xlabel('时间/s'); ylabel('压力/Mpa');
axis([-inf,inf,-1.5,1.5]);
legend('主管路1','主管路2','轮缸1','轮缸2','轮缸3','轮缸4');

figure(9); hold on;
plot(t8(:,1),slip_data(:,1),t8(:,1),slip_data(:,2),t8(:,1),slip_data(:,3),t8(:,1),slip_data(:,4));
title('车轮滑移率'); xlabel('时间/s'); ylabel('滑移率');
legend('右前1','左后2','右后3','左前4');

figure(10); hold on;
plot(t9(:,1),slipdelta_data(:,1),t9(:,1),slipdelta_data(:,2),t9(:,1),slipdelta_data(:,3),t9(:,1),slipdelta_data(:,4));
title('车轮滑移率差分'); xlabel('时间/s'); ylabel('滑移率差分');
legend('右前1','左后2','右后3','左前4');

figure(11); hold on;
plot(t11(:,1),steer_data(:,1)*180/pi);
title('方向盘转向角'); xlabel('时间/s'); ylabel('deg');
legend('方向盘转角左正右负');

figure(12); hold on;
plot(t12(:,1),exptorque_data(:,1));
title('驾驶员期望转矩'); xlabel('时间/s'); ylabel('转矩/Nm');
legend('驾驶员期望转矩');

disp("Done ...")


%% Parameters Analysis
abs_para = [0.05,0.05,0.15,0.006,0.006];
figure(9)
plot([0:1:20],abs_para(1)*ones(1,21),'r--')
plot([0:1:20],abs_para(3)*ones(1,21),'k--')
figure(10)
plot([0:1:20],abs_para(4)*ones(1,21),'r--')
% plot([0:1:20],abs_para(5)*ones(1,21),'k--')
%% 导入simulink
wh_fl = [t5(:,1),wheel_speed_data(:,4)];
wh_fr = [t5(:,1),wheel_speed_data(:,1)];
wh_rl = [t5(:,1),wheel_speed_data(:,2)];
wh_rr = [t5(:,1),wheel_speed_data(:,3)];
wh_spd = [t5(:,1),wheel_speed_data(:,1),wheel_speed_data(:,2),wheel_speed_data(:,3),wheel_speed_data(:,4)];
true_acc_x = [t1(:,1),Xacc_data_zhenzhi(:,1)];
imu_acc_x = [t3(:,1),Xacc_data(:,1)];
true_spd = [t4(:,1),speed_data_zhenzhi(:,1)];
mc_pressure = [t7(:,1),pPost_data(:,1)];
wc_pressure = [t7(:,1),pPost_data(:,2),pPost_data(:,3),pPost_data(:,4),pPost_data(:,5)];
act_est_spd = [t10(:,1),estvel_data(:,1)];
act_slip_rate = [t8(:,1),slip_data(:,1),slip_data(:,2),slip_data(:,3),slip_data(:,4)];
act_control_state = [t7(:,1),state_data(:,1),state_data(:,2),state_data(:,3),state_data(:,4),state_data(:,5),state_data(:,6)];
act_slip_rate_dot = [t9(:,1),slipdelta_data(:,1),slipdelta_data(:,2),slipdelta_data(:,3),slipdelta_data(:,4)];
act_steer_wheel_angle = [t11(:,1),steer_data(:,1)];