//
//  Stack_05_10_02.c
//  C++
//
//  Created by 전효재 on 23/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
    int container[100];
    int top;
}StackType;

int IsEmpty(StackType* stack)
{
    if (stack->top == -1)
        return TRUE;
    else
        return FALSE;
}

int IsFull(StackType * stack)
{
    if (stack->top == 99)
        return TRUE;
    else
        return FALSE;
}

void Init(StackType * stack)
{
    stack->top = -1;
    
    for(int i=0; i<100; i++)
        stack->container[i] = 0;
}

void Push(StackType *stack, int item)
{
    if (IsFull(stack) == TRUE)
    {
        printf("Current Stack is FULL!\n");
        return;
    }
    else
    {
        stack->top++;
        stack->container[stack->top] = item;
    }
}

int Pop(StackType * stack)
{
    if (IsEmpty(stack) == TRUE)
    {
        printf("Current Stack is Empty!\n");
        exit(1);
    }
    else
    {
        int popElement = stack->container[stack->top];
        stack->top--;
        
        return popElement;
    }
}

int eval(char exp[])
{
    int op1, op2, value;
    int len = strlen(exp);
    char ch;
    StackType s;
    
    Init(&s);
    
    for(int i=0; i<len; i++)
    {
        ch = exp[i];
        
        if( ch != '+' && ch != '-' && ch != '*' && ch != '/' )
        {
            value = ch - '0'; // 입력이 피연산자이면
            Push(&s, value);
        }
        
        else
        { //연산자이면 피연산자를 스택에서 제거
            op2 = Pop(&s);
            op1 = Pop(&s);
            
            switch(ch)
            { //연산을 수행하고 스택에 저장
                case '+': Push(&s,op1+op2); break;
                case '-': Push(&s,op1-op2); break;
                case '*': Push(&s,op1*op2); break;
                case '/': Push(&s,op1/op2); break;
            }
        }
    }
    return Pop(&s);
}

int main()
{
    int N;
    
    char input[100]={0,};
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        scanf("%s", input);
        
        printf("%d\n", eval(input));
    }
    
}
