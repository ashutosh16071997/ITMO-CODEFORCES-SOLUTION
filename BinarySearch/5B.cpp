#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>>interim;
long long int n;
long long int k;
bool good(long long int val)
{
    long long int count = 0;
    for(long long int i = 1;i<=n;i++)
    {
        if(val%i == 0)
          count += min(n,val/i -1);
        else
          count += min(n,val/i);
    }
    return count<k;
}
int main()
{
    cin>>n>>k;

    long long int low = 0;
    long long int high = 1e18;
    while(high>low+1)
    {
        long long int mid = (high + low)/2;
        if(good(mid) == true)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout<<low<<endl;
    return 0;
}