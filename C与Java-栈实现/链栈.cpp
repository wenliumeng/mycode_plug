#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *next;
}StackNode,*LinkStack;

LinkStack Init_Stack() {
	return NULL;
}

int Empty_LinkStack(LinkStack top) {
	return top == NULL;
}

LinkStack Push_LinkStack(LinkStack top, char x)
{
	StackNode *s;
	s = (LinkStack)malloc(sizeof(StackNode));
	s->data = x;
	s->next = top;
	top = s;
	return top;
}

LinkStack Pop_LinkStack(LinkStack top, char *x)
{
	StackNode *p;
	if (top == NULL) return NULL;
	else {
		*x = top->data;
		p = top;
		top = top->next;
		free(p);
		return top;
	}
}