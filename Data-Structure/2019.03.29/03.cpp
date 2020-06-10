//
//  03.cpp
//  C++
//
//  Created by 전효재 on 26/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//  34 안됨 50 안됨 100 안됨

#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int cnt = 1;
    
    scanf("%d", &N);
    
    int **array = (int**)malloc(sizeof(int)*N);
    
    for (int i = 0; i < N; i++)
    {
        array[i] = (int*)malloc(sizeof(int)*N);
    }
    
    
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0 || i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                array[i][j] = cnt;
                cnt++;
            }
        }
        else
        {
            for (int j = N - 1; j >= 0; j--)
            {
                array[i][j] = cnt;
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
