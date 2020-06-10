//
//  union_02.c
//  C++
//
//  Created by 전효재 on 30/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int element;
    
    struct Node *next; // 다음 노드를 가리키는 링크
}Node;

typedef struct List
{
    Node *header;
    
    int rank;
}List;

Node *GetNode()
{
    Node *temp = (Node*)malloc(sizeof(Node));
    
    temp->element = 0;
    temp->next = NULL;
    
    return temp;
}

Node *GetNodeWithElement(int element)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    
    temp->element = element;
    temp->next = NULL;
    
    return temp;
}
void Initialize(List *list)
{
    list->header = GetNode();
    
    list->rank = 0;
}

void print(List *list)
{
    Node *temp = list->header->next;
    
    if(list->rank == 0)
        printf("0");
    else
    {
        
        for(int i=0; i<list->rank; i++)
        {
            printf("%d ", temp->element);
            temp = temp->next;
        }
    }
    printf("\n");
}

void AddList(List *list, int member)
{
    Node *q = list->header;
    Node *temp = GetNodeWithElement(member);
    
    for(int i=0; i<list->rank; i++)
    {
        q = q->next;
    }
    
    q->next = temp;
    
    list->rank++;
}

void RemoveNode(Node *node)
{
    //노드는 현재 헤더
    
    int element = node->next->element;
    
    node->next = node->next->next;
    
    node = GetNodeWithElement(element);
}

void Remove(List *list)
{
    Node *p = list->header;
    
    RemoveNode(p);
    
    list->rank--;
}

List Union(List *A, List *B)
{
    List temp;
    Initialize(&temp);
    
    Node *a = A->header->next;
    Node *b = B->header->next;
    
    while((a != NULL) && (b != NULL))
    {
        if(a->element < b->element)
        {
            AddList(&temp, a->element);
            Remove(A);
            a = a->next;
        }
        else if(a->element > b->element)
        {
            AddList(&temp, b->element);
            Remove(B);
            b = b->next;
        }
        else
        {
            AddList(&temp, a->element);
            Remove(A);
            Remove(B);
            a = a->next;
            b = b->next;
        }
    }
    
    a = A->header->next;
    b = B->header->next;
    
    while(a != NULL)
    {
        AddList(&temp, a->element);
        Remove(A);
        a = a->next;
    }
    
    while(b != NULL)
    {
        AddList(&temp, b->element);
        Remove(B);
        b = b->next;
    }
    
    return temp;
}

List Intersect(List *A, List *B)
{
    List temp;
    Initialize(&temp);
    
    Node *a = A->header->next;
    Node *b = B->header->next;
    
    while((a != NULL) && (b != NULL))
    {
        if(a->element < b->element)
        {
            Remove(A);
            a = a->next;
        }
        else if(a->element > b->element)
        {
            Remove(B);
            b = b->next;
        }
        else
        {
            AddList(&temp, a->element);
            Remove(A);
            Remove(B);
            a = a->next;
            b = b->next;
        }
    }
    while(a != NULL)
    {
        Remove(A);
        a = a->next;
    }
    
    while(b != NULL)
    {
        Remove(B);
        b = b->next;
    }
    
    return temp;
}



int main()
{
    List unionA;
    List unionB;
    List unionC;
    List unionD;
    
    List unionTempA;
    List unionTempB;
    
    Initialize(&unionA);
    Initialize(&unionB);
    Initialize(&unionC);
    Initialize(&unionD);
    Initialize(&unionTempA);
    Initialize(&unionTempB);
    
    int sizeofA;
    int sizeofB;
    
    int input;
    
    scanf("%d", &sizeofA);
    
    for(int i=0; i<sizeofA; i++)
    {
        scanf("%d", &input);
        
        AddList(&unionA, input);
        AddList(&unionTempA, input);
    }
    
    scanf("%d", &sizeofB);
    
    for(int i=0; i<sizeofB; i++)
    {
        scanf("%d", &input);
        
        AddList(&unionB, input);
        AddList(&unionTempB, input);
    }
    
    unionC = Union(&unionA, &unionB);
    
    print(&unionC);
    
    unionD = Intersect(&unionTempA, &unionTempB);
    
    print(&unionD);
}
