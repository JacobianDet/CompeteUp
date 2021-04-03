#include <bits/stdc++.h>

struct axed
{
	int x1, y1, x2, y2;
}arr[132700];

int xl[2][132700], xr[2][132700], yu[2][132700], yd[2][132700];

bool cmpx(axed a, axed b)
{
	if(a.x1 < b.x1)
	return 1;
	else if((a.x1 == b.x1) && (a.y1 < b.y1))
	return 1;
	else if((a.x1 == b.x1) && (a.y1 == b.y1) && (a.x2 < b.x2))
	return 1;
	else if((a.x1 == b.x1) && (a.y1 == b.y1) && (a.x2 == b.x2) && (a.y2 < b.y2))
	return 1;
	else return 0;		
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2;
	//std::sort(arr, arr+n, cmpx);
	xl[0][0] = arr[0].x1;
	xr[0][0] = arr[0].x2;
	yd[0][0] = arr[0].y1;
	yu[0][0] = arr[0].y2;
	for(int i=1;i<n;i++)
	{
		xl[0][i] = std::max(arr[i].x1, xl[0][i-1]);
		xr[0][i] = std::min(arr[i].x2, xr[0][i-1]);
		yd[0][i] = std::max(arr[i].y1, yd[0][i-1]);
		yu[0][i] = std::min(arr[i].y2, yu[0][i-1]);
	}
	xl[1][n-1] = arr[n-1].x1;
	xr[1][n-1] = arr[n-1].x2;
	yd[1][n-1] = arr[n-1].y1;
	yu[1][n-1] = arr[n-1].y2;
	for(int i=n-2;i>=0;i--)
	{
		xl[1][i] = std::max(arr[i].x1, xl[1][i+1]);
		xr[1][i] = std::min(arr[i].x2, xr[1][i+1]);
		yd[1][i] = std::max(arr[i].y1, yd[1][i+1]);
		yu[1][i] = std::min(arr[i].y2, yu[1][i+1]);
	}
	for(int i=0;i<n;i++)
	{
		if(!i)
		{
			int x1 = xl[1][1];
			int x2 = xr[1][1];
			int y1 = yd[1][1];
			int y2 = yu[1][1];
			if(x1 <= x2 && y1 <= y2)
			{
				std::cout<<x1<<" "<<y1<<"\n";
				break;
			}	
		}
		else if(i == n-1)
		{
			int x1 = xl[0][n-2];
			int x2 = xr[0][n-2];
			int y1 = yd[0][n-2];
			int y2 = yu[0][n-2];
			if(x1 <= x2 && y1 <= y2)
			{
				std::cout<<x1<<" "<<y1<<"\n";
				break;
			}	
		}
		else
		{
			int x1 = std::max(xl[0][i-1], xl[1][i+1]);
			int x2 = std::min(xr[0][i-1], xr[1][i+1]);
			int y1 = std::max(yd[0][i-1], yd[1][i+1]);
			int y2 = std::min(yu[0][i-1], yu[1][i+1]);
			if(x1 <= x2 && y1 <= y2)
			{
				std::cout<<x1<<" "<<y1<<"\n";
				break;
			}		
		}
	}
	return 0;
}