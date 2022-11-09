#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n, K, a[maxN];
deque<int> dq;

int main(){
    cin >> n >> K;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= K){
            while(!dq.empty() && dq.front() <= i-K) dq.pop_front();
            cout << a[dq.front()] << '\n';
        }
    }
    return 0;
}