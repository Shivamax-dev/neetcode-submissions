class Solution {
public:
    int maxNumberOfBalloons(string text) {
         //a hashmap to store the frequency of the characters in the given text
        unordered_map <char, int> have;
        for(int i = 0; i < text.length(); i++){
            have[text[i]]++;
        }
        //A hashmap to store the frequency of the charaters in string "balloon"
        unordered_map <char, int> need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX;
        for(auto i : need){ //loop the need
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            int times = fhave/fneed;  //to fine the no. of times the string "balloon" can be made from give text

            res = min(res, times);

        }
        return res;
        
        
    }
};