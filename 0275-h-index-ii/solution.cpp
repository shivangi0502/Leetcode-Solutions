class Solution {
public:


    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low =0;
        int high = n-1;
        int res = 0;
        while(low<=high){
            int guess = low+(high-low)/2;
            int rp_count  = n-guess;
            if(citations[guess]>=rp_count){
                res = rp_count;
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        return res;
    }
};
