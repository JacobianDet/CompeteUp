#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>arr[i];
    int i=0, j=n-1;
    ll sum = 0;
    ll s1 = 0, s3 = 0;
    while(i < j)
    {
        if(s1 == s3)
        {
            sum = s1;
            s1 += arr[i];
            s3 += arr[j];
            i++;
            j--;
        }
        else if(s1 < s3)
        {
            s1 += arr[i];
            i++;
        }    
        else 
        {
            s3 += arr[j];
            j--; 
        }    
    }
    if(i == j)
    {
        if(s1 + arr[i] == s3)
        sum = std::max(sum, s3);
        if(s3 + arr[j] == s1)
        sum = std::max(sum, s1);
    }
    if(s1 == s3)
    sum = std::max(sum, s1);
    std::cout<<sum<<"\n";
    return 0;
}