/*
ID: wcsiu1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

struct farmer
{
	int price;
	int amount;
};

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int needed;
	int num;
	int result = 0;
	farmer all[5000];
	fin>>needed>>num;
	for(int i = 0;i < num;i++)
		fin>>all[i].price>>all[i].amount;
	int j;
	for (int p = 1; p < num; p++)
	{
		farmer temp;
		temp.amount = all[p].amount;
		temp.price = all[p].price;
		for (j = p; j > 0 && temp.price < all[j-1].price; j--)
		{

			all[j].price = all[j-1].price;
			all[j].amount = all[j-1].amount;
		}
		all[j].amount = temp.amount;
		all[j].price = temp.price;
	}
	int count = 0;
	while(needed != 0)
	{
		if(all[count].amount <= needed)
		{
			needed = needed - all[count].amount;
			result += all[count].amount * all[count].price;
		}
		else
		{
			result += all[count].price * needed;
			needed = 0;
		}
		count++;
	}
	fout<<result<<endl;
	return 0;
}