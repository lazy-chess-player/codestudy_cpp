#include <iostream>
#include<iomanip>   
using namespace std;
#define MVNum 100        
#define OK 1
#define MAXQSIZE 10000
typedef char VertexType;
typedef int OtherInfo;

/*定义边结点 类型*/
typedef struct EdgeNode
{
	int  adjvex;
	struct EdgeNode* next;
}EdgeNode;

/*定义顶点结点类型*/
typedef struct VNode
{
	VertexType  data;
	EdgeNode* FirstEdge;
}VertexNode;

/*定义邻接表表示的图的数据类型*/
typedef struct
{
	VertexNode  vertices[MVNum];
	int   vexnum, edgenum;
}ALGraph;

typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;

void CreateG(ALGraph& G);
void PrintG(ALGraph G);
int Locate(ALGraph& G, char x);
int FirstAdjVex(ALGraph& G, int v);
int NextAdjVex(ALGraph& G, int v, int w);
void DFS(ALGraph& G, int v);
void BFS(ALGraph& G, int v);
int InitQueue(SqQueue& Q);
int EnQueue(SqQueue& Q, int e);
int DeQueue(SqQueue& Q, int& e);
int QueueEmpty(SqQueue& Q);

static int visited[10]{ 1 };
static SqQueue Queue;

int main()
{
	ALGraph Graph;
	CreateG(Graph);
	PrintG(Graph);

	for (int i = 0; i < Graph.vexnum; i++)
	{
		visited[i] = 0;
	}
	int v = 0;
	cout << "DFS结果：";
	DFS(Graph, v);

	cout << endl;
	for (int i = 0; i < Graph.vexnum; i++)
	{
		visited[i] = 0;
	}

	cout << "BFS结果：";
	BFS(Graph, v);
	cout << endl;

	return 0;
}

///输出图G的邻接表存储结构
void PrintG(ALGraph  G)
{
	EdgeNode* p;
	int i;
	cout << setw(6) << "下标" << setw(6) << " 顶点" << " 邻接点1下标" << " 邻接点2下标" << " 邻接点3下标\n";

	for (i = 0; i < G.vexnum; i++)
	{
		cout << setw(6) << i;
		cout << setw(6) << G.vertices[i].data;

		p = G.vertices[i].FirstEdge;
		while (p)
		{
			cout << setw(7) << "-->" << setw(4) << p->adjvex;
			p = p->next;
		}
		cout << "\n";
	}
}

void CreateG(ALGraph& G)
{
	cout << "请输入顶点个数以及边的个数：" << endl;
	cin >> G.vexnum >> G.edgenum;
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "第" << i + 1 << "个顶点为：";
		cin >> G.vertices[i].data;
		G.vertices[i].FirstEdge = NULL;
	}
	for (int k = 0; k < G.edgenum; k++)
	{
		int i, j, n;
		char v1, v2;
		cout << "第" << k + 1 << "条边为：";
		cin >> v1 >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		struct EdgeNode* p1;
		p1 = new EdgeNode;
		p1->adjvex = j;
		p1->next = G.vertices[i].FirstEdge;
		G.vertices[i].FirstEdge = p1;

		struct EdgeNode* p2;
		p2 = new EdgeNode;
		p2->adjvex = i;
		p2->next = G.vertices[j].FirstEdge;
		G.vertices[j].FirstEdge = p2;
	}
}

void DFS(ALGraph& G, int v)
{
	cout << v << " ";
	visited[v] = 1;
	int w;
	for (w = FirstAdjVex(G, v); w >= 0&&w<G.vexnum; w = NextAdjVex(G, v, w))
	{
		if (!visited[w]) 
			DFS(G, w);
	}
}

int Locate(ALGraph& G, char x)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == x) return i;
	}
}

int FirstAdjVex(ALGraph& G, int v)
{
	if (G.vertices[v].FirstEdge)
	{
		return G.vertices[v].FirstEdge->adjvex;
	}
	return -1;
}

int NextAdjVex(ALGraph& G, int v, int w)
{
	struct EdgeNode* p;
	p = G.vertices[v].FirstEdge;
	while (p && p->adjvex != w)
	{
		p = p->next;
	}
	if (p == NULL) 
		return -1;
	if (p->next != NULL)
		return p->next->adjvex;
	return -1;
}

void BFS(ALGraph& G, int v)
{
	int u, w;
	cout << v << " ";
	visited[v] = 1;
	InitQueue(Queue);
	EnQueue(Queue, v);
	while (QueueEmpty(Queue))
	{
		DeQueue(Queue, u);
		for (w = FirstAdjVex(G, u); w >= 0 && w < G.vexnum; w = NextAdjVex(G, v, w))
			if (!visited[w])
			{
				cout << w << " ";
				visited[w] = 1;
				EnQueue(Queue, w);
			}
	}
}

int InitQueue(SqQueue& Q)
{
	Q.base = new int[MAXQSIZE];
	if (!Q.base) exit(-1);
	Q.front = Q.rear = 0;
	return OK;
}

int EnQueue(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return 1;
}

int DeQueue(SqQueue& Q, int& e)
{
	if (Q.front == Q.rear) return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

int QueueEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear) return 0;
	else return 1;
}



