#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	freopen("inpq1.in","r",stdin);
	freopen("ouq1.txt","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		ll n;
		std::cin>>n;
		ll temp = n;
		int dig = 0;
		while(temp)
		{
			dig++;
			temp /= 10;
		}	
		int arr[dig];
		temp = n;
		for(int i=dig-1;i>=0;i--)
		{
			arr[i] = (temp%10);
			temp /= 10;
		}
		ll a=0,b=0;
		for(int i=0;i<dig;i++)
		{
			if(arr[i] & 1)
			{
				a = 10*a + (arr[i]+1);
				b = 10*b + (arr[i]-1);
				for(int j=i+1;j<dig;j++)
				{
					a = 10*a + 0;
					b = 10*b + 8;
				}
				break;
			}
			else  
			{
				a = 10*a + arr[i];
				b = 10*b + arr[i];
			}	
		}
		std::cout<<"Case #"<<t<<": "<<std::min(n-b, a-n)<<"\n";	
	}	
	return 0;
}
