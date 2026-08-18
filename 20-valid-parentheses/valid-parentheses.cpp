#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // If length is odd, it can't be valid pairs
        if (s.size() % 2 != 0) return false;

        stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            // If it's a closing bracket
            if (mapping.count(c)) {
                if (st.empty() || st.top() != mapping[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket
                st.push(c);
            }
        }
        
        return st.empty();
    }
};   