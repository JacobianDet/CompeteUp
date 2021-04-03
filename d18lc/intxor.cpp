#include <bits/stdc++.h>

int arr[50001], x[50001], vx[17001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    vx[1] = 1;
    for(int i=2;i<17001;i++)
    vx[i] = (3*(i-1)-vx[i-1]);
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(x, 0, sizeof(x));
        int n;
        std::cin>>n;
        if(n % 3)
        {
            for(int i=1;i<=n;i++)
            {
                std::cout<<"1 "<<i<<" "<<(((i+1) > n) ? (i+1)%n : (i+1))<<" "<<(((i+2) > n) ? (i+2)%n : (i+2))<<std::endl;
                int val;
                std::cin>>val;
                if(val == -1)
                return 0;
                else arr[i] = val; 
            }
            int a = 0, b = 0;
            for(int i=1;i<=n;i++)
            {
                int tmp = b;
                b = a ^ b ^ arr[i];
                a = tmp;
            }
            if(!(((n-1) - 1) % 3))
            {
                x[2] = a;
                x[1] = a ^ b;
            }
            else if(!(((n-1) - 3) % 3))
            {
                x[1] = b;
                x[2] = a ^ b;
            }
            for(int i=1;i<=n-2;i++)
            x[i+2] = x[i] ^ x[i+1] ^ arr[i];
        }
        else
        {
            for(int i=1;i<=vx[n/3];i++)
            {
                std::cout<<"1 "<<i<<" "<<(((i+1) > vx[n/3]) ? (i+1)%vx[n/3] : (i+1))<<" "<<(((i+2) > vx[n/3]) ? (i+2)%vx[n/3] : (i+2))<<std::endl;
                int val;
                std::cin>>val;
                if(val == -1)
                return 0;
                else arr[i] = val;
            }
            int a = 0, b = 0;
            for(int i=1;i<=vx[n/3];i++)
            {
                int tmp = b;
                b = a ^ b ^ arr[i];
                a = tmp;
            }
            //std::cout<<a<<" "<<b<<"\n";
            if(!(((vx[n/3]-1) - 1) % 3))
            {
                x[2] = a;
                x[1] = a ^ b;
            }
            else if(!(((vx[n/3]-1) - 3) % 3))
            {
                x[1] = b;
                x[2] = a ^ b;
            }
            for(int i=1;i<=vx[n/3]-2;i++)
            x[i+2] = x[i] ^ x[i+1] ^ arr[i];
            for(int i=vx[n/3]+1;i<=n;i++)
            {
                std::cout<<"1 "<<i<<" "<<(((i+1) > n) ? (vx[n/3] + (i+1)%n) : (i+1))<<" "<<(((i+2) > n) ? (vx[n/3] + (i+2)%n) : (i+2))<<std::endl;
                int val;
                std::cin>>val;
                if(val == -1)
                return 0;
                else arr[i] = val;
            }
            a = 0, b = 0;
            for(int i=vx[n/3]+1;i<=n;i++)
            {
                int tmp = b;
                b = a ^ b ^ arr[i];
                a = tmp;
            }
            //std::cout<<a<<" "<<b<<"\n";
            if(!(((n-vx[n/3]-1) - 1) % 3))
            {
                x[vx[n/3]+2] = a;
                x[vx[n/3]+1] = a ^ b;
            }
            else if(!(((n-vx[n/3]-1) - 3) % 3))
            {
                x[vx[n/3]+1] = b;
                x[vx[n/3]+2] = a ^ b;
            }
            for(int i=vx[n/3]+1;i<=n-2;i++)
            x[i+2] = x[i] ^ x[i+1] ^ arr[i];
        }    
        std::cout<<"2 ";
        for(int i=1;i<=n-1;i++)
        std::cout<<x[i]<<" ";
        std::cout<<x[n]<<std::endl;
        int ver = 0;
        std::cin>>ver;
        if(ver == -1)
        return 0;
    }
    return 0;
}