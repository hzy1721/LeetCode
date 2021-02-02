class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int st = 0, res = 0, ed = st + max(res, 1);
        while (st < len-res) {
            while (ed < len) {
                int pos = -1;
                for (int i = st; i < ed; ++i)
                    if (s[i] == s[ed]) {
                        pos = i;
                        break;
                    }
                if (pos != -1) {
                    res = max(res, ed-st);
                    st = pos + 1;
                    break;
                }
                ++ed;
            }
            if (ed == len) {
                res = max(res, ed-st);
                ++st;
            }
        }
        return res;
    }
};