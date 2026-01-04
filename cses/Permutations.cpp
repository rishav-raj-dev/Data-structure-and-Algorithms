#include<bits/stdc++.h>

using namespace std;

void print(int n){
    while(n > 0){
        cout << n << " ";
        n -= 2;
    }
}

int main(){
    int n;
    cin >> n;

    if (n==3 || n == 2) {cout << "NO SOLUTION" << endl ; return 0;}
    if (n==4){
        cout << "2 4 1 3" << endl;
        return 0;
    }

    if (n%2 == 0){
        print(n);
        print(n-1);
    }
    else{
        print(n-1);
        print(n);
    }
    cout << endl;

    return 0;
}