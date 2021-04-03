/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: www.jac1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#include <fstream>

std::map<std::string, int> cord;
std::map<int, std::string> cxz;
int ctv[11];

int main(void)
{
	std::ofstream fout ("gift1.out");
	std::ifstream fin ("gift1.in");
	int n;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		std::string s;
		fin>>s;
		cord[s] = i;
		cxz[i] = s;
	}
	for(int i=1;i<=n;i++)
	{
		std::string x;
		int mn, m;
		fin>>x>>mn>>m;
		int vx = 0;
		if(!m)
		ctv[cord[x]] += mn;
		else
		{
			vx = mn/m;
			ctv[cord[x]] -= (vx*m);
		}	
		for(int j=0;j<m;j++)
		{
			std::string s;
			fin>>s;
			ctv[cord[s]] += vx;
		}	
	}	
	for(int i=1;i<=n;i++)
	fout<<cxz[i]<<" "<<ctv[i]<<"\n";
	return 0;	
}
