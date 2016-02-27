//PROBLEM : See PDF of same name.
#include<iostream>
#include<conio.h>
#define MAXVAL 999
#define MAXVER 50
using namespace std;

struct sumn
{
       int valw;
       int adj[MAXVER];
       sumn()
       {
            valw=MAXVAL;
            for(int i=0;i<MAXVER;i++)
                    adj[i]=0;
       }
};

int main()
{
    int vert=0,edge=0,i,k,temp1,temp2,flag1=0,flag2=0,mini,j,l,flag3,flag4;
    cout<<"Enter the number of vertices : ";
    cin>>vert;
    cout<<"Enter the number of edges : ";
    cin>>edge;
    int *iso = new int[vert];
    int *weight = new int[vert];
    int *flag = new int[vert];
    struct sumn *sum = new sumn[vert]();
    for(i=0;i<vert;i++)
    {
            iso[i]=MAXVAL;
            weight[i]=0;
            flag[i]=0;
    }
    for(i=0;i<vert;i++)
    {
            cout<<"Enter the weight of node "<<i+1<<" : ";
            cin>>sum[i].valw;
            iso[i]=sum[i].valw;
            weight[i]=iso[i];
    }
    for(k=0;k<edge;k++)
    {
            flag1=0;
            flag2=0;
            flag4=0;
            cout<<"\nFor edge "<<k+1<<" : \n";
            cout<<"Enter vertex 1 : ";
            cin>>temp1;
            --temp1;
            cout<<"Enter vertex 2 : ";
            cin>>temp2;
            --temp2;
            if(sum[temp1].adj[temp2]==1||sum[temp2].adj[temp1]==1)
            {
                      sum[temp1].adj[temp2]=1;
                      sum[temp2].adj[temp1]=1;
                      flag4=1;
            }
            sum[temp1].adj[temp1]=1;
            sum[temp2].adj[temp2]=1;
            for(i=0;i<vert;i++)
            {
                     if(sum[temp1].adj[i]==1&&i!=temp1)
                            flag1 = 1;
                     if(sum[temp2].adj[i]==1&&i!=temp2)
                            flag2 = 1;
                     if(flag1==1&&flag2==1)
                            break;
            }
            if(flag1==0)
            {
                     sum[temp1].adj[temp2]=1;
                     iso[temp1]=MAXVAL;
            }
            if(flag2==0)
            {
                     sum[temp2].adj[temp1]=1;
                     iso[temp2]=MAXVAL;
            }
            for(i=0;i<vert;i++)
            {
                      for(j=0;j<vert;j++)
                             flag[j]=0;
                      if(sum[temp1].adj[i]==1&&i!=temp2)
                      {
                              for(j=0;j<vert;j++)
                              {
                                      if((sum[temp2].adj[j]==1||sum[temp1].adj[j]==1)&&j!=temp1)
                                      {
                                                 sum[temp1].adj[j]=1;
                                                 sum[temp2].adj[j]=1;
                                      }
                                      if(sum[temp1].adj[j]==1||sum[temp2].adj[j]==1)
                                                 flag[j]=1;
                              }
                              flag3=0;
                              for(j=0;j<vert;j++)
                              {
                                        if(flag3==0)
                                        {
                                                      for(l=0;l<vert;l++)
                                                      {
                                                            weight[l]=sum[l].valw;
                                                      }            
                                        }
                                        if(sum[temp1].adj[j]==1)
                                        {
                                                      if(flag[j]==1)
                                                      {
                                                              if(flag4==1)
                                                                          break;
                                                              if(flag3==0)
                                                              {
                                                                        sum[j].valw+=sum[temp2].valw;
                                                                        sum[temp2].valw=sum[j].valw;
                                                                        flag3=1;
                                                              }
                                                              else
                                                                        sum[j].valw=sum[temp2].valw;
                                                              continue;
                                                      }
                                                      else
                                                      {
                                                              sum[temp2].valw+=sum[j].valw;
                                                              sum[j].valw+=sum[temp2].valw-sum[j].valw;
                                                              sum[temp1]=sum[temp2];
                                                              flag[temp1]=1;
                                                              flag[temp2]=1;
                                                      }
                                        }
                              }
                              break;
                      }
            }    
            cout<<"\n";
            mini=MAXVAL;
            for(i=0;i<vert;i++)
            {
                       if(iso[i]<mini)
                                    mini=iso[i]; 
                       if(sum[i].valw<mini)
                                    mini=sum[i].valw;        
            }
            cout<<"\nMinimum total weight of connected component = "<<mini<<endl;
    }
    getch();
    return 0;    
}
