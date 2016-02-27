//PROBLEM : See PDF of same name.
#include<iostream>
#include<algorithm>
#include<functional>  

#define MAX 99
using namespace std;

int globalpath[MAX];
int index=0;
int tempval;


struct Node
{
	int val;
	int path[];
	int k;
	Node operator=(const Node& b)
    {
        Node temp;
        temp.val = b.val;
        temp.k = b.k;
        copy(b.path,b.path+k,temp.path);
        return temp;
    }
};


int payday(int pathcount,int n,int patharr[][MAX],int amount[],int k,int mul)
{
	int valarr[pathcount][n-1];
	int posarr[pathcount][n-1];
	int negarr[pathcount][n-1];
	int posindex[pathcount];
	int negindex[pathcount];
	int karr[k];
	int combarr[pathcount];
	int sizea[pathcount];
	int maxarr[pathcount];
	int i,j,temp,tempindex,m,o,tempk,flag,l;
	for(i=0;i<pathcount;i++)
	{
		sizea[i]=0;
		maxarr[i]=0;
		combarr[i]=0;
		posindex[i]=0;
		negindex[i]=0;
	}
	for(i=0;i<pathcount;i++)
	{
		for(j=0;patharr[i][j]!=-1;j++)
		{
			valarr[i][j]=amount[patharr[i][j]];
			sizea[i]++;
		}
	}
	for(i=0;i<pathcount;i++)
	{
		for(j=0;j<sizea[i];j++)
		{
			if(valarr[i][j]>=0)
				posarr[i][posindex[i]++]=valarr[i][j];
			else
				negarr[i][negindex[i]++]=valarr[i][j];	
		}
		sort(negarr[i], negarr[i] + negindex[i]);
		sort(posarr[i], posarr[i] + posindex[i],greater<int>());
	}
	for(i=0;i<pathcount;i++)
	{
		tempk=k;
		j=0;
		l=0;
		while(tempk>0)
		{
			while(j<posindex[i]&&tempk>0)
			{
					combarr[i]+=posarr[i][j++]*mul;
					tempk--;
			}
			tempk--;
		}
		while(j<posindex[i])
			combarr[i]+=posarr[i][j++];
		while(l<negindex[i])
			combarr[i]+=negarr[i][l++];
	}
	int max=combarr[0];
	for(i=1;i<pathcount;i++)
	{
		if(combarr[i]>max)
			max=combarr[i];
	}
	return max;
}


Node* maxcollect(int curval,int n,int start,int edge[][2],int amount[],int k,int pathc[])
{
	int i,flag=0,j=0,maxv,l=0,m=0;
	int *valarr = new int[n-1];
	struct Node *node = new Node();
	struct Node *temp = new Node();
	pathc[k++]=start;
	curval+=amount[start];
	for(i=0;i<n;i++)
	{
		if(edge[i][0]==start)
		{
			pathc[k++]=start;
			flag=1;
			temp=maxcollect(curval,n,edge[i][1],edge,amount,k,pathc);
			valarr[j]=temp->val;
			k=temp->k;
			j++;
		}
	}
	if(flag==0)
	{
		valarr[j++]=curval;
		copy(pathc,pathc+k,node->path);
		globalpath[index++]=tempval;
		for(i=0;i<k;i++)
			globalpath[index++]=pathc[i];
		globalpath[index++]=-1;
		k=0;
	}	
	maxv=0;
	for(i=1;i<j;i++)
	{
		if(valarr[i]>valarr[maxv])
		        maxv=i;
	}
	node->val = valarr[maxv];
	node->k=k;
	return node;
}

int main()
{
	int n,m,k,i,count=0,j,flag=0,pathcount=0,z=0,q,qindex,l,max[2];
	cin>>n;
    cin>>m;
    cin>>k;
    try
    {
		
		int *amount = new int[n];
    	int *pathc = new int[n-1];
    	int edge[n-1][2];
		struct Node *pathval = new Node[n-1];
		struct Node *temp = new Node;
    	for(i=0;i<n;i++)
    	        cin>>amount[i];                        
    	for(i=0;i<n-1;i++)
    	{
    		cin>>edge[i][0];
    		cin>>edge[i][1];
    	}
    	for(i=0;i<n;i++)
    	{
    		tempval=i;
    		temp=maxcollect(0,n,i,edge,amount,0,pathc);
    		pathval[count].val=temp->val;
    		pathval[count].k=temp->k;
    		copy(temp->path,temp->path+temp->k,pathval[count].path);
    		count++;
    	}
    	do
    	{
    		for(i=0;i<index;i++)
    		{
    			flag=0;
				if(globalpath[i]==globalpath[i+1])
    			{
    				for(j=i+1;j<index-1;j++)
    					globalpath[j]=globalpath[j+1];
    				flag=1;
    				index--;
    			}
    		}
    	}while(flag==1);
    	for(i=0;i<index;i++)
		{
			if(globalpath[i]==-1)
				pathcount++;
		}
		globalpath[++index]=-1;
		pathcount++;
		int patharr[pathcount*100][MAX];
		for(i=0;i<pathcount;i++)
		{
			for(j=0;globalpath[z]!=-1;j++)
				patharr[i][j]=globalpath[z++];
			patharr[i][j]=globalpath[z++];
		}
		int pathcountr = pathcount;
		for(i=0;i<pathcountr;i++)
		{
			for(j=0;patharr[i][j+1]!=-1;j++)
			{
				for(l=j+1;patharr[i][l]!=-1;++l)
				{
					qindex=0;
					for(q=j;q<=l;q++)
						patharr[pathcount][qindex++]=patharr[i][q];
					patharr[pathcount][qindex]=-1;
					pathcount++;
				}
			}
		}		
    	max[0]=payday(pathcount,n,patharr,amount,k,m);
    	max[1]=payday(pathcountr,n,patharr,amount,k,m);
    	cout<<((max[0]>max[1])?max[0]:max[1])<<endl;
	}
	catch (bad_alloc&)
	{
		cout << "Error allocating memory!" << endl;
	}
    return 0;    
}


