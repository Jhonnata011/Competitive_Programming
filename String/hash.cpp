using ull = unsigned long long;
const ull M = (1ULL << 61) - 1;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ull B = uniform_int_distribution<ull>(256, M - 1)(rng); // B > |sigma|
vector<ull> pw{1}; // potencias de B, crescem sob demanda (sem pre())

ull mul(ull a, ull b) { // a*b mod 2^61-1
    __uint128_t c = (__uint128_t) a * b;
    ull r = (ull) (c & M) + (ull) (c >> 61);
    return (r % MOD);
}

struct str_hash {
    vector<ull> h; // h[i] = hash de s[0..i-1], h[0] = 0
    str_hash(const string &s) : h(s.size() + 1, 0) {
        while (pw.size() <= s.size()) pw.push_back(mul(pw.back(), B));
        for (int i = 0; i < (int) s.size(); i++) {
            h[i + 1] = mul(h[i], B) + (unsigned char) s[i];
            h[i+1] %= MOD;
        }
    }
    ull operator()(int l, int r) { // hash de s[l..r]
        ull x = h[r + 1] + M - mul(h[l], pw[r - l + 1]);
        return x >= M ? x - M : x;
    }
};
// Complexidade: construtor O(|s|), operator() O(1)
