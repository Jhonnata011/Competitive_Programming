#include <bits/stdc++.h>

using namespace std;

vector <long long> bit;
int n;

void update (int p, long long v) {
    for (; p<=n; p+= (p & -p)) bit[p] += v;
}

long long query (int p) {
    long long ans = 0;
    for (; p>0; p-= (p & -p)) ans += bit[p];
    return ans;
}

long long queryRange (int l, int r) {
    return query(r) - query(l-1);
}