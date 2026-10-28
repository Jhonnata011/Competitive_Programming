struct Trie {

  Trie() {}

  struct node {
    bool end;
    long long cnt;
    long long ch[26];

    node () {
      memset (ch, -1, sizeof(ch));
    }
  };

  node t[1000000];
  int last = 0;

  void insert (const string &s) {
    int current = 0;

    for (char c: s) {
      int l = c - 'a';

      if (t[current].ch[l] == -1) {
        t[current].ch[l] = ++last;
      }
      current = t[current].ch[l];
      t[current].cnt ++;
    }

    t[current].end = true;
  }

  long long query (const string &s) {
    int current = 0;

    for (char c: s) {
      int l = c - 'a';
      if (t[current].ch[l] == -1) return 0;
      current = t[current].ch[l];
    }
    return t[current].cnt;
  }
};
