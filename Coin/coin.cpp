#include <iostream>
int main(void)
{
    int n;
    std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
        std::cout<<std::endl<<a[i];
    }
    return 0;
}
