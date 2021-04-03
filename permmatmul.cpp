#include <bits/stdc++.h>
using namespace std;

int vx[1000001], arr[1000001], res[1000001], temp[1000001];

void MATMUL(int n, int k)
{
    for(int i=1;i<=n;i++)
    res[i] = i;
    int ct = 1;
    for(int i=1;i<=n;i+=2)
    {
        arr[i] = ct;
        arr[i+1] = n/2 + ct;
        ct++;
    }    
    while(k)
    {
        if(k & 1)
        {
            for(int i=1;i<=n;i++)
            temp[i] = arr[res[i]];
            for(int i=1;i<=n;i++)
            res[i] = temp[i];    
        }    
        for(int i=1;i<=n;i++)
        temp[i] = arr[arr[i]];
        for(int i=1;i<=n;i++)
        arr[i] = temp[i];
        k >>= 1;
    }
    return;
}

int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>vx[i];
    MATMUL(n, k);
    for(int i=1;i<=n;i++)
    cout<<vx[res[i]]<<" ";
    cout<<"\n";
    return 0;
}