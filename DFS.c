#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode *next;
}ArcNode;
typedef struct VertexNode
{
	char vexdata;
	ArcNode *head;
}VertexNode;
typedef struct 
{
	VertexNode vertex[MAXSIZE];
	int vexnum;
	int arcsnum;
}AdjList;

//
void Creat(AdjList *g)
{
	int i,adjvex,weight,vexnum;
	ArcNode *p;
	printf("please input vexnum:");
	scanf("%d",&g->vexnum);
	for(i=1;i<=g->vexnum;i++)
	{
		printf("please input No.%d vex:",i);
		getchar();
		scanf("%c",&g->vertex[i].vexdata);
		g->vertex[i].head=NULL;
		printf("please input adjvex,weight");
		scanf("%d%d",&adjvex,&weight);
		while(adjvex!=0)
		{
			p=(ArcNode *)malloc(sizeof(ArcNode));
			p->adjvex=adjvex;
			p->weight=weight;
			p->next=g->vertex[i].head;
			g->vertex[i].head=p;
			printf("please input adjvex,weight");
			scanf("%d%d",&adjvex,&weight);
		}
	}
 } 

 int visited[MAXSIZE];
 void visit(AdjList g,int v0)
 {
 	printf("%c",g.vertex[v0].vexdata);
 }
 

 int FirstVex(AdjList g,int v0)
 {
 	ArcNode *p;
 	int i; 
 	p=g.vertex[v0].head;
 	if(p!=NULL)
 		return p->adjvex;
 	else
	 	return -1; 
  } 
  

  int NextVex(AdjList g,int v0,int w)
  {
  	ArcNode *p=g.vertex[w].head;
  	p=p->next;
  	if(p!=NULL && !visited[w])
  		return p->adjvex;
  	else
  		return -1;
   } 
 

 void DFS(AdjList g,int v0)
 {
 	int w;
 	visit(g,v0);
 	visited[v0]=1;
 	w=FirstVex(g,v0);
 	while(w!=-1)
 	{
 		if(!visited[w])	
 			DFS(g,w);
 		w=NextVex(g,v0,w);
	}
  } 
  //深度优先搜索遍历图
  void TraverseG(AdjList g)
  {
  	int v;
  	for(v=1;v<=MAXSIZE;v++)
		visited[v]=0;
		
  	for(v=1;v<=g.vexnum;v++)
  		if(visited[v]==0)
		  	DFS(g,v);
   } 
   
 int main(void)
 {
 	AdjList g;
 	int i;
 	Creat(&g);
 	for(i=1;i<=g.vexnum;i++)
 	{
 		ArcNode *p= g.vertex[i].head;
 		printf("%c\t",g.vertex[i].vexdata);
		while(p!=NULL)
		{
 			printf("%d\t%d\t",p->adjvex,p->weight);
			p=p->next; 
		}
		printf("\n");	 
	}

	TraverseG(g);
 	return 0;
 }
