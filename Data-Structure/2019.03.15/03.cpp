//
//  03.cpp
//  C++
//
//  Created by 전효재 on 12/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *prefixAverage1(int *array, int size)
{
    int *_array = (int*)malloc(sizeof(int)*size);
    
    for(int i=0; i<size; i++)
    {
        int sum = 0;
        
        for(int j=0; j<=i; j++)
        {
            sum = sum + array[j];
        }
//        _array[i] = round((float)sum / (i+1));
        
        _array[i] = (float)((float)sum / (i+1) + 0.5f);
    }
    return _array;
}

int *prefixAverage2(int *array, int size)
{
    int *_array = (int*)malloc(sizeof(int)*size);
    
    int sum = 0;
    
    for(int i=0; i<size; i++)
    {
        sum = sum + array[i];
        
        _array[i] = (float)((float)sum / (i+1) + 0.5f);
    }
    
    return _array;
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    int *array = (int*)malloc(sizeof(int)*n);
    
    int *arrayResult = (int*)malloc(sizeof(int)*n);
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    arrayResult = prefixAverage1(array, n);
    
    for(int i=0; i<n; i++)
    {
        printf("%d ", arrayResult[i]);
    }
    
    printf("\n");
    
    arrayResult = prefixAverage2(array, n);
    
    for(int i=0; i<n; i++)
    {
        printf("%d ", arrayResult[i]);
    }
    
    free(array);
    free(arrayResult);
}
