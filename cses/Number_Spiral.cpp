#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long row ;
        long long col ;
        cin >> row >> col;
        long long M = max(row, col);
        long long ans = 0;
        if (row < col){
            if (M%2 == 0){
                ans = (M*M - M) - (col-row) + 1;
            }
            else{
                ans = (M*M - row) + 1;
            }
        }
        else if (row == col){
            ans = (M*M - M )+ 1L;
        }
        else{
            if (M%2 == 0){
                ans = (M*M - col + 1);
            }
            else{
                ans = (M*M - M - (row - col)) + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}