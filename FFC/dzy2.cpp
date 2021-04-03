#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

typedef long long ll;
typedef std::vector<std::pair<ll, ll> > sp;
typedef std::pair<ll, ll> px;

struct elem
{
	ll co,cl;
}elem[100100];

struct sq
{
	ll tc,fc,cc,ac;
	sp s;
}bl[350];

ll Z;

class sqrtdec
{
	public: void update(ll l, ll r, ll x);
			ll query(ll l, ll r);
};

void sqrtdec::update(ll l, ll r, ll x)
{
	ll c_l = l/Z;
	ll c_r = r/Z;
	if(c_l == c_r)
	{
		if(bl[c_l].fc)
		{	
			for(ll i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_l].fc - elem[i].co);
				elem[i].cl += (t + bl[c_l].ac);
				elem[i].co = bl[c_l].cc;
			}	
			bl[c_l].fc = bl[c_l].cc = bl[c_l].ac = 0;
		}	
		for(ll i=l;i<=r;i++)
		{
			ll t = fabs(x - elem[i].co);
			elem[i].cl += t;
			bl[c_l].tc += t;
			ll pos = 0;
			for(sp::iterator it=bl[c_l].s.begin();it != bl[c_l].s.end();it++,pos++)
			{
				if(it->first == elem[i].co)
				{
					ll u = it->first;
					ll v = it->second - 1;
					it++;
					bl[c_l].s.erase(bl[c_l].s.begin()+pos);
					if(v)
					bl[c_l].s.pb(mp(u, v));	
					break;
				}	
			}	
			elem[i].co = x;
		}	
		bool flag = 0;
		ll pos = 0;
		for(sp::iterator it=bl[c_l].s.begin();it != bl[c_l].s.end();it++,pos++)
		{
			if(it->first == x)
			{
				ll u = it->first;
				ll v = it->second + (r-l+1);
				it++;
				bl[c_l].s.erase(bl[c_l].s.begin()+pos);
				if(v)
				bl[c_l].s.pb(mp(u, v));
				flag = 1;
				break;	
			}	
		}	
		if(!flag)
		bl[c_l].s.pb(mp(x, r-l+1));	
	}	
	else
	{
		//LEFT HEAD
		if(bl[c_l].fc)
		{	
			for(ll i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_l].fc - elem[i].co);
				elem[i].cl += (t + bl[c_l].ac);
				elem[i].co = bl[c_l].cc;
			}	
			bl[c_l].fc = bl[c_l].cc = bl[c_l].ac = 0;
		}
		for(ll i=l,j=(c_l+1)*Z;i<j;i++)
		{
			ll t = fabs(x - elem[i].co);
			elem[i].cl += t;
			bl[c_l].tc += t;
			ll pos = 0;
			for(sp::iterator it=bl[c_l].s.begin();it != bl[c_l].s.end();it++,pos++)
			{
				if(it->first == elem[i].co)
				{
					ll u = it->first;
					ll v = it->second - 1;
					it++;
					bl[c_l].s.erase(bl[c_l].s.begin()+pos);
					if(v)
					bl[c_l].s.pb(mp(u, v));	
					break;
				}	
			}	
			elem[i].co = x;
		}	
		bool flag = 0;
		ll pos = 0;
		for(sp::iterator it=bl[c_l].s.begin();it != bl[c_l].s.end();it++,pos++)
		{
			if(it->first == x)
			{
				ll u = it->first;
				ll v = it->second + (c_l+1)*Z-l;
				px e = *it;
				it++;
				bl[c_l].s.erase(bl[c_l].s.begin()+pos);
				if(v)
				bl[c_l].s.pb(mp(u, v));
				flag = 1;
				break;	
			}	
		}	
		if(!flag)
		bl[c_l].s.pb(mp(x, (c_l+1)*Z-l));
		//RIGHT TAIL
		if(bl[c_r].fc)
		{	
			for(ll i=c_r*Z,j=(c_r+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_r].fc - elem[i].co);
				elem[i].cl += (t + bl[c_r].ac);
				elem[i].co = bl[c_r].cc;
			}	
			bl[c_r].fc = bl[c_r].cc = bl[c_r].ac = 0;
		}	
		for(ll i=c_r*Z;i<=r;i++)
		{
			ll t = fabs(x - elem[i].co);
			elem[i].cl += t;
			bl[c_r].tc += t;
			ll pos = 0;
			for(sp::iterator it=bl[c_r].s.begin();it != bl[c_r].s.end();it++,pos++)
			{
				if(it->first == elem[i].co)
				{
					ll u = it->first;
					ll v = it->second - 1;
					it++;
					bl[c_r].s.erase(bl[c_r].s.begin()+pos);
					if(v)
					bl[c_r].s.pb(mp(u, v));	
					break;
				}	
			}	
			elem[i].co = x;
		}	
		flag = 0;
		pos = 0;
		for(sp::iterator it=bl[c_r].s.begin();it != bl[c_r].s.end();it++,pos++)
		{
			if(it->first == x)
			{
				ll u = it->first;
				ll v = it->second + r-(c_r*Z)+1;
				it++;
				bl[c_r].s.erase(bl[c_r].s.begin()+pos);
				if(v)
				bl[c_r].s.pb(mp(u, v));
				flag = 1;
				break;	
			}	
		}	
		if(!flag)
		bl[c_r].s.pb(mp(x, r-(c_r*Z)+1));
		//MIDDLE
		for(ll i=c_l+1;i<c_r;i++)
		{
			for(sp::iterator it=bl[i].s.begin();it != bl[i].s.end();)
			{
				ll u = it->first;
				ll v = it->second;
				bl[i].tc += v*fabs(x - u);
				it++;
			}
			bl[i].s.clear();
			bl[i].s.pb(mp(x, Z));	
			if(bl[i].fc)
			{	
				bl[i].ac += fabs(bl[i].cc - x);
				bl[i].cc = x;
			}	
			else bl[i].fc = bl[i].cc = x;	
		}	
	}	
}

