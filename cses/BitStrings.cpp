#include<bits/stdc++.h>
using namespace std;


long long pow(long long a, long long n, long long MOD){
    if (n == 0) return 1;
    if (n%2==1) return a*pow(a, n-1, MOD) % MOD;
    return pow(a*a%MOD, n/2, MOD) % MOD;
}
int main(){
    long long n;
    cin >> n;
    long long MOD = 1e9+7;
    long long ans = pow(2,n,MOD) % MOD;
    cout << ans << endl;

}