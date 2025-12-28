using namespace std;
#include <bits/stdc++.h>

class Disjoint_Set_Union {
    public:
    vector<int> parent, rank;
    Disjoint_Set_Union(int n){
        parent = vector<int> (n, -1);
        rank = vector<int> (n, 0);
    }
    void make_set(int v){
        parent[v] = v;
        rank[v] = 1;
    }

    int find_set(int v){
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a!=b){
            if (rank[a] < rank[b]){
                swap(a,b);
            }
            parent[b] = a;
            rank[a] += rank[b];
        }
    }
};
int main(){
    Disjoint_Set_Union dsu(10);
    for (int i=0;i<10;i++){
        dsu.make_set(i);
    }
    dsu.union_set(1,2);
    dsu.union_set(2,3);
    dsu.union_set(4,5);
    dsu.union_set(6,7);
    dsu.union_set(5,6);
    dsu.union_set(3,7);
    cout<<dsu.find_set(1)<<endl;
    cout<<dsu.find_set(4)<<endl;
    cout<<dsu.find_set(6)<<endl;
    return 0;
}