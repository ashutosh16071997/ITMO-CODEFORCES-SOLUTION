#include<bits/stdc++.h>
using namespace std;
vector<long long int>num;
vector<long long int>deno;
vector<long long int>prefnum;
vector<long long int>predeno;
long long int n,k;

bool good(double x){
    vector<double> pSum(n, 0);
    
    for (int i = 0; i < n; i++){
        pSum[i] = num[i] - x * deno[i];
    }
    
    sort(pSum.rbegin(), pSum.rend());
    
    double sum = 0;
    
    for (int i = 0; i < k; i++){
        sum += pSum[i];
    }
    
    return sum >= 0;
    
}

int main()
{
   cin>>n>>k;
   num.resize(n);
   deno.resize(n);
   for(int i = 0;i<n;i++)
   {
       cin>>num[i]>>deno[i];
   }
   double low = 0;
   double high = 1e8;
   for(int i = 0;i<75;i++)
   {
       double middle = (high+low)/2;
       //cout<<"middle "<<middle<<endl;
       if(good(middle) == true)
       {
           low = middle;
       }
       else
       {
           high = middle;
       }
   }
   cout<<setprecision(20)<<low<<endl;
 return 0;  
}