#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
public:
    // The number of elements in this union find
    int size;

    UnionFind(int tam)
    {
        if (tam <= 0)
            return;
        size = numComponents = tam;
        sz.resize(size);
        id.resize(size);

        for (int i = 0; i < size; i++)
        {
            id[i] = i; // Link to itself (self root)
            sz[i] = 1; // Each component is originally of size one
        }
    }

    // Find which component/set 'p' belongs to, takes amortized constant time.
    int find(int p)
    {
        // Find the root of the component/set
        int root = p;
        while (root != id[root])
            root = id[root];

        // Compress the path leading back to the root.
        // Doing this operation is called "path compression" and is what gives us amortized time complexity.
        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    // This is an alternative recursive formulation for the find method
    // public int find(int p) {
    //   if (p == id[p]) return p;
    //   return id[p] = find(id[p]);
    // }

    // Return whether or not the elements 'p' and 'q' are in the same components/set.
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    // Return the size of the components/set 'p' belongs to
    int componentSize(int p)
    {
        return sz[find(p)];
    }

    // Return the number of elements in this UnionFind/Disjoint set
    int sizeUF()
    {
        return size;
    }

    // Returns the number of remaining components/sets
    int components()
    {
        return numComponents;
    }

    // Unify the components/sets containing elements 'p' and 'q'
    void unify(int p, int q)
    {
        // These elements are already in the same group!
        if (connected(p, q))
            return;

        int root1 = find(p);
        int root2 = find(q);

        // Merge smaller component/set into the larger one.
        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
            sz[root1] = 0;
        }
        else
        {
            sz[root1] += sz[root2];
            id[root2] = root1;
            sz[root2] = 0;
        }

        // Since the roots found are different we know that the number of components/sets has decreased by one
        numComponents--;
    }

private:
    // Used to track the size of each of the component
    vector<int> sz;
    // id[i] points to the parent of i, if id[i] = i then i is a root node
    vector<int> id;
    // Tracks the number of components in the union find
    int numComponents;
};

class FenwickTreeRangeQueryPointUpdate
{
public:
    // The size of the array holding the Fenwick tree values
    int N;

    // Create an empty Fenwick Tree with 'sz' parameter zero based.
    FenwickTreeRangeQueryPointUpdate(int sz)
    {
        tree.resize(N = sz + 1);
    }

    // Construct a Fenwick tree with an initial set of values.
    // The 'values' array MUST BE ONE BASED meaning values[0] does not get used, O(n) construction.
    FenwickTreeRangeQueryPointUpdate(vector<int> &values)
    {
        if (values.empty())
            return;

        N = values.size();
        values[0] = 0L;

        // Make a clone of the values array since we manipulate the array in place destroying all its original content.
        tree = values;

        for (int i = 1; i < N; i++)
        {
            int parent = i + lsb(i);
            if (parent < N)
                tree[parent] += tree[i];
        }
    }

    // Returns the sum of the interval [left, right], O(log(n))
    int sum(int left, int right)
    {
        if (right < left)
            return -1;
        return prefixSum(right) - prefixSum(left - 1);
    }

    // Get the value at index i
    int get(int i)
    {
        return sum(i, i);
    }

    // Add 'v' to index 'i', O(log(n))
    void add(int i, int v)
    {
        while (i < N)
        {
            tree[i] += v;
            i += lsb(i);
        }
    }

    // Set index i to be equal to v, O(log(n))
    void set(int i, int v)
    {
        add(i, v - sum(i, i));
    }

private:
    // This array contains the Fenwick tree ranges
    vector<int> tree;

    // Returns the value of the least significant bit (LSB)
    // lsb(108) = lsb(0b1101100) =     0b100 = 4
    // lsb(104) = lsb(0b1101000) =    0b1000 = 8
    // lsb(96)  = lsb(0b1100000) =  0b100000 = 32
    // lsb(64)  = lsb(0b1000000) = 0b1000000 = 64
    static int lsb(int i)
    {
        // Isolates the lowest one bit value
        return i & -i;
    }

    // Computes the prefix sum from [1, i], O(log(n))
    int prefixSum(int i)
    {
        int sum = 0L;
        while (i != 0)
        {
            sum += tree[i];
            i &= ~lsb(i); // Equivalently, i -= lsb(i);
        }
        return sum;
    }
};