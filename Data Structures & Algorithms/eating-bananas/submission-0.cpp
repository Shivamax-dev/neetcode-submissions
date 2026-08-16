class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while(low<=high){
            int guess = (low + high)/2;
            long long hour = fun(piles, n, guess);
            if(hour > h){   // Too slow! Took more than h hours. Increase speed.
                low = guess+1;
            }else{      // Valid speed! Record it and try to find a smaller valid speed.
                res = guess;
                high = guess - 1;
            }
        }
        return res;
        
    }
    //Helper Function
    /*
    For each pile a[i], Koko takes ceil of (a[i] /speed) hours (rounded up).Example: If pile has 7 bananas and speed is 3: 7/3 = 2hours
            Remainder 7%3 = 1, so add +1 hour -> Total: 3 hours. 
    */
    long long fun(vector<int>&a, int n, int speed){
        long long h = 0;
        for(int i = 0; i < n; i++){
            h = h + a[i] / speed;
            if(a[i] % speed != 0)
                h++;
        }
        return h;
    }
};
