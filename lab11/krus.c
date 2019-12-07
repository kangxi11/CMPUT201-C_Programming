#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==-1)
				cost[i][j]=999;
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d ", cost[i][j]);
		}
		printf("\n");
	}


	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while (parent[u])
		{
			u = parent[u];
		}
		while (parent[v])
		{
			v = parent[v];
		}

		
		if (u != v)
		{
			parent[v] = u;
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
		}
		cost[a][b]=cost[b][a]=999;
	}
}