#include<bits/stdc++.h>
using namespace std;

vector<long long int>p;
long long int sum = 0;
long long int n;
long long int k;
bool good(long long int mid)
{
    long long int count = 0;
    long long int tot = 0;
    for(long long int i = 0;i<n;i++)
       {if(tot + p[i] > mid)
          { count++;
            tot = p[i];
        }
        else{
            tot+=p[i];
        }
    }
    count++;
   return count<=k;
}
int main()
{
    cin>>n>>k;
    p.resize(n);
    long long int low = 0;
    for(int i =0;i<n;i++)
    {
        cin>>p[i];
        sum += p[i];
        low = max(low,p[i]);
    }
   

  
  
  long long int high = sum;
  for(int i = 0;i<100;i++)
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
  cout<<high<<endl;
  return 0;
}

