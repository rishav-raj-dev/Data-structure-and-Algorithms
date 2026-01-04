
#include<bits/stdc++.h>
using namespace std;

void sieve(int n){
    vector<bool> primes (n+1, true);
    primes[0] = false;
    primes[1] = false;

    // need to iterate to i*i, because, numbers not
    // covered under i*i, would be marked not prime by numbers
    // before it.
    for (int i = 2;i*i<=n;i++){
        // odd number optimization
        if (i!=2 && (i&1)==0) continue;
        if (primes[i]){
            for (int j = i*i ; j<=n ; j+=i){
                primes[j] = false;
            }
        }
    }
    for (int i = 2;i<=n;i++){
        // cout << primes[i] << " ";
        if (primes[i]) cout << i << " ";
    }cout << endl;
}

int main(){
    int n;
    cin >> n;
    sieve(n);
}