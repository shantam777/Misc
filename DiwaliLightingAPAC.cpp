#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
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
		string pattern;
		unsigned long long i, j;
		input >> pattern;
		input >> i >> j;
		unsigned long long startIndex = (i-1)%pattern.length(), bCount = 0, refCount = 0, bUnit = 0, endUnit, startUnit, units, endIndex = (j-1)%pattern.length();
		for(unsigned long long x = startIndex; x < pattern.length(); ++x)
		{
			++refCount;
			if(pattern.at(x)=='B')
				++bCount;
		}
		for(unsigned long long x=0; x<pattern.length(); ++x)
		{
			if(pattern.at(x)=='B')
				++bUnit;
		}
		startUnit = (i-1)/pattern.length();
		endUnit = (j-1)/pattern.length();
		units = endUnit - startUnit - 1;
		bCount = bCount + bUnit*units;
		for(unsigned long long x = 0; x <= endIndex; ++x)
		{
			if(pattern.at(x)=='B')
				++bCount;
		}
		cout << "Case #" << z+1 << ": " << bCount << endl;
	}
	return 0;
}
