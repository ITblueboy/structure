#include"Linklist.h"
#include<stdio.h>
#include<stdlib.h>
void LinkListInit(LinkNode** head)//初始化
{
	if (head == 0)
	{
		return;
	}
	*head = NULL;
	return;
}

LinkNode* LinklistCreate(LinkType value)
{
	LinkNode* new_code = (LinkNode*)malloc(sizeof(LinkNode));
	new_code->data = value;
	new_code->next = NULL;
	return new_code;
}
void LinkListPushBack(LinkNode** head, LinkType value)//尾插一个元素到链表中
{
	if (head == NULL)
	{
		return ;
	}
	if (*head == NULL)
	{
		*head=LinklistCreate(value);
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
		LinklistDestroyNode(cur);
		*head = NULL;
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next->next == NULL)
		{
			LinkNode* to_delete = cur->next;
			cur->next = NULL;
			LinklistDestroyNode(to_delete);
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
	LinklistDestroyNode(cur);
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
		LinkListPushFront(&cur, value);
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
		LinklistDestroyNode(to_delete);
		return;
	}
	LinkNode* cur = *head;
	while (cur != NULL)
	{
		if (cur->next == pos)
		{
			cur->next = pos->next;
			LinklistDestroyNode(pos);
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
		LinklistDestroyNode(to_delete);
		return;
	}
	if (pos->next != NULL)
	{
		pos->data = pos->next->data;
		LinkNode* del = pos->next;
		pos->next = del->next;
		LinklistDestroyNode(del);
	}
	else
	{
		LinkNode* cur = *head;
		while (cur != NULL)
		{
			if (cur->next == pos)
			{
				cur->next = pos->next;
				LinklistDestroyNode(pos);
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
		LinklistDestroyNode(del);
		return;
	}
	LinkNode* cur = (*head)->next;
	LinkNode* pre=*head;
	while (cur->next != NULL)
	{
		if (cur->data == to_delete)
		{
			pre->next = cur->next;
			LinklistDestroyNode(cur);
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
		LinklistDestroyNode(delete);
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
			LinklistDestroyNode(delete);
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
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void LinklistDestroy(LinkNode** head)
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
	while (cur != NULL)
	{
		LinkNode* next = cur->next;
		LinkNode* to_delete = cur;
		LinklistDestroyNode(to_delete);
		cur = next;
	}
	*head = NULL;
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
	if (num ==0)
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
		LinklistDestroyNode(to_delete);
	}
	return cur;
}

void LinklistDestroyNode(LinkNode* delete)
{
	free(delete);
	return;
}

void LinklistReverse(LinkNode** head)
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
	while (cur->next != NULL)
	{
		LinkNode* to_delete = cur->next;
		cur->next =to_delete->next;
		to_delete->next = *head;
		*head = to_delete;
	}
	return;
}

void LinklistReverse2(LinkNode** head)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL||(*head)->next==NULL)
	{
		return;
	}
	LinkNode* pre = *head;
	LinkNode* cur = (*head)->next;
	pre->next = NULL;
	while (cur != NULL)
	{
		LinkNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	*head = pre;
	return;
}

void Swap(LinkType* a, LinkType* b)
{
	LinkType tmp = *a;
	*a = *b;
	*b = tmp;
}
void LinklistBubbleSort(LinkNode* head)
{
	LinkNode* count = head;
	LinkNode* tail = NULL;
	for (; count != NULL; count = count->next)
	{
		LinkNode* cur = head;
		for (; cur->next != tail; cur = cur->next)
		{
			if (cur->data > cur->next->data)
			{
				Swap(&cur->data, &cur->next->data);
			}
		}
		tail = cur;
	}
	return;
}

LinkNode* LinklistMerge(LinkNode* head1, LinkNode* head2)
{
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	LinkNode* new_head = NULL;
	LinkNode* new_tail = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			if (new_head == NULL)
			{
				new_head = new_tail = cur1;
			}
			else
			{
				new_tail->next = cur1;
				new_tail = new_tail->next;
			}
			cur1 = cur1->next;
		}
		else 
		{
			if (new_head == NULL)
			{
				new_head = new_tail = cur2;
			}
			else
			{
				new_tail->next = cur2;
				new_tail = new_tail->next;
			}
			cur2 = cur2->next;
		}
	}
	if (cur1 != NULL)
	{
		new_tail->next = cur1;
	}
	else
	{
		new_tail->next = cur2;
	}
	return new_head;
}

