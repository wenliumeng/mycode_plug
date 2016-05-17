#include<stdio.h>
#include<malloc.h>
typedef char VertexType;        //��������
typedef int EdgeType;           //���ϵ�Ȩֵ
#define MAXVEX 100
#define INFINITY 65535

typedef struct VertexNode       //�������
{
	VertexType data;
	EdgeNode *firstnode;
}VertexNode, AdjList[MAXVEX];

typedef struct EdgeNode {       //�߱�ڵ�
	int adjvex;                 //�ڽӵ��򣬴洢�ö����Ӧ���±�
	EdgeType wight;			    //����Ȩֵ
	struct EdgeNode *next;      //����ָ����һ���ڽӵ�
}EdgeNode;

typedef struct
{
	AdjList adjList;             //����
	int numVertexes, numEdges;   //ͼ�е�ǰ�������ͱ���
}GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("�����붥�����ͱ�����\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for (i = 0; i < G->numVertexes; i++) {
		scanf(&G->adjList[i].data);                 //���붥����Ϣ
		G->adjList[i].firstnode = NULL;
	}

	for (k = 0; k < G->numEdges; k++) {
		printf("����ߣ�vi,vj���ϵĶ�����ţ�\n");
		scanf("%d,%d",&i,&j);
		/* ͷ�巨��ʼ */
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex = j;
		e->next = G->adjList[i].firstnode;
		G->adjList[i].firstnode = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));

		e->adjvex = i;
		e->next = G->adjList[i].firstnode;
		G->adjList[j].firstnode = e;
		/* ͷ�巨���� */
	}
}