#include <bits/stdc++.h>
using namespace std;

// Little Sunday <3

int N;
vector <long long> bit;

void add (int p, long long v) {
    for (; p<=N; p+=(p&-p)) bit[p] +=v;
}

long long query (int p) {
    long long ans = 0;
    for (; p>0; p-=(p&-p)) ans += bit[p];
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    bit.resize(N);

    vector <int> a (N);
    for (int i = 0; i<N; i++) cin >> a[i];

    vector <long long> b (N);
    for (int i = 0; i<N; i++) cin >> b[i];

    long long ans = 0;

    for (int i = 0; i<N; i++) {
        long long current = query(a[i]-1);
        ans = max(ans, current + b[i]);
        add(a[i], b[i]);
    }

    cout << ans << "\n";
}
