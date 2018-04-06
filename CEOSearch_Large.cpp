#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

struct level
{
	long long int exp;
	long long int num;
};

bool compare(const level &a, const level &b)
{
    return a.exp < b.exp;
}

int main()
{
	int T;
	ifstream in("input.in");
	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	cin >> T;
	for(int a=0; a<T; ++a)
	{
		long long int n, ans;
		cin >> n;
		vector<level> emp;
		for(long long int b=0; b<n; ++b)
		{
			struct level temp;
			cin >> temp.num;
			cin >> temp.exp;
			emp.push_back(temp);
		}
		sort(emp.begin(), emp.end(), compare);
		long long int mngNeeded = 0;
		vector<level>::iterator it = emp.begin();
		mngNeeded = (*it).num;
		++it;
		bool justF = false;
		for(; it!=emp.end(); ++it)
		{
			justF = true;
			long long int temp = ((*it).num * (*it).exp) - mngNeeded; //equal exp case?  - assuming never gonna happen(two different entries with same exp value)
			mngNeeded = (temp<0)?mngNeeded = abs(temp):0;
			mngNeeded += (*it).num;
		}
		--it;
		if(mngNeeded > (*it).exp ) // Conditional Operator?
			ans = mngNeeded;
		else
			ans = (*it).exp + 1;
		cout << "Case #" << a+1 << ": " << ans << endl;
	}
	return 0;
}
