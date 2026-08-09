class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string, vector<string>> mp;
        

    //     for(string x:strs)
    //     {
    //         string Reev = strs;
    //         sort(Reev.begin() , Reev.end());
            
    //         mp[key].push_back(strs);
            
    //     }
    //     vector<vector<string>> k;
    //     for(auto z: mp){
    //         k.push_back(z.second);
    //     }
    //     return k;
        
    // }
    
 vector<vector<string>> groupAnagrams(vector<string>& strs)
  {

    unordered_map<string, vector<string>> mp;

    for (string word : strs)
    {

        string key = word;

        sort(key.begin(), key.end());

        mp[key].push_back(word);
    }

    vector<vector<string>> ans;

    for (auto x : mp)
    {
        ans.push_back(x.second);
    }


    return ans;

  }
};