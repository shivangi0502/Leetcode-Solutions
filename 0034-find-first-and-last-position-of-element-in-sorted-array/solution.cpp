class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums,target);
        int last = lastOcc(nums,target);
        return {first,last};
    }
private:
    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();
        int s=0, e= n-1;
        int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int ans = -1;
        int n = nums.size();
        int s=0, e=n-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                s= mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    
};
