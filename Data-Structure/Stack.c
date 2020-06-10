//
//  Stack.c
//  C++
//
//  Created by 전효재 on 29/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 100

void Init(int *stack)
{
    
}

int IsFull(Stacktype *s)
{
    return (s->top == MAX_SIZE - 1);
}

int IsEmpty(Stacktype *s)
{
    return (s->top == -1);
}

void Push(Stacktype *s, int data)
{
    if(IsFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->stack[s->top] = data;
    }
}

int Pop(Stacktype *s) // 스택에서 삭제하면서 데이터 뱉어내기도 가능함
{
    int temp;
    
    if(IsEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = s->stack[s->top];
        s->top-=1;
    }
    return temp;
}

int peak(Stacktype *s)
{
    return s->stack[s->top];
}

int main()
{
    Stacktype s;
    
    Init(s);
}
