#include<stdio.h>
#define MAXSIZE 8

typedef bool Status;
#define TRUE true
#define FALSE false

typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;


void SelectSort(SqList *L);

void main() {

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
	SelectSort(L);
	for (int i = 0; i < L->length; i++) {
		printf("%d,", L->r[i]);
	}
	getchar();
}

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//                              0 5 3 4 6 2    len = 6
//                              关键在于确认i,j,min到底代表
//								数组中的第几个数字还是数组
//                              下标,这里代表数组中的第几个数字
void SelectSort(SqList *l) {
	int i, j, min;
	for (i = 1; i < l->length; i++) {
		min = i;
		for (j = i; j < l->length; j++) {
			if (l->r[min - 1] > l->r[j])
				min = j+1;
		}
		if (i != min)
			swap(l,i-1,min-1);
	}
}

//                              0 5 3 4 6 2    len = 6
//                              关键在于确认i,j,min到底代表
//								数组中的第几个数字还是数组
//                              下标,这里代表数组下标
void SelectSort1(SqList *l) {
	int i, j, min;
	for (i = 0; i < l->length - 1; i++) {
		min = i;
		for (j = i+1; j < l->length; j++) {
			if (l->r[min] > l->r[j])
				min = j;
		}
		if (i != min) {
			swap(l, i, min);
		}
	}
}