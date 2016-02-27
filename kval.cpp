//PROBLEM : See PDF of same name.
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int n=0,count=0,i=0,lval=0,kval=0;
    cin>>n;
    int *arr = new int[n];
    int *newarr = new int[n];
    for(i=0;i<n;i++)
            cin>>arr[i];
    cin>>lval;
	cin>>kval;
    for(i=0;i<n;i++)
    {
            if(arr[i]>=lval)
                 newarr[count++]=arr[i];                 //Reducing time complexity here at the expense of space complexity. Run two loops instead and dynamically initialize array with size 'count' to save space.
    }
    cout<<newarr[kval-1];
    return 0;    
}
