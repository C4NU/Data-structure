//
//  04.cpp
//  C++
//
//  Created by 전효재 on 19/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int recursiveFindMax(int size, int *array, int max)
{
    if(size == 0)
        return max;
    else
    {
        if(array[size] > max)
            max = array[size];
        return recursiveFindMax(size - 1, array, max);
    }
}

int main()
{
    int N;
    
    cin>>N;
    
    int *array = new int[N];
    
    for(int i=0; i<N; i++)
    {
        cin>>array[i];
    }
    
    cout<<recursiveFindMax(N-1, array, array[0])<<endl;
}
