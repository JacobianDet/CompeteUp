#include <bits/stdc++.h>

long long GCD(long long a, long long b)
{
    if(b == 0)
    return a;
    else return GCD(b, a%b);
}
//In this problem, diophantine equation is used to analyze where we can get no solution and for getting solution we fixed one jug for pouring and shifting and other for shift addition and discharging to get minimum steps and then calculated min value//
long long stepc(long long x,long long y,long long chor,long long police,long long res)
{
   long long counter = 0;
   while(x != res && y != res)
   {
       counter++;
       if(x == 0)
       x = chor;
       else if(y == police)
       y = 0;
       else if(y < police)
       {
           if(y + x > police)
           {
               long long temp = y;
               y = police;
               x -= (police - temp);
           }
           else{
               y += x;
               x = 0;
           }
       }
   }
   return counter;
}

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long a,b,c,counter1,counter2;
        std::cin>>a>>b>>c;
        if(c % GCD(a,b) != 0 || c > std::max(a,b))
        {
            std::cout<<-1<<std::endl;
            continue;
        }
        counter1 = stepc(0,0,a,b,c);
        counter2 = stepc(0,0,b,a,c);
        std::cout<<std::min(counter1,counter2)<<std::endl;
    }
    return 0;
}
