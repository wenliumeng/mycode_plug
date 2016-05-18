#include<stdio.h>
#include<malloc.h>
typedef char VertexType;        //顶点类型
typedef int EdgeType;           //边上的权值
#define MAXVEX 100
#define INFINITY 65535

typedef struct EdgeNode {       //边表节点
	int adjvex;                 //邻接点域，存储该顶点对应的下标
	EdgeType wight;			    //储存权值
	struct EdgeNode *next;      //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode       //顶点表结点
{
	VertexType data;
	EdgeNode *firstnode;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;             //表顶点
	int numVertexes, numEdges;   //图中当前顶点数和边数
}GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("请输入顶点数和边数：\n");
	scanf_s("%d,%d",&G->numVertexes,&G->numEdges);
	for (i = 0; i < G->numVertexes; i++) {
		scanf(&G->adjList[i].data);                 //输入顶点信息
		G->adjList[i].firstnode = NULL;
	}

	for (k = 0; k < G->numEdges; k++) {
		printf("输入边（vi,vj）上的顶点序号：\n");
		scanf_s("%d,%d",&i,&j);
		/* 头插法开始 */
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex = j;
		e->next = G->adjList[i].firstnode;
		G->adjList[i].firstnode = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));

		e->adjvex = i;
		e->next = G->adjList[i].firstnode;
		G->adjList[j].firstnode = e;
		/* 头插法结束 */
	}
}
