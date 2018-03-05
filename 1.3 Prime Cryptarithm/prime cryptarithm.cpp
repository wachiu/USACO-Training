/*
ID: wcsiu1
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

bool check(int in, int no[],int num)
{
	bool trigger = false;
	for(int i = 0;i < num;i++)
		if(no[i] == in)
			trigger = true;
	return trigger;
}

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int num;
	int no[10];
	int useful[10000][2];
	int count = 0;
	int result = 0;
	fin>>num;
	for(int i = 0;i < num;i++)
		fin>>no[i];
	for(int i = 0;i < num;i++)
		for(int j = 0;j < num;j++)
			for(int k = 0;k < num;k++)
				for(int l = 0;l < num;l++)
				{
					int temp = no[i]+ no[j]*10 + no[k]*100;
					temp *= no[l];
					if(check(temp%10,no,num) && check((temp/10)%10,no,num) && check((temp/100)%10,no,num) && temp<1000 && temp > 100)
	
					{
						useful[count][0] = no[i]+ no[j]*10 + no[k]*100;
						useful[count][1] = temp;
						count++;
					}
				}
				for(int i = 0;i < count;i++)
					for(int j = 0;j < count;j++)
					{
						if(useful[i][0] == useful[j][0])
						{
							int temp1 = useful[i][1]*10 + useful[j][1];
							if(check(temp1%10,no,num) && check((temp1/10)%10,no,num) && check((temp1/100)%10,no,num) && check((temp1/1000)%10,no,num) && temp1 < 10000 && temp1 > 1000)
								result++;
						}
					}
	fout<<result<<endl;
	return 0;
}