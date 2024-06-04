class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {
        if ( X.size() < Y.size() ) swap(X,Y) ;
        int m = X.size() , n = Y.size();
        if (m == 0 || n == 0) return 0;
        int w = (m + 31) >> 5;
        std::uint32_t S[256][w];
        std::memset(S, 0, sizeof(std::uint32_t) * 256 * w);
        std::int32_t set = 1;
        for (int i = 0, j = 0; i < m; ++i) {
            S[X[i]][j] |= set;
            set <<= 1;
            if (!set) set++,j++;
        }
        std::uint32_t L[w];
        std::memset(L, 0, sizeof(std::uint32_t) * w);
        for (int i = 0; i < n; ++i) {
            std::uint32_t b1 = 1;
            std::uint32_t b2 = 0;
            for (int j = 0; j < w; ++j) {
                std::uint32_t U  = L[j] | S[Y[i]][j];
                std::uint32_t c  = L[j] >> 31;
                std::uint32_t V  = U - (L[j] << 1 | b1+b2);
                b1 = c;
                b2 = (V > U);
                L[j] = U & (~V);
            }
        }      
        int res = 0;
        for (int i = 0; i < w; ++i)
            for (; L[i]; ++res)
                L[i] &= L[i] - 1;
        return res;
    }
};
