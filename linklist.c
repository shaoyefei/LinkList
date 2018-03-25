#include "linklist.h"

LinkNode* CreatNode(LinkType value){
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node ->data = value;
    new_node ->next = NULL;
    return new_node;
}

void DestoryNode(LinkNode* node){
    free(node);
}

void LinkListInit(LinkNode** head){
    if(head == NULL){
       //非法输入
        return;
    }
    *head = NULL;       
}

void LinkListDestroy(LinkNode** head){
    if(head == NULL){
        //非法输入
        return;
    }
    while(*head != NULL){
    LinkNode* cur = *head;
    *head = cur->next;
    DestoryNode(cur);
    }
    head = NULL;
    return;
}

LinkNode* LinkListPushBack(LinkNode** head, LinkType value){
    if(head == NULL){
        //非法输入
        return NULL;
    }
    if(*head == NULL){
        LinkNode* new_node = CreatNode(value);
        (*head) = new_node;
        return new_node;
    } 
    LinkNode* cur = *head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    LinkNode* new_node = CreatNode(value);
    cur->next = new_node;
    return new_node;
}

void LinkListPopBack(LinkNode** head){
    if(head == NULL){
        //非法输入
        return;
    }
    if(*head == NULL){
        //空链表
        return;   
    }
    LinkNode* cur = *head;
    if(cur->next==NULL){
        (*head) = NULL;
        DestoryNode(cur);
        return;
        //cur = NULL;
    }
    while(cur->next->next!=NULL){
        cur = cur->next;
    }
    LinkNode* to_delete = cur->next;
    DestoryNode(to_delete);
    cur->next = NULL;

}

void LinkListPushFront(LinkNode** head, LinkType value){
    if(head == NULL){
        //非法输入
        return;
    }
//    if(*head == NULL){
//        LinkListPushBack(head,value);       
//    }
//    if(*head == NULL){
//        LinkNode* new_node = CreatNode(value);
//        (*head) = new_node;
//    }
    LinkNode* new_node =  CreatNode(value);
    LinkNode* cur = *head;
    *head = new_node;
    new_node->next = cur;

}

void LinkListPopFront(LinkNode** head){
    if(head == NULL){
        //非法输入
        return;
    }
    if(*head == NULL){
        return;
    }
    LinkNode* cur = *head;
    *head = cur->next;
    DestoryNode(cur);
}

LinkNode* LinkListFind(LinkNode* head, LinkType to_find){
    if(head == NULL){
        //非法输入
        return NULL;
    }
    LinkNode* cur = head;
    while(cur != NULL){
        if(cur->data == to_find){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        LinkListPushBack(head,value);
        return;
    }
    if(pos == *head){
        LinkListPushFront(head,value);
        return;
    }
    LinkNode* cur = *head;
    while(cur->next != NULL){
        if(cur->next == pos){
        LinkNode* new_node = CreatNode(value);
        new_node->next = cur->next;
        cur->next = new_node;
        return;
    }
        cur = cur->next;
    }
}

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        LinkListPushBack(head,value);
        return;
    }
    LinkNode* new_node = CreatNode(value);
    new_node->next = pos->next;
    pos->next = new_node;
    return;
}

void LinkListErase(LinkNode** head, LinkNode* pos){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        return;
    }
    if(pos == *head){
        LinkNode* cur = *head;
        *head = cur->next;
        DestoryNode(cur);
        return;
    }
    LinkNode* cur = *head;
    while(cur != NULL){
        if(cur->next == pos){
            cur->next = pos->next;
            DestoryNode(pos);
            return;
        }
        cur = cur->next;
    }
}

void LinkListErase2(LinkNode** head, LinkNode** pos){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        return;
    }
    if((*pos)->next == NULL){
        LinkListErase(head,*pos);
        return;
    }
    LinkNode* cur = (*pos);
    (*pos)->data = cur->data;
    (*pos)->next = cur->next;
    DestoryNode(cur);
    return;
}

void LinkListRemove(LinkNode** head, LinkType to_delete){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        return;
    }
   LinkNode* pre = *head;
