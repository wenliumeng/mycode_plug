#include<stdio.h>

typedef struct {
	int l[9] = {5,1,9,3,7,4,8,6,2};
	int len = 9;
} SqLists;

void selectSort(SqLists *l);
void swap(SqLists *l, int i, int j);
void swap(SqLists *l, int i, int j) {
	int temp = l->l[i];
	l->l[i] = l->l[j];
	l->l[j] = temp;
}


void main() {
	SqLists *l = new SqLists();
	for (int i = 0; i < l->len; i++)
	{
		printf("%d,", l->l[i]);
	}
	printf("\n");
	selectSort(l);
	for (int i = 0; i < l->len; i++)
	{
		printf("%d,", l->l[i]);
	}
	printf("\n");
	getchar();
}

// 4 3 2 1
void selectSort(SqLists *l) {
	for (int i = 0; i < l->len;i++) {
		int max = 0;
		int j;
		for (j = 0; j < l->len - i-1;j++) {
			if (l->l[max] < l->l[j+1])
				max = j+1;
		}
		swap(l, max, j + 1);
	}
}

