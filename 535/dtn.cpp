#include <bits/stdc++.h>

int arr[130], ctr[10001];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
        ctr[arr[i]]++;
    }    
    int x = 1, y = 1;
    std::sort(arr, arr+n);
    x = arr[n-1];
    for(int i=0;i<10001;i++)
    {
        if(ctr[i] == 2)
        y = (y * i)/std::__gcd(y, i);
    }
    for(int i=0;i<n;i++)
    {
        if(x % arr[i])
        y = (y * arr[i])/std::__gcd(y, arr[i]);
    }
    std::cout<<x<<" "<<y<<"\n";
    return 0;
}