/*
PROBLEM : Same as that of Googol_Rec.cpp, except here I try to generate complete Sgoogol and output it to a file for lookup lol. Just for fun, only suitable for small inputs :P
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

typedef unsigned long long LLD;

using namespace std;

string switchz(string str){
		for(LLD i=0;i!=str.length();++i){
			if(str.at(i)=='0')
				str[i]='1';
			else
				str[i]='0';
	}
	return str;	
}

string gengoogol(){
	string base = "";
	string revbase;
	string final;
	try{
		for(LLD i=0; final.length()<=(pow(10,18)+1); ++i){
			revbase = base;
			reverse(revbase.begin(), revbase.end());
			final = base + "0" + switchz(revbase);
			base = final;
		}
	}
	catch (const std::bad_alloc&) {
  		return final;
  	}
	return final;
}



int main(){
	int T;
	unsigned long k[100];
	string str;
	char *endptr;
	char ch;
	if (!ifstream("googol.txt")){
		string googol = gengoogol();
		ofstream out("googol.txt");
    	out << googol;
    	out.close();
	}
	ifstream inpin("0.in");
	ofstream op("0x.out");
	getline(inpin,str);
	T = atoi (str.c_str());
	for(int i=0;i!=T;++i){
		ifstream fin("googol.txt");
		getline(inpin,str);
		k[i]=strtoull(str.c_str(), &endptr, 0);
		fin.seekg(k[i]-1,ios::beg);
		fin.get(ch);
		op<<"Case #"<<i+1<<": "<<ch<<endl;
		fin.close();
	}
	inpin.close();
	op.close();
	return 0;
}
