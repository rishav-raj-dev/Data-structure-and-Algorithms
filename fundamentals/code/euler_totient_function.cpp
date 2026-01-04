

#include<bits/stdc++.h>
using namespace std;

int phi(int n){
    int res = n;
    for (int i = 2;i*i<=n;i++){
        if (n%i == 0) res -= res/i;
        while (n%i == 0){
            n = n/i;
        }
    }
    if (n > 1){
        res -= res/n;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int num_coprimes = phi(n);
    cout << "Number of integers coprime to " << n << " is: " << num_coprimes << endl;

    return 0;
}