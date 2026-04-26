class Solution {
public:
    int get_max(vector<int> &arr){
        int maxi = -1;
        for(int i=0;i<256;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
        int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256,0); //array form with 0 as elements having size 256
        int low = 0;
        int res = INT_MIN;
        for(int high = 0; high<n;high++){
            f[s[high]]++;
            int max_cnt = get_max(f); // maximum frequency
            int len = high-low+1; //length of elements present
            int diff = len-max_cnt;
            while(diff>k){
                f[s[low]]--;
                low++;
                max_cnt = get_max(f);
                len = high-low+1;
                diff = len-max_cnt;
            }
            len = high-low+1;
            res = max(res,len);

        }
        return res;

    }
};
