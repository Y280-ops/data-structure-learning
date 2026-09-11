#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//定义了一个结构体类型名称为BOOK（相当于int、char等）

typedef struct {
	int isbn;
	char bookName[20];
	double price;
}BOOK;

typedef struct {
	BOOK data[100];
	int length;
}SeqList;

//初始化

void InitList(SeqList* list)
{
	list->length = 0;
}

//插入

void InsertList(SeqList* list, int location, BOOK book)
{
	if (list->length >= 100)
	{
		printf("溢出，无效");
		return;
	}
	if ((location - list->length) > 1)
	{
		printf("顺序表不能跳位，请重新输入插入位置");
		return;
	}
	int t = list->length;
	while (t >= location)
	{
		list->data[t] = list->data[t - 1];
		t--;
	}
	list->data[location - 1] = book;
	list->length++;
}

//删除

void DeleteList(SeqList* list, int location)
{
	if (list->length == 0)
	{
		printf("无数据，删除无效");
		return;
	}
	if (location <= 0 || location > list->length)
	{
		printf("此处无数据，请重新输入删除位置");
		return;
	}
	int t = location - 1;
	list->length--;
	while (t < list->length)
	{
		list->data[t] = list->data[t + 1];
		t++;
	}
}

//查找
int SearchList(SeqList* list, int isbn)
{
	for (int i = 0; i < list->length; i++)
	{
		if (list->data[i].isbn == isbn)
			return i + 1;
	}
	return -1;
}

//修改

void UpdateList(SeqList* list, int location, double price)
{
	if (location <= 0 || location > list->length || list->length == 0)
	{
		printf("数据不存在");
		return;
	}
	list->data[location - 1].price = price;
}

//遍历

void PrintList(SeqList* list)
{
	for (int i = 0; i < list->length; i++)
	{
		printf(" %d |", list->data[i].isbn);
		printf(" %s |", list->data[i].bookName);
		printf(" %.2f |", list->data[i].price);
		printf("\n");
	}
}

int main()
{
	SeqList list = {
		{
			{001, "活着", 40.1},
			{002, "第二性", 50.2},
			{004, "百年孤独", 62.8},
			{005, "算法导论", 31.8}
		},
		4
	};
	BOOK book = { 003, "数据结构", 25.6 };
	InsertList(&list, 3, book);
	DeleteList(&list, 1);
	int location = SearchList(&list, 005);
	printf("查找到的位置：%d\n", location);
	UpdateList(&list, 1, 10.5);
	PrintList(&list);
	return 0;
}