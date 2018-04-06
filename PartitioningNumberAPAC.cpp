#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
unsigned long long xcount;
int memo[MAX];

void partition(unsigned long long bVal, unsigned long long leftOver, unsigned long long initVal)
{
	if(memo[leftOver]!=0)
	{
		xcount+=memo[leftOver];
		return;
	}
	if(bVal > leftOver && leftOver != 0)
		return;
	if(leftOver == 0)
	{
		++xcount;
		memo[initVal] = xcount; //??
		return;
	}
	if(bVal <= leftOver)
		partition(bVal, leftOver-bVal, initVal);
	if(bVal + 1 <= leftOver && ((bVal+1)-initVal) <= 2)
		partition(bVal+1, leftOver-(bVal+1), initVal);
	if(bVal + 2 <= leftOver && ((bVal+2)-initVal) <= 2)
		partition(bVal+2, leftOver-(bVal+2), initVal);
}

inline unsigned long long positive_modulo(unsigned long long i, unsigned long long n) {
    return (i % n + n) % n;
}

int main()
{
	fstream input, output;
	int T;
	input.open("input.in", std::ios::in);
	output.open("output.out", std::ios::out);
	input >> T;
	for(int z=0; z<T; ++z)
	{
		unsigned long long n,d;
		xcount = 0;
		input >> n >> d;
		for(unsigned long long i=0; i<=n; ++i)
			memo[i] = 0;
		for(unsigned long long i=1; i<=n; ++i)
		{
			//if(i%d == 0) //big mod? no...fast mod!
			if(positive_modulo(i,d) == 0)
			{
				partition(i, n-i, i);
			}
		}
		cout << "Case #" << z+1 << ": " << xcount << endl;
	}
	return 0;
}
