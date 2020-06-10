//
//  Tree_03.c
//  C++
//
//  Created by 전효재 on 11/06/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

typedef struct TreeNode
{
    int nodeNumber;
    
    struct TreeNode* leftLink;
    struct TreeNode* rightLink;
}TreeNode;

typedef struct TreeList
{
    TreeNode *root;
    
}TreeList;

TreeNode* GetNode(int nodeNumber)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    
    node->nodeNumber = nodeNumber;
    node->leftLink = NULL;
    node->rightLink = NULL;
    
    return node;
}

void InitList(TreeList *list)
{
    list->root = NULL;
}

void SearchPreOrder(TreeNode)
{
    
}

void SetNode(TreeList *list)
{
    
}

int main()
{
    int n;
    
    int leftNum, myNum, rightNum;
    int searchTime;
    
    TreeList list;
    
    InitList(&list);
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &leftNum, &myNum, &rightNum);
        
    }
    
    scanf("%d", &searchTime);
    
    
}
