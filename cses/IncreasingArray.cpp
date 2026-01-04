#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long prev;
    long long moves = 0;
    for (int i = 0;i<n;i++){
        long long k; cin >> k;
        if (i==0) prev = k;
        else{
            if (k<prev){
                moves += prev - k;
                prev = k + prev - k;
            }
            else prev = k ;
        }
    }
    cout << moves << endl;
    return 0;
}