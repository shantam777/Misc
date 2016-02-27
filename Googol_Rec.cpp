/*
Problem :

A "0/1 string" is a string in which every character is either 0 or 1. There are two operations that can be performed on a 0/1 string:

switch: Every 0 becomes 1 and every 1 becomes 0. For example, "100" becomes "011".
reverse: The string is reversed. For example, "100" becomes "001".
Consider this infinite sequence of 0/1 strings:

S0 = ""

S1 = "0"

S2 = "001"

S3 = "0010011"

S4 = "001001100011011"

...

SN = SN-1 + "0" + switch(reverse(SN-1)).

You need to figure out the Kth character of Sgoogol, where googol = 10100.

Input :

The first line of the input gives the number of test cases, T. Each of the next T lines contains a number K.

Output :

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the Kth character of Sgoogol.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>

typedef unsigned long long LLD;

using namespace std;

int getDigit(LLD pos,int n,bool neg)
{
	if(n==1)
		return (neg==false)?0:1;
	else
	{
		if(pos==pow(2,n-1))
			return (neg==false)?0:1;
		else if(pos<pow(2,n-1))
			return getDigit(pos,n-1,neg);
		else
			return getDigit(pow(2,n)-pos,n-1,!neg);
	}
}

int main(){
	int T;
	LLD n,k;
	string str;
	char *endptr;
	int ch;
	ifstream inpin("0.in");
	ofstream op("0z.out");
	getline(inpin,str);
	T = atoi (str.c_str());
	for(int i=0;i!=T;++i){
		getline(inpin,str);
		k=strtoull(str.c_str(), &endptr, 0);
		n=ceil(log(k+1)/log(2));
		ch=getDigit(k,n,false);
		op<<"Case #"<<i+1<<": "<<ch<<endl;
	}
	inpin.close();
	op.close();
	return 0;
}
