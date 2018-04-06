#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#define MAX 99999
using namespace std;

int main()
{
	fstream input, output;
	int T;
	input.open("input.in", std::ios::in);
	output.open("output.out", std::ios::out);
	input >> T;
	for(int z=0; z<T; ++z)
	{
		unsigned long long n;
		input >> n;
		for(unsigned long long i=2; i<n; ++i)
		{
			vector<unsigned long long> digits;
			unsigned long long num = n;
			while(num != 0)
			{
				unsigned long long temp = num/i;
				digits.push_back(num%i);
				num = temp;
			}
			int flag = 0;
			for(vector<unsigned long long>::iterator it = digits.begin(); it!=digits.end(); ++it)
			{
				if((*it) != 1)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				output << "Case #" << z+1 << ": " << i << endl;
				break;
			}
		}
	}
}
