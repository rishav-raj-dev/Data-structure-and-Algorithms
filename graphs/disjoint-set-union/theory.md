# Disjoint Set Union
It is also called Union Find because of its two main operations. This data structure provides the following capabilities. We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is.
## Data structure Interface
- make_set(v) - creates a new set consisting of the new element v.
- union_set (a,b) - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
- find_set(v) - I returns the representative (also called leader) of the set that contains the element v. This representative is an element of its corresponding set. It is selected in each set by the data structure itself (and can change over time, namely after union_sets calls). This representative can be used to check if two elements are part of the same set or not. a and b are exactly in the same set, if find_set(a) == find_set(b). Otherwise they are in different sets.
## Implementation
All the information about the sets of elements will be kept in an array parent. To create a new set (operation make_set(v)), we simply create a tree with root in the vertex v, meaning that it is its own ancestor.

To combine two sets (operation union_sets(a, b)), we first find the representative of the set in which a is located, and the representative of the set in which b is located. If the representatives are identical, that we have nothing to do, the sets are already merged. Otherwise, we can simply specify that one of the representatives is the parent of the other representative - thereby combining the two trees.

Finally the implementation of the find representative function (operation find_set(v)): we simply climb the ancestors of the vertex v until we reach the root, i.e. a vertex such that the reference to the ancestor leads to itself. This operation is easily implemented recursively.
```cpp
void make_set(int v){
    parent[v] = v;
}

void find_set(int v){
    if (v == parent[v]) return v;
    return find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a!=b){
        parent[b] = a;
    }
}
```
This approach is inefficient as we can easily create an example in which trees degenerate into long chains. In that case, each call to find_set(v), wil cost O(n) time.

## Path Compression Optimization
This optimization is designed for speeding up find_set.

If we call find_set(v) for some vertex v, we actually find the representative p for all vertices that we visit on the path between v and the actual representative p. The trick is to make the paths for all those nodes shorter, by setting the parent of each visited vertex directly to p.

```cpp
void find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
```

The simple implementation does what was intended: first find the representative of the set (root vertex), and then in the process of stack unwinding the visited nodes are attached directly to the representative.

This simple modification of the operation already achieves the time complexity  
$O(\log n)$  per call on average (here without proof).

## Union by size / rank
In this optimization we will change the union_set operation. To be precise, we will change which tree gets attached to the other one. In the naive implementation the second tree always got attached to the first one. In practice that can lead to trees containing chains of length  
$O(n)$ . With this optimization we will avoid this by choosing very carefully which tree gets attached.

There are many possible heuristics that can be used. Most popular are the following two approaches: In the first approach we use the size of the trees as rank, and in the second one we use the depth of the tree (more precisely, the upper bound on the tree depth, because the depth will get smaller when applying path compression).

In both approaches the essence of the optimization is the same: we attach the tree with the lower rank to the one with the bigger rank.

```cpp

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
```

- size[a] contains the size of tree a
- size[b] contains the size of tree b
- If size[a] < size[b], then tree a is smaller
- After the swap, a becomes the larger tree and b becomes the smaller tree
- Then parent[b] = a attaches the smaller tree to the larger one

## Time Complexity
As mentioned before, if we combine both optimizations - path compression with union by size / rank - we will reach nearly constant time queries. It turns out, that the final amortized time complexity is  
$O(\alpha(n))$ , where  
$\alpha(n)$  is the inverse Ackermann function, which grows very slowly. In fact it grows so slowly, that it doesn't exceed  
$4$  for all reasonable  
$n$  (approximately  
$n < 10^{600}$ ).

Amortized complexity is the total time per operation, evaluated over a sequence of multiple operations. The idea is to guarantee the total time of the entire sequence, while allowing single operations to be much slower then the amortized time. E.g. in our case a single call might take  
$O(\log n)$  in the worst case, but if we do  
$m$  such calls back to back we will end up with an average time of  
$O(\alpha(n))$ .

We will also not present a proof for this time complexity, since it is quite long and complicated.

Also, it's worth mentioning that DSU with union by size / rank, but without path compression works in  
$O(\log n)$  time per query.





