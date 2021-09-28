#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

long long  w;
long long h;
long long n;
bool good(long long val)
{
	return (val/w)*(val/h) >= n;
}
int main()
{
	
	cin>>w>>h>>n;
	long long low = 0;
    long long high = 1;
    while(good(high) == false)
	{
		high = high*2;
	}
    while(high>low+1)
	{
		long long mid = (high + low)/2;
		if(good(mid) == true)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	cout<<high<<endl;
	return 0;
}
