#pragma once
#include<stddef.h>

typedef char LinkType;//不带头结点，不带环

typedef struct LinkNode {
	LinkType data;
	struct LinkNode* next;
} LinkNode;

/**
* @brief 初始化链表
*
* @param head
*/
void LinkListInit(LinkNode** head);

/**
* @brief 尾插一个元素到链表中
*
* @param head
* @param value
*/
void LinkListPushBack(LinkNode** head, LinkType value);

/**
* @brief 尾删一个元素
*
* @param head
*/
void LinkListPopBack(LinkNode** head);

/**
* @brief 头插一个元素
*
* @param head
* @param value
*/
void LinkListPushFront(LinkNode** head, LinkType value);

/**
* @brief 头删一个元素
*
* @param head
*/
void LinkListPopFront(LinkNode** head);

/**
* @brief 查找元素在链表中的位置
*
* @param head
* @param to_find 要查找的值
*
* @return 这个值对应的节点的地址
*/
LinkNode* LinkListFind(LinkNode* head, LinkType to_find);

/**
* @brief 在pos之前插入元素
*
* @param head
* @param pos
* @param value
*/
void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value);

/**
* @brief 在pos之后插入元素
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value);

/**
* @brief 删除指定位置的元素
*/
void LinkListErase(LinkNode** head, LinkNode* pos);

void LinkListErase2(LinkNode** head, LinkNode* pos);

/**
* @brief 删除指定值的元素
*
* @param head
* @param to_delete
*/
void LinkListRemove(LinkNode** head, LinkType to_delete);
void LinkListRemove2(LinkNode** head, LinkType to_delete);
/**
* @brief 指定值的所有元素都删掉.
*
* @param head
* @param value
*/
void LinkListRemoveAll(LinkNode** head, LinkType value);
void LinkListRemoveAll2(LinkNode** head, LinkType value);


/**
* @brief 判定链表为空
*
* @return 链表为空, 返回1, 否则返回0
*/
int LinkListEmpty(LinkNode* head);

/**
* @brief 求链表的元素个数
*
* @param head
*
* @return
*/
size_t LinkListSize(LinkNode* head);

/**
* @brief 逆序打印单链表.
*
* @param head
*/
void LinkListReversePrint(LinkNode* head);

/**
* @brief 不允许遍历链表, 在 pos之前插入
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value);

LinkNode* JosephCycle(LinkNode* head, size_t num);//约瑟夫环

void LinklistDestroyNode(LinkNode* delete);//销毁节点

void LinklistDestroy(LinkNode** head);//销毁链表


void LinklistReverse(LinkNode** head);//逆置单链表

void LinklistReverse2(LinkNode** head);//逆置单链表

void LinklistBubbleSort(LinkNode* head);//单链表冒泡排序

LinkNode* LinklistMerge(LinkNode* head1, LinkNode* head2);//两个链表重组

LinkNode* LinklistFindMiddle(LinkNode* head);//找链表中间结点

LinkNode* LinklistFindLastK(LinkNode* head, size_t k);//找倒数第k个节点

void LinklistEraseLastK(LinkNode** head, size_t k);//删除倒数第k个节点

int HaveCycle(LinkNode* head);//判断是否有环

LinkNode* Cycle(LinkNode* head);

size_t CycleLength(LinkNode* head);//求环的长度

LinkNode* CycleEntrance(LinkNode* head);//求环的入口

LinkNode* CycleCross(LinkNode* head1, LinkNode* head2);//

int HaveCrossWithCycle(LinkNode* head1, LinkNode* head2);//判断两个链表是否相交

LinkNode* CrossWithCycle(LinkNode* head1, LinkNode* head2);//求环的交点

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2);//求两个不相交链表的值交集

typedef struct ComplexNode
{
	LinkType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;

ComplexNode* ComplexNodeCreate(LinkType value);//创建复杂链表节点

ComplexNode* CopyComplex(ComplexNode* head);//复制复杂链表



