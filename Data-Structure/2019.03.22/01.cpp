
//
//  01.cpp
//  C++
//
//  Created by 전효재 on 19/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int recursiveSum(int n)
{
    if(n == 1)
        return 1;
    else
        return n + recursiveSum(n-1);
}

int main()
{
    int n;
    
    cin>>n;
    
    cout<<recursiveSum(n)<<endl;
}
