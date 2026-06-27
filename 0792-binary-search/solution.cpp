class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int res = -1;
        int low =0;
        int high = n-1;
        while(low<=high){
            int guess = (high-low)/2 + low;
            if(nums[guess] == target)
            return res = guess;
            else if(nums[guess]<target){
                low = guess+1;
            }
            else{
                high = guess-1;
            }
        }
        return res;
    }
};
