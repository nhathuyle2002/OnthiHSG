#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;

struct Data{
    int x, y1, y2, del;
};
Data a[2*maxN]; 
int K, len[4*maxN], cnt[4*maxN];

void update(int id, int l, int r, int u, int v, int del){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        cnt[id] += del;
        if (cnt[id] > 0) len[id] = r-l+1; 
        else len[id] = len[id*2] + len[id*2+1];
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u, v, del);
    update(id*2+1, mid+1, r, u, v, del);
    if (cnt[id] > 0) len[id] = r-l+1; 
    else len[id] = len[id*2] + len[id*2+1]; 
}

void init(){
    
}

void enter(){
    cin >> n;
    K = 0;
    for(int i=1; i<=n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1+1, y2, 1};
        a[i+n] = {x2, y1+1, y2, -1};
        K = max(K, max(y1+1, y2));
    }
    sort(a+1, a+2*n+1, [](Data x, Data y){return x.x < y.x;});
}

void solve(){
    int64_t ans = 0;
    for(int i=1; i<=2*n; ++i) {
        ans += 1LL * (a[i].x - a[i-1].x) * len[1];
        update(1, 1, K, a[i].y1, a[i].y2, a[i].del);
    }
    cout << ans;
}

int main(){
    enter();
    solve();
    return 0;
}