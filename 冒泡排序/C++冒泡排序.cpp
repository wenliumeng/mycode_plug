#include<stdio.h>
#define MAXSIZE 10

typedef bool Status;
#define TRUE true
#define FALSE false

typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void BubbleSort(SqList *L);
void BubbleSort1(SqList *L);
void main() {
	SqList* l = new SqList;
	SqList L1 = { 9,1,5,8,3,7,4,6,2,NULL,NULL,9};
	SqList *l2 = &L1;
	printf("%d", l2->r[3]);
	l->r[1] = { 9 };
	l->r[2] = { 1 };
	l->r[3] = { 5 };
	l->r[4] = { 8 };
	l->r[5] = { 3 };
	l->r[6] = { 7 };
	l->r[7] = { 4 };
	l->r[8] = { 6 };
	l->r[9] = { 2 };
	l->length = 9;
	/*for (int i = 1; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	printf("\n");
	BubbleSort1(l);
	for (int i = 1; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}*/
	getchar();
}

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSort(SqList *L) {
	int i, j;
	Status flag = TRUE;
	for (i = 1; i < L->length && flag; i++) {
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--) {
			if (L->r[j] > L->r[j + 1]) {
				swap(L, j, j + 1);
				flag = TRUE;
			}
		}
	}
}

void BubbleSort1(SqList *L) {
	int flag = 1;
	for (int i = 1; i < L->length; i++) {
		flag = flag + 1;
		for (int j = 1; j <= L->length - i; j++) {
			if (L->r[j] > L->r[j + 1]) {
				swap(L, j, j + 1);
			}
			if (flag == 344) {
				for (int k = 1; k <= L->length; k++) {
					printf("%d,", L->r[k]);
				}
				printf("\n");
			}
		}
	}
}