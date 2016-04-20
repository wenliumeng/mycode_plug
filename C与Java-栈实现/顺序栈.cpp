#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
//不能加冒号
#define MAXSIZE 1024

typedef struct
{
	char data[MAXSIZE];
	int top;
}SequenceStack;

//初始化栈
SequenceStack *Init_SeqStack()
{
	SequenceStack *s;
	s = (SequenceStack*)malloc(sizeof(SequenceStack));
	//获取指针指向复杂类型的目标成员
	s->top = -1; return s;
}

//判断空栈
int isEmpty(SequenceStack *s)
{
	if (s->top == -1) return 1;
	else return 0;
}

//入栈
int push(SequenceStack *s, char x)
{
	if (s->top == MAXSIZE - 1) return 0; /*栈满不能入栈*/
	else {
		(s->top)++;
		s->data[s->top] = x;
		return 1;
	}
}

//出栈
int pop(SequenceStack *s, char *x)
{
	if (isEmpty(s)) return 0;//栈为空不出栈
	else {
		*x = s->data[s->top];
		s->top--; return 1;
	}
}

//取栈顶元素
char peek(SequenceStack *s)
{
	if (isEmpty(s)) return 0; /*栈空*/
	else return (s->data[s->top]);
}