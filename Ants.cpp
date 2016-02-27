//PROBLEM : See PDF of same name.
#include<iostream>
#include<math.h>
using namespace std;

int ways(int n)
{
	int total_ways = 0;
    if (n==1)
        return 1;
    for(int i=1;i<=n;i++)
    {
		if (i==1||i==n)
    	{
            total_ways+=ways(n - 1);
            total_ways+=2;
    	}
        else
        {
            total_ways+=ways(i - 1);
            total_ways+=ways(n - i);
            total_ways++;
    	}
	}
    return total_ways;
}

int main()
{
	int input,n;
    double wj,wa,w;
	cin>>input;
	for(int i=0;i<input;i++)
	{
		cin>>n;
		wa=pow(2,n-1);
		wj=ways(n);
		w=wj-wa;
		cout<<fmod(w,(pow(10,9)+7))<<endl;
	}
	return 0;
}
