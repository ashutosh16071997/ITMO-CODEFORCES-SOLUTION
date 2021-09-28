#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int n,x,y;
bool good(long long int val)
{
    int temp = 0;
    temp = (val/x) + (val/y);
    return temp>=n; 
}
int main() {
	// your code goes here
	cin>>n>>x>>y;
	n--;
	long long int low = 0;
	long long int high = n*x;
	while(high > low+1)
	{
	    long long int mid = (low+high)/2;
	    if(good(mid) == true)
	    {
	        high = mid;
	    }
	    else
	    {
	        low = mid;
	    }
	}
	cout<<high+(min(x,y))<<endl;
	return 0;
}
