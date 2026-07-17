class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int high = 0, low = 0, res = 0;
        int max_count = 0;  //To tracks the maximum frequency of any single character inside the current window.
        vector <int> f(256, 0);

        for(high = 0; high < n; high++){
            f[s[high]]++;
            int len = high - low + 1;
            max_count = max(max_count, f[s[high]]); //maximum frequency seen in the current window.
            int diff = len - max_count;
            
            while(diff > k){   //Jab tk #occurrences of non repeating charaters > k(no of replacement allowed)
                f[s[low]]--;
                low++;
                len = high - low + 1;  // Updating the window length 
                diff = len - max_count; //recalculating the no. of occurrences of non-repeating characters in the current window

            }
            len = high - low + 1;
            res = max(res, len);

        }
        return res;
        
    }
};
