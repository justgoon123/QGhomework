#include <stdio.h>
#include <stdlib.h>

//˫��������Ķ���
typedef struct dbnode
{
	int data;
	struct dbnode *prio, *next;
}DbNode, linkdblist;

//����˫������
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

//���˫������
void print(linkdblist *head){
	linkdblist *p;
	p = head->next;
	if (p == NULL)
	printf("������\n");
	while (p != NULL){
		printf("%d  ", p->data);
		p = p->next;
	}
}

//��˫�������еĵ�i��λ�ò���һ�����x
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
			printf("�Ҳ��������λ�ã�");
			}

//ɾ��˫��������ָ��λ���ϵ�һ�����
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
			printf("û���ҵ���ɾ���Ľ��");
		}

//˫�������������
void main(){
	linkdblist *head;
	head = creatlist();	
	print(head);		
	printf("\n\n====��˫�������ĳλ�ò���һ��ֵ====\n");
	int num, i;
	printf("��������λ�ã�");
	scanf("%d", &i);
	printf("\n��������ֵ��");
	scanf("%d", &num);
	insertdblist(head, num, i);
	print(head);
	printf("\n");
	printf("\n\n====ɾ��˫�������ĳλ���ϵ�һ��ֵ====\n");
	int j;
	printf("����ɾ����λ�ã�"); 
	scanf("%d", &j);
	deletelinkdblist(head, j);
	print(head);
	system("pause");
	printf("\n");
}
