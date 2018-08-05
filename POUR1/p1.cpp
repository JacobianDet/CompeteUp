#include <bits/stdc++.h>
#define mp std::make_pair

struct trx
{
    int a,b,c;
};

struct cmp
{
    bool operator()(const trx& X, const trx& Y)
    {
        if(X.a < Y.a)
        return 1;
        else if((X.a == Y.a) && (X.b < Y.b))
        return 1;
        else if((X.a == Y.a) && (X.b == Y.b) && (X.c < Y.c))
        return 1;
        else return 0;
    }
};

int c;
std::map<trx, int, cmp> mx;

int bfs_visit(int a, int b)
{
    std::queue<trx> Q;
    int ans = 0;
    Q.push({0, 0, 0});
    while(!Q.empty())
    {
        trx p = Q.front();
        Q.pop();
        int u = p.a;
        int v = p.b;
        int w = p.c;
        if(u == c || v == c)
        {
            ans = w;
            break;
        }
        if(!u && !v)
        {
            Q.push({u, b, w + 1});
            Q.push({a, v, w + 1});
        }
        else if((u == a) && (v == b))
        {
            Q.push({0, v, w + 1});
            Q.push({u, 0, w + 1});
        }
        else
        {
            int tx1 = a - u;
            int tx2 = b - v;
            if(tx1 >= v)
            Q.push({u + v, 0, w + 1});
            else if(tx1 < v)
            Q.push({a, v - tx1, w + 1});
            if(tx2 >= u)
            Q.push({0, u + v, w + 1});
            else if(tx2 < u)
            Q.push({u - tx2, b, w + 1});
            if(v)
            Q.push({u, 0, w + 1});
            if(u)
            Q.push({0, v, w + 1});
            if(u != a)
            Q.push({a, v, w + 1});
            if(v != b)
            Q.push({u, b, w + 1});
        }
    }
    return ans;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        int a,b;
        std::cin>>a>>b>>c;
        if(mx.find({a, b, c}) != mx.end())
        {
            std::cout<<mx[{a, b, c}]<<"\n";
            continue;
        }
        if((c % std::__gcd(a, b)) || c > std::max(a, b))
        {
            std::cout<<"-1\n";
            mx[{a, b, c}] = -1;
        }
        else
        {
            int ans = bfs_visit(a, b);
            std::cout<<ans<<"\n";
            mx[{a, b, c}] = ans;
        }
    }
    return 0;
}
