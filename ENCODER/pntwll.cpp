#include <bits/stdc++.h>

using namespace std;

int h[100001], c[100001];
bool colu[100001];

int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(colu, 0, sizeof(colu));
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		cin>>h[i];
		for(int i=0;i<n;i++)
		cin>>c[i];
		stack<int> S;
		for(int i=0;i<n;i++)
		S.push(i);
		int mh = 0;
		while(!S.empty())
		{
			int x = S.top();
			S.pop();
			if(h[x] > mh)
			{
				mh = h[x];
				colu[c[x]] = 1;
			}	
		}	
		int col = 0;
		for(int i=1;i<=m;i++)
		{
			if(colu[i])
			col++;	
		}	
		cout<<col<<"\n";
	}
	return 0;
}