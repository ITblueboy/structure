e);
		return ;
	}
	LinkNode*cur = *head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = LinklistCreate(value);
	return ;

}
void LinkListPopBack(LinkNode** head)//尾删一个元素
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	LinkNode* cur = *head;
	if (cur->next == NULL)
	{
		LinklistDestroy(cur);
		*head = NULL;
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
		{
			LinkNode* to_delete = cur->next;
			cur->next = NULL;
			LinklistDestroy(to_delete);
		}
		else
		{
			cur = cur->next;
		}
	}
	return;
}
void LinkListPushFront(LinkNode** head, LinkType value)//头插一个元素
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		*head = LinklistCreate(value);
		return;
	}
	LinkNode* new_node = LinklistCreate(value);
	new_node->next = *head;
	*head = new_node;
	
}

void LinkListPopFront(LinkNode** head)//头删一个元素
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	LinkNode* cur = *head;
	*head = (*head)->next;
	LinklistDestroy(cur);
}

/**
* @brief 查找元素在链表中的位置
*
* @param head
* @param to_find 要查找的值
*
* @return 这个值对应的节点的地址
*/
LinkNode* LinkListFind(LinkNode* head, LinkType to_find)
{
	if (head == NULL)
	{
		return NULL;
	}
	LinkNode* cur = head;
	while (cur!= NULL)
	{
		if (cur->data == to_find)
		{
			return cur;
		}
		else
		cur = cur->next;
	}
	return NULL;
}

/**
* @brief 在pos之前插入元素
*
* @param head
* @param pos
* @param value
*/
void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	LinkNode* cur = *head;
	if (cur == pos)
	{
		LinkListPushFront(cur, value);
		return;
	}
	LinkNode* new_node = LinklistCreate(value);
	while (cur->next != NULL)
	{
		if (cur->next == pos)
		{
			new_node->next =pos;
			cur->next = new_node;
			return;
		}
		else
			cur = cur->next;
	}
	return;
}

/**
* @brief 在pos之后插入元素
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		*head = LinklistCreate(value);
		return;
	}
	if (pos == NULL)
	{
		return;
	}
	LinkNode* new_node = LinklistCreate(value);
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}

/**
* @brief 删除指定位置的元素
*/
void LinkListErase(LinkNode** head, LinkNode* pos)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL || pos == NULL)
	{
		return;
	}
	if (*head == pos)
	{
		LinkNode* to_delete = pos;
		*head = (*head)->next;
		LinklistDestroy(to_delete);
		return;
	}
	LinkNode* cur = *head;
	while (cur != NULL)
	{
		if (cur->next == pos)
		{
			cur->next = pos->next;
			LinklistDestroy(pos);
			return;
		}
		else
			cur = cur->next;
	}
	return;
}

void LinkListErase2(LinkNode** head, LinkNode* pos)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL || pos == NULL)
	{
		return;
	}
	if (pos==*head)
	{
		LinkNode* to_delete = pos;
		*head = (*head)->next;
		LinklistDestroy(to_delete);
		return;
	}
	if (pos->next != NULL)
	{
		pos->data = pos->next->data;
		LinkNode* del = pos->next;
		pos->next = del->next;
		LinklistDestroy(del);
	}
	else
	{
		LinkNode* cur = *head;
		while (cur != NULL)
		{
			if (cur->next == pos)
			{
				cur->next = pos->next;
				LinklistDestroy(pos);
				return;
			}
			else
				cur = cur->next;
		}
	}
	return;
}

/**
* @brief 删除指定值的元素
*
* @param head
* @param to_delete
*/
void LinkListRemove(LinkNode** head, LinkType to_delete)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	LinkNode* del = LinkListFind(*head, to_delete);
	LinkListErase(head, del);
	return;
}


void LinkListRemove2(LinkNode** head, LinkType to_delete)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	if ((*head)->data == to_delete)
	{
		LinkNode* del = *head;
		*head = (*head)->next;
		LinklistDestroy(del);
		return;
	}
	LinkNode* cur = (*head)->next;
	LinkNode* pre=*head;
	while (cur->next != NULL)
	{
		if (cur->data == to_delete)
		{
			pre->next = cur->next;
			LinklistDestroy(cur);
			return;
		}
		else
		{
			cur = cur->next;
			pre = pre->next;
		}
	}
	return;
}


/**
* @brief 指定值的所有元素都删掉.
*
* @param head
* @param value
*/
void LinkListRemoveAll(LinkNode** head, LinkType value)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	while (1)
	{
		LinkNode* del = LinkListFind(*head,value);
		if (del == NULL)
		{
			break;
		}
		LinkListErase(head, del);
	} 
	return;
}

void LinkListRemoveAll2(LinkNode** head, LinkType value)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	if ((*head)->data == value)
	{
		LinkNode* delete = *head;
		*head = (*head)->next;
		LinklistDestroy(delete);
		return;
	}
	LinkNode* cur = *head;
	LinkNode* pre = *head;
	while (cur!=NULL)
	{
		if (cur->data == value)
		{
			LinkNode* delete = cur;
			cur = cur->next;
			pre->next = cur;
			LinklistDestroy(delete);
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return;
}
/**
* @brief 判定链表为空
*
* @return 链表为空, 返回1, 否则返回0
*/
int LinkListEmpty(LinkNode* head)
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

/**
* @brief 求链表的元素个数
*
* @param head
*
* @return
*/
size_t LinkListSize(LinkNode* head)
{
	if (head == NULL)
	{
		return 0;
	}
	size_t count = 0;
	LinkNode* cur = head;
	while (cur->next != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

/**
* @brief 逆序打印单链表.
*
* @param head
*/
void LinkListReversePrint(LinkNode* head)
{
	if (head == NULL)
	{
		return;
	}
	LinkListReversePrint(head->next);
	printf("[%c:%p]", head->data,head);
}

/**
* @brief 不允许遍历链表, 在 pos之前插入
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)
{
	if (head == NULL || pos == NULL)
	{
		return;
	}
	LinkNode* new_node = LinklistCreate(pos->data);
	pos->data = value;
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}

LinkNode* JosephCycle(LinkNode* head, size_t num)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (num == NULL)
	{
		return NULL;
	}
	LinkNode* cur = head; 
	while (cur != cur->next)
	{
		size_t i = 1;
		for (; i < num; i++)
		{
			cur = cur->next;
		}
		printf("data:[%c]\n", cur->data);
		cur->data = cur->next->data;
		LinkNode* to_delete = cur->next;
		cur->next = to_delete->next;
		LinklistDestroy(to_delete);
	}
	return cur;
}

void LinklistDestroy(LinkNode* delete)
{
	free(delete);
	return;
}
