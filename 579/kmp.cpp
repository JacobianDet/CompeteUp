#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp make_pair
#define ft first
#define sd second

long double Round(long double root)
{
	root = root*1000.0 + 0.50;
	return root/1000.0;

}
int main()
{
	//ax**2 + bx + c = 0
	long double a, b, c;
	cin >> a >> b >> c;

	long double dis = sqrt(b*b - 4*a*c);
	long double root1 = (-b + dis)/2.0*a;
	long double root2 = (-b - dis)/2.0*a;
	root1 = Round(root1);
	root2 = Round(root2);
	cout << root1 << ' ' << root2 << '\n';

}