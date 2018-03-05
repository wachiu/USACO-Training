/*
ID: wcsiu1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N;
	int S;
	fin>>N>>S;
	S++;
	int countn = 0;
	int current;
	string result;
	int base = 2;
	bool trigger1 = true;
	int trigger2 = 0;
	while(countn != N)
	{
		current = S;
		while(base <= 10)
		{
			while(current != 0)
			{
				result.push_back(current%base);
				current -= current%base;
				current /= base;
			}
			for(int j = 0;j < result.size()/2;j++)
				if(result[j] != result[result.size()-j-1])
					trigger1 = false;
			if(trigger1)
				trigger2++;
			result.erase(0,result.size());
			trigger1 = true;
			base++;
			current = S;
		}
		if(trigger2 >= 2)
			{
				fout<<S<<endl;
				countn++;
			}
		base = 2;
		trigger2 = 0;
		S++;
	}
	return 0;
}