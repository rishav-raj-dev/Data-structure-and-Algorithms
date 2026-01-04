#include<bits/stdc++.h>
using namespace std;

long long factorial(long long n){
    if (n == 0) return 1;
    return n* factorial(n-1);
}
long long combinatorics(long long n, long long r){
    return n*(n-1)/2;
}

int main(){
    int n;cin >> n;
    cout << 0 << endl;
    for (long long i = 2;i<=n;i++){
        long long k_c_2 = combinatorics(i*i,2);
        long long ans = k_c_2 - ((i-2)*(2 + (i-2)*2))*2;
        cout << ans << endl;

    }
}