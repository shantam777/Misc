/*
PROBLEM : Program to check whether any anagram of a given string is a palindrome or not.
*/
#include<iostream>
#include<string>
#include<set>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	multiset<char> ele1,ele2;
	string str,temp1,temp2;
	int flag=0,flag1=0,flag2=0,i;
	cout<<"\nEnter the string : ";
	cin>>str;
	temp1 = str.substr(0, str.length()/2);
    temp2 = str.substr(str.length()/2);
    for(i=0;i<((temp1.length()<temp2.length())?temp2.length():temp1.length());++i)
    {
    	if(i!=temp1.length())
			ele1.insert(temp1.at(i));
		if(i!=temp2.length())
    		ele2.insert(temp2.at(i));
    }
	for(i=0;i!=str.length();++i)
	{
    	multiset<char>::iterator hit1(ele1.find(str.at(i)));
    	if (hit1!= ele1.end())
    	{
    		flag1=1;
		 	ele1.erase(hit1);
		}
    	multiset<char>::iterator hit2(ele2.find(str.at(i)));
		if (hit2!= ele2.end())
		{	
			flag2=1;
		 	ele2.erase(hit2);
		}
		cout<<"\nCenter is "<<str.at(i)<<endl;
		for (multiset<char>::const_iterator j(ele1.begin()), end(ele1.end());
    	j != end;
    	++j)
    	cout << *j << "\n";
    	cout<<"\nOTHER\n";
    	for (multiset<char>::const_iterator k(ele2.begin()), end(ele2.end());
    	 k != end;
    	 ++k)
    	cout << *k << "\n";
		cout<<" BREAK\n\n";			
		if(ele1==ele2)
		{
			flag=1;
			break;
		}
		if(flag1==1)
		{
			ele1.insert(str.at(i));
			flag1=0;
		}
		if(flag2==1)
		{
			ele2.insert(str.at(i));
			flag2=0;
		}
	}
	if(flag==1)
		cout<<"\n\nPalindrome!";
	else
		cout<<"\n\nNot Palindrome!";
	return 0;
}
