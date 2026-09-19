#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义了一个结构体类型名称为BOOK（相当于int、char等）

typedef int BOOK;

typedef struct node{
    BOOK data;
    struct node *next;
}Node;

//初始化，带有了头结点

Node* InitList()
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    return list;
}

//初始化，不带有头结点

Node* InitList1(BOOK book)
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    list->data = book;
    return list;
}

//遍历

void ListNode(Node* list)
{
    Node* node = list->next;
    while (node != NULL)
    {
        printf("%d\n", node->data);
        node = node->next;
    }
}

//头插法（我们会发现如果有头结点的话不需要考虑链表里面到底有没有东西）

void ListInsertHead(Node* list, BOOK book)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book;
    newNode->next = list->next;
    list->next = newNode;
}

//尾插法（list还是那个头结点，然后需要一个临时节点来推）

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

//指定位置插入

void ListInsert(Node* list, int pos, BOOK book)
{
    if (pos <= 0)
    {
        printf("插入位置错误");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book;
    Node* node = list;
    for (int i = 1; i < pos; i++)
    {
        node = node->next;
        if (node == NULL)
        {
            printf("插入位置错误");
            return;
        }
    }
    newNode->next = node->next;
    node->next = newNode;
}

//指定位置删除

void ListDelete(Node* list, int pos)
{
    if (pos <= 0)
    {
        printf("删除位置错误");
        return;
    }
    Node* node = list;
    for (int i = 1; i < pos; i++)
    {
        if (node->next == NULL)
        {
            printf("删除位置错误");
            return;
        }
        node = node->next;
    }
    Node* temp = node->next;
    node->next = node->next->next;
    free(temp);
}

int main()
{
    Node* head = InitList();
    for (int i = 0; i < 5; i++)
    {
        BOOK book;
        scanf("%d", &book);
        ListInsertTail(head, book);
    }
    ListDelete(head, 3);
    ListNode(head);
    return 0;
}
