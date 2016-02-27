//PROBLEM : See PDF of same name.
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int main()
{
    int n=0,i=1,sum=0;
    cin>>n;
    int *arr1 = new int[n+1];
    int *arr2 = new int[n+1];
    arr1[0]=0;
    arr2[0]=0;
    for(i=1;i<n+1;i++)
    {
            cin>>arr1[i];
            arr2[i]=arr1[i];
    }
    for(i=2;i<=(n/2);i++)
    {
            if(arr1[i-1]%2==0&&arr1[i+1]%2==0)
            {
                       if(arr1[i]<((arr1[i-1]+arr1[i+1])/2))
                                 arr1[i]=(arr1[i-1]+arr1[i+1])/2;
            }
            if(arr2[i-1]%2==0&&arr2[i+1]%2==0)
            {
                       if(arr2[i]>((arr2[i-1]+arr2[i+1])/2))
                                 arr2[i]=(arr2[i-1]+arr2[i+1])/2;
            }
    }
    for(i=(n/2)+1;i<n;i++)
    {
            if(arr1[i-1]%2==0&&arr1[i+1]%2==0)
            {
                       if(arr1[i]>((arr1[i-1]+arr1[i+1])/2))
                                 arr1[i]=(arr1[i-1]+arr1[i+1])/2;
            }
            if(arr2[i-1]%2==0&&arr2[i+1]%2==0)
            {
                       if(arr2[i]<((arr2[i-1]+arr2[i+1])/2))
                                 arr2[i]=(arr2[i-1]+arr2[i+1])/2;
            }
    }
    for(i=1;i<=n/2;i++)
    {
            if(abs(arr1[i]-arr1[n-i+1])>abs(arr2[i]-arr2[n-i+1]))
                       sum+=abs(arr1[i]-arr1[n-i+1]);
            else
                       sum+=abs(arr2[i]-arr2[n-i+1]);
    }
    cout<<sum;
    return 0;
}
