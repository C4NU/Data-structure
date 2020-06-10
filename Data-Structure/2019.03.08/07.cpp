//
//  07.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int N;
    
    cin>>N;
    
    int *ArrayOne = new int[N];
    int *ArrayTwo = new int[N];
    int *ArrayResult = new int[N];
    
    for(int i=0; i<N; i++)
    {
        cin>>ArrayOne[i];
    }
    
    for(int i=0; i<N; i++)
    {
        cin>>ArrayTwo[i];
    }
    
    for(int i=0, j=N-1; i<N, j>=0; i++, j--)
    {
        ArrayResult[i] = ArrayTwo[j]+ArrayOne[i];
    }
    
    for(int i=0; i<N; i++)
    {
        cout<<ArrayResult[i]<<" ";
    }
    
    delete [] ArrayOne;
    delete [] ArrayTwo;
    delete [] ArrayResult;
}
