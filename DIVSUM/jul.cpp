#include <bits/stdc++.h>

int A[102], B[102], C[102], D[102];
int na, nb, nc, nd;

void NSUB(void)
{
    int temp = 0;
    int nc = 102;
    memset(C, 0, sizeof(C));
    for(int i=0;i<na;i++)
    {
        int x = (A[i] - B[i]) - temp;
        if(x < 0)
        {
            x += 10;
            temp = 1;
        }    
        else temp = 0;
        C[i] = x;
    }
    for(int i=101;i>=0;i--)
    {
        if(C[i])
        break;
        else nc--;
    }
    if(!nc)
    nc = 1;
    memset(A, 0, sizeof(A));
    na = 0;
    for(int i=nc-1;i>=0;i--)
    A[na++] = C[i];
    return;
}

void NDIV(void)
{
    int temp = 0;
    memset(D, 0, sizeof(D));
    int d = 0;
    nd = 0;
    while(temp < 2)
    temp = 10*temp + A[d++];
    while(na > d)
    {
        D[nd++] = (temp/2);
        temp = 10*(temp%2) + A[d++];
    }
    if(na == d)
    {
        D[nd++] = (temp/2);
        temp %= 2;
        memset(A, 0, sizeof(A));
        na = 0;
        if(!nd)
        nd = 1;
        for(int i=nd-1;i>=0;i--)
        A[na++] = D[i];
    }
    return;
}

void NADD(void)
{
    int temp = 0;
    nc = 102;
    memset(C, 0, sizeof(C));
    for(int i=0,z=std::max(na, nb);i<z;i++)
    {
        int x = (A[i] + B[i]) + temp;
        if(x > 9)
        {
            x -= 10;
            temp = 1;
        }
        else temp = 0;
        C[i] = x;
    }
    int z = std::max(na, nb);
    C[z] = temp;
    for(int i=101;i>=0;i--)
    {
        if(C[i])
        break;
        else nc--;
    }
    if(!nc)
    nc = 1;
    memset(A, 0, sizeof(A));
    na = 0;
    for(int i=nc-1;i>=0;i--)
    A[na++] = C[i];
    if(!na)
    na = 1;
    return;
}

int main(void)
{
    for(int t=0;t<10;t++)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        std::string a,b;
        std::cin>>a>>b;
        na = 0, nb = 0;
        for(int i=(int)a.size()-1;i>=0;i--)
        {
            A[na] = (a[i] - '0');
            na++;
        }    
        for(int i=(int)b.size()-1;i>=0;i--)
        {
            B[nb] = (b[i] - '0');
            nb++;
        }
        NSUB();
        NDIV();
        NADD();
        for(int i=0;i<na;i++)
        std::cout<<A[i];
        std::cout<<"\n";
        for(int i=0;i<nd;i++)
        std::cout<<D[i];
        std::cout<<"\n";
    }
    return 0;
}