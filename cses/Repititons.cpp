#include<bits/stdc++.h>
using namespace std;

int main(){
    string str ;
    cin >> str;
    int n = str.size();
    int curr = 0;
    char prev;
    int ans = 0;
    for (int i = 0;i<n;i++){
        char k = str[i];
        if (i == 0){curr = 1;}
        else {
            if (prev == k) curr ++;
            else {
                curr = 1;
            }
        }
        prev = k;
        ans = max(ans, curr);
    }
    cout<< ans << endl;
    return 0;
}