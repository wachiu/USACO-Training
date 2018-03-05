/*
ID: wcsiu1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int total;
	fin>>total;
	char one[10][10];
	char two[10][10];
	char three[10][10];
	char original[10][10];
	char result[10][10];
	bool trigger = true;
	for(int i = 0;i < total;i++)
		for(int j = 0;j < total;j++)
			fin>>original[i][j];
	for(int i = 0;i < total;i++)
		for(int j = 0;j < total;j++)
			fin>>result[i][j];
	for(int i = 0,j = total - 1; i < total, j >= 0;i++,j--) //rotate original
		for(int k = 0, l = 0;k < total,l < total;k++,l++)
			one[l][j] = original[i][k];
	for(int i = 0;i < total;i++)                        //check rotate original 90 
		for(int j = 0;j < total;j++)
			if(one[i][j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<1<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0,j = total - 1; i < total, j >= 0;i++,j--) //rotate one 90
		for(int k = 0, l = 0;k < total,l < total;k++,l++)
			two[l][j] = one[i][k];
	for(int i = 0;i < total;i++)                        //check rotate original 180 degrees
		for(int j = 0;j < total;j++)
			if(two[i][j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<2<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0,j = total - 1; i < total, j >= 0;i++,j--) //rotate two 90
		for(int k = 0, l = 0;k < total,l < total;k++,l++)
			three[l][j] = two[i][k];
	for(int i = 0;i < total;i++)                        //check rotate original 270 degrees
		for(int j = 0;j < total;j++)
			if(three[i][j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<3<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0;i < total;i++)                        //check reflect original 
		for(int j = 0;j < total;j++)
			if(original[i][total-1-j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<4<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0;i < total;i++)                        //check reflect one 
		for(int j = 0;j < total;j++)
			if(one[i][total-1-j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<5<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0;i < total;i++)                        //check reflect two 
		for(int j = 0;j < total;j++)
			if(two[i][total-1-j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<5<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0;i < total;i++)                        //check reflect three 
		for(int j = 0;j < total;j++)
			if(three[i][total-1-j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<5<<endl;
		return 0;
	}
	trigger = true;
	for(int i = 0;i < total;i++)                        //check original
		for(int j = 0;j < total;j++)
			if(original[i][j] != result[i][j])
				trigger = false;
	if(trigger == true)
	{
		fout<<6<<endl;
		return 0;
	}
	trigger = true;
	fout<<7<<endl;
	return 0;
}