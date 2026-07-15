class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high = 0, low = 0;
        int res = 0;
        unordered_map<char, int> f;
        int k;

        for(high = 0; high < s.length(); high++){
            f[s[high]]++;
            k = high - low + 1;
            while(f.size() < k){
                f[s[low]]--; //Shrink the window
                if(f[s[low]] == 0){     //when the occurrance of any character becomes zero in the hashmap
                    f.erase(s[low]);
                }

                low++;
                k = high - low + 1;
            }
            
            // now it can be more or equal
            int len = high - low + 1;
            res = max(res, len);

        }
        return res;
        
    }
};
