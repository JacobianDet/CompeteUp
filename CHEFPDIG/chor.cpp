#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    std::cin.ignore();
    for(int i=0;i<T;i++)
    {
        std::vector<long long> z(10,0);
        char c = getchar();
        std::string s;
        while(c != '\n')
        {
            z[c-'0']++;
            c = getchar();
        }
        for(int j=6,k=5;j<9;j++)
        {
            while(k < 10)
            {
                if((j == k && z[j]>1)||(j != k && z[j]>0 && z[k]>0))
                s += (char)(j*10 + k);
                k++;
            }
            k %= 10;
        }
        if(z[9]>0 && z[0]>0)
        s += 'Z';
        if(s == "")
        std::cout<<std::endl;
        else std::cout<<s<<std::endl;
    }
    return 0;
}
