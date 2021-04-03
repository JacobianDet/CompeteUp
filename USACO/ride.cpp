/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: www.jac1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#include <fstream>
#define MOD 47

int main(void)
{
	std::ofstream fout ("ride.out");
	std::ifstream fin ("ride.in");
	std::string s1,s2;
	fin>>s1>>s2;
	int a1 = 1, a2 = 1;
	for(int i=0,j=(int)s1.size();i<j;i++)
	a1 = ((a1 % MOD) * ((s1[i] - 64) % MOD))%MOD;
	for(int i=0,j=(int)s2.size();i<j;i++)
	a2 = ((a2 % MOD) * ((s2[i] - 64) % MOD))%MOD;	
	if(a1 == a2)
	fout<<"GO\n";
	else fout<<"STAY\n";
	return 0;	
}
