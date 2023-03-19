#include <stdio.h>
#include <stdlib.h>

//双向链表结点的定义
typedef struct dbnode
{
	int data;
	struct dbnode *prio, *next;
}DbNode, linkdblist;

//创建双向链表
DbNode *creatlist(void){

	linkdblist *p, *q, *head;
	q = p = (linkdblist *)malloc(sizeof(linkdblist));
	p->next = NULL;
	head = q;
	p = (linkdblist *)malloc(sizeof(linkdblist));
	scanf("%d", &p->data);
	while (p->data != -1){
		q->next = p;
		p->prio = q;
		q = p;
		p = (linkdblist *)malloc(sizeof(linkdblist));
		scanf("%d", &p->data);
		}
	q->next = NULL;
	return head;
}

//输出双向链表
void print(linkdblist *head){
	linkdblist *p;
	p = head->next;
	if (p == NULL)
	printf("空链表！\n");
	while (p != NULL){
		printf("%d  ", p->data);
		p = p->next;
	}
}

//向双向链表中的第i个位置插入一个结点x
void insertdblist(linkdblist *head, int x, int i){
	linkdblist *p, *q = head;
	if (i == 1)
		q = head;
	else{
		q = q->next;
		int c = 1;
	while ((c<i - 1) && (q != NULL)){
		q = q->next;
		c++;
		}
	}
	if (q != NULL && q->next != NULL){
		p = (linkdblist *)malloc(sizeof(linkdblist));
		p->data = x;
		p->prio = q;
		p->next = q->next;
		q->next = p;
		q->next->prio = p;
		} else
			printf("找不到插入的位置！");
			}

//删除双向链表中指定位置上的一个结点
void deletelinkdblist(linkdblist *head, int i){
	linkdblist *p, *q = head;
	if (i == 1)
		q = head;
		else{
			q = q->next;
			int c = 1;
		while (c < i - 1 && q != NULL){
			q = q->next;
			c++;
		}
	}
	if (q != NULL && q->next != NULL){
		p = q->next;
		p->prio = q;
		p->prio->next = p->next;
		p->next->prio = p->prio;
		free(p);
	} else if (q->next == NULL){
		p = q;
		p->prio->next = NULL;
		free(p);
		}else
			printf("没有找到待删除的结点");
		}

//双向链表的主函数
void main(){
	linkdblist *head;
	head = creatlist();	
	print(head);		
	printf("\n\n====向双向链表的某位置插入一个值====\n");
	int num, i;
	printf("输入插入的位置：");
	scanf("%d", &i);
	printf("\n输入插入的值：");
	scanf("%d", &num);
	insertdblist(head, num, i);
	print(head);
	printf("\n");
	printf("\n\n====删除双向链表的某位置上的一个值====\n");
	int j;
	printf("输入删除的位置："); 
	scanf("%d", &j);
	deletelinkdblist(head, j);
	print(head);
	system("pause");
	printf("\n");
}
