struct Trie {
    struct node {
        bool end;
        long long cnt;
        long long end_cnt;
        int ch[26]; 

        node() : end(false), cnt(0), end_cnt(0) {
            std::fill(std::begin(ch), std::end(ch), -1);
        }
    };

    std::vector<node> t;

    Trie() {
        clear();
    }

    void clear() {
        t.clear();
        t.emplace_back();
    }

    void insert(const std::string &s) {
        int current = 0;
        t[current].cnt++;

        for (char c : s) {
            int l = c - 'a';
            if (t[current].ch[l] == -1) {
                t[current].ch[l] = t.size();
                t.emplace_back();
            }
            current = t[current].ch[l];
            t[current].cnt++;
        }
        t[current].end = true;
        t[current].end_cnt++;
    }

    long long count_prefix(const std::string &s) const {
        int current = 0;
        for (char c : s) {
            int l = c - 'a';
            if (t[current].ch[l] == -1) return 0;
            current = t[current].ch[l];
        }
        return t[current].cnt;
    }

    bool search(const std::string &s) const {
        int current = 0;
        for (char c : s) {
            int l = c - 'a';
            if (t[current].ch[l] == -1) return false;
            current = t[current].ch[l];
        }
        return t[current].end;
    }

    long long count_exact(const std::string &s) const {
        int current = 0;
        for (char c : s) {
            int l = c - 'a';
            if (t[current].ch[l] == -1) return 0;
            current = t[current].ch[l];
        }
        return t[current].end_cnt;
    }

    bool erase(const std::string &s) {
        if (count_exact(s) == 0) return false;

        int current = 0;
        t[current].cnt--;

        for (char c : s) {
            int l = c - 'a';
            current = t[current].ch[l];
            t[current].cnt--;
        }

        t[current].end_cnt--;
        if (t[current].end_cnt == 0) {
            t[current].end = false;
        }
        return true;
    }
};
