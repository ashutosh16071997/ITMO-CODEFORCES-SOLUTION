#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int k;
vector<long long int>interim;
bool good(long long int mid)
{
    long long int count = 0;
    long long int start = interim[0];
    for(int i = 1;i<interim.size();i++)
    {
        if(interim[i] - start >= mid)
        {
            count++;
            start = interim[i];
        }
    
    }
    count++;
    return count<k;
}
int main()
{
    cin>>n>>k;
    interim.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>interim[i];
    }
    long long int low = 0;
    long long int high = 1e15;
    while(low+1<high)
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
    cout<<low<<endl;
    return 0;
}
