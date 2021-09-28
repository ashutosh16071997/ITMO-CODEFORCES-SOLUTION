#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double c;
bool good(double val)
{
    double temp = 0;
    temp = val*val + sqrt(val);
    return temp >= c;
}
int main() {
	// your code goes here
	cin>>c;
	double low = 0;
	double high = c;
	int i = 0;
	while(i<100)
	{
	    double mid = double((low+high)/2);
	    bool flag = good(mid);
	    if(flag == true)
	    {
	        high = mid;
	    }
	    else
	    {
	        low = mid;
	    }
	    i++;
	}
	cout<<setprecision(20)<<high<<endl;
	return 0;
}
