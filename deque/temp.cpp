#include<bits/stdc++.h>
#define ll long long
#define ntr "\n"
using namespace std;

const int maxN = 1e5+100;
ll arr[maxN],sum=0;
ll dp[maxN];
deque<int> q;

void push(int i){
    while (!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
    q.push_back(i);
}

void pop(int i){
    while (!q.empty() && q.front() <= i) q.pop_front();
}

int main(){
    ll n,k;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    fill(dp,dp+n,INT_MAX);
    for(int i=0;i<k;i++){
        dp[i]=arr[i];
        push(i);
    }
    for(int i=k;i<n;i++){
        // for(int j=1;j<=k;j++){
        //     if(i-j>=0)
        //         dp[i]=min(dp[i],arr[i]+dp[i-j]);
        // }
        pop(i-k);
        dp[i] = arr[i] + dp[q.front()];
        cout << i << ' ' << dp[i] << ' ' << q.front() << '\n';
        push(i);
    }
    pop(n-k);

    ll ans=INT_MAX;
    // for(int i=0;i<k;i++){
    //     ans=min(ans,dp[n-1-i]);
    // }
    ans = dp[q.front()];
    cout<<sum-ans;
    return 0;
}
