//
//  Tree_02.c
//  C++
//
//  Created by 전효재 on 31/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct TreeNode
{
    int id; //폴더 순서
    int data; // 폴더 용량
    
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct TreeList
{
    TreeNode* root;
    
}TreeList;

TreeNode* CreateNode(int id, int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    
    node->id = id;
    node->data = data;
    
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void Init(TreeList* tList)
{
    tList->root = CreateNode(1, 20);
    tList->root->left = CreateNode(2, 30);
    tList->root->right = CreateNode(3, 50);
    tList->root->left->left = CreateNode(4, 70);
    tList->root->left->right = CreateNode(5, 90);
    tList->root->right->right = CreateNode(6, 120);
    tList->root->right->right->left = CreateNode(7, 130);
    tList->root->right->right->right = CreateNode(8, 80);
}

void SearchFolderSize_PreOrder(int id, TreeNode *root, int flag)
{
    //전위 순회
    int check = flag;
    
    if (id < 1 || id > 8)
    {
        printf("-1");
        return;
    }
    else
    {
        if (root)
        {
            if (root->id == id)
            {
                check = 1;
            }
            if (check == 1)
                printf("%d ", root->data);
            SearchFolderSize_PreOrder(id, root->left, check);
            SearchFolderSize_PreOrder(id, root->right, check);
        }
    }
    
}

void SearchFolderSize_InOrder(int id, TreeNode *root)
{
    static int check;

    //중위 순회
    if (id < 1 || id > 8)
    {
        printf("-1");
        return;
    }
    else
    {
        if (root)
        {
            if(root->id == id)
            {
                printf("checked forward ");
            }
            SearchFolderSize_InOrder(id, root->left);
            if(root->id == id)
            {
                printf("checked center ");
            }
            printf(" %d", root->id);
            SearchFolderSize_InOrder(id, root->right);
            if(root->id == id)
            {
                printf("checked backward ");
            }
        }
    }
}

void SearchFolderSize_PostOrder(int id, TreeNode *root, int flag)
{
    int check = flag;
    //후위 순회
    if (id < 1 || id > 8)
    {
        printf("-1");
        return;
    }
    else
    {
        if (root)
        {
            SearchFolderSize_PostOrder(id, root->left, check);
            SearchFolderSize_PostOrder(id, root->right, check);
            if (root->id == id)
            {
                check = 1;
            }
            if (check == 1)
                printf("%d ", root->data);
        }
    }
}

int main()
{
    TreeList list;
    
    int select;
    int folderID;
    
    Init(&list);
    scanf("%d %d", &select, &folderID);
    
    switch (select)
    {
        case 1:
            SearchFolderSize_PreOrder(folderID, list.root, 0);
            break;
        case 2:
            SearchFolderSize_InOrder(folderID, list.root);
            break;
        case 3:
            SearchFolderSize_PostOrder(folderID, list.root, 0);
            break;
    }
}
