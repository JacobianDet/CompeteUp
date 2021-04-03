#include <bits/stdc++.h>
 
int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		std::map<std::string, int> msi;
		std::string s;
		int n;
		std::cin>>n;
		for(int j=0;j<n;j++)
		{
			std::cin>>s;
			msi[s]++;
		}	
		if(msi.size() == 0)
		std::cout<<"Draw\n";
		else
		{	
			int maxm = (msi.begin()->second);
			s = msi.begin()->first;
			for(std::map<std::string, int>::iterator it = msi.begin(); it != msi.end(); it++)
			{
				if(maxm < it->second)
				{
					s = it->first;
					maxm = it->second;
				}
				else if(maxm == it->second && s != it->first)
				s = "Draw";	
			}	
			std::cout<<s<<"\n";
		}
	}		
	return 0;
} 