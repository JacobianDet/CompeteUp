#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int cg = 0, cs = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'G')
		cg++;
		else cs++;	
	}	
	if(!cg)
	std::cout<<"0\n";	
	else if(!cs)
	std::cout<<n<<"\n";
	else
	{
		std::vector<std::pair<int, int> > gst;
		int gind = -1, gl = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i] == 'G' && (!i || s[i-1] == 'S'))
			{
				gind = i;
				gl++;
			}	
			else if(s[i] == 'G')
			gl++;
			else if(i && s[i] == 'S' && s[i-1] == 'G')
			{
				gst.pb(mp(gind, gl));
				gl = 0;
				gind = -1;
			}	
		}
		if(gl)
		gst.pb(mp(gind, gl));	
		if((int)gst.size() == 1)
		std::cout<<gst[0].second<<"\n";
		else
		{
			int mg = 0;
			for(int i=0,j=(int)gst.size();i<j-1;i++)
			{
				if((gst[i+1].first - gst[i].first) == (gst[i].second + 1))
				{
					if(j > 2)
					mg = std::max(mg, gst[i].second + gst[i+1].second + 1);
					else mg = std::max(mg, gst[i].second + gst[i+1].second);	
				}	
				else
				{
					mg = std::max(mg, gst[i].second + 1);
					mg = std::max(mg, gst[i+1].second + 1);
				}	
			}	
			std::cout<<mg<<"\n";
		}	
	}
	return 0;	
}