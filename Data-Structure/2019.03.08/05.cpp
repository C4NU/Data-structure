//
//  05.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

typedef struct Time
{
    int hour;
    int minute;
    int second;
} _time;

int main()
{
    _time t1, t2, t3;
    
    scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
    
    scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);
    
    t3.second = t2.second - t1.second;
    
    if(t3.second < 0)
    {
        t3.second +=60;
        t3.minute -=1;
    }
    
    t3.minute += (t2.minute - t1.minute);
    
    if(t3.minute < 0)
    {
        t3.minute +=60;
        t3.hour -=1;
    }
    
    t3.hour += (t2.hour - t1.hour);
    
    printf("%d %d %d", t3.hour, t3.minute, t3.second);
}
