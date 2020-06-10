
//
//  Stack_02_01.c
//  C++
//
//  Created by 전효재 on 03/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int IsEmpty(int top)
{
    if(top == -1)
        return TRUE;
    else
        return FALSE;
}

int IsFull(int top, int stackSize)
{
    if(top == stackSize - 1)
        return TRUE;
    else
        return FALSE;
}

char Pop(char stack[], int *top)
{
    *top = *top - 1;
    return stack[*top+1];
}

void Push(char stack[], char element, int *top)
{
    *top = *top + 1;
    stack[*top] = element;
}

int CheckMatching(char *input, int *count)
{
    int result = TRUE;
    int length = strlen(input);
    
    char *stack = (char*)malloc(sizeof(char)*length);
    int top = -1;
    
    char ch, openCh;
    
    for(int i=0; i<length; i++)
    {
        ch = input[i];
        
        switch(ch)
        {
            case '(':
            case '[':
            case '{':
                Push(stack, ch, &top);
                *count = *count + 1;
                break;
            case ')':
            case ']':
            case '}': //}}}}}}}}
                *count = *count + 1;
                if(IsEmpty(top) == TRUE)
                {
                    result = FALSE;
                    break;
                }
                openCh = Pop(stack, &top);
                
                if((openCh == '(' && ch != ')') || (openCh == '[' && ch != ']') ||
                   (openCh == '{' && ch != '}'))
                {
                    result = FALSE;
                }
                break;
                
        }
    }
    if(IsEmpty(top) == FALSE)
        result = FALSE;
    
    return result;
}

int main()
{
    int count = 0;
    int index = 0;
    char input[1000]={0,};
    
    gets(input);
    
    if(CheckMatching(input, &count) == TRUE)
        printf("OK_%d\n", count);
    else
        printf("Wrong_%d\n", count);
}
