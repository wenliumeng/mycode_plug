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
