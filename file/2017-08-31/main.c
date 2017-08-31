//
//  main.c
//  ReverseList
//
//  Created by liuyuning on 2017/8/31.
//  Copyright © 2017年 liuyuning. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

//循环反转，逐个遍历；也相当于把链表的各个节点插入到头部
Node *reverseList1(Node *pHead) {
    if (NULL == pHead) {//也可以提前判断next是否为空
        return NULL;
    }
    
    Node *p1 = pHead;
    Node *p2 = pHead->next;
    Node *p3 = NULL;
    pHead->next = NULL;
    
    while (p2) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    
    return p1;
}

//递归反转，逐个赋值，最后返回尾节点
Node *reverseList2(Node *pHead) {
    if (NULL == pHead) {
        return NULL;
    }
    
    if (NULL == pHead->next) {//最后一个节点
        return pHead;
    }
    
    Node *p1 = reverseList2(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;
    return p1;
}

//利用数组反转，占用额外内存，内存分配可能失败，用realloc可以循环两次完成
Node *reverseList3(Node *pHead) {
    if (NULL == pHead) {
        return NULL;
    }
    
    Node *p1 = pHead;
    int count = 0;
    while (p1) {
        count ++;
        p1 = p1->next;
    }
    
    Node **list = (Node **)malloc(count * sizeof(Node *));
    if (list) {
        p1 = pHead;
        for (int i = count - 1; i >= 0; i--) {
            *(list + i) = p1;
            p1 = p1->next;
        }
        
        for (int i = 0; i < count; i++) {
            if (1 == count - i) {
                (*(list + i))->next = NULL;
            } else {
                (*(list + i))->next = *(list + i + 1);
            }
        }
        p1 = *list;
        free(list);
        return p1;
    }
    return NULL;
}

//打印链表
void printList(Node *pHead) {
    while (pHead) {
        printf("node:%d\n",pHead->data);
        pHead = pHead->next;
    }
}

//创建链表，需调用freeList释放
Node *createList(int count) {
    Node *pHead = NULL;
    Node *pCur = NULL;
    
    for (int i = 1; i <= count;  i++) {
        Node *pNode = malloc(sizeof(Node));
        if (NULL == pNode) {
            break;
        }
        pNode->data = i;
        pNode->next = NULL;
        
        if (NULL == pHead) {
            pHead = pNode;
        }
        if (pCur) {
            pCur->next = pNode;
        }
        pCur = pNode;
    }
    return pHead;
}

//释放链表
void freeList(Node *pHead) {
    if (pHead) {
        freeList(pHead->next);
        printf("free node:%d\n", pHead->data);
        free(pHead);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    printf("\n--create--\n");
    Node *pHead = createList(5);
    printList(pHead);
    
    printf("\n--reverseList1--\n");
    pHead = reverseList1(pHead);
    printList(pHead);
    
    printf("\n--reverseList2--\n");
    pHead = reverseList2(pHead);
    printList(pHead);
    
    printf("\n--reverseList3--\n");
    pHead = reverseList3(pHead);
    printList(pHead);
    
    printf("\n--free--\n");
    freeList(pHead);
    
    return 0;
}
