const int LG = 29;

struct trie {
    trie *ch[2];
    int cnt;

    trie() {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }

    ~trie() {
        delete ch[0];
        delete ch[1];
    }

    void insert(int x, int bit = LG) {
        cnt++;
        if (bit < 0) return;

        int nxt = (x >> bit) & 1;
        if (!ch[nxt]) ch[nxt] = new trie();
        ch[nxt]->insert(x, bit - 1);
    }

    bool erase(int x, int bit = LG) {
        if (bit < 0) {
            cnt--;
            return cnt == 0;
        }

        int nxt = (x >> bit) & 1;

        if (!ch[nxt]) return false;

        bool removeChild = ch[nxt]->erase(x, bit - 1);
        cnt--;

        if (removeChild) {
            delete ch[nxt];
            ch[nxt] = nullptr;
        }

        return cnt == 0;
    }

    int xor_min(int x, int bit = LG) {
        if (bit < 0) return 0;

        int nxt = (x >> bit) & 1;
        if (ch[nxt] && ch[nxt]->cnt > 0) {
            return ch[nxt]->xor_min(x, bit - 1);
        }
        return (1 << bit) + ch[nxt ^ 1]->xor_min(x, bit - 1);
    }

    int xor_max(int x, int bit = LG) {
        if (bit < 0) return 0;

        int nxt = (x >> bit) & 1;
        if (ch[nxt ^ 1] && ch[nxt ^ 1]->cnt > 0) {
            return (1 << bit) + ch[nxt ^ 1]->xor_max(x, bit - 1);
        }
        return ch[nxt]->xor_max(x, bit - 1);
    }

    void get_all(std::vector<int> &v, int bit = LG, int x = 0) {
        if (bit < 0) {
            for (int i = 0; i < cnt; i++) {
                v.push_back(x);
            }
            return;
        }
        if (ch[0]) ch[0]->get_all(v, bit - 1, x);
        if (ch[1]) ch[1]->get_all(v, bit - 1, x | (1 << bit));
    }
};
