class Solution {
public:

    int getOR(vector<int>& nums, int low,int high){
        int winOR = 0;
        for(int i=low;i<=high;i++){
            winOR |= nums[i];
        }
        return winOR;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        int currOR = 0;
        int low =0;
        for(int high = 0;high<n;high++){
            currOR |= nums[high];
            while(currOR>=k && low<=high){
                int len = high-low+1;
                res =  min(len,res);
                low++;
                currOR = getOR(nums,low,high);
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};
