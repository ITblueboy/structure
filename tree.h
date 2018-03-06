#pragma once
#include<stdio.h>
#include<Windows.h>

#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"
#include"seqstack.h"


typedef char TreeNodetype;
typedef struct TreeNode
{
	TreeNodetype data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;
void TreeInit(TreeNode** root);

void PreOrder(TreeNode* root);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

void LevelOrder(TreeNode* root);

/**
* @brief ��������������(���пսڵ���),
* ����һ����
*
* @param array[] ��������Ľ��
* @param size ������Ԫ�ظ���
* @param null_node �����пսڵ��������.
*
* @return
*/
TreeNode* TreeCreate(TreeNodetype array[],size_t size, TreeNodetype null_node);

void TreeDestroy(TreeNode** root);

TreeNode* TreeClone(TreeNode* root);

size_t TreeSize(TreeNode* root);

/**
* @brief ��һ������Ҷ�ӽڵ����
*
* @param root
*
* @return
*/
size_t TreeLeafSize(TreeNode* root);

/**
* @brief ��һ������ K ��ڵ�ĸ���
*
* @param root
*
* @return
*/
size_t TreeKLevelSize(TreeNode* root, int K);

size_t TreeHeight(TreeNode* root);

TreeNode* TreeFind(TreeNode* root, TreeNode to_find);

TreeNode* LChild(TreeNode* node);

TreeNode* RChild(TreeNode* node);

TreeNode* Parent(TreeNode* root, TreeNode* node);

void PreOrderByLoop(TreeNode* root);

void InOrderByLoop(TreeNode* root);

void PostOrderByLoop(TreeNode* root);

void TreeMirror(TreeNode* root);

int IsCompleteTree(TreeNode* root);