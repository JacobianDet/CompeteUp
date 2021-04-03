#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ins insert
#define sz size

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;

int ar[MV];
ll arr[MV];
VI Z;

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{	
		std::cin>>ar[i];
		if(ar[i] != -1)
		Z.pb(i);
	}		
	bool ok = 1;
	int p1 = -1;
	for(auto u : Z)
	{
		if(u - p1 > 1)
		{
			int l1 = -1, l2 = -1;
			if(p1 != -1)
			l1 = ar[p1];
			if(u != -1)
			l2 = ar[u];	
			if(l1 != -1)
			{
				if((l1 == 1) && (l2 == 1))
				{
					if((u - p1 - 1) & 1)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u-1;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
						if(k == 2)
						{
							ok = 0;
							break;
						}	
						else ar[u-1] = 3;
					}
				}
				else if((l1 == 1) && (l2 == 2))
				{
					if(!((u - p1 - 1) & 1))
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u-1;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
						if(k == 2)
						{
							ok = 0;
							break;
						}	
						else ar[u-1] = 3;
					}
				}
				else if((l1 == 2) && (l2 == 1))
				{
					if(!((u - p1 - 1) & 1))
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u-1;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
						if(k == 2)
						{
							ok = 0;
							break;
						}	
						else ar[u-1] = 3;
					}
				}
				else if((l1 == 2) && (l2 == 2))
				{
					if((u - p1 - 1) & 1)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u-1;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
						if(k == 2)
						{
							ok = 0;
							break;
						}	
						else ar[u-1] = 3;
					}
				}
				else
				{
					if(l1 == 1)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
					}
					else if(l1 == 2)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
					}
					else if(l2 == 1)
					{
						if((u - p1 - 1) & 1)
						{
							for(int i=p1+1;i<u;i++)
							{
								if((i - p1) & 1)
								ar[i] = 2;
								else ar[i] = 1;	
							}	
						}
						else
						{
							for(int i=p1+1;i<u;i++)
							{
								if((i - p1) & 1)
								ar[i] = 1;
								else ar[i] = 2;	
							}	
						}
					}
					else
					{
						if((u - p1 - 1) & 1)
						{
							for(int i=p1+1;i<u;i++)
							{
								if((i - p1) & 1)
								ar[i] = 1;
								else ar[i] = 2;	
							}	
						}
						else
						{
							for(int i=p1+1;i<u;i++)
							{
								if((i - p1) & 1)
								ar[i] = 2;
								else ar[i] = 1;	
							}	
						}
					}				
				}	
			}
			else
			{
			    if(l2 == 1)
				{
					if((u - p1 - 1) & 1)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
					}
				}
				else
				{
					if((u - p1 - 1) & 1)
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 1;
							else ar[i] = 2;	
						}	
					}
					else
					{
						for(int i=p1+1;i<u;i++)
						{
							if((i - p1) & 1)
							ar[i] = 2;
							else ar[i] = 1;	
						}	
					}
				}	
			}	
		}	
		p1 = u;
	}
	if((p1 != n-1) && ok)
	{
		if(ar[p1] == 1)
		{
			for(int i=p1+1;i<n;i++)
			{
				if((i - p1) & 1)
				ar[i] = 2;
				else ar[i] = 1;	
			}
		}
		else
		{
			for(int i=p1+1;i<n;i++)
			{
				if((i - p1) & 1)
				ar[i] = 1;
				else ar[i] = 2;	
			}
		}
	}
	if(ok)
	{
		std::cout<<"YES\n";
		for(int i=0;i<n;i++)
		std::cout<<ar[i]<<" ";
		std::cout<<"\n";	
	}	
	else std::cout<<"NO\n";
	Z.clear();
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}