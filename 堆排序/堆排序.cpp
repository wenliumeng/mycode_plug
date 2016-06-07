#include<stdio.h>

typedef struct
{
	int r[10];
	int length;
}SqList;


void HeapAdjust(SqList *L, int s, int m);
void swap(SqList *L, int i, int j);
/* 已知L->[s]不满足推排序的定义，除此之外全部满足 */
void HeapSort(SqList *L) {
	int i;
	for (i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);

	for (i = L->length; i > 2; i--) {
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}

//构建大顶堆,s:第一个非叶子节点，m:长度
void HeapAdjust(SqList *L, int s, int m) {
	int temp, j;
	temp = L->r[s];

	for (j = s * 2; j < m; j *= 2) {
		if (j < m && L->r[j] < L->r[j+1])
			++j;
		if (temp >= L->r[j])
			break;
		L->r[s] = L->r[j];
		s=j;
	}
	L->r[s] = temp;
}

void main() {
	SqList* l = new SqList;
	l->r[0] = { 00 };
	l->r[1] = { 50 };
	l->r[2] = { 10 };
	l->r[3] = { 90 };
	l->r[4] = { 30 };
	l->r[5] = { 70 };
	l->r[6] = { 40 };
	l->r[7] = { 80 };
	l->r[8] = { 60 };
	l->r[9] = { 20 };
	l->length = 9;

	for (int i = 0; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	printf("\n");
	HeapSort(l);
	for (int i = 0; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	getchar();

}