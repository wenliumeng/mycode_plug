#include<stdio.h>
#define MAXSIZE 8

typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void InsertSort(SqList *L);

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
	InsertSort(L);
	for (int i = 0; i < L->length; i++) {
		printf("%d,", L->r[i]);
	}
	getchar();
}

//≤Â»Î≈≈–Ú
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