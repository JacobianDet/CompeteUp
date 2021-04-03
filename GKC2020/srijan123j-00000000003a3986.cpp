#include <bits/stdc++.h>
using namespace std;

long long ans;
vector<int> p, d;
vector<long long> a, b;
vector<vector<int>> e;

void call1(int n, int i, long long l, long long x, long long y)
{
    long long temp;
    temp = l/x;
    while((temp*x)>l)
        temp--;
    while(((temp+1)*x)<=l)
        temp++;
    if((temp*x)<l)
        temp++;
    //cout<<i<<" "<<temp<<"\n";
    ans += (temp*n);
    temp = l/y;
    while((temp*y)>l)
        temp--;
    while(((temp+1)*y)<=l)
        temp++;
    if((temp*y)<l)
        temp++;
    ans += (temp*n);
    //cout<<i<<" "<<temp<<" ";
    ans -= (a[i]*b[i]);
    for(int j=0; j<e[i].size(); j++)
        call1(n, e[i][j], l+1, x, y);
}

void call(int n, int x, int y)
{
    int i, k = 1, j = 1;
    while(j < n-1)
    {
        j *= 2;
        k++;
    }
    vector<int> e(k);
    vector<vector<int>> c(n, e);
    for(i=0; i<n; i++)
        c[i][0] = p[i];
    for(i=1; i<k; i++)
        for(j=0; j<n; j++)
        {
            if(c[j][i-1] != -1)
                c[j][i] = c[c[j][i-1]][i-1];
            else
                c[j][i] = -1;
        }
    queue<int> q;
    for(i=0; i<n; i++)
        if(d[i] == 0)
            q.push(i);
    int x1 = -1, y1 = -1, tempx = x, tempy = y, z;
    while(tempx > 0)
    {
        x1++;
        tempx >>= 1;
    }
    while(tempy > 0)
    {
        y1++;
        tempy >>= 1;
    }
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        if(x1 < k)
        {
            j = i;
            z = x1;
            tempx = 1<<x1;
            while(tempx > 0)
            {
                if(x&tempx)
                {
                    if(c[j][z] == -1)
                        break;
                    j = c[j][z];
                }
                z--;
                tempx >>= 1;
            }
            if(tempx == 0)
            {
                //cout<<i<<" "<<j<<" "<<x<<"\n";
                a[j] += a[i];
            }
        }
        if(y1 < k)
        {
            j = i;
            z = y1;
            tempy = 1<<y1;
            while(tempy > 0)
            {
                if(y&tempy)
                {
                    if(c[j][z] == -1)
                        break;
                    j = c[j][z];
                }
                z--;
                tempy >>= 1;
            }
            if(tempy == 0)
            {
                //cout<<i<<" "<<j<<" "<<y<<"\n";
                b[j] += b[i];
            }
        }
        if(p[i] >= 0)
        {
            d[p[i]]--;
            if(d[p[i]] == 0)
                q.push(p[i]);
        }
    }
    // cout<<"\n";
    // for(i=0; i<n; i++)
    //     cout<<a[i]<<" "<<b[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, z, n, x, y, i;
    long double r;
    cin>>t;
    for(z=1; z<=t; z++)
    {
        cout<<"Case #"<<z<<": ";
        ans = 0;
        cin>>n>>x>>y;
        p.resize(n);
        a.resize(n, 1);
        b.resize(n, 1);
        d.resize(n);
        e.resize(n);
        p[0] = -1;
        for(i=1; i<n; i++)
        {
            cin>>p[i];
            p[i]--;
            e[p[i]].push_back(i);
            d[p[i]]++;
        }
        call(n, x, y);
        call1(n, 0, 1, x, y);
        r = ans;
        r = r/n;
        r = r/n;
        cout<<fixed;
        cout<<setprecision(10);
        cout<<r<<"\n";
        a.clear();
        b.clear();
        d.clear();
        e.clear();
    }
    return 0;
}