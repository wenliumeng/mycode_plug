#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
//不能加冒号
#define MAXSIZE 1024

typedef struct
{
	char data[MAXSIZE];
	int top;
}SeqStack;

//初始化栈
SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	//获取指针指向复杂类型的目标成员
	s->top = -1; return s;
}

//判断空栈
int Empty_SeqStack(SeqStack *s)
{
	if (s->top == -1) return 1;
	else return 0;
}

//入栈
int Push_SeqStack(SeqStack *s, char x)
{
	if (s->top == MAXSIZE - 1) return 0; /*栈满不能入栈*/
	else {
		(s->top)++;
		s->data[s->top] = x;
		return 1;
	}
}

//出栈
int Pop_SeqStack(SeqStack *s, char *x) 
{
	if (Empty_SeqStack(s)) return 0;//栈为空不出栈
	else {
		*x = s->data[s->top];
		s->top--; return 1;
	}
}

//取栈顶元素
char Top_SeqStack(SeqStack *s)
{
	if (Empty_SeqStack(s)) return 0; /*栈空*/
	else return (s->data[s->top]);
}