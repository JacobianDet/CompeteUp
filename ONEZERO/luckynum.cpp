#include <bits/stdc++.h>
#define mp std::make_pair

bool bfs_ans[10000][2];

struct xxx
{
    int mv,p6,dig;
};

std::pair<int, int> bfs_visit(int x)
{
    std::pair<int, int> res = mp(-1, -1);
    std::queue<xxx> Q;
    Q.push({(6%x), 1, 1});
    Q.push({(8%x), 0, 1});
    int n = 0;
    while(!Q.empty())
    {
        xxx p = Q.front();
        Q.pop();
        int v1 = p.mv;
        int v2 = p.p6;
        int n1 = p.dig;
        n = std::max(n, n1);
        if(n1 > 200)
        break;
        if(!v1)
        {
            res = mp(v2, n1);
            bfs_ans[v1][(v2 == 0)] = 1;
            break;
        }
        else
        {
            if(v2)
            {
                if(bfs_ans[v1][0])
                continue;
                else
                {
                    int nv1 = ((((10%x) * (v1%x))%x) + (6%x))%x;
                    Q.push({nv1, v2, n1+1});
                    bfs_ans[v1][(v2 == 0)] = 1;
                }
            }
            else
            {
                if(bfs_ans[v1][0] && bfs_ans[v1][1])
                continue;
                else if(bfs_ans[v1][0])
                {
                    int nv1 = ((((10%x) * (v1%x))%x) + (8%x))%x;
                    Q.push({nv1, v2, n1+1});
                    bfs_ans[v1][(v2 == 0)] = 1;
                }
                else if(bfs_ans[v1][1])
                {
                    int nv1 = ((((10%x) * (v1%x))%x) + (6%x))%x;
                    Q.push({nv1, n1+1, n1+1});
                    bfs_ans[v1][(v2 == 0)] = 1;
                }
                else
                {
                    int nv1 = ((((10%x) * (v1%x))%x) + (8%x))%x;
                    Q.push({nv1, v2, n1+1});
                    nv1 = ((((10%x) * (v1%x))%x) + (6%x))%x;
                    Q.push({nv1, n1+1, n1+1});
                    bfs_ans[v1][(v2 == 0)] = 1;
                }
            }
        }
    }
    return res;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(bfs_ans, 0, sizeof(bfs_ans));
        int x;
        std::cin>>x;
        std::pair<int, int> ax = bfs_visit(x);
        if(ax.first == -1)
        std::cout<<"-1\n";
        else
        {
            if(!ax.first)
            {
                for(int i=1;i<=ax.second;i++)
                std::cout<<"8";
                std::cout<<"\n";
            }
            else
            {
                for(int i=1;i<ax.first;i++)
                std::cout<<"8";
                for(int i=ax.first;i<=ax.second;i++)
                std::cout<<"6";
                std::cout<<"\n";
            }
        }
    }
    return 0;
}
