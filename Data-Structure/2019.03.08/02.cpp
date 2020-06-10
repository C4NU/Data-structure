//
//  02.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

void ABC(int *_array, int k)
{
    int temp = 0;
    
    for(int i=k; i<10; i++)
    {
        if(_array[i] > _array[k])
        {
            temp = _array[k];
            _array[k] = _array[i];
            _array[i] = temp;
        }
    }
}

int main()
{
    int Array[10]={0,};
    
    for(int i=0; i<10; i++)
    {
        cin>>Array[i];
    }
    
    for(int i=0; i<10; i++)
    {
        ABC(Array, i);
    }
    
    for(int i=0; i<10; i++)
    {
        cout<<Array[i]<<" ";
    }
}
