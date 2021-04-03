#include <bits/stdc++.h>
using namespace std;

struct v
{
    int i,j;
};

int a[250][250],d[250][2],r,c,k;
queue <v> q;
vector <v> e;

void call()
{
    v p;
    int i,j;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        i=p.i;
        j=p.j;
        if(i>0 && a[i-1][j]==k)
        {
            a[i-1][j]=a[i][j]+1;
            q.push({i-1,j});
        }
        if(j>0 && a[i][j-1]==k)
        {
            a[i][j-1]=a[i][j]+1;
            q.push({i,j-1});
        }
        if(j<(c-1) && a[i][j+1]==k)
        {
            a[i][j+1]=a[i][j]+1;
            q.push({i,j+1});
        }
        if(i<(r-1) && a[i+1][j]==k)
        {
            a[i+1][j]=a[i][j]+1;
            q.push({i+1,j});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,z,i,j,l,h,m;
    bool f;
    char s;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        cout<<"Case #"<<z<<": ";
        cin>>r>>c;
        k=r*c;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                a[i][j]=k;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                cin>>s;
                if(s=='0')
                    e.push_back({i,j});
                else
                {
                    a[i][j]=0;
                    q.push({i,j});
                }
            }
        call();
        l=0;
        h=r+c-2;
        j=e.size();
        while(l<h)
        {
            f=false;
            m=(l+h)>>1;
            for(i=0;i<r;i++)
            {
                d[i][0]=0;
                d[i][1]=c-1;
            }
            for(i=0;i<j;i++)
                if(a[e[i].i][e[i].j]>m)
                {
                    f=true;
                    for(k=0;k<r;k++)
                    {
                        d[k][0]=max(d[k][0],e[i].j-m+abs(k-e[i].i));
                        d[k][1]=min(d[k][1],e[i].j+m-abs(k-e[i].i));
                    }
                }
            if(f==false)
                h=m;
            else
            {
                for(k=0;k<r;k++)
                    if(d[k][0]<=d[k][1])
                        break;
                if(k<r)
                    h=m;
                else
                    l=m+1;
            }
        }
        cout<<l<<"\n";
        e.clear();
    }
    return 0;
}