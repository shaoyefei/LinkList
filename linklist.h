
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef char LinkType;

typedef struct LinkNode {
    LinkType data;
    struct LinkNode* next;
} LinkNode;


//约瑟夫环
LinkNode* LinkListJosephCircle(LinkNode** head,size_t value);

//销毁链表
void LinkListDestroy(LinkNode** head);
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
LinkNode* LinkListPushBack(LinkNode** head, LinkType value);

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

void LinkListErase2(LinkNode** head, LinkNode** pos);

/**
* @brief 删除指定值的元素
*
* @param head
* @param to_delete
*/
void LinkListRemove(LinkNode** head, LinkType to_delete);




/**
* @brief 指定值的所有元素都删掉.
*
* @param head
* @param value
*/
void LinkListRemoveAll(LinkNode** head, LinkType value);

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
void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value);//cur->next = pos;if(phead == NULL)return; if (pos ==NULL)return;if(*phead == pos)头结点插入，调用头插Linknode* cur = phead; for(;cur!=NULL;cur=cur->next)if(cur->next=pos)

/**
* @brief 单链表逆置
*
* @param head
*/
void LinkListReverse(LinkNode** head);
void LinkListReverse2(LinkNode** head);
//LinkNode* JosephCycle(LinkNode* head, size_t food);
