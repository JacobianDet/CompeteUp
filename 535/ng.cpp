#include <bits/stdc++.h>

/* R = 0
  G = 1
  B = 2*/

int cx[3][3];
int arr[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    if(n >= 3)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')
            cx[i%3][0]++;
            else if(s[i] == 'G')
            cx[i%3][1]++;
            else cx[i%3][2]++;
        }
        int df = 10000001;
        int af = -1;
        for(int i=0;i<6;i++)
        {
            int idf = 0;
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(arr[i][j] != k)
                    idf += cx[k][j];
                }
            }
            if(df > idf)
            {
                df = idf;
                af = i;
            }
        }
        std::cout<<df<<"\n";
        for(int i=0;i<n;i++)
        {
            if(arr[af][0] == i%3)
            std::cout<<'R';
            else if(arr[af][1] == i%3)
            std::cout<<'G';
            else std::cout<<'B';
        }
        std::cout<<"\n";
    }
    else if(n == 1)
    std::cout<<"0\n"<<s<<"\n";
    else
    {
        if(s[0] != s[1])
        std::cout<<"0\n"<<s<<"\n";
        else 
        {
            if(s[0] == 'R')
            std::cout<<"1\n"<<"RB\n";
            else if(s[0] == 'G')
            std::cout<<"1\n"<<"GB\n";
            else std::cout<<"1\n"<<"GB\n";
        }
    }
    return 0;
}