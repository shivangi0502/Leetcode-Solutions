class Solution {
public:

    long long time_used(vector<int>& piles, int n, int speed){
        long long time = 0;
        for(int i =0; i<n;i++){
            time = time+piles[i]/speed;
            if(piles[i]%speed!=0){
                time++;
            }
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while(low<=high){
            int guess = low+(high-low)/2;
            long long hour = time_used(piles,n,guess);
            if(hour>h){
                low = guess+1;
            }
            else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};
