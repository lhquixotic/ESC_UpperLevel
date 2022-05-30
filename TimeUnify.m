function [Out] = TimeUnify(OriginalTime,OriginalData,TimeVector)
  %按新时间序列对原数据进行线性插值
  [Time,Index]=unique(OriginalTime);
  Out=interp1(Time,OriginalData(Index),TimeVector,'linear','extrap');
end

