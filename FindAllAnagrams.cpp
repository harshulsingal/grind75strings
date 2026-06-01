class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> pfreq(26, 0);
        vector<int> wfreq(26, 0);

        for (char ch : p)
            pfreq[ch - 'a']++;

        int left = 0;

        for (int right = 0; right < n; right++) {

            wfreq[s[right] - 'a']++;

            if (right - left + 1 > m) {
                wfreq[s[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == m) {
                if (wfreq == pfreq)
                    ans.push_back(left);
            }
        }

        return ans;
    }
};
