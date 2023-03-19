#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node{
	char name[20];//姓名 
	int number;//学号 
	struct node *next;//next的类型是指向本结构体数据类型的指针类型 
}Node,*LinkList;
 
//单链表的初始化：就是创建一个头结点  
LinkList InitList()
{
	LinkList head;//定义头指针变量 
	head = (Node*)malloc(sizeof(Node));//头指针指向分配的头结点内存空间 
	head->next=NULL;//头指针指针域为空 
	return head;//返回头结点地址，即头指针 
}
 
//尾插法创建单链表 
void CreatByRear(LinkList head)
{
	Node *r,*s;//s指向新创建的结点 
	char name[20];
	int number;
	r = head;//r指向头结点 ，即当前单链表的尾结点 
	printf ("请输入学生学号和姓名：\n");
	while(1)
	{
		scanf ("%d",&number);
		scanf ("%s",name);
		if (number==0)
		break;
		s = (Node*)malloc(sizeof(Node));//分配结点的内存空间 ，令s指向新分配的内存 
		//分别赋值姓名和学号 
		strcpy(s->name ,name);
		s->number = number;
		r->next = s;//原来的结点指向新结点 
		r = s;//r指向新结点 
	}
	r->next = NULL;//链表的尾结点指针为空 
}
 
//头插法创建单链表
void CreatByHead(LinkList head)
{
	Node *s;
	char name[20];
	int number;
	printf ("请输入学生学号和姓名：\n");
	while(1)
	{
		scanf ("%d",&number);
		scanf ("%s",name);
		if (number==0)
		break;
		s = (Node*)malloc(sizeof(Node));
		strcpy(s->name ,name);
		s->number = number;
		s->next = head->next ;//新结点指向原来的首元结点 
		head->next = s;//链表的头结点指向新结点 
	}
	
} 
//单链表的遍历
void OutPut(LinkList head)
{
	Node *p;//循环所用的临时指针 
	p = head->next ;//p指向链表的首元结点 
	while (p)
	{
		printf ("学号:%d\n",p->number);//输出学号 
		printf ("姓名:%s\n",p->name);//输出姓名 
		p = p->next; //移动临时指针到下一个结点 
	}  	
} 
int main (void)
{
	LinkList ha,hb;//定义单链表头指针 
	ha = InitList();//初始化单链表 
	CreatByRear(ha);//尾插法创建单链表 
	OutPut(ha);//输出单链表 
	hb = InitList();
	CreatByHead(hb);
	OutPut(hb);
		
	return 0;
}
