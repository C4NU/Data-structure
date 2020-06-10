//
//  Queue_LinkedList.c
//  C++
//
//  Created by 전효재 on 16/06/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

#define TRUE 0
#define FALSE 1

typedef int element;

typedef struct QueueNode
{
    element data;
    
    struct QueueNode *next;
}QueueNode;

typedef struct QueueList
{
    QueueNode *front;
    QueueNode *rear;
}QueueList;

QueueNode* CreateNode(element data)
{
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

void Init(QueueList *list)
{
    list->front = list->rear = NULL;
}

int IsEmpty(QueueList *list)
{
    if(list->front == NULL && list->rear == NULL)
        return TRUE;
    else
        return FALSE;
}

void EnQueue(QueueList *list, element data)
{
    QueueNode *node = CreateNode(data);
    
    if(IsEmpty(list) == TRUE)
    {
        list->front = node;
        list->rear = node;
    }
    else
    {
        list->rear->next = node;
        list->rear = node;
    }
}

int DeQueue(QueueList *list)
{
    if(IsEmpty(list) == TRUE)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        QueueNode *node = list->front;
        
        int returnValue = node->data;
        
        list->front = list->front->next;
        
        if(list->front == NULL)
            list->rear = NULL;
        
        return returnValue;
    }
}

int main()
{
    QueueList list;
    Init(&list);
    
    int select, input;
    
    while(1)
    {
        scanf("%d", &select);
        
        switch(select)
        {
            case 1:
                scanf("%d", &input);
                EnQueue(&list, input);
                break;
            case 2:
                printf("%d\n", DeQueue(&list));
                break;
        }
    }
}
