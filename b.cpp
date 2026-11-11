#include <bits/stdc++.h>
using namespace std;

// Little Sunday <3

// [QUANTOS SALTOS EU VOU DAR NAQUELE GRUPO | DESTINO]
vector <vector <pair <int, int>>> block;
vector <vector <int>> vB;

int n;

void build (vector <int> a) {

    int SQ = sqrt(n) + 1;
    block.assign(SQ, vector <pair <int, int>>(SQ, {1, -1}));
    vB.assign(SQ, vector <int>(SQ, -1));

    for (int i = 0; i < n; i++) {
        int bk = i / SQ;
        int id = i - bk * SQ;
        block[bk][id] = {1, -1};
        vB[bk][id] = a[i];
    }

    for (int b = SQ - 1; b >= 0; b--) {
        for (int i = SQ - 1; i >= 0; i--) {
            if (vB[b][i] == -1) continue;

            int nextP = b * SQ + i + vB[b][i];
            int nextB = nextP / SQ;
            int nextPB = nextP - nextB * SQ;

            if (nextB > b) {
                if (nextP < n) block[b][i].second = nextP;
            }
            else if (nextPB < SQ && vB[nextB][nextPB] != -1) {
                block[b][i].first += block[nextB][nextPB].first;
                block[b][i].second = block[nextB][nextPB].second;
            }
        }
    }
}

pair <int, int> query (int a) {

    int SQ = sqrt(n) + 1;

    long long jump = 0;
    int last = a;
    int bk = a / SQ;
    int pB = a - bk * SQ;

    while (true) {
        jump += block[bk][pB].first;
        int p = block[bk][pB].second;
        if (p == -1) return {jump, last};
        bk = p / SQ;
        pB = p - bk * SQ;
    }
}

void update (int p, int v) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    vector <int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(arr);

    while (m--) {
        int type; cin >> type;

        if (type) {
            int idx; cin >> idx;
            pair <int, int> ans = query(idx);
            cout << ans.first << " " << ans.second << "\n";
        }
        else {
            int idx, x;
            cin >> idx >> x;
            update(idx, x);
        }
    }
}
