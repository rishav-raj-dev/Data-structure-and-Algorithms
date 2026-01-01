#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y){
    if (b == 0){
        x = (a>=0) ? 1 : -1;
        y = 0;
        return abs(a);
    }
    int x1, y1;
    int divisor = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return divisor;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a , b;
        cin >> a >> b;

        int x, y;
        int g = gcd(a, b, x, y);
        if (g!=1) {
            cout << -1 << endl;
            continue;
        }
        cout << g << " " << x << " " << y << endl;
        int x1 = ceil(-x*min(a,b)/ float(b));
        int y1 = floor(y*min(a,b)/float(a));

        if (x1 > y1) {
            cout << -1 << endl;
            continue;
        }
        cout << x1 << endl;

    }
}