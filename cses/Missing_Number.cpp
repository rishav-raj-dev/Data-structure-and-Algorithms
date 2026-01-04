#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0;i<n-1;i++){
        long long k;
        cin >> k;
        sum += k;
    }
    long long required_sum = n* (n + 1) / 2;
    long long missing = required_sum - sum;
    cout << missing << endl;
    return 0;
}