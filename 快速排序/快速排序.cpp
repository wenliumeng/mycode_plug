#include<stdio.h>

typedef struct {
	int r[10] = {0,50,10,90,30,70,40,80,60,20};
	int length = 9;
} SqList;

void QuickSort(SqList *l);
void QSort(SqList *l,int low,int high);
int Gotomid(SqList *l, int low, int high);
void swap(SqList *l, int i, int j);

void main() {
	SqList *l = new SqList();
	for (int i = 0; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	printf("\n");
	QuickSort(l);
	for (int i = 0; i <= l->length; i++)
	{
		printf("%d,", l->r[i]);
	}
	getchar();
}

void QuickSort(SqList *l) {
	QSort(l, 1, l->length);
}

void QSort(SqList *l, int low, int high) {
	int gotomid = 0;
	if (low < high) {
		gotomid = Gotomid(l, low, high);
		QSort(l, low, gotomid - 1);
		QSort(l, gotomid + 1, high);
	}
}

int Gotomid(SqList *l, int low, int high) {
	int key = l->r[low];
	while (low < high)
	{
		while (low < high && l->r[high] >= key)
			high--;
		swap(l, low, high);
		while (low < high && l->r[low] <= key)
			low++;
		swap(l, low, high);
	}
	return low;
}