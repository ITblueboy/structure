#include"tree.h"



TreeNode *CreateTreeNode(TreeNodetype value)
{
	TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
	ptr->data = value;
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	return ptr;
}
void DestroyTreeNode(TreeNode *to_delete)
{
	free(to_delete);
}
void TreeInit(TreeNode** root)
{
	if (root == NULL)
	{
		return;
	}
	*root = NULL;
}

void PreOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%2c", root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	printf("%2c", root->data);
	InOrder(root->rchild);
}

void PostOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%2c", root->data);
}

//void LevelOrder(TreeNode* root)
//{
//	
//	if (root == NULL)
//	{
//		return;
//	}
//	SeqQueue q;
//	QeqQueueInit(&q);
//	TreeNode *cur = NULL;
//	while (SeqQueueFront(&q, &cur))
//	{
//		printf("%c", cur->data);
//		SeqQueuePop(&q);
//		if (cur->lchild != NULL)
//		{
//			SeqQueuePush(&q, cur->lchild);
//		}
//		if (cur->rchild != NULL)
//		{
//			SeqQueuePush(&q, cur->rchild);
//		}
//	}
//}

TreeNode *_TreeCreate(TreeNodetype array[], size_t size, size_t *index, TreeNodetype null_node)
{
	if (index == NULL)
	{
		return NULL;
	}
	if (*index >= size)
	{
		return NULL;
	}
	if (array[*index] == null_node)
	{
		return NULL;
	}
	TreeNode *new_node = CreateTreeNode(array[*index]);
	++(*index);
	new_node->lchild = _TreeCreate(array, size, index, null_node);
	++(*index);
	new_node->rchild = _TreeCreate(array, size, index, null_node);
	return new_node;
}
TreeNode* TreeCreate(TreeNodetype array[], size_t size, TreeNodetype null_node)
{
	/**
	* @brief 根据先序遍历结果(带有空节点标记),
	* 构造一棵树
	*
	* @param array[] 先序遍历的结果
	* @param size 数组中元素个数
	* @param null_node 数组中空节点的特殊标记.
	*
	* @return
	*/
	size_t index = 0;
	return _TreeCreate(array, size, &index, null_node);
}

void TreeDestroy(TreeNode** root)
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		return;
	}
	TreeNode *to_delete = *root;
	TreeDestroy(&to_delete->lchild);
	TreeDestroy(&to_delete->rchild);
	DestroyTreeNode(to_delete);
	*root = NULL;
}

TreeNode* TreeClone(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode *new_node = CreateTreeNode(root->data);
	new_node->lchild = TreeClone(root->lchild);
	new_node->rchild = TreeClone(root->rchild);
	return new_node;
}

size_t TreeSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->lchild) + TreeSize(root->rchild);
}

/**
* @brief 求一棵树的叶子节点个数
*
* @param root
*
* @return
*/
size_t TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->lchild == NULL&&root->rchild == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}

/**
* @brief 求一棵树第 K 层节点的个数
*
* @param root
*
* @return
*/
size_t TreeKLevelSize(TreeNode* root, int k)
{
	if (root == NULL || k < 1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->lchild, k - 1) + TreeKLevelSize(root->rchild, k - 1);
}

size_t TreeHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size_t lheight = TreeHeight(root->lchild);
	size_t rheight = TreeHeight(root->rchild);
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

TreeNode* TreeFind(TreeNode* root, TreeNodetype to_find)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == to_find)
	{
		return root;
	}
	TreeNode *lresult = TreeFind(root->lchild, to_find);
	TreeNode *rresult = TreeFind(root->rchild, to_find);
	return lresult != NULL ? lresult : rresult;
}


TreeNode* LChild(TreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	return node->lchild;
}

TreeNode* RChild(TreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	return node->rchild;
}

TreeNode* Parent(TreeNode* root, TreeNode* node)
{
	if (root == NULL || node == NULL)
	{
		return NULL;
	}
	if (root->lchild == node || root->rchild == node)
	{
		return root;
	}
	TreeNode *lresult = Parent(root->lchild, node);
	TreeNode *rresult = Parent(root->rchild, node);
	return lresult != NULL ? lresult : rresult;

}

void PreOrderByLoop(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	while (1)
	{
		TreeNode *top = NULL;
		SeqStackTop(&stack, &top);
		if (top == NULL)
		{
			break;
		}
		printf("%c", top->data);
		SeqStackPop(&stack);
		if (top->lchild != NULL)
		{
			SeqStackPush(&stack, top->lchild);
		}
		if (top->rchild != NULL)
		{
			SeqStackPush(&stack, top->rchild);
		}
	}
	printf("\n");
}

void InOrderByLoop(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	TreeNode *cur = root;
	while (1)
	{
		while (cur != NULL)
		{
			SeqStackPush(&stack, cur);
			cur = cur->lchild;
		}
		TreeNode *top = NULL;
		SeqStackTop(&stack, &top);
		if (top == NULL)
		{
			break;
		}
		printf("%c", top->data);
		SeqStackPop(&stack);
		cur = top->rchild;
	}

}

void PostOrderByLoop(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	TreeNode *cur = root;
	while (1)
	{
		while (cur != NULL)
		{
			SeqStackPush(&stack, cur);
			cur = cur->lchild;
		}
		TreeNode *top = NULL;
		SeqStackTop(&stack, &top);
		if (top == NULL)
		{
			break;
		}
		if (top->rchild == NULL ||top->rchild==pre )
		{
			printf("%c", top->data);
			SeqStackPop(&stack);
			pre = top;
		}
		else
		{
			cur = top->rchild;
		}
	}
	printf("\n");
}

void TreeMirror(TreeNode* root)
{
	//二叉树的水平翻转
	if (root == NULL)
	{
		return;
	}
	TreeNode *tem = root->lchild;
	root->lchild = root->rchild;
	root->rchild = tem;
	TreeMirror(root->lchild);
	TreeMirror(root->rchild);

}
int IsCompleteTree(TreeNode* root)
{
	//判断是不是完全二叉树
	if (root == NULL)
	{
		return 1;
	}
	SeqQueue queue;
	SeqQueueInit(&queue);
	SeqQueuePush(&queue, root);
	int check_two_child = 1;
	while (1)
	{
		TreeNode *cur = NULL;
		SeqQueueFront(&queue, &cur);
		if (cur == NULL)
		{
			break;
		}
		if (check_two_child = 0)//第一阶段判定
		{
			if (cur->lchild != NULL&&cur->rchild != NULL)
			{
				SeqQueuePush(&queue, cur->lchild);
				SeqQueuePush(&queue, cur->rchild);
			}
			else if (cur->lchild == NULL&&cur->rchild != NULL)
			{
				return 0;
			}
			else if (cur->lchild != NULL&&cur->rchild == NULL)
			{
				SeqQueuePush(&queue, cur->lchild);
				int check_two_child = 1;
			}
			else if (cur->lchild == NULL&&cur->rchild == NULL)
			{
				int check_two_child = 1;

			}
		}
		else//第二阶段判定
		{
			if (cur->lchild==NULL&&cur->rchild==NULL)
			{

			}
			else
			{
				return 0;
			}
		}
		SeqQueuePop(&queue);
	}
	return 1;
}


