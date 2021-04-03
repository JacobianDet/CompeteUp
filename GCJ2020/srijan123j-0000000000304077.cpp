#include <bits/stdc++.h>
using namespace std;

long long temp=500000000,temp1=1000000000;

string solve(int i)
{
    long long x1,x2,y1,y2,l,h,m;
    string s="";
    if(i==1)
    {
        l=-temp1;
        h=temp;
        y1=temp;
    }
    else if(i==2)
    {
        l=-temp1;
        h=-temp;
        y1=temp;
    }
    else if(i==3)
    {
        l=-temp1;
        h=-temp;
        y1=-temp;
    }
    else if(i==4)
    {
        l=-temp1;
        h=temp;
        y1=-temp;
    }
    else
    {
        l=-temp1;
        h=0;
        y1=0;
    }
    while(l<h)
    {
        m=(l+h)>>1;
        cout<<m<<" "<<y1<<endl;
        cin>>s;
        if(s=="WRONG" || s=="CENTER")
            return s;
        else if(s=="HIT")
            h=m;
        else
            l=m+1;
    }
    x1=l;
    if(i==1)
    {
        l=temp;
        h=temp1;
        y1=temp;
    }
    else if(i==2)
    {
        l=-temp;
        h=temp1;
        y1=temp;
    }
    else if(i==3)
    {
        l=-temp;
        h=temp1;
        y1=-temp;
    }
    else if(i==4)
    {
        l=temp;
        h=temp1;
        y1=-temp;
    }
    else
    {
        l=0;
        h=temp1;
        y1=0;
    }
    while(l<h)
    {
        m=(l+h+1)>>1;
        cout<<m<<" "<<y1<<endl;
        cin>>s;
        if(s=="WRONG" || s=="CENTER")
            return s;
        else if(s=="HIT")
            l=m;
        else
            h=m-1;
    }
    x2=l;
    x1=(x1+x2)>>1;

    if(i==1)
    {
        l=-temp1;
        h=temp;
        //y1=temp;
    }
    else if(i==2)
    {
        l=-temp1;
        h=temp;
        //y1=temp;
    }
    else if(i==3)
    {
        l=-temp1;
        h=-temp;
        //y1=-temp;
    }
    else if(i==4)
    {
        l=-temp1;
        h=-temp;
        //y1=-temp;
    }
    else
    {
        l=-temp1;
        h=0;
        //y1=0;
    }
    while(l<h)
    {
        m=(l+h)>>1;
        cout<<x1<<" "<<m<<endl;
        cin>>s;
        if(s=="WRONG" || s=="CENTER")
            return s;
        else if(s=="HIT")
            h=m;
        else
            l=m+1;
    }
    y1=l;
    if(i==1)
    {
        l=temp;
        h=temp1;
        //y1=temp;
    }
    else if(i==2)
    {
        l=temp;
        h=temp1;
        //y1=temp;
    }
    else if(i==3)
    {
        l=-temp;
        h=temp1;
        //y1=-temp;
    }
    else if(i==4)
    {
        l=-temp;
        h=temp1;
        //y1=-temp;
    }
    else
    {
        l=0;
        h=temp1;
        //y1=0;
    }
    while(l<h)
    {
        m=(l+h+1)>>1;
        cout<<x1<<" "<<m<<endl;
        cin>>s;
        if(s=="WRONG" || s=="CENTER")
            return s;
        else if(s=="HIT")
            l=m;
        else
            h=m-1;
    }
    y2=l;
    y1=(y1+y2)>>1;
    cout<<x1<<" "<<y1<<endl;
    cin>>s;
    return s;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t,z;
    long long a,b;
    string s="";
    cin>>t>>a>>b;
    for(z=1; z<=t; z++)
    {
        cout<<temp<<" "<<temp<<endl;
        cin>>s;
        if(s=="CENTER")
            continue;
        else if(s=="HIT")
            s=solve(1);
        else
        {
            cout<<-temp<<" "<<temp<<endl;
            cin>>s;
            if(s=="CENTER")
                continue;
            else if(s=="HIT")
                s=solve(2);
            else
            {
                cout<<-temp<<" "<<-temp<<endl;
                cin>>s;
                if(s=="CENTER")
                    continue;
                else if(s=="HIT")
                    s=solve(3);
                else
                {
                    cout<<temp<<" "<<-temp<<endl;
                    cin>>s;
                    if(s=="CENTER")
                        continue;
                    else if(s=="HIT")
                        s=solve(4);
                    else
                        s=solve(0);
                }
            }
        }
        if(!(s=="CENTER"))
            break;
    }
    return 0;
}