//
//  03-2.cpp
//  C++
//
//  Created by 전효재 on 12/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int *prefixAverage1(int *array, int size)
{
    int *_array = new int[size];
    
    for(int i=0; i<size; i++)
    {
        int sum = 0;
        
        for(int j=0; j<=i; j++)
        {
            sum = sum + array[j];
        }
        _array[i] = round((float)sum / (i+1));
    }
    return _array;
}

int *prefixAverage2(int *array, int size)
{
    int *_array = new int[size];
    
    int sum = 0;
    
    for(int i=0; i<size; i++)
    {
        sum = sum + array[i];
        
        _array[i] = round((float)sum / (i+1));
    }
    
    return _array;
}

int main()
{
    srand((unsigned)int(time(NULL)));
    
    clock_t startTimeOne, startTimeTwo, endTimeOne, endTimeTwo;
    
    float result1, result2;
    
    int n;
    
    cin>>n;
    
    int *array = new int[n];
    
    int *arrayResult = new int[n];
    
    for(int i=0; i<n; i++)
    {
        array[i] = (int)rand();
    }

    startTimeOne = clock();
    
    arrayResult = prefixAverage1(array, n);
    
    endTimeOne = clock();
    
    result1 = (float)(endTimeOne - startTimeOne)/CLOCKS_PER_SEC;
    
    startTimeTwo = clock();
    
    arrayResult = prefixAverage2(array, n);
    
    endTimeTwo = clock();
    
    result2 = (float)(endTimeTwo - startTimeTwo)/CLOCKS_PER_SEC;
    
    cout<<result1<<"ms"<<endl<<result2<<"ms"<<endl;
    
    delete []array;
    delete []arrayResult;
}
