#include<stdio.h>
#define MAXSIZE 8

typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void InsertSort(SqList *L);
void ShellSort(SqList *L);
void main() {

	SqList* l = new SqList;
	l->r[0] = { 0 };
	l->r[1] = { 9 };
	l->r[2] = { 1 };
	l->r[3] = { 5 };
	l->r[4] = { 8 };
	l->r[5] = { 3 };
	l->r[6] = { 7 };
	l->r[7] = { 4 };
	l->r[8] = { 6 };
	l->r[9] = { 2 };
	l->length = 10;

	SqList* L = new SqList;
	L->r[0] = {0};
	L->r[1] = {5};
	L->r[2] = {3};
	L->r[3] = {4};
	L->r[4] = {6};
	L->r[5] = {2};
	L->length = 6;

	for (int i = 0; i < L->length; i++) {
		printf("%d,", L->r[i]);
	}
	printf("\n");
	//InsertSort(L);
	ShellSort(L);
	for (int i = 0; i < L->length; i++) {
		printf("%d,", L->r[i]);
	}
	getchar();
}

//直接插入
void InsertSort(SqList *L) {
	int i, j;
	for (i = 2; i < L->length; i++) {
		
		if (L->r[i] < L->r[i - 1])
		{
			L->r[0] = L->r[i];
			for (j = i - 1; L->r[j]>L->r[0]; j--)
				L->r[j + 1] = L->r[j];
			L->r[j + 1] = L->r[0];
		}

		for (int k = 0; k < L->length; k++) {
			printf("%d,",L->r[k]);
		}
		printf("\n");
	}
}

//掌握第二个循环一定是j--，因为是从右往左逐次移动
//0 4 3 2 1
//0 3 4 2 1 
//len = 4
/*
void insertSort(SqLists *l) {
	for (int i = 0; i < l->len-1;i++) {
		if (l->l[i+2] < l->l[i+1]) {
			l->l[0] = l->l[i + 2];
			int j;
			for (j = i;l->l[j+1] > l->l[0] ;j--) {
				l->l[j + 2] = l->l[j + 1];
			}
			l->l[j + 2] = l->l[0];
		}
	}
}
*/

void ShellSort(SqList *L) {
	int i, j;
	int increment = L->length;
	do {
		increment = increment / 3 + 1;
		for (i = increment + 1; i < L->length; i++) {
			if (L->r[i] < L->r[i - increment]) {
				L->r[0] = L->r[i];
				for (j = i - increment; L->r[j] > L->r[0] && j>0; j = j - increment) {
					L->r[j + increment] = L->r[j];
				}
				L->r[j + increment] = L->r[0];
			}
		}
	} while (increment > 1);
}
