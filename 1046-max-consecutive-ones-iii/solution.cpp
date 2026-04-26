class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = -1;
        int low = 0;
        int zero_cnt = 0;
        for(int high = 0;high<n;high++){
            if(nums[high]==0){
                zero_cnt++;
            }
            while(zero_cnt>k){
                
                if(nums[low]==0){
                    zero_cnt--;
                }
                low++;
            }
            int len = high-low+1;
            res = max(res,len);
        }
        return res;
        
    }
};
