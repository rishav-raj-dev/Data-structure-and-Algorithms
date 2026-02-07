#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(ll n){
    vector<ll> arr (n,0);
    ll sum = 1;
    arr[n-1] = 1;
    for (int i = 1;i<n-1;i++){
        arr[i] = (i+1) ^ arr[n-1];
        sum += arr[i];
    }
    arr[0] = (n*(n+1)/2) - sum;
    for (auto it: arr){
        cout << it << " ";
    }cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);

    }
}
/*
 */