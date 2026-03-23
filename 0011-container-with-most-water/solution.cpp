class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0, right = height.size()-1;
        int ans=0;
        while(left<right){
            int length = min(height[left], height[right]);
            int breadth = right - left;
            int area = length * breadth;
            ans = max(ans,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
