//
//  01.c
//  C++
//
//  Created by 전효재 on 11/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    
    char element;
}Node;

Node *GetNode(char element)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->element = element;
    temp->prev = temp->next = NULL;
    
    return temp;
}

typedef struct list
{
    Node *head;
    Node *tail;
    
    int rank;
}List;
//node, list 구조체 정의

void Initialize(List *list)
{
    list->head = GetNode(0);
    list->tail = GetNode(0);
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->rank = 1;
}
//리스트 초기화

void addNodeBefore(Node *p, char element)
{
    Node *q = GetNode(element);
    
    q->prev = p->prev;
    q->next = p;
    p->prev->next = q;
    p->prev = q;
}

void add(List *list, int _rank, char element)
{
    if ((_rank < 1) || (_rank > list->rank))
    {
        printf("invalid position\n");
        return;
    }
    
    Node* p = list->head;
    //노드 p 생성, list의 헤드 대입
    
    for (int i = 1; i <= _rank; i++)
    {
        p = p->next;
    }
    
    addNodeBefore(p, element);
    
    list->rank += 1;
    //입력된 rank 위치에 노트 삽입
}

void deleteNode(Node *p)
{
    char element = p->element;
    
    p->prev->next = p->next;
    p->next->prev = p->prev;
    
    p = GetNode(element);
}

void delete(List *list, int _rank)
{
    if ((_rank < 1) || (_rank >= list->rank))
    {
        printf("invalid position\n");
        return;
    }
    
    Node* p = list->head;
    //노드 p 생성, list의 헤드 대입
    
    for (int i = 1; i <= _rank; i++)
    {
        p = p->next;
    }
    
    deleteNode(p);
    
    list->rank -= 1;
    //입력된 rank 위치에 노트 삽입
}

void get(List *list, int _rank)
{
    int cnt = 0;
    
    if ((_rank < 1) || (_rank >= list->rank))
    {
        printf("invalid position\n");
        return;
    }
    
    Node* p = list->head;
    
    while (p != list->tail)
    {
        if (cnt == _rank)
        {
            printf("%c\n", p->element);
        }
        p = p->next;
        
        cnt++;
    }
}

void print(List *list)
{
    Node* p = list->head;
    
    while (p != list->tail)
    {
        p = p->next;
        printf("%c", p->element);
    }
    printf("\n");
}

int main()
{
    //연산 개수
    int num;
    //add delete get print 설정할 인풋 변수
    char inputSelection;
    //리스트 위치 인덱스 값
    int rank = 0;
    //입력할 문자 하나
    char input = 0;
    
    List list;
    
    Initialize(&list);
    
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf(" %c", &inputSelection);
        if (inputSelection == 'A')
        {
            scanf(" %d %c", &rank, &input);
        }
        
        else if (inputSelection == 'D' || inputSelection == 'G')
        {
            scanf( "%d", &rank);
        }
        
        switch (inputSelection)
        {
            case 'A':
                add(&list, rank, input);
                break;
            case 'D':
                delete(&list, rank);
                break;
            case 'G':
                get(&list, rank);
                break;
            case 'P':
                print(&list);
                break;
        }
    }
}
