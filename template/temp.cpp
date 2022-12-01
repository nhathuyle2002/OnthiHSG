#include <bits/stdc++.h>
using namespace std;

bool dequy(int n, int m){
    if (m == 0) return false;
    bool pre = dequy(m, n % m);
    if (!pre) return true;
    else if (pre){
        if (n / m > 1) return true;
        return false;
    }
}


int main(){
    int test = 1; cin >> test;
    while (test--){
        int n, m; cin >> n >> m;
        if (n < m) swap(n, m);
        if (dequy(n, m)) cout << "copium"; else cout << "illya";
        cout << '\n';
    }
}