#include<stdio.h>

#define MAXVEX 100
#define INFINITE 65535
#define TRUE 1;
#define FALSE 0;

typedef char VertexType;					/* 顶点类型 */
typedef int EdgeType;						/* 边上的权值 */

typedef struct
{
	VertexType vexs[MAXVEX];				/* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];			/* 邻接矩阵，可看做边表，这里是《矩阵表示边》*/
	int numVertexes, numEdges;				/* 图中的顶点数和边数 */
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
	for (int i = 0; i < G->numVertexes; i++)
	{
		scanf_s(&G->vexs[i]);
	}
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numEdges; j++)
		{
			G->arc[i][j] = INFINITE;		/* 邻接矩阵初始化 */
		}
	}
	for (int k = 0; k < G->numEdges; k++)
	{
		printf("输入边（vi,vj）上的下标i，下标j和权w：\n");
		scanf_s("%d,%d,%d", &i, &j, &w);			/* 输入边的上下标和权值 */
		G->arc[i][j] = w;
		G->arc[j][i] = w;					/* 无向图矩阵倒置 */
	}
}

/* 图的遍历 */
typedef int Boolean;
Boolean visited[MAXVEX];

/* 邻接矩阵的深度递归算法 */
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