#define MAXSIZE 5
#define OK 1
#define ERROR 0
#include<stdio.h>

typedef int QElemType;

typedef int Status;

typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

//��ʼ��һ���ն���
Status InitQueue(SqQueue Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//��ѭ�����еĳ���
int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//��Ӳ���
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

//���Ӳ���
Status OutQueue(SqQueue *Q,QElemType *e)
{
	if (Q->rear == Q->front)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

//int main() {
//	printf("start......\n");
//
//	char *a;
//	char a1 = 'c';
//	a = &a1;
//	printf("%c\n", *a);
//
//	SqQueue *s;
//	SqQueue s1;
//	int d[5] = {99,88,77,66,55};
//	s1 = {d[5],0,0};
//	s = &s1;
//	InitQueue(s);
//	printf("%d",s->front);
//	getchar();
//	return 0;
//}