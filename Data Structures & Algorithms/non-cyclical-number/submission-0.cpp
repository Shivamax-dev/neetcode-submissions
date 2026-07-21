class Solution {
public:
    int fun(int m){
        int sum = 0;
        while(m > 0){
            int d = m % 10;
            m = m / 10;
            sum = sum + d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(fast!=1){
            slow = fun(slow);  //moving 1 steps
            fast = fun(fun(fast));  //Moving 2 steps

            if(slow == fast && slow!=1){
                return false;
            }
        }
        //If slow == 1; or say fast == 1
        return true;
        
    }
};
