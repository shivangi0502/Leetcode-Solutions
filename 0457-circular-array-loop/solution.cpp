class Solution {
public:

    int geti(vector<int>& nums,bool isforward, int curr){
        bool currdir = nums[curr]>=0;
        if(isforward!=currdir){
            return -1;
        }
        int n = nums.size();
        int next = (curr+nums[curr])%n;
        if(next<0){
            next+=n;
        }
        if(next==curr){
            return -1;
        }
        return next;
    }


    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            bool isforward = nums[i]>=0;
            int slow=i;
            int fast =i;
            while(slow!=-1 && fast!=-1){
                slow = geti(nums,isforward,slow);
                fast = geti(nums,isforward,fast);
                if(fast!=-1){
                    fast = geti(nums,isforward,fast);
                }
                if(slow!=-1 && slow==fast){
                    return true;
                }
            }
        }
        return false;
    }
};
