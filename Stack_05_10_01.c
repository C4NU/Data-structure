//
//  Stack_05_10_01.c
//  C++
//
//  Created by 전효재 on 10/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

#define TRUE 1
#define FALSE 0

typedef struct
{
    char container[100];
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
    stack->container[0] = '\0';
    stack->top = -1;
}

void Push(StackType * stack, char item)
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

char Pop(StackType * stack)
{
    if (IsEmpty(stack) == TRUE)
    {
        printf("Current Stack is Empty!\n");
        exit(1);
    }
    else
    {
        char popElement = stack->container[stack->top];
        stack->top--;
        
        return popElement;
    }
}

char Peek(StackType * stack)
{
    if (IsEmpty(stack) == TRUE)
    {
        printf("Current Stack is Empty!\n");
        exit(1);
    }
    else
    {
        return stack->container[stack->top];
    }
}

int Prec(char Operator)
{
    if (Operator == '!')
        return 6;
    if (Operator == '*' || Operator == '/')
        return 5;
    if (Operator == '+' || Operator == '-')
        return 4;
    if (Operator == '<' || Operator == '>')
        return 3;
    if (Operator == '&')
        return 2;
    if (Operator == '|')
        return 1;
    else
        return 0;
}

void InfixToPrefix(char* input)
{
    char ch, topOp;
    char temp;
    
    int length = strlen(input);
    
    StackType stack;
    
    Init(&stack);
    
    for (int i = 0; i < length; i++)
    {
        ch = input[i];
        
        switch (ch)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '<':
            case '>':
            case '!':
                while (IsEmpty(&stack) == FALSE && Prec(ch) <= Prec(Peek(&stack)))
                    printf("%c", Pop(&stack));
                Push(&stack, ch);
                break;
            case '|':
            case '&':
                while (IsEmpty(&stack) == FALSE && Prec(ch) <= Prec(Peek(&stack)))
                {
                    temp = Pop(&stack);
                    printf("%c%c", temp, temp);
                }
                Push(&stack, ch);
                break;
            case '(':
                Push(&stack, ch);
                break;
            case ')':
                topOp = Pop(&stack);
                
                while (topOp != '(')
                {
                    printf("%c", topOp);
                    topOp = Pop(&stack);
                }
                
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while (IsEmpty(&stack) == FALSE)
        printf("%c", Pop(&stack));
    
    printf("\n");
}

int main()
{
    int length;
    char input[100] = { 0, };
    
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        scanf("%s", input);

        InfixToPrefix(input);
        
        input[0] = '\0';
    }
}
