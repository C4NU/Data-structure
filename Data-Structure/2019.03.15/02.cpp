//
//  02.cpp
//  C++
//
//  Created by 전효재 on 11/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

int mostOnes(int array[][100], int size)
{
    int i=0, j =0, row = 0;
    while((i<size)&&(j<size))
    {
        if(array[i][j] == 0)
        {
            i += 1;
        }
        else
        {
            row = i;
            j += 1;
        }
    }
    return row;
}

int main()
{
    int n;
    int nArray[100][100] = {0,};
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &nArray[i][j]);
        }
    }
    
    printf("%d", mostOnes(nArray, n));
}
