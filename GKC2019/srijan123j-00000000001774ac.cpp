#include <bits/stdc++.h>
using namespace std;

struct v
{
    int c,e;
};

struct u
{
    int i,c,e;
};

bool comp1(v a,v b)
{
    if((a.c*b.e)==(b.c*a.e))
    {
        if(a.c==b.c);
            return(a.e<b.e);
        return(a.c>b.c);
    }
    return((a.c*b.e)>(b.c*a.e));
}

bool comp2(v a,v b)
{
    if((a.e*b.c)==(b.e*a.c))
    {
        if(a.e==b.e);
            return(a.c<b.c);
        return(a.e>b.e);
    }
    return((a.e*b.c)>(b.e*a.c));
}

bool comp3(u a,u b)
{
    if(a.e==b.e)
    {
        if(a.c==b.c)
            return(a.i<b.i);
        return(a.c<b.c);
    }
    return(a.e>b.e);
}

bool comp4(u a,u b)
{
    if(a.c==b.c)
    {
        if(a.e==b.e)
            return(a.i<b.i);
        return(a.e<b.e);
    }
    return(a.c>b.c);
}

v x[100000];
u z[100000];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,w,d,s,i,j,tc[2],te[2];
    long long a[2],b[2];
    string r;
    cin>>t;
    for(w=1;w<=t;w++)
    {
        tc[0]=tc[1]=te[0]=te[1]=0;
        cout<<"Case #"<<w<<": ";
        cin>>d>>s;
        for(i=0;i<s;i++)
        {
            cin>>x[i].c>>x[i].e;
            te[0]+=x[i].e;
            tc[1]+=x[i].c;
        }
        r="";
        for(i=0;i<d;i++)
        {
            r.push_back('N');
            cin>>z[i].c>>z[i].e;
            z[i].i=i;
        }
        sort(x,x+s,comp1);
        sort(z,z+d,comp3);
        j=0;
        for(i=0;i<d;i++)
        {
            while(j<s && z[i].e<te[0] && z[i].c>tc[0])
            {
                if((te[0]-x[j].e)>=z[i].e)
                {
                    te[0]-=x[j].e;
                    tc[0]+=x[j].c;
                    j++;
                }
                else
                {
                    if((tc[0]+x[j].c)>=z[i].c)
                    {
                        a[0]=z[i].c-tc[0];
                        a[1]=x[j].c;
                        b[0]=te[0]-z[i].e;
                        b[1]=x[j].e;
                        if((a[0]*b[1])<=(a[1]*b[0]))
                            r[z[i].i]='Y';
                    }
                    break;
                }
            }
            if(z[i].e<=te[0] && z[i].c<=tc[0])
                r[z[i].i]='Y';
        }
        sort(x,x+s,comp2);
        sort(z,z+d,comp4);
        j=0;
        for(i=0;i<d;i++)
        {
            while(j<s && z[i].c<tc[1] && z[i].e>te[1])
            {
                if((tc[1]-x[j].c)>=z[i].c)
                {
                    tc[1]-=x[j].c;
                    te[1]+=x[j].e;
                    j++;
                }
                else
                {
                    if((te[1]+x[j].e)>=z[i].e)
                    {
                        a[0]=z[i].e-te[1];
                        a[1]=x[j].e;
                        b[0]=tc[1]-z[i].c;
                        b[1]=x[j].c;
                        if((a[0]*b[1])<=(a[1]*b[0]))
                            r[z[i].i]='Y';
                    }
                    break;
                }
            }
            if(z[i].e<=te[1] && z[i].c<=tc[1])
                r[z[i].i]='Y';
        }
        cout<<r<<"\n";
    }
    return 0;
}