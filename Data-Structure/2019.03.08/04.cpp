//
//  04.cpp
//  C++
//
//  Created by 전효재 on 08/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char string[100]={0,};
    char stringTemp[100]={0,};
    char temp;
    
    scanf("%s", string);
    
    for(int i=0; i<strlen(string); i++)
    {
        printf("%s\n", string);
        
        for(int j=0; j<strlen(string); j++)
        {
            stringTemp[j] = string[j];
        }
        
        temp = string[0];
            
        for(int j=1; j<strlen(string); j++)
        {
            string[j-1] = stringTemp[j];
        }
        
        string[strlen(string)-1] = temp;
    }
}
