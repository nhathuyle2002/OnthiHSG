#include <bits/stdc++.h>
using namespace std;

vector<int> a,L,R,l,r;
vector<vector<int>> s;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

    for (int i=1;i<=n;i++){
        if (L[i]!=0 && R[i]!=0){
            s[L[i]].push_back(R[i]);
        }
        if (l[i]!=0 && r[i]!=0){
            s[l[i]].push_back(r[i]);
        }
        s[i].push_back(i+1);
    }

    // queue<int> BFS;
    // BFS.push(1);
    // while (!BFS.empty()){
    //     for (int i: s[BFS.front()]){
    //         if (!Check[i]){
    //             Check[i]=true;
    //             BFS.push(i);
    //             depth[i] = depth[BFS.front()] + 1;
    //         }
    //     }
    //     BFS.pop();
    // }
    // cout << depth[n];

    int F[n+1];
    for (int i=1;i<=n;i++){
        F[i]=INT32_MAX;
    }
    F[1]=0;
    for (int i=1;i<=n;i++){
        for (int j : s[i]){
            F[j] = min(F[j],F[i] + 1);
        }
    }
    cout << F[n];
}