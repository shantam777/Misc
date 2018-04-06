#include<iostream>
#include<fstream>
#include<bitset>
#include<conio.h>
#define MAX 101

using namespace std;

long long colcalc(const long long colsize, long long colnum)
{
	if(colsize == 1)
		return 1;
	else if(colsize == 2)
		return 2;
	bitset<MAX> col;
	long long count=0;
	if(colnum == 1)
	{
		col[0] = true;
		col[1] = true;
	}
	else if(colnum == 2)
		col[0] = true;
	else if(colnum == 3)
		col[1] = true;
	for(long long i=2; i<colsize; ++i)
	{
		if(!col[i-1]||!col[i-2])
			col[i] = true;
	}
	for(long long i=0; i<colsize; ++i)
	{
		if(col[i])
			++count;
	}
	return count;
}

long long seatcalc(long long unit1, long long unit2, long long unit3, long long row)
{
	long long seats = 0, quotient;
	int mod;
	quotient = row/3;
	seats += quotient*(unit1+unit2+unit3);
	mod = row%3;
	if(mod == 1)
		seats+=unit1;
	else if(mod == 2)
		seats+=unit1+unit2;
	return seats;
}

int main()
{
	ifstream in("input.in");
	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	int t;
	cin >> t;
	for(int a=0; a<t; ++a)
	{
		long long row, col, unit1, ans;
		cin >> row >> col;
		if(row>col)
		{
			int temp = col;
			col = row;
			row = temp;
		}
		unit1 = colcalc(col,1);
		if(row<=2)
			ans = row*unit1;
		else
		{
			long long unit2, unit3;
			unit2 = colcalc(col,2);
			unit3 = colcalc(col,3);
			ans = seatcalc(unit1,unit2,unit3,row);
		}
		cout << "Case #" << a+1 << ": " << ans << endl;
	}
	return 0;
}
