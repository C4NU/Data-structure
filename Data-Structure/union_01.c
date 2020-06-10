//
//  union_01.c
//  C++
//
//  Created by 전효재 on 29/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef struct Node
{
    int element;
    
    struct Node *next;
}Node;

typedef struct List
{
    int rank;
    
    Node *node;
}List;

Node *GetNode(int element)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    
    temp->element = element;
    temp->next = NULL;
    
    return temp;
}

void Initialize(List *list)
{
    list->node = GetNode(0);
    list->rank = 0;
}

void SetUnion(List *list, int member)
{
    Node *temp = list->node;

    for(int i=0; i<list->rank; i++)
    {
        temp = temp->next;
    }
    
    temp->element = member;
    temp->next = GetNode(0);
    
    list->rank++;
}

int Member(List *list, int element)
{
    if(list->rank == 0)
        return FALSE;
    else
    {
        Node *p = list->node;
        
        while(1)
        {
            int a = p->element;
            
            if(a < element)
            {
                if(p->next == NULL)
                    return FALSE;
                else
                    p = p->next;
            }
            
            else if(a > element)
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }
    }
}

int SubSet(List *first, List *second)
{
    if(first->rank == 0) //공집합일때 (안에 있는 애가 없을때)
        return TRUE;
    else
    {
        Node *p = first->node; //집합 A의 노드 받기 (이름: 노드 P)
        
        while(1)
        {
            if(Member(second, p->element) == TRUE) //집합 B랑 집합 A의 노드 비교해서
            {
                if(p->next == NULL)
                    return TRUE; // 노드 P가 마지막일때 -> 부분집합으로 판단, 참값 뱉기
                else
                    p = p->next; // 노드 P가 아직 마지막이 아니면 다음으로 넘기기
            }
            else
                return p->element; // 부분집합이 아니라서 뱉기
        }
    }}

void print(List *list)
{
    Node *temp = list->node;
    
    for(int i=0; i<list->rank; i++)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    
    printf("\n");
}

int main()
{
    List unionA;
    Initialize(&unionA);
    List unionB;
    Initialize(&unionB);
    
    int sizeofA;
    int sizeofB;
    
    int input;
    
    scanf("%d", &sizeofA);
    
    for(int i=0; i<sizeofA; i++)
    {
        scanf("%d", &input);
        
        SetUnion(&unionA, input);
    }
    
    scanf("%d", &sizeofB);
    
    for(int i=0; i<sizeofB; i++)
    {
        scanf("%d", &input);
        
        SetUnion(&unionB, input);
    }
    
    printf("%d", SubSet(&unionA, &unionB));
}
