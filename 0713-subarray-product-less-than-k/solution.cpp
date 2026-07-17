class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int res =0;
        int low = 0;
        if(k<=1) return 0;
        for(int high = 0; high<n;high++){
            prod = prod*nums[high];
            
            while(prod>=k){
                prod = prod/nums[low];
                low++;
            }
            res += high-low+1;
        }
        return res;
    }
};