ll sqrtdec::query(ll l, ll r)
{
	ll c_l = l/Z;
	ll c_r = r/Z;
	ll sum = 0;
	if(c_l == c_r)
	{
		if(bl[c_l].fc)
		{	
			for(ll i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_l].fc - elem[i].co);
				elem[i].cl += (t + bl[c_l].ac);
				elem[i].co = bl[c_l].cc;
			}	
			bl[c_l].fc = bl[c_l].cc = bl[c_l].ac = 0;
		}	
		for(ll i=l;i<=r;i++)
		sum += elem[i].cl;	
	}	
	else
	{
		//LEFT HEAD
		if(bl[c_l].fc)
		{	
			for(ll i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_l].fc - elem[i].co);
				elem[i].cl += (t + bl[c_l].ac);
				elem[i].co = bl[c_l].cc;
			}	
			bl[c_l].fc = bl[c_l].cc = bl[c_l].ac = 0;
		}
		for(ll i=l,j=(c_l+1)*Z;i<j;i++)
		sum += elem[i].cl;
		//MIDDLE
		for(ll i=c_l+1;i<c_r;i++)
		sum += bl[i].tc;
		//RIGHT TAIL
		if(bl[c_r].fc)
		{	
			for(ll i=c_r*Z,j=(c_r+1)*Z;i<j;i++)
			{
				ll t = fabs(bl[c_r].fc - elem[i].co);
				elem[i].cl += (t + bl[c_r].ac);
				elem[i].co = bl[c_r].cc;
			}	
			bl[c_r].fc = bl[c_r].cc = bl[c_r].ac = 0;
		}	
		for(ll i=c_r*Z;i<=r;i++)
		sum += elem[i].cl;	
	}	
	return sum;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m;
	std::cin>>n>>m;
	Z = floor(sqrt(n));
	for(ll i=1;i<=n;i++)
	{
		elem[i].co = i;
		elem[i].cl = 0;
		bl[i/Z].s.pb(mp(i, 1));
	}
	for(ll i=0;i<=Z;i++)
	bl[i].tc = bl[i].cc = bl[i].fc = bl[i].ac = 0;
	sqrtdec T;
	while(m--)
	{
		ll q;
		std::cin>>q;
		if(--q)
		{
			ll l,r;
			std::cin>>l>>r;
			std::cout<<T.query(l, r)<<"\n";
		}	
		else
		{
			ll l,r,x;
			std::cin>>l>>r>>x;
			T.update(l, r, x);
		}	
	}	
	return 0;
}