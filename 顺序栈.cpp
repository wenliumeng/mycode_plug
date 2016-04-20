#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
//���ܼ�ð��
#define MAXSIZE 1024

typedef struct
{
	char data[MAXSIZE];
	int top;
}SeqStack;

//��ʼ��ջ
SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	//��ȡָ��ָ�������͵�Ŀ���Ա
	s->top = -1; return s;
}

//�жϿ�ջ
int Empty_SeqStack(SeqStack *s)
{
	if (s->top == -1) return 1;
	else return 0;
}

//��ջ
int Push_SeqStack(SeqStack *s, char x)
{
	if (s->top == MAXSIZE - 1) return 0; /*ջ��������ջ*/
	else {
		(s->top)++;
		s->data[s->top] = x;
		return 1;
	}
}

//��ջ
int Pop_SeqStack(SeqStack *s, char *x) 
{
	if (Empty_SeqStack(s)) return 0;//ջΪ�ղ���ջ
	else {
		*x = s->data[s->top];
		s->top--; return 1;
	}
}

//ȡջ��Ԫ��
char Top_SeqStack(SeqStack *s)
{
	if (Empty_SeqStack(s)) return 0; /*ջ��*/
	else return (s->data[s->top]);
}