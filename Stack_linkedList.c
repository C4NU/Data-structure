//
//  Stack_linkedList.c
//  C++
//
//  Created by 전효재 on 16/06/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

#define TRUE 0
#define FALSE 1

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode;

typedef struct StackList
{
    StackNode* top;
}StackList;

void Init(StackList *list)
{
    list->top = NULL;
}

int IsEmpty(StackList *list)
{
    if(list->top == -1)
        return TRUE;
    else
        return FALSE;
}

StackNode *CreateNode(int data)
{
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

void Push(StackList *list, int data)
{
    StackNode *_node = CreateNode(data);
    
    _node->next = list->top;
    list->top = _node;
}

int Pop(StackList *list)
{
    if(IsEmpty(list) == TRUE)
    {
        printf("UNDERFLOW\n");
        
        exit(1);
    }
    else
    {
        StackNode *node = list->top;
        
        int returnData = node->data;

        list->top = node->next;
        
        return returnData;
    }
}

int main()
{
    StackList list;
    
    int selection;
    int input;
    
    Init(&list);
    
    while(1)
    {
        scanf("%d", &selection);
        
        switch(selection)
        {
            case 1:
                scanf("%d", &input);
                Push(&list, input);
                break;
            case 2:
                printf("%d\n", Pop(&list));
                break;
        }
    }
}
