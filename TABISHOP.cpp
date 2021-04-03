#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct point {
	int x,y;
	point(){}
	point(int x_,int y_):x(x_),y(y_){}
	bool operator<(const point &p) const {
		return x<p.x || x==p.x && y<p.y;
	}
};

typedef vector<point> VP;

struct segm { 
	int x,y1,y2;
	bool operator<(const segm &s) const {
		return x<s.x || (x==s.x && (y1<s.y1 || y1==s.y1 && y2<s.y2));
	}
	bool operator==(const segm &s) const {
		return x==s.x && y1==s.y1 && y2==s.y2;
	}
};

typedef vector<segm> VSG;

LL gen_segments(VP &a,VP &b,int sA,int sB,int dA,int dB,VSG &s)
{
	s.clear();
	sort(b.begin(), b.end()); // sort other chess pieces
	for(int i=0;i<a.size();i++)
	{
		int x = a[i].x, y = a[i].y;
		// init y1,y2 by board boundary
		int y1 = max(sA-x,x-dB);
		int y2 = min(sB-x,x-dA);
		// seek for other chess pieces in the same column
		int j = lower_bound(b.begin(), b.end() ,a[i])-b.begin();
		// update y2 if we have other chess piece with the same x and larger y
		if(j<b.size() && b[j].x==x)
			y2=min(y2,b[j].y-1);
		// update y2 if we have other chess piece with the same x and smaller y
		if(j>0 && b[j-1].x==x)
			y1=max(y1,b[j-1].y+1);
		segm cur = {x,y1,y2};
		s.push_back(cur);
	}
	// sort and unique segments
	// after that they all will be non-intersecting
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()) ,s.end());
	// sum their lengths
	LL ans=0;
	for(int i=0;i<s.size();i++)
		ans+=s[i].y2-s[i].y1+1;
	return ans;
}

// swap coordinates of the points in a
void swapXY(VP &a)
{
	for(int i=0;i<a.size();i++)
		swap(a[i].x,a[i].y);
}

struct Event {
	int x;
	int tp;
	int y1,y2;
	Event(){}
	Event(int x_,int tp_,int y1_,int y2_=0){x=x_;tp=tp_;y1=y1_;y2=y2_;}
	bool operator<(const Event &e) const {
		return x<e.x || x==e.x && tp<e.tp;
	}
};

LL intersect(VSG &a,VSG &b)
{
	// creating the list of all unique y values for horizontal segments
	VI y;
	for(int i=0;i<b.size();i++)
		y.push_back(b[i].x);
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	// creating events
	vector<Event> ev;
	for(int i=0;i<a.size();i++)
		// count event for vertical segments
		ev.push_back(Event(a[i].x, 0, a[i].y1, a[i].y2));
	for(int i=0;i<b.size();i++) {
		// add and del events for horizontal segments
		ev.push_back(Event(b[i].y1, -1, b[i].x));
		ev.push_back(Event(b[i].y2, +1, b[i].x));
	}
	sort(ev.begin(), ev.end());
	int n = ev.size();
	VI BIT(n+1,0); // binary index tree 
	LL ans=0;
	for(int i=0;i<ev.size();i++)
	{
		int tp = ev[i].tp;
		if(tp) {
			// add or del event
			int j = lower_bound(y.begin(), y.end(), ev[i].y1) - y.begin() + 1;
			for(;j<=n;j+=j&-j)
				BIT[j]-=tp;
		} else {
			// count event
			// we count the number of marked y between j1 and j2
			int j1 = lower_bound(y.begin(), y.end(), ev[i].y1) - y.begin();
			int j2 = upper_bound(y.begin(), y.end(), ev[i].y2) - y.begin();
			for(int j=j2;j>0;j-=j&-j) ans+=BIT[j];
			for(int j=j1;j>0;j-=j&-j) ans-=BIT[j];
		}
	}
	return ans;
}

// the board that constrained by inequalities
// sA<=x+y<=sB, dA<=x-y<=dB
// a are bishops (which are rooks now), b other chess pieces
LL calc(VP &a,VP &b,int sA,int sB,int dA,int dB)
{
	LL ans=0;

	VSG x, y;
	// gen unique safe vertical segments for each bishop
	// and add their total length to the answer
	ans+=gen_segments(a,b,sA,sB,dA,dB,x);

	// the swap trick to use the same routine for both vertical and horizontal segments
	swapXY(b);
	swapXY(a);

	// gen safe horizontal segments for each bishop
	// and add their total length to the answer
	ans+=gen_segments(a,b,sA,sB,-dB,-dA,y);

	// subtract intersection
	ans-=intersect(x,y);
	return ans;
}

int main()
{
	int W, N, M;
	scanf("%d%d%d",&W,&N,&M);
	// b[0] are black bishops, o[0] are black other pieces
	// b[1], o[1] are similar for white cells
	// we split the board in 2 boards of black and white cells
	// and do the change of coordinate system to consider them as rectangular boards
	VP b[2],o[2];
	for(int i=0;i<N+M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int r=(x+y)%2;
		int u=(x+y-r)/2;
		int v=(x-y-r)/2;
		(i<N?b[r]:o[r]).push_back(point(u,v));
	}
	LL ans=0;
	// process each board separately
	for(int r=0;r<=1;r++)
		ans+=calc(b[r],o[r],1-r,W-r,1,W);
	printf("%lld\n",ans);
	return 0;
}
