#include <bits/stdc++.h>

int main(void)
{
    int x[3], y[3];
    for(int i=0;i<3;i++)
    std::cin>>x[i]>>y[i];
    int sx[3], sy[3];
    for(int i=0;i<3;i++)
    {
        sx[i] = x[i];
        sy[i] = y[i];
    }
    std::sort(sx, sx+3);
    std::sort(sy, sy+3);
    int mx = sx[1], my = sy[1];
    std::cout<<(sx[2] - sx[0]) + (sy[2] - sy[0]) + 1<<"\n";
    for(int i=0;i<3;i++)
    {
        if(!i)
        {
            if(x[i] < mx)
            {
                for(int j=x[i];j<=mx;j++)
                std::cout<<j<<" "<<y[i]<<"\n";
            }
            else
            {
                for(int j=x[i];j>=mx;j--)
                std::cout<<j<<" "<<y[i]<<"\n";
            }
            if(y[i] < my)
            {
                for(int j=y[i]+1;j<=my;j++)
                std::cout<<mx<<" "<<j<<"\n";
            }
            else
            {
                for(int j=y[i]-1;j>=my;j--)
                std::cout<<mx<<" "<<j<<"\n";
            }
        }
        else
        {
            if(x[i] < mx)
            {
                for(int j=x[i];j<mx;j++)
                std::cout<<j<<" "<<y[i]<<"\n";
            }
            else
            {
                for(int j=x[i];j>mx;j--)
                std::cout<<j<<" "<<y[i]<<"\n";
            }
            if(y[i] < my)
            {
                for(int j=y[i];j<my;j++)
                std::cout<<mx<<" "<<j<<"\n";
            }
            else
            {
                for(int j=y[i];j>my;j--)
                std::cout<<mx<<" "<<j<<"\n";
            }
        }    
    }
    return 0;
}