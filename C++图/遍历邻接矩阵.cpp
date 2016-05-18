#include<stdio.h>

#define MAXVEX 100
#define INFINITE 65535
#define TRUE 1;
#define FALSE 0;

typedef char VertexType;					/* �������� */
typedef int EdgeType;						/* ���ϵ�Ȩֵ */

typedef struct
{
	VertexType vexs[MAXVEX];				/* ����� */
	EdgeType arc[MAXVEX][MAXVEX];			/* �ڽӾ��󣬿ɿ����߱������ǡ������ʾ�ߡ�*/
	int numVertexes, numEdges;				/* ͼ�еĶ������ͱ��� */
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("�����붥�����ͱ�����\n");
	scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
	for (int i = 0; i < G->numVertexes; i++)
	{
		scanf_s(&G->vexs[i]);
	}
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numEdges; j++)
		{
			G->arc[i][j] = INFINITE;		/* �ڽӾ����ʼ�� */
		}
	}
	for (int k = 0; k < G->numEdges; k++)
	{
		printf("����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw��\n");
		scanf_s("%d,%d,%d", &i, &j, &w);			/* ����ߵ����±��Ȩֵ */
		G->arc[i][j] = w;
		G->arc[j][i] = w;					/* ����ͼ������ */
	}
}

/* ͼ�ı��� */
typedef int Boolean;
Boolean visited[MAXVEX];

/* �ڽӾ������ȵݹ��㷨 */
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);
	}
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	for (i = 0; i < G.numVertexes; i++)
		if (!visited[i])
			DFS(G,i);
}