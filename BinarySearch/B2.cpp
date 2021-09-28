#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int n;
double k;
vector<int>pq;
bool good(double val)
{
	int  sum = 0;
	for(int i= 0;i<pq.size();i++)
	{
		sum += floor(pq[i]/val);
	}
	return sum >= k;
}
int main()
{
	
	cin>>n>>k;
	pq.resize(n);
	for(int i = 0;i<n;i++)
	{
       cin>>pq[i];
	}
	double low = 0;
    double high = 1e8;
	for(int i = 0;i<100;i++)
    { 
		double mid = (high + low)/2;
		if(good(mid) == true)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	cout<<setprecision(20)<<low<<endl;
	return 0;
}
