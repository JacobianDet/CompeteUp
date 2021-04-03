#include <bits/stdc++.h>

int main(void)
{
	std::string s1,s2;
	std::cin>>s1>>s2;
	int v1=0,v2=0,qc=0;
	int ctr = 0;
	for(int i=0,j=(int)s1.size();i<j;i++)
	{
		if(s1[i] == '+')
		v1++;
		else v1--;
	}	
	for(int i=0,j=(int)s2.size();i<j;i++)
	{
		if(s2[i] == '+')
		v2++;
		else if(s2[i] == '-')
		v2--;
		else qc++;	
	}	
	for(int i=0;i<(1 << qc);i++)
	{
		int z=0;
		for(int j=0;j<qc;j++)
		{
			if(i & (1 << j))
			z++;
			else z--;	
		}
		if(v2 + z == v1)
		ctr++;	
	}
	printf("%.12lf\n", (double)ctr/(1 << qc));
	return 0;	
}