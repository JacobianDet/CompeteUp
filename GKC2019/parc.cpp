#include <bits/stdc++.h>
#define mp std::make_pair

std::string G[251];
std::set<std::pair<int, int> > VX0, VX1;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int r,c;
		std::cin>>r>>c;
		for(int i=0;i<r;i++)
		std::cin>>G[i];
		int mxv = 1000000000;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(G[i][j] == '1')
				VX1.insert(mp(i, j));	
				else VX0.insert(mp(i, j));
			}	
		}
		for(auto u : VX0)
		{
			int mrx = 0;
			for(auto v : VX0)
			{
				int mnx = abs(u.first - v.first) + abs(u.second - v.second);
				for(auto w : VX1)
				mnx = std::min(mnx, abs(w.first - v.first) + abs(w.second - v.second));
				mrx = std::max(mrx, mnx);
			}
			mxv = std::min(mxv, mrx);
		}
		if(mxv == 1000000000)
		mxv = 0;	
		std::cout<<"Case #"<<t<<": "<<mxv<<"\n";
		VX0.clear();
		VX1.clear();
	}
	return 0;
}