#pragma once
#include<stddef.h>

typedef char LinkType;//����ͷ��㣬������

typedef struct LinkNode {
	LinkType data;
	struct LinkNode* next;
} LinkNode;

/**
* @brief ��ʼ������
*
* @param head
*/
void LinkListInit(LinkNode** head);

/**
* @brief β��һ��Ԫ�ص�������
*
* @param head
* @param value
*/
void LinkListPushBack(LinkNode** head, LinkType value);

/**
* @brief βɾһ��Ԫ��
*
* @param head
*/
void LinkListPopBack(LinkNode** head);

/**
* @brief ͷ��һ��Ԫ��
*
* @param head
* @param value
*/
void LinkListPushFront(LinkNode** head, LinkType value);

/**
* @brief ͷɾһ��Ԫ��
*
* @param head
*/
void LinkListPopFront(LinkNode** head);

/**
* @brief ����Ԫ���������е�λ��
*
* @param head
* @param to_find Ҫ���ҵ�ֵ
*
* @return ���ֵ��Ӧ�Ľڵ�ĵ�ַ
*/
LinkNode* LinkListFind(LinkNode* head, LinkType to_find);

/**
* @brief ��pos֮ǰ����Ԫ��
*
* @param head
* @param pos
* @param value
*/
void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value);

/**
* @brief ��pos֮�����Ԫ��
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value);

/**
* @brief ɾ��ָ��λ�õ�Ԫ��
*/
void LinkListErase(LinkNode** head, LinkNode* pos);

void LinkListErase2(LinkNode** head, LinkNode** pos);

/**
* @brief ɾ��ָ��ֵ��Ԫ��
*
* @param head
* @param to_delete
*/
void LinkListRemove(LinkNode** head, LinkType to_delete);

/**
* @brief ָ��ֵ������Ԫ�ض�ɾ��.
*
* @param head
* @param value
*/
void LinkListRemoveAll(LinkNode** head, LinkType value);

/**
* @brief �ж�����Ϊ��
*
* @return ����Ϊ��, ����1, ���򷵻�0
*/
int LinkListEmpty(LinkNode* head);

/**
* @brief �������Ԫ�ظ���
*
* @param head
*
* @return
*/
size_t LinkListSize(LinkNode* head);

/**
* @brief �����ӡ������.
*
* @param head
*/
void LinkListReversePrint(LinkNode* head);

/**
* @brief �������������, �� pos֮ǰ����
*
* @param head
* @param pos
* @param value
*/
void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value);

LinkNode* JosephCycle(LinkNode* head, size_t food);

void LinklistDestroy(LinkNode* delete);