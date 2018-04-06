#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 99999
using namespace std;
unsigned long long L=0, M=0, minv;

struct Band
{
	unsigned long long index;
	unsigned long long length;
	unsigned long long cost;
};

void knapsack(struct Band rubber[], unsigned long long currLen, unsigned long long cost, unsigned long long items, unsigned long long selected)
{
	if(currLen == L && cost <= M)
	{
		if(cost < minv)
			minv = cost;
		return;
	}
	if(items == 0 || currLen > L || cost > M)
		return;
	knapsack(rubber, currLen, cost, items-1, selected);
	unsigned long long bit = (selected >> rubber[items].index) & 1;
	if(bit == 0)
	{
		selected |= 1 << rubber[items].index;
		knapsack(rubber, currLen + rubber[items].length, cost + rubber[items].cost, items-1, selected);
	}
}

int main()
{
	fstream output;
	int T;
	ifstream in ("input.in");
  	streambuf * cinbuf = std::cin.rdbuf();
  	cin.rdbuf( in .rdbuf());
	output.open("output.out", std::ios::out);
	cin >> T;
	for(int z=0; z<T; ++z)
	{
		unsigned long long n = 0;
		cin >> n >> M >> L;
		unsigned long long min[n], max[n], price[n];
		unsigned long long arrSize = 0;
		for(unsigned long long i = 0; i<n; ++i)
		{
			cin >> min[i] >> max[i] >> price[i];
			arrSize += max[i] - min[i] + 1;
		}
		struct Band *rubber = new struct Band[arrSize];
		unsigned long long tr = 0;
		for(unsigned long long i=0; i<n; ++i)
		{
			unsigned long long range = max[i] - min[i];
			for(unsigned long long j=0; j<=range; ++j)
			{
				rubber[tr].index = i;
				rubber[tr].length = min[i] + j;
				rubber[tr++].cost = price[i];
			}
		}
		minv = MAX;
		knapsack(rubber, 0, 0, tr-1, 0);
		if(minv==MAX)
			cout << "Case #" << z+1 << ": " << "IMPOSSIBLE" << endl;
		else
			cout << "Case #" << z+1 << ": " << minv << endl;
	}
	return 0;
}