//   if(pre->next == NULL){
//       if(pre->data == to_delete){
//           *head = NULL;
//           DestoryNode(pre);
//           return;
//       }
//   }
   if(pre->next == NULL){
       if(pre->data == to_delete){
           *head = NULL;
           DestoryNode(pre);
           return;
       }
   }
    if((*head)->data == to_delete){    
       LinkNode* cur = *head;
       *head = cur->next;
       DestoryNode(cur);
       return;}
   while(pre != NULL){
       if(pre->next->data == to_delete){
           LinkNode* cur = pre->next;
           pre->next = cur->next;
           DestoryNode(cur);
           return;
       }
       pre = pre->next;
   }
}
void LinkListRemoveAll(LinkNode** head, LinkType value){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        return;
    }
        LinkNode* cur = *head;
        if(cur->next == NULL){
            if(cur->data == value){
                *head = NULL;
                DestoryNode(cur);
                return;
            }
        }
        while(1){
            LinkNode* pos = LinkListFind(*head,value);

            if(pos == NULL){
                break;
            }
            LinkListErase(head,pos);
            cur = cur->next;
        }
//    if((*head)->data == value){
//        *head = cur->next;
//        LinkListRemove(head,value);
//    }
//    return;
}

int LinkListEmpty(LinkNode* head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

size_t LinkListSize(LinkNode* head){
    if(head == NULL){
        return (size_t)0;
    }    
    size_t count = 0;
    LinkNode* cur = head;
    while(cur != NULL){
        ++count;
        cur = cur->next;
    }
    return count;
}

void LinkListReversePrint(LinkNode* head){
    if(head == NULL){
        return;
    }
    LinkListReversePrint(head->next);
    printf(" [%c|%p] ",head->data,head);
}

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value){
    if(head == NULL){
        return;
    }
    if(*head == NULL){
        return;
    }
    if(pos == NULL){
        return;
    }
    if(pos == *head){
        LinkListPushFront(head,value);
        return;
    }
    LinkNode* cur = *head;
    for(;cur != NULL;cur = cur->next){
        if(cur->next == pos){
            LinkNode* new_node = CreatNode(value);
            new_node->next = cur->next;
            cur->next = new_node;
            return;
        }
    }
}
LinkNode* LinkListJosephCircle(LinkNode** head,size_t value){
    if(head == NULL){
        //非法输入
        return NULL;
    }
    if(*head == NULL){
        //空链表
        return NULL;
    }
    size_t i = 0;
    LinkNode* cur = *head;
    while(cur->next!=cur){
        for(i=1;i<value;++i){
            cur = cur->next;
        }
            printf("要删除的节点是[%c]\n",cur->data);
            LinkNode* to_delete = cur->next;
            cur->data = to_delete->data;
            cur->next = to_delete->next;
            DestoryNode(to_delete);
    }
    return cur;
}

void LinkListReverse(LinkNode** head){
    if(head == NULL){
        //非法输入
        return;
    }
    if(*head == NULL){
        //空链表
        return;
    }

}

///////////////////////////////////////////////////////////
////以下为测试代码
///////////////////////////////////////////////////////////

#if 1
#include <stdio.h>

#define TEST_HEADER printf("\n------------------%s----------------------\n",__FUNCTION__) 

void PrintLinkListChar(LinkNode* head){
    LinkNode* cur = head;
    for(;cur!=NULL;cur=cur->next){
        printf(" [%c]|[%p] ",cur->data,cur);
    }
    printf("\n");
}

void testInit(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    printf("%p\n",phead);
}

void testPushBack(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    PrintLinkListChar(phead);
}

void testPopBack(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListPopBack(&phead); 
    PrintLinkListChar(phead);
    LinkListPopBack(&phead); 
    PrintLinkListChar(phead);
    LinkListPopBack(&phead); 
    PrintLinkListChar(phead);
    LinkListPopBack(&phead); 
    PrintLinkListChar(phead);
}

void testPushFront(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushFront(&phead,'a');
    LinkListPushFront(&phead,'b');
    LinkListPushFront(&phead,'c');
    LinkListPushFront(&phead,'d');
    PrintLinkListChar(phead);
}

void testPopFront(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushFront(&phead,'a');
    LinkListPushFront(&phead,'b');
    LinkListPushFront(&phead,'c');
    LinkListPushFront(&phead,'d');
    LinkListPopFront(&phead);
    PrintLinkListChar(phead);
    LinkListPopFront(&phead);
    PrintLinkListChar(phead);
    LinkListPopFront(&phead);
    PrintLinkListChar(phead);
    LinkListPopFront(&phead);
    PrintLinkListChar(phead);
    LinkListPopFront(&phead);
    PrintLinkListChar(phead);
}

