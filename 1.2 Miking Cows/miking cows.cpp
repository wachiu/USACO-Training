/*
ID: wcsiu1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct framer
{
	int start;
	int end;
};

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int num;
	int occupied = 0;
	int unoccupied = 0;
	framer temp;
	framer nono;
	nono.start = 0;
	nono.end = 0;
	fin>>num;
	vector<framer> all;
	all.resize(num);
	for(int i = 0;i < num;i++)
	{
		fin>>all[i].start;
		fin>>all[i].end;
	}
	for (int p = 0; p < num; p++) 
	{
		framer tmp;
		tmp.start = all[p].start;
		tmp.end = all[p].end;
		int q;
		for (q = p; q > 0 && tmp.start < all[q-1].start; q--)
		{
			all[q].start = all[q-1].start;
			all[q].end = all[q-1].end;
		}
		all[q].start = tmp.start;
		all[q].end = tmp.end;
	}
	for(int j = 0; j < num;j++)
	{
		temp.start = all[j].start;
		temp.end = all[j].end;
			for(int i = 0; i < num;i++)
			{
				if(all[i].start <= temp.end && all[i].end > temp.end && all[i].start > temp.start)
					temp.end = all[i].end;
				if(all[i].start < temp.start && all[i].end >= temp.start && temp.end > all[i].end)
					temp.start = all[i].end;
				if(all[i].start < temp.start && all[i].end > temp.end)
				{
					temp.end = all[i].end;
					temp.start = all[i].start;
				}
			}
		if(occupied < temp.end - temp.start)
			occupied = temp.end - temp.start;
		if(nono.start != 0 || nono.end != 0)
		{
			if(temp.end < nono.start)
			{
				if(nono.start - temp.end > unoccupied)
					unoccupied = nono.start - temp.end;
				nono.start = temp.start;
			}
			if(temp.start > nono.end)
			{
				if(temp.start - nono.end > unoccupied)
					unoccupied = temp.start - nono.end;
				nono.end = temp.end;
			}
			if(temp.end == nono.start && temp.start < nono.start)
				nono.start = temp.start;
			if(temp.start = nono.end && temp.end > nono.end)
				nono.end = temp.end;
		}
		else
		{
			nono.end = temp.end;
			nono.start = temp.start;
		}
	}
	fout<<occupied<<' '<<unoccupied<<endl;
	return 0;
}