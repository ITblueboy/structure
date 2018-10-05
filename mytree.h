#include<stdio.h>

typedef char Treetype;

typedef struct TreeNode
{
  struct TreeNode* leftchil;
  struct TreeNode* rightchil;
  Treetype data;
}TreeNode;

void TreeInit(TreeNode** root);
void PreOrder(TreeNode* root);
void InOrder(TreeNode* root);
void PostOrder(TreeNode* root);
void LeverOrder(TreeNode* root);



