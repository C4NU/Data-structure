//
//  Stack_01.c
//  C++
//
//  Created by 전효재 on 02/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

int IsFull(char *stack, int stackSize, int top)
{
    if(top == stackSize - 1)
        return TRUE;
    else
        return FALSE;
}

int IsEmpty(char *stack, int top)
{
    if(top == -1)
        return TRUE;
    else
        return FALSE;
}

void Push(char stack[], char element, int stackSize, int *top)
{
    if(IsFull(stack, stackSize, *top) == TRUE)
    {
        printf("Stack FULL\n");
        return;
    }
    else
    {
        *top = *top + 1;
        stack[*top] = element;
    }
}

char Pop(char *stack, int *top)
{
    if(IsEmpty(stack, *top) == TRUE)
    {
        printf("Stack Empty\n");
        return 0;
    }
    else
    {
        *top = *top - 1;
        return stack[*top+1];
    }
}

void Peek(char *stack, int top)
{
    if(IsEmpty(stack, top) == TRUE)
    {
        printf("Stack Empty\n");
        return;
    }
    else
    {
        printf("%c\n", stack[top]);
        return;
    }
}

void Duplicate(char *stack, int *top, int stackSize)
{
    char c;
    
    c = Pop(stack, top);
    
    Push(stack, c, stackSize, top);
    Push(stack, c, stackSize, top);
}

void UpRotate(char *stack, int *top, int N, int stackSize)
{
    char *temp = (char*)malloc(sizeof(char)*N);
    
    if(N-1 > *top)
        return;
    else
    {
        for(int i=0; i<N; i++)
        {
            temp[i] = Pop(stack, top);
        }
        
        Push(stack, temp[0], stackSize, top);
        
        for(int i=N-1; i>=1; i--)
        {
            Push(stack, temp[i], stackSize, top);
        }
    }
}

void DownRotate(char *stack, int *top, int N, int stackSize)
{
    char *temp = (char*)malloc(sizeof(char)*N);
    
    if(N-1 > *top)
        return;
    else
    {
        for(int i=0; i<N; i++)
        {
            temp[i] = Pop(stack, top);
        }
        
        for(int i=N-2; i>=0; i--)
        {
            Push(stack, temp[i], stackSize, top);
        }
        
        Push(stack, temp[N-1], stackSize, top);
    }
}

void Print(char *stack, int top)
{
    for(int i=top; i>=0; i--)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main()
{
    int stackSize;
    int top = -1; //가장 최근에 들어온 요소, 기본값은 -11
    
    int calcSize; //계산하는 횟수
    
    char order[6]={0,}; //명령어
    char input;
    
    int rotateN;
    
    scanf("%d", &stackSize);
    
    char *stack = (char*)malloc(sizeof(char)*stackSize);
    
    scanf("%d", &calcSize);
    
    for(int i=0; i<calcSize; i++)
    {
        scanf("%s", order);
        
        if(strncmp(order,"POP", 3) == TRUE)
        {
            Pop(stack, &top);
        }
        if(strncmp(order,"PUSH", 4) == TRUE)
        {
            scanf(" %c", &input);
            Push(stack, input, stackSize, &top);
        }
        if(strncmp(order, "PRINT", 5) == TRUE)
        {
            Print(stack, top);
        }
        if(strncmp(order, "PEEK", 4) == TRUE)
        {
            Peek(stack, top);
        }
        if(strncmp(order, "DUP", 3) == TRUE)
        {
            Duplicate(stack, &top, stackSize);
        }
        if(strncmp(order, "UpR", 3) == TRUE)
        {
            scanf("%d", &rotateN);
            
            UpRotate(stack, &top, rotateN, stackSize);
        }
        if(strncmp(order, "DownR", 5) == TRUE)
        {
            scanf("%d", &rotateN);
            
            DownRotate(stack, &top, rotateN, stackSize);
        }
        strcpy(order, "");
    }
}
