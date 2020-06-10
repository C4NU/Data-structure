//
//  Tree_05_28_01.c
//  C++
//
//  Created by 전효재 on 30/05/2019.
//  Copyright © 2019 전효재. All rights reserved.
//

#include <stdio.h>

typedef struct TreeNode
{
    int data; // 폴더 용량
    
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void ViewSizeofFolders(TreeNode *root)
{
    if(root)
    {
        printf("%d ", root->data);
        
        if(root->left != NULL)
            printf("%d ", root->left->data);
        if(root->right != NULL)
            printf("%d ", root->right->data);
    }
}

int main()
{
    TreeNode F8 = {80, NULL, NULL};
    TreeNode F7 = {130, NULL, NULL};
    TreeNode F6 = {120, &F7, &F8};
    TreeNode F5 = {90, NULL, NULL};
    TreeNode F4 = {70, NULL, NULL};
    TreeNode F3 = {50, NULL, &F6};
    TreeNode F2 = {30, &F4, &F5};
    TreeNode F1 = {20, &F2, &F3}; // root pos
    
    int nodeNumber;
    
    scanf("%d", &nodeNumber);
    
    switch(nodeNumber)
    {
        case 1:
            ViewSizeofFolders(&F1);
            break;
        case 2:
            ViewSizeofFolders(&F2);
            break;
        case 3:
            ViewSizeofFolders(&F3);
            break;
        case 4:
            ViewSizeofFolders(&F4);
            break;
        case 5:
            ViewSizeofFolders(&F5);
            break;
        case 6:
            ViewSizeofFolders(&F6);
            break;
        case 7:
            ViewSizeofFolders(&F7);
            break;
        case 8:
            ViewSizeofFolders(&F8);
            break;
        default:
            printf("-1");
            break;
    }
}
