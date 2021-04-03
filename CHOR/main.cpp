#include <iostream>
#include <vector>
#include <string>

void nearpal(std::vector<int> &,int,int);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long T;
    std::cin>>T;
    std::cin.ignore();
    for(long long i=0;i<T;i++)
    {
        std::vector<int>n;
        std::string x;
        std::getline(std::cin,x);
        for(int j=0,k=x.size();j<k;j++)
        {
            if(n.size() == 0 && x[j]-'0'==0 && j != k-1)
            continue;
            else n.push_back(x[j]-'0');
        }
        if(n.size() == 1 && n[0] != 9)
        {
            std::cout<<n[0] + 1<<std::endl;
            continue;
        }
        int count=0;
        for(int j=0,k=(int)n.size();j<k;j++)
        {
            if(n[j] == 9)
            count++;
        }
        if(count == (int)n.size())
        {
            for(int j=0;j<count+1;j++)
            {
                if(j == 0 || j == count)
                std::cout<<1;
                else std::cout<<0;
            }
            std::cout<<std::endl;
            continue;
        }
        nearpal(n,0,(int)n.size()-1);
        n.clear();
    }
    return 0;
}

void nearpal(std::vector<int> &a,int beg,int las)
{
    std::vector<int>chor = a;
    while(beg < las)
    {
        chor[las]=chor[beg];
        beg++;
        las--;
    }
    int flag = 0;
    for(int i=0,j=(int)chor.size();i<j;i++)
    {
        if(chor[i] < a[i])
        {
            flag = 2;
            break;
        }
        else if(chor[i] > a[i])
        {
            flag = 1;
            break;
        }
        else flag=0;
    }
    if((beg == las || beg == las+1) && (flag == 2 || flag == 0))
    {
        while(chor[beg] == 9)
        {
            chor[beg]=(chor[beg]+1)%10;
            chor[las] = chor[beg];

            if(beg == las +1)
            {
                beg -= 2;
                las += 2;
            }
            else {
            beg--;
            las++;
            }
        }
        chor[beg]=(chor[beg]+1)%10;
        chor[las]=chor[beg];
    }
    for(int i=0,j=chor.size();i<j;i++)
    std::cout<<chor[i];
    std::cout<<std::endl;
}