void testFind(){
    TEST_HEADER;
    LinkNode* phead; 
//    LinkListPushFront(&phead,'a');
//    LinkListPushFront(&phead,'b');
//    LinkListPushFront(&phead,'c');
//    LinkListPushFront(&phead,'d');
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    PrintLinkListChar(phead);
    printf("%p\n",LinkListFind(phead,'a'));
    printf("%p\n",LinkListFind(phead,'b'));
    printf("%p\n",LinkListFind(phead,'c'));
    printf("%p\n",LinkListFind(phead,'d'));

}

void testInsert(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkNode* pos =  LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListInsert(&phead,pos,'x');
    PrintLinkListChar(phead);
}

void testInsertAfter(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
//    LinkListPushBack(&phead,'a');
//    LinkListPushBack(&phead,'b');
//    LinkListPushBack(&phead,'c');
//    LinkNode* pos = LinkListPushBack(&phead,'d');
    LinkListInsertAfter(&phead,phead,'x');
    PrintLinkListChar(phead);
}

void testErase(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkNode* pos = LinkListPushBack(&phead,'d');
    LinkListErase(&phead,pos);
    PrintLinkListChar(phead);

}

void testErase2(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkNode* pos = LinkListPushBack(&phead,'d');
    LinkListErase2(&phead,&pos);
    PrintLinkListChar(phead);
}

void testRemove(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListRemove(&phead,'a');
    LinkListRemove(&phead,'b');
    LinkListRemove(&phead,'c');
    LinkListRemove(&phead,'d');
    PrintLinkListChar(phead);
}

void testRemoveAll(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'a');
    LinkListRemoveAll(&phead,'a');
    PrintLinkListChar(phead);
}

void testEmpty(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'a');
    int ret = LinkListEmpty(phead);
    printf(" [%d] \n",ret);

}

void testSize(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    size_t ret = LinkListSize(phead);
    printf(" [%lu] \n",ret);

}

void testReverse(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkListReversePrint(phead);
    printf("\n");

}

void testInsertBefore(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkNode* pos = LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkNode* pos1 = LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    LinkNode* pos2 = LinkListPushBack(&phead,'e');
    LinkListPushBack(&phead,'f');
    LinkListInsertBefore(&phead,pos,'x');
    LinkListInsertBefore(&phead,pos1,'y');
    LinkListInsertBefore(&phead,pos2,'z');
    PrintLinkListChar(phead);

}

void testDestory(){
    TEST_HEADER;
    LinkNode* phead;
    LinkListInit(&phead);
    LinkListPushBack(&phead,'a');
    LinkListPushBack(&phead,'b');
    LinkListPushBack(&phead,'c');
    LinkListPushBack(&phead,'d');
    printf("After Destroy\n");
    PrintLinkListChar(phead);
    LinkListDestroy(&phead);
    printf("Before Destroy\n");
    PrintLinkListChar(phead);

}

void testJosephCircle(){
//    LinkNode* a = CreatNode('a');
//    LinkNode* b = CreatNode('b');
//    LinkNode* c = CreatNode('c');
//    LinkNode* d = CreatNode('d');
//    LinkNode* e = CreatNode('e');
//    LinkNode* f = CreatNode('f');
//    LinkNode* g = CreatNode('g');
//    LinkNode* h = CreatNode('h');
//    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
//    e->next = f;
//    f->next = g;
//    g->next = h;
//    h->next = a;
//    LinkNode* alive = LinkListJosephCircle(&a,5);
    TEST_HEADER;
    LinkNode* head;
    LinkListInit(&head);
    LinkListPushBack(&head,'a');
    LinkListPushBack(&head,'b');
    LinkListPushBack(&head,'c');
    LinkListPushBack(&head,'d');
    LinkListPushBack(&head,'e');
    LinkListPushBack(&head,'f');
    LinkListPushBack(&head,'g');
    LinkNode* pos =  LinkListPushBack(&head,'h');
    pos->next = head;
    LinkNode* value = LinkListJosephCircle(&head,5);
    printf("幸存者是[%c]\n",value->data);
}

int main(){
    testInit();
    testPushBack();
//    printf("%lu\n",sizeof(LinkNode*));
    testPopBack();
    testPushFront();
    testPopFront();
    testFind();
    testInsert();
    testInsertAfter();
    testErase();
    testErase2();
    testRemove();
    testRemoveAll();
    testEmpty();
    testSize();
    testReverse();
    testInsertBefore();
    testDestory();
    testJosephCircle();
    return 0;
}

#endif
