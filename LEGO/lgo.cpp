#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

struct tx
{
	int x1, y1, x2, y2, par, rank;
}arr[100002];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return (x == arr[x].par) ? x : arr[x].par = root(arr[x].par);
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(arr[rx].rank < arr[ry].rank)
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[rx].x1 = std::min(arr[rx].x1, arr[ry].x1);
	arr[rx].x2 = std::max(arr[rx].x2, arr[ry].x2);
	arr[rx].y1 = std::min(arr[rx].y1, arr[ry].y1);
	arr[rx].y2 = std::max(arr[rx].y2, arr[ry].y2);
	arr[ry].par = rx;
	if(arr[rx].rank == arr[ry].rank)
	arr[rx].rank++;
	return;
}

bool cmpx(tx A, tx B)
{
	return (A.x1 < B.x1) || ((A.x1 == B.x1) && (A.x2 < B.x2)) || ((A.x1 == B.x1) && (A.x2 == B.x2) && (A.y1 < B.y1)) || ((A.x1 == B.x1) && (A.x2 == B.x2) && (A.y1 == B.y1) && (A.y2 < B.y2));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
    	std::cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2;
    }	
    std::sort(arr+1, arr+n+1, cmpx);
    for(int i=1;i<=n;i++)
    {
    	arr[i].par = i;
    	arr[i].rank = 0;
    }
    dsu T;
    int cmp = n;
    for(int i=2;i<=n;i++)
    {
    	int idx = T.root(i-1);
    	bool ox = 0, oy = 0;
    	int lx1 = std::max(arr[idx].x1, arr[i].x1);
    	int lx2 = std::min(arr[idx].x2, arr[i].x2);
    	int ly1 = std::max(arr[idx].y1, arr[i].y1);
    	int ly2 = std::min(arr[idx].y2, arr[i].y2);
    	if(lx1 < lx2)
    	ox = 1;
    	if(ly1 <= ly2)
    	oy = 1;
    	if(ox && oy)
    	{
    		T.find_union(idx, i);
    		cmp--;
    	}	
    }
    std::cout<<cmp<<"\n";
    return 0;
}
