#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int BOOK;

typedef struct node {
    BOOK data;
    struct node* next;
}Node;

Node* InitList()
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    return list;
}

void ListInsertTail(Node* list, BOOK book)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book;
    newNode->next = NULL;
    Node* node = list;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newNode;
}

void ListNode(Node* list)
{
    Node* node = list->next;
    while (node != NULL)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int FindList(Node* list, int k)
{
    Node* p = list;
    Node* q = list;
    int i = 0;
    while (q->next != NULL)
    {
        q = q->next;
        i++;
        if (i > k - 1)
            p = p->next;
    }
    if (i <= k - 1)
        return 0;
    printf("%d", p->data);
    return 1;
}

void VisitFind(Node* list,int n)
{
    int* visit = (int*)malloc((n + 1) * sizeof(int));
    if (visit == NULL)
    {
        printf("内存申请失败\n");
        return;
    }
    for (int i = 0; i < n + 1;i++)
    {
        visit[i] = 0;
    }
    Node* node = list->next;
    Node* p = list;
    while (node != NULL)
    {
        int value = abs(node->data);
        if (visit[value] == 1)
        {
            p->next = node->next;
            free(node);
            node = p->next;
        }
        else
        {
            p = node;
            node = node->next;
            visit[value] = 1;
        }
    }
    free(visit);
}

void TList(Node* list)
{
    Node* p = list->next;
    Node* q = p->next;
    Node* t = NULL;
    p->next = NULL;
    while (q != NULL)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    list->next = p;
}

void SList(Node* list)
{
    Node* p = list->next;
    Node* q = p->next;
    Node* t = list;
    while (q != NULL)
    {
        t = p;
        p = p->next;
        q = q->next->next;
    }
    t->next = p->next;
    free(p);
}

void CList(Node* list)
{
    Node* p = list->next;
    Node* q = p->next;
    Node* t = NULL;
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    Node* p1 = p->next;
    Node* q1 = p1->next;
    p->next = NULL;
    while (q1 != NULL)
    {
        t = q1->next;
        q1->next = p1;
        p1 = q1;
        q1 = t;
    }
    Node* node = list->next;
    Node* t1 = NULL;
    while (p1 != NULL && node != NULL)
    {
        t = node->next;
        t1 = p1->next;
        node->next = p1;
        p1->next = t;
        p1 = t1;
        node = t;
    }


}

void CLList(Node* list)
{
    if (list == NULL || list->next == NULL)
        return;

    // ① 找到前半部分最后一个节点
    Node* p = list;
    Node* q = list->next;

    while (q != NULL && q->next != NULL)
    {
        q = q->next->next;
        p = p->next;
    }
    Node* first = NULL;
    Node* second = p->next;
    p->next = NULL;
    Node* third = NULL;
    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    // ④ 交叉合并
    Node* p1 = list->next;
    Node* q1 = first;
    Node* p2, * q2;

    while (p1 != NULL && q1 != NULL)
    {
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
    if (q1 != NULL)
    {
        p1 = list->next;

        while (p1->next != NULL)
        {
            p1 = p1->next;
        }

        p1->next = q1;
    }
}

void CLLList(Node* list)
{
    if (list == NULL || list->next == NULL)
        return;

    // ① 找到前半部分最后一个节点
    Node* p = list->next;
    Node* q = p->next;

    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }

    // ② 分开前后两部分
    Node* p1 = p->next;
    p->next = NULL;

    // ③ 反转后半部分
    Node* q1 = p1->next;
    Node* t = NULL;

    while (q1 != NULL)
    {
        t = q1->next;
        q1->next = p1;
        p1 = q1;
        q1 = t;
    }

    // ④ 交叉合并
    Node* node = list->next;
    Node* t1 = NULL;

    while (p1 != NULL)
    {
        t = node->next;
        t1 = p1->next;

        node->next = p1;
        p1->next = t;

        node = t;
        p1 = t1;
    }
}

int main()
{
    Node * head = InitList();
    for (int i = 0; i < 5; i++)
    {
        BOOK book;
        scanf("%d", &book);
        ListInsertTail(head, book);
    }
    CLLList(head);
    ListNode(head);
    return 0;
}
