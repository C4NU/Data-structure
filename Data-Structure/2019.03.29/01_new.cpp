//
//  01_new.cpp
//  C++
//
//  Created by 전효재 on 09/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int array[101]={0,};
    int order;
    int orderChange[101]={0,};
    int count = 0;
    int temp = 0;
    
    int start, end;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    scanf("%d", &order);
    for(int i=0; i<order; i++)
    {
        scanf("%d", &orderChange[i]);
    }
    
    while(count < order-1)
    {
        start = orderChange[count];
        end = orderChange[count+1];
        
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        
        count++;
    }
    
    for(int i=0; i<N; i++)
    {
        printf("%d ", array[i]);
    }
}

