#include<bits/stdc++.h>
using namespace std;

// a > b
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int iter_gcd(int a, int b){
    while(b!=0){
        a = a%b;
        swap(a,b);
    }
    return a;
}

int main(){
    while(true){
        cout << "Enter two numbers to find GCD (or -1 -1 to exit): ";
        int a, b;
        cin >> a >> b;
        if (a==-1 || b==-1) break;
        int ans = gcd(a,b);
        cout << "GCD: " << ans << endl;

        int iterative_ans = iter_gcd(a,b);
        cout << "Iterative GCD: " << iterative_ans << endl;
    }
}