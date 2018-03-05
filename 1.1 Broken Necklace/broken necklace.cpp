/*
ID: wcsiu1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	int max = 0;
	int temp = 0;
	int count;
	char first;
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	string necklace;
	int total;
	fin>>total>>necklace;
	for(int i = 0;i < total;i++)
	{
		first = necklace[i];
		count = i;
		if(first == 'w')
		{
			for(int j = 0;j < total;j++)
			{
				if(count >= total)
					count -= total;

				if(necklace[count] == 'w')
					count++;
				else
				{
					first = necklace[count];
					break;
				}
			}
		}
		count = i;
		temp = 0;
		for(int j = 0;j < total;j++,count++)
		{
			if(count >= total)
				count -= total;
			if(necklace[count] == first || necklace[count] == 'w')
				temp ++;
			else
				break;
		}
		count = i - 1;
		if(count < 0)
			count += total;
		first = necklace[count];
		if(first == 'w')
		{
			for(int j = 0;j < total;j++)
			{
				if(count >= total)
					count -= total;

				if(necklace[count] == 'w')
					count--;
				else
				{
					first = necklace[count];
					break;
				}
			}
		}
		count = i - 1;
		if(count < 0)
			count += total;
		for(int k = 0;k < total;k++,count--)
		{
			if(count < 0)
				count += total;
			if(necklace[count] == first || necklace[count] == 'w')
				temp++;
			else
				break;
		}
		if(temp > max)
			max = temp;
	}
	if(max > total)
		max = total;
	fout<<max<<endl;
	return 0;
}