#include <bits/stdc++.h>

bool checkpal(std::string t)
{
	std::string cy(t.rbegin(), t.rend());
	return (t == cy);
}

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	std::string mx;
	for(int i=1;i<(1 << n);i++)
	{
		std::string z;
		for(int j=0;j<n;j++)
		{
			if(i & (1 << j))
			z += s[j];	
		}
		bool f = checkpal(z);
		if(f)	
		{
			if(i == 1)
			mx = z;
			else
			{
				int l1 = (int)mx.size();
				int l2 = (int)z.size();
				for(int j=0;j<std::min(l1, l2);j++)
				{
					if(mx[j] > z[j])
					break;
					else if(z[j] > mx[j])
					{
						mx = z;
						break;
					}	
					else if((j + 1 == std::min(l1, l2)) && (l2 > l1))
					mx = z;
				}	
			}	
		}	
	}
	std::cout<<mx<<"\n";	
	return 0;
}