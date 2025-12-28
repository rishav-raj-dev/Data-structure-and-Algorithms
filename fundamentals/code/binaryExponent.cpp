#include<bits/stdc++.h>
using namespace std;

long long power(int a, int n){
    if (n == 0) return 1;
    if ((n&1) == 1) return power(a,n-1) * a;
    return power(a*a, n/2);
}

int main(){
    int a;
    int n;
    while(a !=-1){
        cout << "Enter base and exponent: ";
        cin >> a >> n;
        // recursive function to calculate a^n
        long long recursive_answer = power(a,n);
        cout << "Recursive: " << recursive_answer << endl;

        long long iterative_answer = 1;
        int expo = n;
        int base = a;
        while(expo > 0){
            if ((expo & 1)){
                iterative_answer = iterative_answer * base;
            }
            base = base * base;
            expo = expo >> 1;
        }
        cout << "Iterative: " << iterative_answer << endl;
    }
    
}