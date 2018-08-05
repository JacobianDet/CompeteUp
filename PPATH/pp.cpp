#include <bits/stdc++.h>

std::vector<bool> kp(10000, true);
std::vector<std::vector<int>> primes(10000);

void siever(void)
{
    kp[0] = false;
    kp[1] = false;
    for(int p = 2; p*p < 10001; p++)
    {
        if(kp[p] == true)
        {
            for(int i = p*p; i < 10001; i+=p)
            kp[i] = false;
        }
    }
}

void prime_graph(void)
{
    for(int p = 1000; p < 9999; p++)
    {
        if(kp[p] == true)
        {
            int w = p;
            std::vector<int> dig(4);
            int j = 3;
            while(w)
            {
                dig[j] = w%10;
                w /= 10;
                j--;
            }
            for(j=0;j<4;j++)
            {
                for(int k = 0; k < 10; k++)
                {
                    if(j == 0)
                    w = 0;
                    else if(j == 1)
                    w = dig[0]*1000;
                    else if(j == 2)
                    w = dig[0]*1000 + dig[1]*100;
                    else w = dig[0]*1000 + dig[1]*100 + dig[2]*10;
                    if((j == 0 && k == 0) || (k == dig[j]))
                    continue;
                    else {
                          if(j == 0)
                          w = k*1000 + dig[1]*100 + dig[2]*10 + dig[3];
                          else if(j == 1)
                          w += k*100 + dig[2]*10 + dig[3];
                          else if(j == 2)
                          w += k*10 + dig[3];
                          else w += k;
                    }
                    if(kp[w] == true)
                    primes[p].push_back(w);
                }
            }
        }
    }
}

void bfs_visit(int a, std::vector<int> &lev)
{
    std::queue<int> q;
    q.push(a);
    lev[a] = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=0,j=primes[t].size();i<j;i++)
        {
            if(lev[primes[t][i]] == 0)
            {
                q.push(primes[t][i]);
                lev[primes[t][i]] = 1 + lev[t];
            }
        }
    }
    return;
}

int main(void)
{
    siever();
    prime_graph();
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        int a,b;
        std::cin>>a>>b;
        std::vector<int> lev(10000, 0);
        bfs_visit(a, lev);
        if(lev[b] == 0)
        std::cout<<"Impossible\n";
        else std::cout<<lev[b]-1<<"\n";
    }
    return 0;
}
