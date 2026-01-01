#include<bits/stdc++.h>
using namespace std;

// a > b
// (4, 5, 0, 1) - > (5, 4,1,1) -> (4, 1, 1, 0) -> (1, 0, 1, 0)
int gcd(int a, int b, int& x1, int& y1){
    if (b==0){
        x1 = (a >= 0) ? 1 : -1;
        y1 = 0;
        return abs(a);
    }
    int x, y;
    int divisor = gcd(b, a%b,x,y);
    x1 = y;
    y1 = (x - y*(a/b));
    return divisor;
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
        int x, y;
        int ans = gcd(a,b,x,y);
        cout << "GCD: " << ans << " x: " << x << " y: " << y << endl ;

        x = 0;
        y = 0;
        // int iterative_ans = iter_gcd(a,b,x,y);
        // cout << "Iterative GCD: " << iterative_ans << endl;
    }
}