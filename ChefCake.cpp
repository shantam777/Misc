/*The Chef always makes perfect cakes and is known for the same. Its Christmas time and the Chef is asked to deliver a cake to all the houses. The Chef is given a sample cake (which is imperfect since the Chef hasn't baked it himself). When the Chef is done making all the cakes, he asks his subordinate the pack them all in boxes while he rests for sometime. When the Chef returns and counts the boxes, there is 1 extra. His worst fear comes true when he can't find the sample cake anywhere.

He wants to find out which of the boxes contains the imperfect cake. He asks his subordinate to fix the issue he has created. But the subordinate is also in Christmas mood, and leaves after making a few comparisons.

The Chef finds a sheet of paper with the comparisons, and needs your help to figure out the box with the imperfect cake.

The boxes are marked 1 to N, and the comparisons are between weights of equal number of cakes. For example:

Weight of (Cake #1 + Cake #2 + Cake #3) > Weight of (Cake #4 + Cake #5 + Cake #6)
Weight of (Cake #2 + Cake #4 + Cake #6) = Weight of (Cake #1 + Cake #3 + Cake #5)
Weight of (Cake #1 + Cake #5) < Weight of (Cake #2 + Cake #3)
*/

#include <iostream>
#define MAX 99999

using namespace std;

int findImperfectCake(int N, int M, int numBoxesCompared[100], int boxesLeft[100][1000], int boxesRight[100][1000], char compRes[100])
{
	int check[MAX], res;
	bool flag = false;
	for(int i=0; i<=MAX; ++i)
		check[i]=0;
	for(int i=0; i<M; ++i)
	{
		if(compRes[i] == '>')
		{
			for(int j=0; j<N; ++j)
			{
				check[boxesLeft[i][j]]  -= 1;
				check[boxesRight[i][j]]  -= 1;
			}
		}
		else if(compRes[i] == '<')
		{
			for(int j=0; j<N; ++j)
			{
				check[boxesLeft[i][j]]  += 1;
				check[boxesRight[i][j]]  += 1;
			}
		}
	}
	for(int i=0; i<M; ++i)
	{
		if(compRes[i] == '=')
		{
			for(int j=0; j<N; ++j)
			{
				check[boxesLeft[i][j]] = 0;
				check[boxesRight[i][j]]  = 0;
			}
		}
	}
	for(int i=1; i<=N; ++i)
	{
		if(check[i] != 0)
		{
			if(flag)
			{
				res = 0;
				break;
			}
			else
			{
				res = i;
				flag = true;
			}
		}
	}
	cout << res << endl;
	return 0;
}

int main()
{
	int t, n, m;
	cin >> t;
	for(int z=0; z<t; ++z)
	{
		int numBoxesCompared[100], boxesLeft[100][1000], boxesRight[100][1000];
		char compRes[100];
		cin >> n >> m;
		for(int i=0; i<m; ++i)
		{
			cin >> numBoxesCompared[i];
			for(int j=0; j<numBoxesCompared[i]; ++j)
				cin >> boxesLeft[i][j];
			for(int j=0; j<numBoxesCompared[i]; ++j)
				cin >> boxesRight[i][j];
			cin >> compRes[i];
		}
		findImperfectCake(n, m, numBoxesCompared, boxesLeft, boxesRight, compRes);
	}
	return 0;
}
