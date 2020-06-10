//
//  04.cpp
//  C++
//
//  Created by 전효재 on 28/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width;
    int height;
    int cnt = 1;
    int posRev = 1;
    int row, columm;
    int a=-1, b=0;
    int array[100][100]={0,};
    scanf("%d %d", &height, &width);
    
    
    row = width;
    columm = height-1;
    
    while(1)
    {
        for(int i=0; i<row; i++)
        {
            a += posRev;
            array[b][a] = cnt++;
        }
        row -= 1;
        
        if(row < 0)
            break;
        for(int i=0; i<columm; i++)
        {
            b += posRev;
            array[b][a] = cnt++;
        }
        
        columm --;
        
        if(columm< 0)
            break;
        posRev *= -1;
    }
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
