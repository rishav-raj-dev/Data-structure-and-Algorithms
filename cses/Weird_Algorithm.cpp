#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }
    while(n!=1){
        cout << n << " ";
        if ((n&1) == 1){
            n = 3*n + 1;
        }else n = n>>1;
    }
    cout << n << endl;
}