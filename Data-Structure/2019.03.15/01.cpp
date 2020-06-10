//
//  01.cpp
//  C++
//
//  Created by 전효재 on 11/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

int modulo(int a, int b)
{
    while(a >= b)
    {
        a -= b;
    }
    
    return a;
}

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d", modulo(a, b));
}
