#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    public:
        vector<int> A;
        vector<int> t;
    
    SegmentTree(vector<int>& arr){
        int n = arr.size();
        for (int i = 0;i<n;i++) A.push_back(arr[i]);
        t = vector<int> (4*n);
        build(0,0,n-1);
    }

    void build(int v, int tl, int tr){
        if (tl==tr) {
            t[v] = A[tl];
            return;
        }
        int tmid = (tl + tr) / 2;
        build(2*v+1, tl, tmid);
        build(2*v+2, tmid+1, tr);
        t[v] = t[2*v+1] + t[2*v+2];
    }
    int sum(int v, int tl, int tr, int l, int r){
        if (l>r) return 0;
        if (tl==l && tr==r) return t[v];
        int tmid = (tl + tr)/2;
        int left_sum = sum(2*v+1,tl,tmid,l, min(tmid,r));
        int right_sum = sum(2*v+2,tmid+1,tr,max(l, tmid+1), r);
        return left_sum + right_sum;
    }
    void update(int v, int tl, int tr, int idx, int val){
        if (tl == tr){
            A[idx] = val;
            t[v] = val;
            return ;
        }
        int tmid = (tl + tr)/2;
        if (idx <= tmid) update(2*v+1, tl, tmid, idx, val);
        else update(2*v+2, tmid+1,tr, idx, val);
        t[v] = t[2*v+1] + t[2*v+2];
    }
};

int main(){
    vector<int> vec = {-1,3,5,2,-3};
    int n = vec.size();
    SegmentTree* seg = new SegmentTree(vec);
    cout << seg->sum(0,0,n-1,0,n-1) << endl;
    cout << seg->sum(0,0,n-1,0,n-2) << endl;
    seg->update(0,0,n-1,4,10);
    cout << seg->sum(0,0,n-1,0,n-1) << endl;

    return 0;
}