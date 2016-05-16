#define MAXSIZE 5
#define OK 1
#define ERROR 0
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

typedef int QElemType;

typedef int Statue;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct LinkQueue {
	QueuePtr front, rear;
}LinkQueue;

//Èë¶Ó²Ù×÷
Statue EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

//³ö¶Ó²Ù×÷
Statue OuQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
