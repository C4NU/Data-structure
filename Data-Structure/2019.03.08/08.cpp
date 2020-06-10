//
//  08.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Student
{
    char name[7];
    int korean;
    int english;
    int math;
    
    float avg;
} student;

int main()
{
    int N;
    
    cin>>N;
    
    student *st = new student[N];
    
    for(int i=0; i<N; i++)
    {
        scanf("%s %d %d %d", st[i].name, &st[i].korean, &st[i].english, &st[i].math);
    }
    
    for(int i=0; i<N; i++)
    {
        st[i].avg = ((float)st[i].korean + (float)st[i].math + (float)st[i].english)/3;
    }
    
    for(int i=0; i<N; i++)
    {
        printf("%s %.1f ", st[i].name, st[i].avg);
        if(st[i].korean >= 90 || st[i].math >= 90 || st[i].english >= 90)
            printf("GREAT ");
        if(st[i].korean < 70 || st[i].math < 70 || st[i].english < 70)
            printf("BAD ");
        printf("\n");
    }
}
