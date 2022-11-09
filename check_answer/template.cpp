#include <bits/stdc++.h>
using namespace std;

const int NTEST = 100;
const string NAME = "template";

int64_t random(int left, int right){
    assert(left <= right);
    //return left + rand() % (right - left + 1);
    return left + (1LL * rand() * rand()) % (right - left + 1);
}

void genTest(){
    ofstream inp((NAME + ".inp").c_str()); 
    int maxN = 20;
    int n = random(5, maxN);
    int k = random(3, n);
    inp << n << ' ' << k << '\n';
    for(int i=1; i<=n; ++i){
        inp << random(1, 20) << ' ';
    }
    inp.close();
}

int main(){
    srand(time(NULL));
    // genTest();
    // return 0;

    for(int t = 0; t <= NTEST; ++t){
        genTest();
        system((NAME + ".exe").c_str());
        system((NAME + "_temp.exe").c_str());
        if (system(("fc " + NAME + ".out" + NAME + "._temp.out").c_str()) != 0){
            cout << "Test " << t << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << t << ": RIGHT!\n";
    }
    return 0;
}