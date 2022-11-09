#include <bits/stdc++.h>
using namespace std;

vector<int> a,L,R,l,r;
vector<vector<int>> s;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    a.resize(n+1);
    L.resize(n+1);
    R.resize(n+1);
    l.resize(n+1);
    r.resize(n+1);
    s.resize(n+3);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    deque<int> dq;
    dq.clear();
    for (int i=1;i<=n;i++){
        while (!dq.empty() && a[i] > a[dq.back()]){
            R[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    dq.clear();
    for (int i=1;i<=n;i++){
        while (!dq.empty() && a[i] < a[dq.back()]){
            r[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    dq.clear();
    for (int i=n;i>=1;i--){
        while (!dq.empty() && a[i] > a[dq.back()]){
            L[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    dq.clear();
    for (int i=n;i>=1;i--){
        while (!dq.empty() && a[i] < a[dq.back()]){
            l[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    

    int ans = 0;
    for(int i=1; i<=n; ++i){
        if (r[i] == 0) r[i] = n+1;
        if (r[i]-l[i]-1 >= a[i]) ans = max(ans, a[i]);
    }
    cout << ans;
}