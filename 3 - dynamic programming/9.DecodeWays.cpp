class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> arr(n, -1);
        function<int(int)> dp = [&](int i) {
            if (i > n || s[i] == '0')
                return 0;
            if (i == n)
                return 1;
            if (arr[i] != -1)
                return arr[i];
            int a1 = dp(i+1);
            int a2 = s.substr(i, 2) <= "26" ? dp(i+2) : 0;
            return arr[i] = a1 + a2;
        };
        return dp(0);
    }
};