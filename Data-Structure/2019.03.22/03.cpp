//
//  03.cpp
//  C++
//
//  Created by 전효재 on 19/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

void recursivePrint(int n)
{
    if(n<10)
        cout<<n<<endl;
    else
    {
        cout<<n%10<<endl;
        recursivePrint(n/10);
    }
}

int main()
{
    int n;
    
    cin>>n;
    
    recursivePrint(n);
}
