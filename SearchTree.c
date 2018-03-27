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

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key)//�ǵݹ����
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


void RecursionSearchTreeInsert(SearchTreeNode** root, SearchTreeType key)//�ݹ����
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



SearchTreeNode* SearchTreeFind(SearchTreeNode* root, SearchTreeType to_find)//�ǵݹ����
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


SearchTreeNode* RecursionSearchTreeFind(SearchTreeNode* root, SearchTreeType to_find)//�ݹ����
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
	//1.��������������ֱ�ӷ��أ�
	if (*root == NULL)
	{
		return;
	}
	//2.�ҵ�Ҫɾ���Ľڵ��λ�ã��Լ����ĸ��ڵ㣻
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
	//3.���Ҫɾ����Ԫ��������û���ҵ���Ҳֱ�ӷ��أ�
	if (to_remove == NULL)
	{
		return;
	}
	//4.���Ҫɾ����Ԫ�ش��ڣ�Ҫ��������ۣ�
	//a.Ҫɾ���Ľڵ㣬û��������ֱ��ɾ���ýڵ㣬���ҽ����ڵ�ָ���ָ�룻
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
	//bҪɾ���Ľڵ㣬ֻ����������ɾ���ýڵ��ͬʱ �����ýڵ���������ҵ����ڵ��ϣ�
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
	//cҪɾ���Ľڵ㣬ֻ����������ɾ���ýڵ��ͬʱ �����ýڵ���������ҵ����ڵ��ϣ�
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
	//dҪɾ���Ľڵ㣬ͬʱ���������������ҵ��������е���Сֵ��Ȼ�󽫸���Сֵ��ֵ��Ҫɾ����λ�ã�
	//Ȼ����ɾ�����������е���Сֵ�ڵ㣬����һ���ڵ����ֻ��һ������������ת���������c;
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