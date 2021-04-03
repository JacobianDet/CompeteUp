#include <iostream>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        int N,bal=0,fine=0;
        std::cin>>N;
        bool a[N];
        for(int j=0;j<N;j++)
        std::cin>>a[j];
        int zc=0;
        for(int j=0;j<N;j++)
        {
            if(a[j]==0)
            {
                bal+=1000;
                fine+=100;
                zc++;
            }
            else if(a[j]==1 && zc!=0)
            fine+=100;
            else continue;
        }
        std::cout<<bal+fine<<std::endl;
    }
}
