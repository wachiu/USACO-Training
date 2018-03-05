/*
ID: wcsiu1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int base;
	fin>>base;
	int square;
	int current;
	string result;
	string multiple;
	bool trigger = true;
	for(int i = 1;i <= 300;i++)
	{
		square = i * i;
		current = i;
		while(square != 0)
		{
			result.push_back(square%base);
			square -= square%base;
			square /= base;
		}
		for(int j = 0;j < result.size()/2;j++)
			if(result[j] != result[result.size()-j-1])
				trigger = false;
		if(trigger)
		{
			while(current != 0)
		{
			multiple.push_back(current%base);
			current -= current%base;
			current /= base;
		}
			for(int l = multiple.size() - 1;l >= 0;l--)
			{
				if(multiple[l] < 10)
				{
					multiple[l] = multiple[l] + '0';
					fout<<multiple[l];
				}
				else
				{
					multiple[l] = multiple[l] + 'A' - 10;
					fout<<multiple[l];
				}
			}
			fout<<' ';
			for(int l = 0;l < result.size();l++)
			{
				if(result[l] < 10)
				{
					result[l] = result[l] + '0';
					fout<<result[l];
				}
				else
				{
					result[l] = result[l] + 'A' - 10;
					fout<<result[l];
				}
			}
			fout<<endl;
		}
		result.erase(0,result.size());
		multiple.erase(0,multiple.size());
		trigger = true;
	}
	return 0;
}