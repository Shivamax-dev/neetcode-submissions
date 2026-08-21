class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); //or capital.size();
        vector <pair<int, int>> proj;
        int i;

        for(i = 0; i < n; i++){
            proj.push_back({capital[i], profits[i]});
        }
        //Sort the pair(by default it will sorted according to the first element of the pair)
        sort(proj.begin(), proj.end());

        priority_queue<int> pq; //maxheap

        int idx = 0;
        while(k--){
            while(idx < n){
                if(w < proj[idx].first)
                    break;
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty())
                return w;   //Company bankrupt ho gyi hai ipo nhi bn sakta
            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};