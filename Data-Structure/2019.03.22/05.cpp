//
//  05.cpp
//  C++
//
//  Created by 전효재 on 21/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

void RecursiveHanoi(int N, char a, char b, char c)
{
    if(N == 1)
        cout<<a<<" "<<c<<endl;
    else
    {
        RecursiveHanoi(N-1, a, c, b);
        cout<<a<<" "<<c<<endl;
        RecursiveHanoi(N-1, b, a ,c);
    }
}

int main()
{
    int N;
    
    cin>>N;
    
    RecursiveHanoi(N, 'A', 'B', 'C');
    
}
