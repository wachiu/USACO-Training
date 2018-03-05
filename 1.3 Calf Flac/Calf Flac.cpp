/*
ID: wcsiu1
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

struct unit
{
	char con;
	int pos;
};

int main()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	string input;
	vector<unit> only;
	bool trigger = true;
	int maxstart;
	int maxend;
	int maxlength = 0;
	getline(fin, input, '\0');
	for(int i = 0;i < input.size();i++)
	{
		unit temp;
		temp.con = input[i];
		temp.pos = i;
		if(input[i] > 64 && input[i] < 91)
			only.push_back(temp);
		if(input[i] > 96 && input[i] < 123)
		{
			temp.con -= 'a' - 'A';
			only.push_back(temp);
		}
	}
	for(int i = 0;i < only.size();i++)
	{
		if(i + 2000 < only.size())
		{
			for(int j = i + 2000;j > i;j--)
			{
				if(only[i].con == only[j].con)
				{
					for(int k = i,l = j;k <= (i+j)/2, l >= (i+j)/2;k++,l--)
					{
						if(only[k].con != only[l].con)
						{
							trigger = false;
							break;
						}
					}
					if(trigger)
					{
						if(j-i+1 > maxlength || (j-i+1 ==maxlength && i < maxstart))
						{
							maxstart = i;
							maxend = j;
							maxlength = j-i+1;
						}
						i = j;
						trigger = true;
						break;
					}
					trigger = true;
				}
			}
		}
		if(i + 2000 >= only.size())
		{
			for(int j = only.size()-1;j > i+1;j--)
			{
				if(only[i].con == only[j].con)
				{
					for(int k = i,l = j;k <= (i+j)/2, l >= (i+j)/2;k++,l--)
					{
						if(only[k].con != only[l].con)
						{
							trigger = false;
							break;
						}
					}
					if(trigger)
					{
						if(j-i+1 > maxlength || (j-i+1 ==maxlength && i < maxstart))
						{
							maxstart = i;
							maxend = j;
							maxlength = j-i+1;
						}
						i = j;
						trigger = true;
						break;
					}
					trigger = true;
				}
			}
		}
	}
	fout<<maxlength<<endl;
	for(int u = only[maxstart].pos;u <= only[maxend].pos;u++)
		fout<<input[u];
	fout<<endl;
	return 0;
}