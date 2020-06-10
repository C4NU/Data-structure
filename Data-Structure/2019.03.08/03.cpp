//
//  03.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *A, int *B)
{
    int temp = 0;
    
    temp = *A;
    A = B;
    B = &temp;
}

int main()
{
    int N;
    int Array[50]={0,};
    int swapIndexA, swapIndexB;
    
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        cin>>Array[i];
    }
    
    cin>>swapIndexA>>swapIndexB;
    
    swap(Array[swapIndexA], Array[swapIndexB]);
    
    for(int i=0; i<N; i++)
    {
        cout<<Array[i]<<" ";
    }
}
