#include"threadtree.h"

ThreadNode *CreateThreadNode(ThreadType value)
{
	ThreadNode *new_node = (ThreadNode*)malloc(sizeof(ThreadNode));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->lflag = CHILD;
	new_node->rflag = CHILD;
	return new_node;
}
ThreadNode *_ThreadTreeCreate(ThreadType array[], size_t size, size_t* index, ThreadType invalid)
{
	if (index == NULL || *index>= size)
	{
		return NULL;
	}
	if (array[*index] == invalid)
	{
		return NULL;
	}
	ThreadNode *root = CreateThreadNode(array[*index]);
	++(*index);
	root->left = _ThreadTreeCreate(array, size, index, invalid);
	++(*index);
	root->right = _ThreadTreeCreate(array, size, index, invalid);
}
ThreadNode* ThreadTreeCreate(ThreadType array[], size_t size, ThreadType invalid)
{
	size_t index = 0;
	return  _ThreadTreeCreate(array, size, &index,invalid);
}

void _PreThreading(ThreadNode *root,ThreadNode **prev)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL)
	{
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev != NULL && (*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
	if (root->lflag == CHILD)
	{
		_PreThreading(root->left, prev);
	}
	if (root->rflag == CHILD)
	{
		_PreThreading(root->right, prev);
	}
	return;
	
}
void PreThreading(ThreadNode* root)
{
	ThreadNode *prev = NULL;
	_PreThreading(root,&prev);
}

void PreOrderByThreading(ThreadNode* root)
{
	if (root == NULL)
	{
		return;
	}
	ThreadNode *cur = root;
	while (cur != NULL)
	{
		while (cur->lflag == CHILD)
		{
			printf("%c", cur->data);
			cur = cur -> left;
		}
		printf("%c", cur->data);
		cur = cur->right;
	}
	return;
}
void _InThreading(ThreadNode *root, ThreadNode **prev)
{
	if (root == NULL || prev == NULL)
	{
		return;
	}
	if (root->lflag == CHILD)
	{
		_InThreading(root->left, prev);
	}
	if (root->left == NULL)
	{
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev != NULL && (*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
	if (root->rflag == CHILD)
	{
		_InThreading(root->right, prev);
	}
}
void InThreading(ThreadNode* root)
{
	ThreadNode *prev = NULL;
	_InThreading(root, prev);
}

void InOrderByThreading(ThreadNode* root)
{
	if (root == NULL)
	{
		return;
	}
	ThreadNode *cur = root;
	while (cur != NULL&&cur->lflag == CHILD)
	{
		cur = cur->left;
	}
	while (cur != NULL)
	{
		printf("%c", cur->data);
		if (cur->rflag == THREAD)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->right;
			while (cur != NULL&&cur->lflag == CHILD)
			{
				cur = cur->left;
			}
		}
	}
	return;
}

void _PostThreading(ThreadNode *root, ThreadNode **prev)
{
	if (root == NULL || prev == NULL)
	{
		return;
	}
	if (root->data == CHILD)
	{
		_PostThreading(root->left, prev);
	}
	if (root->rflag == CHILD)
	{
		_PostThreading(root->right, prev);
	}
	if (root->left == NULL)
	{
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev != NULL &&(*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
}
void PostThreading(ThreadNode* root)
{
	ThreadNode *prev = NULL;
	_PostThreading(root, prev);
}

void PostOrderByThreading(ThreadNode* root);
