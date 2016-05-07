#include<malloc.h>
#include<cstdlib>
#include<time.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}

	if (!p || j > i)
		return ERROR;

	*e = p->data;
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;
	LinkList p,s;
	p = *L;
	while (j < i && p) {
		p = p->next;
		j++;
	}
	if (j > i || !p)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time_t(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

Status CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	r = *L;
	for (i = 0; i < n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

Status ClaerList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}