LinkNode* LinklistFindMiddle(LinkNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	LinkNode* fast = head;
	LinkNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

LinkNode* LinklistFindLastK(LinkNode* head, size_t k)
{
	LinkNode* fast = head;
	LinkNode* slow = head;;
	size_t i = 0;
	for (; i < k && fast != NULL; i++)
	{
		fast = fast->next;
	}
	if (i < k)
	{
		return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void LinklistEraseLastK(LinkNode** head, size_t k)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	size_t size = LinkListSize(*head);
	if (size < k)
	{
		return;
	}
	if (size == k)
	{
		LinkNode* delete = *head;
		*head = (*head)->next;
		LinklistDestroyNode(delete);
		return;
	}
	LinkNode* cur = *head;
	size_t i = 0;
	for (; i < size - (k+1); ++i)
	{
		cur = cur->next;
	}
	LinkNode* to_delete = cur->next;
	cur->next = to_delete->next;
	LinklistDestroyNode(to_delete);
	return;
}


int HaveCycle(LinkNode* head)
{
	if (head == NULL)
	{
		return 0;
	}
	LinkNode* fast = head;
	LinkNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}

LinkNode* Cycle(LinkNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	LinkNode* fast = head;
	LinkNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}

size_t CycleLength(LinkNode* head)
{
	LinkNode* meet = Cycle(head);
	if (meet == NULL)
	{
		return 0;
	}
	size_t count = 1;
	LinkNode* cur = meet;
	for (; cur->next != meet; cur = cur->next)
	{
		count++;
	}
	return count;
}

LinkNode* CycleEntrance(LinkNode* head)
{
	LinkNode* meet = Cycle(head);
	if (meet == NULL)
	{
		return NULL;
	}
	LinkNode* cur1 = head;
	LinkNode* cur2 = meet;
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

LinkNode* CycleCross(LinkNode* head1, LinkNode* head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	size_t size1 = LinkListSize(head1);
	size_t size2 = LinkListSize(head2);
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	if (size1 < size2)
	{
		while (size1 != size2)
		{
			cur2 = cur2->next;
			size2--;
		}
	}
	else
	{
		while (size1 != size2)
		{
			cur1 = cur1->next;
			size1--;
		}
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

int HaveCrossWithCycle(LinkNode* head1, LinkNode* head2)//判断两个链表是否有交点
{
	if (head1 == NULL || head2 == NULL)
	{
		return 0;
	}
	LinkNode* entry1 = CycleEntrance(head1);
	LinkNode* entry2 = CycleEntrance(head2);
	if (entry1 == NULL && entry2 == NULL)//两个链表都不带环
	{
		return CycleCross(head1, head2) != NULL ? 1 : 0;
	}
	else if (entry1 != NULL && entry2 != NULL)//两个都带环
	{
		if (entry1 == entry2)//交点在环外
		{
			return 1;
		}
		LinkNode* cur = entry1->next;
		while (cur!= entry1)
		{
			if (cur = entry2)//交点在环上
			{
				return 1;
			}
			cur = cur->next;
		}
		return 0;
	}
	else//一个带环，一个不带环，一定不相交
	{
		return 0;
	}
	return 0;
}

LinkNode* CrossWithCycle(LinkNode* head1, LinkNode* head2)//判断两个链表是否有交点,若想相交，求出交点；
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	LinkNode* entry1 = CycleEntrance(head1);
	LinkNode* entry2 = CycleEntrance(head2);
	if (entry1 == NULL && entry2 == NULL)//两个链表都不带环
	{
		return CycleCross(head1, head2);
	}
	else if (entry1 != NULL && entry2 != NULL)//两个都带环
	{
		if (entry1 == entry2)//交点在环外
		{
			return entry1;
		}
		LinkNode* cur = entry1->next;
		while (cur != entry1)
		{
			if (cur = entry2)//交点在环上
			{
				return entry2;
			}
			cur = cur->next;
		}
		return NULL;
	}
	else//一个带环，一个不带环，一定不相交
	{
		return NULL;
	}
	return NULL;
}

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	LinkNode* cur1 = head1;
	LinkNode* cur2 = head2;
	LinkNode* new_head = NULL;
	LinkNode* new_tail = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			LinkNode* new_node = LinklistCreate(cur1->data);
			if (new_head == NULL)
			{
				new_head = new_tail = new_node;
			}
			else
			{
				new_tail->next = new_node;
				new_tail = new_tail->next;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	return new_head;
}

ComplexNode* ComplexNodeCreate(LinkType value)
{
	ComplexNode* ptr = (ComplexNode*)malloc(sizeof(ComplexNode));
	ptr->data=value;
	ptr->next=NULL;
    ptr->random=NULL;
	return ptr;
}

size_t Getoffset(ComplexNode* src,ComplexNode* dest)
{
	if (src == NULL || dest == NULL)
	{
		return (size_t)-1;
	}
	size_t count = 0;
	while (src != NULL)
	{
		if (src == dest)
		{
			return count;
		}
		++count;
		src = src->next;
	}
	return (size_t)-1;
}
ComplexNode* Step(ComplexNode* pos, size_t offsetnum)
{
	size_t i = 0;
	for (; i < offsetnum; i++)
	{
		if (pos == NULL)
		{
			return NULL;
		}
		pos = pos->next;
	}
	return pos;
}
//复制复杂链表的步骤：

ComplexNode* CopyComplex(ComplexNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//1，先对链表进行简单复制
	ComplexNode* new_head = NULL;
	ComplexNode* new_tail = NULL;
	ComplexNode* cur = head;
	while (cur != NULL)
	{
		LinkNode* new_node = ComplexNodeCreate(cur->data);
		if (new_head == NULL)
		{
			new_head = new_tail = new_node;
		}
		else
		{
			new_tail->next = new_node;
			new_tail = new_tail->next;
		}
	}
	//2，计算每个random指针相对于头结点的偏移量
	//3，根据偏移量来修改每个新链表的random指针
	ComplexNode* new_cur = new_head;
	for (cur = head; cur != NULL && new_cur != NULL; cur = cur->next, new_cur = new_cur->next)
	{
		if (cur->random == NULL)
		{
			new_cur->random = NULL;
			continue;
		}
		size_t offset = Getoffset(head, cur->random);
		new_cur->random = Step(new_head, offset);
	}
	return new_head;
}

ComplexNode* CopyComplex2(ComplexNode* head)
{
	//1遍历旧链表，给每一个节点都创建一个对应的新节点，并且把新节点插到旧节点之后
	ComplexNode* cur = head;
	while (cur != NULL)
	{
		ComplexNode* new_node = ComplexNodeCreate(cur->data);
		new_node->next = cur->next;
		cur->next = new_node;
		cur = cur->next->next;
	}
	//2.再遍历链表，更新每个新节点的random指针
	for (cur = head; cur != NULL; cur = cur->next->next)
	{
		if (cur->random == NULL)
		{
			cur->next->random = NULL;
			continue;
		}
		cur->next->random = cur->random->next;
	}
	//3.再遍历链表，把新节点依次拆下来，组成一个新链表
	ComplexNode* new_head = NULL;
	ComplexNode* new_tail = NULL;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		ComplexNode* delete = cur->next;
		cur->next = delete->next;
		if (new_head == NULL)
		{
			new_head = new_tail = delete;
		}
		else
		{
			new_tail->next = cur->next;
			new_tail = new_tail->next;
		}
	}
	return new_head;
}


//第三种为C++做法
#if 1
#include<unordered_map>
ComplexNode* CopyComplex3(ComplexNode* head)
{
	std::unordered_map<ComplexNode*, ComplexNode*> table;
	for (ComplexNode* cur = head; cur != NULL; cur = cur->next)
	{
		table[cur] = ComplexCreate(cur->data);
	}
	for (ComplexNode* cur = head; cur != NULL; cur = cur->next)
	{
		table[cur]->next = table[cur->next];
		table[cur]->random = table[cur->random];
	}
	return table[head];
}
#endif