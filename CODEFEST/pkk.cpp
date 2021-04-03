#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int ct = (32 - __builtin_clz(n));
	std::cout<<ct<<"\n";
	return 0;
}