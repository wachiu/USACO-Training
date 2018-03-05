/*
ID: wcsiu1
PROG: packrec
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct rec
{
	int width;
	int length;
}

int main()
{
	int rect[4][2];
	vector<rec> ans;
	rec temp;
	temp.length = 0;
	temp.width = 0;
	int min = 0;
	ifstream fin("packrec.in");
	ofstream fout("packrec.out");
	for(int i = 0;i < 4;i++)
		fin>>rect[i][1]>>rect[i][2];
	for(int i = 0;i < 4;i++)
	{
		temp.length+= rect[i][0];
		temp.width += rect[i][1];
	}
	min = temp[0] * temp[1];
	ans.push_back(temp);
	for(int i = 0;i < 4;i++)
	{
