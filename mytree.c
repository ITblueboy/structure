#include"tree.h"
#include<stdlib.h>
TreeNode* TreeCreate(Treetype data)
{
  TreeNode* newnode=(TreeNode*)malloc(sizeof(TreeNode));
  newnode->leftchil=NULL;
  newnode->rightchil=NULL;
  newnode->data=data;
}

void TreeInit(TreeNode** root)
{
  if(root==NULL)
  {
    return;
  }
  *root=NULL;
}

void PreOrder(TreeNode* root)
{
  if(root==NULL)
  {
    return;
  }
  printf("%c ",root->data);
  PreOrder(root->leftchil);
  PreOrder(root->rightchil);
}

void InOrder(TreeNode* root)
{
  if(root==NULL)
  {
    return;
  }
  InOrder(root->leftchil);
  printf("%c ",root->data);
  InOrder(root->rightchil);
}

void PostOrder(TreeNode* root)
{
  if(root==NULL)
  {
   return;
  }
  PostOrder(root->leftchil);
  PostOrder(root->rightchil);
  printf("%c ",root->data);
}

void LeverOrder(TreeNode* root)
{

}

