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

void LinkListErase2(LinkNode** head, LinkNode* pos);

/**
* @brief ɾ��ָ��ֵ��Ԫ��
*
* @param head
* @param to_delete
*/
void LinkListRemove(LinkNode** head, LinkType to_delete);
void LinkListRemove2(LinkNode** head, LinkType to_delete);
/**
* @brief ָ��ֵ������Ԫ�ض�ɾ��.
*
* @param head
* @param value
*/
void LinkListRemoveAll(LinkNode** head, LinkType value);
void LinkListRemoveAll2(LinkNode** head, LinkType value);


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

LinkNode* JosephCycle(LinkNode* head, size_t num);//Լɪ��

void LinklistDestroyNode(LinkNode* delete);//���ٽڵ�

void LinklistDestroy(LinkNode** head);//��������


void LinklistReverse(LinkNode** head);//���õ�����

void LinklistReverse2(LinkNode** head);//���õ�����

void LinklistBubbleSort(LinkNode* head);//������ð������

LinkNode* LinklistMerge(LinkNode* head1, LinkNode* head2);//������������

LinkNode* LinklistFindMiddle(LinkNode* head);//�������м���

LinkNode* LinklistFindLastK(LinkNode* head, size_t k);//�ҵ�����k���ڵ�

void LinklistEraseLastK(LinkNode** head, size_t k);//ɾ��������k���ڵ�

int HaveCycle(LinkNode* head);//�ж��Ƿ��л�

LinkNode* Cycle(LinkNode* head);

size_t CycleLength(LinkNode* head);//�󻷵ĳ���

LinkNode* CycleEntrance(LinkNode* head);//�󻷵����

LinkNode* CycleCross(LinkNode* head1, LinkNode* head2);//

int HaveCrossWithCycle(LinkNode* head1, LinkNode* head2);//�ж����������Ƿ��ཻ

LinkNode* CrossWithCycle(LinkNode* head1, LinkNode* head2);//�󻷵Ľ���

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2);//���������ཻ�����ֵ����

typedef struct ComplexNode
{
	LinkType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;

ComplexNode* ComplexNodeCreate(LinkType value);//������������ڵ�

ComplexNode* CopyComplex(ComplexNode* head);//���Ƹ�������



