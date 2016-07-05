#include <stdio.h>

#define MAX 10

typedef struct
{
	int r[10];
	int length = 10;
}SqList;

void MergeSort(SqList *l);
void MSort(int SR[], int TR1[], int s, int len);
void Merge(int SR[], int TR[], int i, int m, int n);

void main() {
	SqList* l = new SqList;
	l->r[0] = { 0 };
	l->r[1] = { 5 };
	l->r[2] = { 1 };
	l->r[3] = { 9 };
	l->r[4] = { 3 };
	l->r[5] = { 7 };
	l->r[6] = { 4 };
	l->r[7] = { 8 };
	l->r[8] = { 6 };
	l->r[9] = { 2 };
	l->length = MAX;
	for (int i = 0; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	printf("\n");
	MergeSort(l);
	for (int i = 0; i <= l->length; i++) {
		printf("%d,", l->r[i]);
	}
	getchar();
}

void MergeSort(SqList *l) {
	MSort(l->r, l->r, 1, l->length);
}

//length = 10
//0 5 1 9 3 7 4 8 6 2
void MSort(int SR[], int TR1[], int s, int len) {
	int m;
	int TR2[MAX + 1];
	if (s == len)
		TR1[s] = SR[s];
	else {
		m = (s + len) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, len);
		Merge(TR2, TR1, s, m, len);
	}
}

//将SR[i,m]和TR[m+1,n]归并为有序的TR[i,n]
void Merge(int SR[], int TR[], int i, int m, int n) {
	SR[i, m];
	TR[m + 1, n];
	int j, k, l;
	for (j = m + 1, k = i; i <= m&&j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m) {
		for (l = 0; l <= m - i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}

}
