//
//  01.cpp
//  C++
//
//  Created by 전효재 on 26/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int array[101] = { 0, };
    int revNum;
    int revArray[201] = { 0, };
    
    int checkCount = 0;
    int cnt = 0;
    int arraycnt = 0;
    
    int first, last;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &revNum);
    for (int i = 0; i < revNum * 2; i += 2)
    {
        scanf("%d %d", &revArray[i], &revArray[i + 1]);
    }
    
    while (checkCount < revNum)
    {
        first = revArray[cnt];
        last = revArray[cnt + 1];
        
        int* temp = (int*)malloc(sizeof(int*)*(last - first + 1));
        
        for (int i = first; i <= last; i++, arraycnt++)
        {
            temp[arraycnt] = array[i];
        }
        
        arraycnt = 0;
        
        for (int i = last; i >= first; i--, arraycnt++)
        {
            array[i] = temp[arraycnt];
        }
        
        checkCount += 1;
        
        cnt+=2;
        arraycnt = 0;
        
        free(temp);
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
}
