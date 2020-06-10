//
//  06.cpp
//  C++
//
//  Created by 전효재 on 19/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int RecursiveGCD(int a, int b)
{
    if(a == 0)
        return b;
    else if( b == 0)
        return a;
    else
        return RecursiveGCD(b, a%b);
}

int main()
{
    int a, b;
    
    cin>>a>>b;
    
    cout<<RecursiveGCD(a, b)<<endl;
}
