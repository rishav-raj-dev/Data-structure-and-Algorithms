#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    int i;
    int j;
    if (n%2==0){
        i = 1;j=n;
    }else {
        i = 2; j = n;
    }
    int turn = 0;
    vector<int> setA = {};
    vector<int> setB = {};
    while(j>i){
        if (n%2==1 && j == i+1){
            setA.push_back(i);
            setA.push_back(1);
            setB.push_back(j);
            break;
        }
        if (turn == 0){
            setA.push_back(i);
            setA.push_back(j);
        }
        if (turn == 1){
            setB.push_back(i);
            setB.push_back(j);
        }
        turn = !turn;
        i ++;
        j--;
    }
    cout << "YES" << endl;
    cout << setA.size() << endl;
    for (auto it: setA){
        cout << it << " ";
    }cout << endl;
    cout << setB.size() << endl;
    for (auto it: setB){
        cout << it << " ";
    }cout << endl;

}