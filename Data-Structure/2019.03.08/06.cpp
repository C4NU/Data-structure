//
//  06.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

typedef struct Student
{
    char name[9];
    int score;
} student;

int main()
{
    student st[5];
    int avg =0;
    
    for(int i=0; i<5; i++)
    {
        scanf("%s %d", &st[i].name, &st[i].score);
        
        avg += st[i].score;
    }
    
    avg /=5;
    
    for(int i=0; i<5; i++)
    {
        if(st[i].score <= avg)
            printf("%s\n", st[i].name);
    }
}
