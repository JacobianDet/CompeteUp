#include <bits/stdc++.h>
#define mp std::make_pair

int main(void)
{
	std::pair<int, int> sq1[4];
	std::pair<int, int> sq2[4];
	for(int i=0;i<4;i++)
	{
		int x,y;
		std::cin>>x>>y;
		sq1[i] = mp(x, y);
	}	
	for(int i=0;i<4;i++)
	{
		int x,y;
		std::cin>>x>>y;
		sq2[i] = mp(x, y);
	}
	bool ok = 0;
	for(int i=0;i<4;i++)
	{
		int x = sq2[i].first;
		int y = sq2[i].second;
		int cx1 = x - sq1[0].first;
		int cx2 = x - sq1[2].first;
		int cy1 = y - sq1[0].second;
		int cy2 = y - sq1[2].second;
		if(((cx1 <= 0) && (cx2 >= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 <= 0) && (cx2 >= 0) && (cy1 >= 0) && (cy2 <= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 >= 0) && (cy2 <= 0)))
		ok = 1;
	}
	for(int i=0;i<4;i++)
	{
		int x = sq1[i].first;
		int y = sq1[i].second;
		int cx1 = y - x + sq2[0].first - sq2[0].second;
		int cx2 = y - x + sq2[2].first - sq2[2].second;
		int cy1 =  y + x - sq2[0].first - sq2[0].second;
		int cy2 =  y + x - sq2[2].first - sq2[2].second;
		if(((cx1 <= 0) && (cx2 >= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 <= 0) && (cx2 >= 0) && (cy1 >= 0) && (cy2 <= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 >= 0) && (cy2 <= 0)))
		ok = 1;
	}
	double c1 = (sq1[0].first + sq1[2].first)/2;
	double c2 = (sq1[0].second + sq1[2].second)/2;
	double cx1 = c2 - c1 + sq2[0].first - sq2[0].second;
	double cx2 = c2 - c1 + sq2[2].first - sq2[2].second;
	double cy1 =  c2 + c1 - sq2[0].first - sq2[0].second;
	double cy2 =  c2 + c1 - sq2[2].first - sq2[2].second;
	if(((cx1 <= 0) && (cx2 >= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 <= 0) && (cx2 >= 0) && (cy1 >= 0) && (cy2 <= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 <= 0) && (cy2 >= 0)) || ((cx1 >= 0) && (cx2 <= 0) && (cy1 >= 0) && (cy2 <= 0)))
	ok = 1;
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}