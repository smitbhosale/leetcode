class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        vector<int> freq(128, 0);

        // Frequency required from t
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int count = t.size();

        int minLength = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            // Include s[right]
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;
            right++;

            // Window is valid
            while (count == 0) {

                // Update minimum window
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                // Remove s[left]
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};