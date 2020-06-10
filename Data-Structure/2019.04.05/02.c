//
//  02.c
//  C++
//
//  Created by 전효재 on 19/04/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef; // 항의 계수
    int exp; // 항의 차수
    
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
    
    temp->coef = 0;
    temp->exp = 0;
    
    temp->next = NULL;
    
    return temp;
}

void Initialize(List *list)
{
    list->header = GetNode();
    
    list->rank = 0;
}

//리스트 초기화

void AddNode(Node *node, int coef, int exp)
{
    Node *q = GetNode();
    q->coef = coef;
    q->exp = exp;
    
    node->next = q;
}

void AppendTerm(List *list, int coef, int exp)
{
    Node *temp = list->header;

    for(int i=0; i< list->rank; i++)
    {
        temp = temp->next;
    }
    
    AddNode(temp, coef, exp);
    
    list->rank+=1;
}

List AddPoly(List *firstList, List *secondList)
{
    List result;
    
    Node *i = firstList->header->next;
    Node *j = secondList->header->next;
    
    Initialize(&result);
    
    while((i != NULL)&&(j!=NULL))
    {
        if(i->exp > j->exp)
        {
            AppendTerm(&result, i->coef, i->exp);
            i = i->next;
        }
        else if( i->exp < j->exp)
        {
            AppendTerm(&result, j->coef, j->exp);
            j = j->next;
        }
        else
        {
            int sum = i->coef + j->coef;
            
            if(sum != 0)
                AppendTerm(&result, sum, i->exp);
            
            i = i->next;
            j = j->next;
        }
    }
    
    while(i != NULL)
    {
        AppendTerm(&result, i->coef, i->exp);
        i = i->next;
    }
    while(j != NULL)
    {
        AppendTerm(&result, j->coef, j->exp);
        j = j->next;
    }
    return result;
}

void print(List *list)
{
    Node *node = list->header->next;

    for(int i =0; i<list->rank; i++)
    {
        printf("%d %d ", node->coef, node->exp);
        
        node = node->next;
    }
    
    printf("\n");
}

int main()
{
    List firstList;
    List secondList;
    List result;
    
    int firstFormula; //첫번째 공식 항의 개수
    int secondFormula; //두번째 공식 항의 개수
    
    int coef; //계수
    int exp; //차수
    
    Initialize(&firstList);
    Initialize(&secondList);
    Initialize(&result);
    
    scanf("%d", &firstFormula);
    
    for(int i=0; i<firstFormula; i++)
    {
        scanf("%d %d", &coef, &exp);
        AppendTerm(&firstList, coef, exp);
    }
    
    scanf("%d", &secondFormula);
    
    for(int i=0; i<secondFormula; i++)
    {
        scanf("%d %d", &coef, &exp);
        AppendTerm(&secondList, coef, exp);
    }
    
    result = AddPoly(&firstList, &secondList);
    
    print(&result);
}
