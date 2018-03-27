#include"SearchTree.h"
#include<stdio.h>

SearchTreeNode* CreateSearchTreeNode(SearchTreeType value)
{
	SearchTreeNode* new_node = (SearchTreeNode*)malloc(sizeof(SearchTreeNode));
	new_node->key = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}
void DestroySearchTreeNode(to_remove)
{
	free(to_remove);
}
void SearchTreeInit(SearchTreeNode** root)
{
	if (root == NULL)
	{
		return;
	}
	*root = NULL;
	return;
}

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key)//非递归插入
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		*root = CreateSearchTreeNode(key);
		return;
	}
	SearchTreeNode* cur = *root;
	SearchTreeNode* parent = NULL;
	while (1)
	{
		if (cur == NULL)
		{
			break;
		}
		if (key < cur->key)
		{
			parent = cur;
			cur = cur->lchild;
		}
		else if (key > cur->key)
		{
			parent = cur;
			cur = cur->rchild;
		}
		else
		{
			return;
		}
	}
	SearchTreeNode* new_node = CreateSearchTreeNode(key);
	if (key < parent->key)
	{
		parent->lchild = new_node;
	}
	else 
	{
		parent->rchild = new_node;
	}
	return;
}


void RecursionSearchTreeInsert(SearchTreeNode** root, SearchTreeType key)//递归插入
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		*root = CreateSearchTreeNode(key);
		return;
	}
	if (key < (*root)->key)
	{
		RecursionSearchTreeInsert(&(*root)->lchild, key);
		return;
	}
	else if(key > (*root)->key)
	{
		RecursionSearchTreeInsert(&(*root)->rchild, key);
		return;
	}
	else
	{
		return;
	}
}



SearchTreeNode* SearchTreeFind(SearchTreeNode* root, SearchTreeType to_find)//非递归查找
{
	if (root == NULL)
	{
		return NULL;
	}
	SearchTreeNode* cur = root;
	while (cur!=NULL)
	{
		if (cur->key>to_find)
		{
			cur = cur->lchild;
		}
		else if (cur->key < to_find)
		{
			cur = cur->rchild;
		}
		else
			break;
	}
	return cur;
}


SearchTreeNode* RecursionSearchTreeFind(SearchTreeNode* root, SearchTreeType to_find)//递归查找
{
	if (root == NULL)
	{
		return NULL;
	}
	if (to_find < root->key)
	{
		return RecursionSearchTreeFind(root->lchild, to_find);
	}
	else if (to_find > root->key)
	{
		return RecursionSearchTreeFind(root->rchild, to_find);
	}
	else
	{
		return root;
	}
}
void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key)
{
	if (root == NULL)
	{
		return;
	}
	//1.处理空树的情况，直接返回；
	if (*root == NULL)
	{
		return;
	}
	//2.找到要删除的节点的位置，以及它的父节点；
	SearchTreeNode* to_remove = *root;
	SearchTreeNode* parent = NULL;
	while (to_remove != NULL)
	{
		if (to_remove->key < key)
		{
			parent = to_remove;
			to_remove = to_remove->rchild;
		}
		else if (to_remove->key > key)
		{
			parent = to_remove;
			to_remove = to_remove->lchild;
		}
		else
			break;
	}
	//3.如果要删除的元素在树中没有找到，也直接返回；
	if (to_remove == NULL)
	{
		return;
	}
	//4.如果要删除的元素存在，要分情况讨论：
	//a.要删除的节点，没有子树，直接删除该节点，并且将父节点指向空指针；
	if (to_remove->lchild == NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			*root = NULL;
		}
		else
		{
			if (parent->lchild == to_remove)
			{
				parent->lchild = NULL;
				DestroySearchTreeNode(to_remove);
			}
			else
			{
				parent->rchild = NULL;
				DestroySearchTreeNode(to_remove);
			}
		}
		return;
	}
	//b要删除的节点，只有左子树，删除该节点的同时 ，将该节点的左子树挂到父节点上；
	if (to_remove->lchild != NULL && to_remove->rchild == NULL)
	{
		if (to_remove == *root)
		{
			*root = to_remove->lchild;
		}
		else
		{
			if (to_remove == parent->lchild)
			{
				parent->lchild = to_remove->lchild;
			}
			else
			{
				parent->rchild = to_remove->lchild;
			}
		}
		DestroySearchTreeNode(to_remove);
		return;
	}
	//c要删除的节点，只有右子树，删除该节点的同时 ，将该节点的右子树挂到父节点上；
	else if (to_remove->lchild == NULL && to_remove->rchild != NULL)
	{
		if (to_remove == *root)
		{
			*root = to_remove->rchild;
		}
		else
		{
			if (to_remove == parent->lchild)
			{
				parent->lchild = to_remove->rchild;
			}
			else
			{
				parent->rchild = to_remove->rchild;
			}
		}
		DestroySearchTreeNode(to_remove);
		return;
	}
	//d要删除的节点，同时具有左右子树，找到右子树中的最小值，然后将该最小值赋值给要删除的位置，
	//然后再删除该右子树中的最小值节点，这样一个节点最多只有一个右子树，就转换成了情况c;
	else
	{
		SearchTreeNode* min = to_remove->rchild;
		SearchTreeNode* min_parent = to_remove;
		while (min->lchild != NULL)
		{
			min_parent = min;
			min = min->lchild;
		}
		to_remove->key = min->key;
		if (min_parent->lchild == min)
		{
			min_parent->lchild = min->rchild;
		}
		else
		{
			min_parent->rchild = min->rchild;
		}
		DestroySearchTreeNode(min);
		return;
	}
}