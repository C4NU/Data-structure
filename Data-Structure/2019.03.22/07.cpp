//
//  07.cpp
//  C++
//
//  Created by 전효재 on 21/03/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <string.h>

using namespace std;

int RecursiveFindLetter(char *input, int size,int index,  char letter, int count)
{
    if(index == size)
    {
        if(input[index] == letter)
            return count+1;
        else
            return count;
    }
    
    return RecursiveFindLetter(input, size, index+1, letter, count);
}

int main()
{
    char input[100]={0,};
    char findLetter;
    
    scanf("%s", input);
    scanf("%c", &findLetter);
    
    printf("%d", RecursiveFindLetter(input,(int)strlen(input), 0,findLetter, 0));
}
