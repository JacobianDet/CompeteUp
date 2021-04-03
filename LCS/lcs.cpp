#include <bits/stdc++.h>
#define mp std::make_pair
#define MV 500005
#define LM 21

typedef long long ll;

struct trip
{
	int x, y, id;
}L[MV];

bool cmp(trip a, trip b)
{
    return (a.x == b.x) ? ((a.y < b.y) ? 1 : 0) : ((a.x < b.x) ? 1 : 0);
}

std::string s;
int SA[MV], cord[30], RW[MV], rk[MV], lcp[MV];
int x;

class SAX
{
	public: void SA_build(int n);
			void LCP_kasai(int n);
};

void counting_sort(int n, int u)
{
    int count[u+1];
    trip temp[n + 9];
    memset(count , 0 , sizeof(count));

    for(int i = 0 ;i < n ; i++)
        count[L[i].y + 1]++;

    for(int i = 1 ; i < u+1 ; i++)
        count[i] += count[i-1];

    for(int i = 0 ; i<n ; i++)
    {
        temp[count[L[i].y +1] - 1] = L[i];
        count[L[i].y + 1]--;
    }

    memset(count , 0 , sizeof(count));

    for(int i = 0 ; i < n ; i ++)
        count[L[i].x + 1] ++;

    for(int i = 1 ; i<u+1 ; i++)
        count[i] += count[i-1];

    for(int i = n- 1; i>=0 ; i--)
    {
        L[count[temp[i].x + 1] - 1] = temp[i];
        count[temp[i].x + 1]--;
    }
}

void SAX::SA_build(int n)
{
	for(int i=0;i<n;i++)
	SA[i] = cord[s[i]-'`'];
	int pu = 27;
	for(int i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			L[j].x = SA[j];
			L[j].y = (j + (1<<(i-1))) < n ? SA[j + (1<<(i-1))] : -1;
			L[j].id = j;
		}	
		counting_sort(n, pu);
		int u = 0;
		for(int j=0;j<n;j++)
		SA[L[j].id] = (j && (L[j].x == L[j-1].x) && (L[j].y == L[j-1].y)) ? SA[L[j-1].id] : u++;
		pu = u;	
	}
	for(int i=0;i<n;i++)
	RW[i] = L[i].id;		
	return;
}	

void SAX::LCP_kasai(int n)
{
	for(int i=0;i<n;i++)
	rk[RW[i]] = i;	
	int k = 0;
	for(int i=0;i<n;i++)
	{
		if(rk[i] == n-1)
		{
			k = 0;
			continue;
		}	
		int j = RW[rk[i] + 1];
		while(i + k < n && j + k < n && s[i+k] == s[j+k])
		k++;
		lcp[RW[i]] = k;
		if(k)
		k--;	
	}
	return;
}

int main(void)
{
	memset(cord, -1, sizeof(cord));
	std::string s1, s2;
	std::cin>>s1>>s2;
	s = s1 + '`' + s2;
	int m = (int)s2.size();
	int n = (int)s.size();
	int u = 0;
	for(int i=0;i<n;i++)
	{
		if(cord[s[i] - '`'] == -1)
		cord[s[i] - '`'] = u++;
	}	
	for(x=0;(1<<x)<=n;x++);
	SAX T;
	T.SA_build(n);
	T.LCP_kasai(n);
	int ans = 0;
	for(int i=0;i<n-1;i++)
	{	
		if((RW[i] > m && RW[i+1] <= m) || (RW[i] <= m && RW[i+1] > m))
		ans = std::max(ans, lcp[i]);
	}	
	std::cout<<ans<<"\n";
	return 0;
}