#include <bits/stdc++.h>

int main(void)
{
    int n;
    std::cin>>n;
    std::string a, b;
    std::cin>>a>>b;
    int px = 0;
    if(n & 1)
    {
        for(int i=0;i<n/2;i++)
        {
            char u = a[i];
            char v = a[n-i-1];
            char w = b[i];
            char x = b[n-i-1];
            if(((u != v) && (w != x)) || ((u == v) && (w != x)))
            {
                if(u == w)
                {
                    if(v != x)
                    px++;
                }
                else if(u == x)
                {
                    if(v != w)
                    px++;
                }
                else if(v == x)
                {
                    if(u != w)
                    px++;
                }
                else if(v == w)
                {
                    if(u != x)
                    px++;
                }
                else px += 2;
            }
            else if((u != v) && (w == x))
            px++;
        }
        if(a[n/2] != b[n/2])
        px++;
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            char u = a[i];
            char v = a[n-i-1];
            char w = b[i];
            char x = b[n-i-1];
            if(((u != v) && (w != x)) || ((u == v) && (w != x)))
            {
                if(u == w)
                {
                    if(v != x)
                    px++;
                }
                else if(u == x)
                {
                    if(v != w)
                    px++;
                }
                else if(v == x)
                {
                    if(u != w)
                    px++;
                }
                else if(v == w)
                {
                    if(u != x)
                    px++;
                }
                else px += 2;
            }
            else if((u != v) && (w == x))
            px++;
        }
    }
    std::cout<<px<<"\n";
    return 0;
}