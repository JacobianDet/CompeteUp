#include <bits/stdc++.h>

typedef long long ll;

void swapp(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

int main(void)
{
	ll n;
	std::cin>>n;
	int dig = 0;
	ll temp = n;
	while(temp)
	{
		dig++;
		temp /= 10;
	}	
	int arr[4][dig+1];
	memset(arr, 0, sizeof(arr));
	temp = n;
	for(int i=dig;i>0;i--)
	{
		for(int j=0;j<4;j++)
		arr[j][i] = temp%10;
		temp /= 10;
	}
	int c0=0,c2=0,c5=0,c7=0;
	for(int i=1;i<=dig;i++)
	{
		if(arr[0][i] == 0)
		c0++;
		else if(arr[0][i] == 2)
		c2++;
		else if(arr[0][i] == 5)
		c5++;
		else if(arr[0][i] == 7)
		c7++;	
	}	
	ll tot = 20000000;
	if((c2 >= 1) && (c5 >= 1))
	{
		ll sw = 0;
		int pos5 = -1,pos2 = -1;
		for(int i=dig;i>0;i--)
		{
			if(arr[0][i] == 5)
			{
				pos5 = i;
				break;
			}	
		}
		for(int i=pos5;i<dig;i++)
		{
			sw++;
			swapp(arr[0][i], arr[0][i+1]);
		}	
		for(int i=dig-1;i>0;i--)
		{
			if(arr[0][i] == 2)
			{
				pos2 = i;
				break;
			}	
		}
		for(int i=pos2;i<dig-1;i++)
		{
			sw++;
			swapp(arr[0][i], arr[0][i+1]);
		}	
		if(dig > 2)
		{	
			int p = -1;
			for(int i=1;i<dig-1;i++)
			{
				if(arr[0][i])
				{
					p = i;
					break;
				}	
			}
			if(p == -1)
			sw = 20000000;
			else
			{
				for(int i=p;i>1;i--)
				{
					sw++;
					swapp(arr[0][i], arr[0][i-1]);
				}	
			}
		}	
		tot = std::min(tot, sw);	
	}
	if((c5 >= 1) && (c0 >= 1))
	{
		ll sw = 0;
		int pos5 = -1,pos0 = -1;
		for(int i=dig;i>0;i--)
		{
			if(!arr[1][i])
			{
				pos0 = i;
				break;
			}	
		}
		for(int i=pos0;i<dig;i++)
		{
			sw++;
			swapp(arr[1][i], arr[1][i+1]);
		}	
		for(int i=dig-1;i>0;i--)
		{
			if(arr[1][i] == 5)
			{
				pos5 = i;
				break;
			}	
		}
		for(int i=pos5;i<dig-1;i++)
		{
			sw++;
			swapp(arr[1][i], arr[1][i+1]);
		}
		if(dig > 2)
		{	
			int p = -1;
			for(int i=1;i<dig-1;i++)
			{
				if(arr[1][i])
				{
					p = i;
					break;
				}	
			}
			if(p == -1)
			sw = 20000000;
			else
			{
				for(int i=p;i>1;i--)
				{
					sw++;
					swapp(arr[1][i], arr[1][i-1]);
				}	
			}
		}	
		tot = std::min(tot, sw);
	}	
	if((c7 >= 1) && (c5 >= 1))
	{
		ll sw = 0;
		int pos5 = -1,pos7 = -1;
		for(int i=dig;i>0;i--)
		{
			if(arr[2][i] == 5)
			{
				pos5 = i;
				break;
			}	
		}
		for(int i=pos5;i<dig;i++)
		{
			sw++;
			swapp(arr[2][i], arr[2][i+1]);
		}	
		for(int i=dig-1;i>0;i--)
		{
			if(arr[2][i] == 7)
			{
				pos7 = i;
				break;
			}	
		}
		for(int i=pos7;i<dig-1;i++)
		{
			sw++;
			swapp(arr[2][i], arr[2][i+1]);
		}
		if(dig > 2)
		{	
			int p = -1;
			for(int i=1;i<dig-1;i++)
			{
				if(arr[2][i])
				{
					p = i;
					break;
				}	
			}
			if(p == -1)
			sw = 20000000;
			else
			{
				for(int i=p;i>1;i--)
				{
					sw++;
					swapp(arr[2][i], arr[2][i-1]);
				}	
			}
		}	
		tot = std::min(tot, sw);
	}	
	if(c0 >= 2)
	{
		ll sw = 0;
		int pos0 = -1;
		for(int i=dig;i>0;i--)
		{
			if(!arr[3][i])
			{
				pos0 = i;
				break;
			}	
		}
		for(int i=pos0;i<dig;i++)
		{
			sw++;
			swapp(arr[3][i], arr[3][i+1]);
		}	
		for(int i=dig-1;i>0;i--)
		{
			if(!arr[3][i])
			{
				pos0 = i;
				break;
			}	
		}
		for(int i=pos0;i<dig-1;i++)
		{
			sw++;
			swapp(arr[3][i], arr[3][i+1]);
		}
		if(dig > 2)
		{	
			int p = -1;
			for(int i=1;i<dig-1;i++)
			{
				if(arr[3][i])
				{
					p = i;
					break;
				}	
			}
			if(p == -1)
			sw = 20000000;
			else
			{
				for(int i=p;i>1;i--)
				{
					sw++;
					swapp(arr[3][i], arr[3][i-1]);
				}	
			}
		}	
		tot = std::min(tot, sw);
	}	
	if(tot < 20000000)
	std::cout<<tot<<"\n";
	else std::cout<<"-1\n";
	return 0;
}