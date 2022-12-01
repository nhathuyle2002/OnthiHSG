em vào được không
Long Dương Hoàng
dạ vào r ạ
https://meet.google.com/typ-ymmm-zst
https://github.com/nhathuyle2002/OnthiHSG
https://meet.google.com/yfw-ayhi-qfu
https://github.com/nhathuyle2002/OnthiHSG/blob/main/hashing/practice_problems.txt
https://meet.google.com/sdv-axps-aeq
Dương Nguyên Hãn
@Lê Nhật Huy @Long Dương Hoàng tuần 3 buổi 2ae có thấy mệt ko?
Long Dương Hoàng
@Lê Nhật Huy anh Huy ơi mai mình có học không ạ
Có nha e
Long Dương Hoàng
anh Huy ơi ngày mai khoàng 1h-1h30 mình học được không ạ?
Long Dương Hoàng
#include<bits/stdc++.h>
#define ll long long
#define ntr "\n"
#define mod (ll)(1e9+7);
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll q,k,x,flag=1;
        map<ll,ll> chk;
        cin>>q;
        while(q--){
            cin>>k>>x;
            if(k==1){
                chk[x]++;
            }
            else{
                if(chk[x]==0){
                    if(chk[0]==0){
                        flag=0;
                    }
                    else{
                        chk[0]--;
                    }
                }
                else{
                    chk[x]--;
                }
            }
        }
        if(flag){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<ntr;
    }
    return 0;
}
code map
#include<bits/stdc++.h>
#define ll long long
#define ntr "\n"
#define mod (ll)(1e9+7);
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll q,k,x,flag=1;
        cin>>q;
        ll chk[100001]={0};
        while(q--){
            cin>>k>>x;
            if(k==1){
                chk[x]++;
            }
            else{
                if(chk[x]==0){
                    if(chk[0]==0){
                        flag=0;
                    }
                    else{
                        chk[0]--;
                    }
                }
                else{
                    chk[x]--;
                }
            }
        }
        if(flag){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<ntr;
    }
    return 0;
}
code mảng thống kê
#include<bits/stdc++.h>
#define ll long long
#define ntr "\n"
#define mod (ll)(1e9+7);
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    ll chk[100001]= {0};
    for(int i=0;i<t;i++){
        ll q,k,x,flag=1;
        cin>>q;
        vector<int> d;
        while(q--){
            cin>>k>>x;
            if(k==1){
                chk[x]++;
                d.push_back(x);
            }
            else{
                if(chk[x]==0){
                    if(chk[0]==0){
                        flag=0;
                    }
                    else{
                        chk[0]--;
                    }
                }
                else{
                    chk[x]--;
                }
            }
        }
        if(flag){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<ntr;
        for(int x: d) chk[x] = 0;
    }
    return 0;
}
