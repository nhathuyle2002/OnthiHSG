#include<bits/stdc++.h>
#define ll long long
#define i128 __int128_t
#define ntr "\n"
#define mod (ll)(1e9+7)
#define maxn 900005
#define vll vector<ll>
#define ntr "\n"
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output_temp.txt", "w", stdout);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> L(n),l(n),R(n),r(n);
    stack<ll> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            l[i]=-1;
        }
        else{
            l[i]=st.top();
        }
        st.push(i);
    }
    st={};
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            L[i]=-1;
        }
        else{
            L[i]=st.top();
        }
        st.push(i);
    }
    st={};
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            r[i]=-1;
        }
        else{
            r[i]=st.top();
        }
        st.push(i);
    }
    st={};
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            R[i]=-1;
        }
        else{
            R[i]=st.top();
        }
        st.push(i);
    }
    st={};
    vector<ll> adj[n];
    for(int i=0;i<n-1;i++){
        adj[i].push_back(i+1);
    }
    for(int i=0;i<n;i++){
        if(R[i]!=-1&&L[i]!=-1){
            adj[L[i]].push_back(R[i]);
            adj[R[i]].push_back(L[i]);
        }
        if(r[i]!=-1&&l[i]!=-1){
            adj[l[i]].push_back(r[i]);
            adj[r[i]].push_back(l[i]);
        }
    }
    queue<ll> q;
    vector<ll> check(n,0),dis(n,1e18);
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        if(check[u]==1) continue;
        check[u]=1;
        for(auto i:adj[u]){
            q.push(i);
            dis[i]=min(dis[i],dis[u]+1);
        }
    }
    cout<<dis.back();
    /**/
    return 0;
}
