//
//  02.cpp
//  C++
//
//  Created by 전효재 on 09/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//  순서가 자리를 바꾸는게 아니고 하나씩 밀어내는거임

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int array[101] = { 0, };
    int order;
    int orderChange[101] = { 0, };
    int count = 0;
    int temp = 0;
    
    int start, end;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    scanf("%d", &order);
    for (int i = 0; i < order; i++)
    {
        scanf("%d", &orderChange[i]);
    }
    
    while (count < order - 1)
    {
        if (count == 0)
            start = orderChange[count];
        else
            array[start] = temp;
        end = orderChange[count + 1];
        
        temp = array[end];
        array[end] = array[start];
        
        count++;
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
}

