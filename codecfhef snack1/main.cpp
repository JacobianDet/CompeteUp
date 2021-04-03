#include <iostream>
#include <string>
int main(void)
{
    int t,c[2];
    std::string s;
    std::cin>>t;
    std::cin.ignore();
    for(int i=0;i<t;i++)
    {
        c[0]=0;
        c[1]=0;
        std::getline(std::cin,s,'\n');
        for(size_t j=0;j<s.size();j++)
        {
            if(s[j]=='m'&&s[j-1]=='s')
            {
                s.erase(s.begin()+j-1);
                j-=1;
                c[1]--;
            }
            else if(s[j]=='m'&&s[j+1]=='s')
            s.erase(s.begin()+j+1);
            if(s[j]=='m')
            c[0]++;
            else c[1]++;
        }
        s.clear();
        if(c[0]>c[1])
        std::cout<<"mongooses\n";
        else if(c[1]>c[0])
        std::cout<<"snakes\n";
        else std::cout<<"tie\n";
    }
    return 0;
}
