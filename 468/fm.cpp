#include <bits/stdc++.h>

int main(void)
{
	int a,b;
	std::cin>>a>>b;
	int i=1;
	int t=0;
	while(a != b)
	{
		if(a < b)
		{
			a++;
			t += i;
			if(b > a)
			{
				b--;
				t += i;
			}	
		}
		else if(a > b)
		{
			a--;
			t += i;
			if(b < a)
			{
				b++;
				t += i;
			}	
		}	
		i++;
	}	
	std::cout<<t<<"\n";
	return 0;
}