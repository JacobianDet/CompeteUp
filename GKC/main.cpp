#include <bits/stdc++.h>
using namespace std;

struct v
{
    int i,j;
};

vector <vector<v> > e;
vector <bool> a;
set <pair<int,int> > d;
int c[10];

int call(int l)
{
    pair <int,int> p;
    int i,j,k;
    while(!d.empty())
    {
        p=*(d.begin());
        d.erase(d.begin());
        j=p.first;
        k=p.second;
        if(a[k]!=a[l])
            return j;
        for(i=0;i<e[k].size();i++)
        {
            if(c[e[k][i].i]==10000000)
            {
                c[e[k][i].i]=j+e[k][i].j;
                d.insert(make_pair(c[e[k][i].i],e[k][i].i));
            }
            else if(c[e[k][i].i]>j+e[k][i].j)
            {
                d.erase(d.find(make_pair(c[e[k][i].i],e[k][i].i)));
                c[e[k][i].i]=j+e[k][i].j;
                d.insert(make_pair(c[e[k][i].i],e[k][i].i));
            }
        }
    }
    return 10000000;
}

int main()
{
    freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,o,n,m,i,j,k,l,r,co,p;
	v x;
	cin>>t;
	for(o=1;o<=t;o++)
    {
        cout<<"Case #"<<o<<": ";
        co=0;
        r=INT_MAX;
        cin>>n>>m;
        a.resize(n);
        e.resize(n);
        for(i=0;i<m;i++)
        {
            cin>>j>>k>>x.j;
            j--;
            k--;
            x.i=k;
            e[j].push_back(x);
            x.i=j;
            e[k].push_back(x);
        }
        j=(1<<n)-1; //comment
        for(i=1;i<j;i++)
        {
            for(k=0;k<n;k++)
            {
                if((1<<k)&i)
                    a[k]=true;
                else
                    a[k]=false;
            }
            l=0;
            for(k=0;k<n;k++)
            {
                d.clear();
                d.insert(make_pair(0,k));
                for(p=0;p<n;p++)
                    c[p]=10000000;
                c[k]=0;
                l+=call(k);
            }
            if(l<r)
            {
                r=l;
                co=1;
            }
            else if(l==r)
                co++;
        }
        e.clear();
        cout<<co<<"\n";
    }
    return 0;
}
