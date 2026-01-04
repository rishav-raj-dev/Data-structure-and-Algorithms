#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long two = 0;
    long long five = 0;
    long long temp = n;
    long long i = 2;
    while (temp > 0 && i <= temp){
        two += (temp)/i;
        i = i << 1;
    }
    i = 5;
    temp = n;
    while (temp > 0 && i <= temp){
        five += (temp) / i;
        i = i*5;
    }
    cout << min(two, five) << endl;
}