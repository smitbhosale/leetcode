class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left =0;
       int right =0;
       int maxlen =0;
       int count ;
       unordered_set<char> st;

       while(right<s.size()){
        if(st.find(s[right])!= st.end()){
            st.erase(s[left]);
            left++;
        }else{
            st.insert(s[right]);
            right++;
            maxlen = max(maxlen , right-left);
        }
       }

       return maxlen;
    //    unordered_set<char> st;
    //    if(st.find(s[left])!= st.end()){
    //     st.insert(s[right]);
    //     right++;
        
    //    }else{
    //     count++;
    //      st.erase(s[left]);
    //    }
    //    return count;
    }
    
};