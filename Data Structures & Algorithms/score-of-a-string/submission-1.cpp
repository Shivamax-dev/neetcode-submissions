class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 0; i < s.length() - 1; i++){
            int first_char = s[i];
            int second_char = s[i+1];

            int s_absolute = abs(first_char - second_char);
            sum = sum + s_absolute;
        }
        return sum;
        
    }
};