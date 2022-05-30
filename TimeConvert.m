function timestamp = TimeConvert(origin_time_data)
    timeset = zeros(1,4);
    time_sec = zeros(1,3);
    timeset = string(regexp(deblank(char(origin_time_data)),':','split'));
    time_sec = regexp(deblank(timeset(3)),'\.','split');
    timeset(3:4) = time_sec(1:2);
    for k = 1:4
        timestamp(k) = str2num(timeset(k));
    end
end
