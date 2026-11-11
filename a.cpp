#include <bits/stdc++.h>
 
using namespace std;
 
// Little Sunday <3

// [QUANTOS SALTOS EU VOU DAR NAQUELE GRUPO | DESTINO]
vector <vector <pair <int, int>>> block;
vector <vector <int>> vB;

void build (int n, vector <int> a) {
    
    int SQ = sqrt(n) + 1;
    block.assign(SQ, vector <int>(SQ, -1));
    vB.assign(SQ, vector <int>(SQ -1));

    for (int i = 0; i<n; i++) {
        int bk = i / SQ;
        int id - bk*SQ;
        block[bk][id] = {1, -1};
        vB[bk][id] = a[i];
    }

    for (int b = sq-1; b>=0; b--) {
        for (int i = sq-1; i>=0; i--) {
            if (vB[b][i] == -1) continue;
            
            int nextP = b*bk + i + vB[b][i];
            int nextB = nextP / SQ;
            int nextPB = nextP - bk*SQ;

            if (nextB < SQ && nextPB < SQ && vB[nextB][nextPB] != -1) {
                block[b][i].first += block[nextB][nextPB].first;
                block[b][i].second = block[nextB][nextPB].second;
            }
        }
    }
}

int query (int a) {
    long long jump = 0;
    int last = a;

    int bk = 
}

void update (int p, int v) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <int> arr (n);
    for (int i = 0; i<n; i++) cin >> arr[i];

    while (q--) {
        
        int type; cin >> type;

        if (type) {
            int idx; cin >> idx;

        }

        else {
            int idx, x;
            cin >> idx >> x;
        }

    }

}
