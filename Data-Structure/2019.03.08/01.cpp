//
//  01.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int sum(int n)
{
    int result = 0;
    
    for(int i=1; i<=n; i++)
    {
        result += i;
    }
    
    return result;
}

int main()
{
    int n;
    int resultSum = 0;
    
    cin>>n;
    
    for(int i =1; i<=n; i++)
    {
        resultSum += sum(i);
    }
    
    cout<<resultSum;
}
