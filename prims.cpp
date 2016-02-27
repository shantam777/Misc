/*
PROBLEM : Prim's Algorithm. 
*/
#include<iostream>
#include<conio.h>
#include<limits.h>

using namespace std;

int** graph;
int VERT;

int check(int vis[])
{
	for(int i=0;i<VERT;i++)
	{
		if(vis[i]==-1)
			return 0;
	}
	return 1;	
}

void prims()
{
	int cost=0,i,j,vis[VERT],select,min;
	for(i=0;i<VERT;i++)
		vis[i]=-1;
	
	vis[0]=1;
	i=0;
	min=INT_MAX;
	select=-1;
	while(!check(vis))
	{
		if(i==VERT)
		{
			if(select!=-1)
			{
				cout<<"\nVertex selected : "<<select+1<<"\nCost being added : "<<min<<endl;
				vis[select]=1;
				cost+=min;
			}
			min=INT_MAX;
			select=-1;
			i=0;
		}
		if(vis[i]==-1)
		{
			i++;
			continue;
		}
		for(j=0;j<VERT;j++)
		{
			if(graph[i][j]<min&&i!=j&&graph[i][j]!=-1&&graph[i][j]!=-2&&vis[j]==-1)
			{
				min=graph[i][j];
				select=j;
			}
		}
		i++;
	}
	cout<<"\nCost of MST : "<<cost;
}

int main()
{
	int i,j;
	char ch;
	cout<<"\t\tPRIM'S ALGORITHM\n\n\n\n";
	cout<<"Enter the number of vertices : ";
	cin>>VERT;
	graph = new int*[VERT];
	for(i=0;i<VERT;i++)
      graph[i] = new int[VERT];
	for(i=0;i<VERT;i++)
	{
		for(j=0;j<VERT;j++)
			graph[i][j]=-1;
	}
	for(i=0;i<VERT;i++)
	{
		for(j=0;j<VERT;j++)
		{
			if(i==j)
			{
				graph[i][j]=0;
				continue;
			}
			if(graph[j][i]!=-1)
				continue;
			cout<<"Is vertex "<<i+1<<" connected to vertex "<<j+1<<" ? (Y for yes)\n";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<"Enter weight : ";
				cin>>graph[i][j];
				graph[j][i]=graph[i][j];
			}
			else
				graph[i][j]=graph[j][i]=-2;
		}
	}
	cout<<"\n\nApplying Prim's Algorithm : \n\n";
	prims();
	getch();
	return 0;
}
