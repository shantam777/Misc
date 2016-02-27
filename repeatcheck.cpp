/*
PROBLEM : Check whether a given string is composed of repeating units or not.
*/
#include<iostream>
#include<string>

using namespace std;

bool repeatcheck(string str)
{
	int mid = str.length()/2;
	string str1,str2;
	int beg2,end1;
	if(mid==0)
		return true;
	else if(mid==1)
		return (str.at(0)==str.at(1))?true:false;
	else
	{
		if(str.length()%2!=0)
		{
			end1=mid+1;
			beg2=mid;
		}
		else
		{
			end1=mid;
			beg2=mid;
		}
		while(end1<str.length()&&beg2>=0)
		{
			str1 = str.substr(0,end1);
			str2 = str.substr(beg2,(str.length()-beg2));
			cout<<endl<<str1<<endl<<str2<<endl;
			if(str1.compare(str2)==0)
				return true;
			--beg2;
			++end1;
		}
		return false;
	}
}

int main()
{
	string str;
	bool result;
	cin>>str;
	result=repeatcheck(str);
	cout<<"\nResult "<<(result?"true":"false")<<endl;
	return 0;
}
