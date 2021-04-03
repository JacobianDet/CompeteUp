#include <bits/stdc++.h>
#define CHOR 1000001

typedef long long ll;

int arr[CHOR], lo[CHOR];
ll sx[CHOR];

void siever(void)
{
    for(int i=1;i<CHOR;i++)
    lo[i] = i;
    for(ll i=2;i*i<CHOR;i++)
    {
        if(lo[i] == i)
        {
            for(ll p=i*i;p<CHOR;p+=i)
            {
                if(lo[p] == p)
                lo[p] = i;
            }
        }
    }
    return;
}

ll fexp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    siever();
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            std::cin>>arr[i];
            ll t = arr[i];
            ll x = 0;
            while(t > 1)
            {
                ll p = lo[t];
                while(!(t%p))
                t /= p;
                x += p;
            }
            sx[i] = x;
        }
        ll ct = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i != j) && (!(arr[j] % arr[i])) && (!(sx[j] % sx[i])))
                ct++;  
            }
        }
        std::cout<<ct<<"\n";
    }
    return 0;
}