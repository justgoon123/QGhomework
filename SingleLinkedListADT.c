#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node{
	char name[20];//���� 
	int number;//ѧ�� 
	struct node *next;//next��������ָ�򱾽ṹ���������͵�ָ������ 
}Node,*LinkList;
 
//������ĳ�ʼ�������Ǵ���һ��ͷ���  
LinkList InitList()
{
	LinkList head;//����ͷָ����� 
	head = (Node*)malloc(sizeof(Node));//ͷָ��ָ������ͷ����ڴ�ռ� 
	head->next=NULL;//ͷָ��ָ����Ϊ�� 
	return head;//����ͷ����ַ����ͷָ�� 
}
 
//β�巨���������� 
void CreatByRear(LinkList head)
{
	Node *r,*s;//sָ���´����Ľ�� 
	char name[20];
	int number;
	r = head;//rָ��ͷ��� ������ǰ�������β��� 
	printf ("������ѧ��ѧ�ź�������\n");
	while(1)
	{
		scanf ("%d",&number);
		scanf ("%s",name);
		if (number==0)
		break;
		s = (Node*)malloc(sizeof(Node));//��������ڴ�ռ� ����sָ���·�����ڴ� 
		//�ֱ�ֵ������ѧ�� 
		strcpy(s->name ,name);
		s->number = number;
		r->next = s;//ԭ���Ľ��ָ���½�� 
		r = s;//rָ���½�� 
	}
	r->next = NULL;//�����β���ָ��Ϊ�� 
}
 
//ͷ�巨����������
void CreatByHead(LinkList head)
{
	Node *s;
	char name[20];
	int number;
	printf ("������ѧ��ѧ�ź�������\n");
	while(1)
	{
		scanf ("%d",&number);
		scanf ("%s",name);
		if (number==0)
		break;
		s = (Node*)malloc(sizeof(Node));
		strcpy(s->name ,name);
		s->number = number;
		s->next = head->next ;//�½��ָ��ԭ������Ԫ��� 
		head->next = s;//�����ͷ���ָ���½�� 
	}
	
} 
//������ı���
void OutPut(LinkList head)
{
	Node *p;//ѭ�����õ���ʱָ�� 
	p = head->next ;//pָ���������Ԫ��� 
	while (p)
	{
		printf ("ѧ��:%d\n",p->number);//���ѧ�� 
		printf ("����:%s\n",p->name);//������� 
		p = p->next; //�ƶ���ʱָ�뵽��һ����� 
	}  	
} 
int main (void)
{
	LinkList ha,hb;//���嵥����ͷָ�� 
	ha = InitList();//��ʼ�������� 
	CreatByRear(ha);//β�巨���������� 
	OutPut(ha);//��������� 
	hb = InitList();
	CreatByHead(hb);
	OutPut(hb);
		
	return 0;
}
