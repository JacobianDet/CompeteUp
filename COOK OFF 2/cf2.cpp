#include <iostream>

void bincount(long long beg,long long las,long long &c)
{
    if(beg > las)
    return;
    long long mid = (beg + las)/2;
    c++;
    bincount(beg,mid-1,c);
    bincount(mid+1,las,c);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long k,A,B,chor=0,police=0;
        std::cin>>k>>A>>B;
        bincount(A,B,chor);
        bincount(B,k+A,police);
        if(chor - 2 > police - 2)
        std::cout<<police - 2<<std::endl;
        else if(chor - 2 < police - 2)
        std::cout<<chor - 2<<std::endl;
        else std::cout<<0<<std::endl;
    }
    return 0;
}
