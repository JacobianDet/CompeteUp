#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

struct eventX
{
	int x, ty, ix;

	bool operator < (const eventX& wx) const
	{ 
		return (x < wx.x) || ((x == wx.x) && (ty < wx.ty));
	}	
};

struct eventY
{
	int y, ty, iy;

	bool operator < (const eventY& wx) const
	{ 
		return (y < wx.y) || ((y == wx.y) && (ty < wx.ty));
	}	
};

std::pair<int, int> X[501];
std::pair<int, int> Y[501];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		std::multiset<eventX> EX;
		std::multiset<eventY> EY;
		int p,q;
		std::cin>>p>>q;
		for(int i=0;i<p;i++)
		{
			int x,y;
			char d;
			std::cin>>x>>y>>d;
			if(d == 'W')
			{
				X[i] = mp(0, x-1);
				Y[i] = mp(0, q);
				EX.insert({X[i].first, 0, i});
				EX.insert({X[i].second, 1, i});
				EY.insert({Y[i].first, 0, i});
				EY.insert({Y[i].second, 1, i});
			}		
			else if(d == 'E')
			{	
				X[i] = mp(x+1, q);
				Y[i] = mp(0, q);
				EX.insert({X[i].first, 0, i});
				EX.insert({X[i].second, 1, i});
				EY.insert({Y[i].first, 0, i});
				EY.insert({Y[i].second, 1, i});
			}	
			else if(d == 'S')
			{	
				X[i] = mp(0, q);
				Y[i] = mp(0, y-1);
				EX.insert({X[i].first, 0, i});
				EX.insert({X[i].second, 1, i});
				EY.insert({Y[i].first, 0, i});
				EY.insert({Y[i].second, 1, i});
			}	
			else 
			{
				X[i] = mp(0, q);
				Y[i] = mp(y+1, q);
				EX.insert({X[i].first, 0, i});
				EX.insert({X[i].second, 1, i});
				EY.insert({Y[i].first, 0, i});
				EY.insert({Y[i].second, 1, i});
			}	
		}
		int xm = 0, cx = 0;
		std::multiset<eventX> ER1;
		for(auto u : EX)
		{
			if(!u.ty)
			{	
				ER1.insert(u);
				if(cx < (int)ER1.size())
				{
					cx = (int)ER1.size();
					xm = ((ER1.rbegin())->x);
				}
				else if(cx == (int)ER1.size())
				xm = std::min(xm, ((ER1.rbegin())->x));
			}
			else ER1.erase(ER1.find({X[u.ix].first, 0, u.ix}));
		}
		int ym = 0, cy = 0;
		std::multiset<eventY> ER2;
		for(auto u : EY)
		{
			if(!u.ty)
			{	
				ER2.insert(u);
				if(cy < (int)ER2.size())
				{
					cy = (int)ER2.size();
					ym = ((ER2.rbegin())->y);
				}
				else if(cy == (int)ER2.size())
				ym = std::min(ym, ((ER2.rbegin())->y));
			}
			else ER2.erase(ER2.find({Y[u.iy].first, 0, u.iy}));
		}
		std::cout<<"Case #"<<t<<": "<<xm<<" "<<ym<<"\n";
	}
	return 0;
}