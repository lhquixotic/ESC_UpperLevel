function time = GetTime(now_time_stamp,beginning_time_stamp)
    msec = now_time_stamp(4) - beginning_time_stamp(4);
    sec = now_time_stamp(3) - beginning_time_stamp(3);
    min = now_time_stamp(2) - beginning_time_stamp(2);
    hour = now_time_stamp(1) - beginning_time_stamp(1);
    time = 0.001 * msec + sec + 60 * min + 3600 * hour;
end
