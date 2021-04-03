#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        std::string s,s1="",s2="";
        int x[2],y[2],cou[2],star[2];
        std::cin>>s>>x[0]>>y[0];
        x[1]=0;
        y[1]=0;
        memset(cou,0,sizeof(cou));
        memset(star,0,sizeof(star));
        for(int j=0,k=s.size();j<k;j++)
        {
            if(s[j] == 'a')
            cou[0]++;
            else cou[1]++;
        }
        if(cou[0] == cou[1])
        {
            for(int j=0;j<cou[0];j++)
            std::cout<<"ab";
            std::cout<<"\n";
        }
        int j=0,k=s.size();
        while(j<k)
        	{
            	if((cou[0] > 0)&&(x[1] < x[0]))
            	{
                	cou[0]--;
                	x[1]++;
                	y[1]=0;
                	s1+='a';
            	}
            	else if((cou[1] > 0)&&(y[1] < y[0]))
            	{
                	cou[1]--;
                	y[1]++;
                	x[1]=0;
                	s1+='b';
            	}
            	else {
                    x[1]=0;
                 	y[1]=0;
                 	s1+='*';
                 	star[0]++;
                 	j--;
            	}
            	j++;
        	}
        x[1]=0;
        y[1]=0;
        memset(cou,0,sizeof(cou));
        for(int j=0,k=s.size();j<k;j++)
        {
            if(s[j] == 'a')
            cou[0]++;
            else cou[1]++;
        }
        j=0;
        while(j<k)
        	{
            	if((cou[1] > 0) && (y[1] < y[0]))
            	{
                	cou[1]--;
                	y[1]++;
                	x[1]=0;
                	s2+='b';
            	}
            	else if((cou[0] > 0) && (x[1] < x[0]))
            	{
                	cou[0]--;
                	x[1]++;
                	y[1]=0;
                	s2+='a';
            	}
            	else {
                    x[1]=0;
                 	y[1]=0;
                 	s2+='*';
                 	j--;
                 	star[1]++;
            	}
            	j++;
        	}
        if(star[0] <= star[1])
        std::cout<<s1<<"\n";
		else std::cout<<s2<<"\n";
    }
    return 0;
}
