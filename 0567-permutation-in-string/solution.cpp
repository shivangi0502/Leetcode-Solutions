class Solution {
public:

    bool is_true(vector<int>& have, vector<int>& needed){
        for(int i=0;i<256;i++){
            if(have[i]!=needed[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> have(256,0);
        vector<int> needed(256,0);
        for(int i=0;i<n;i++){
            needed[s1[i]]++;
        }
        int low = 0;
        for(int high=0; high<m; high++){
            have[s2[high]]++;
            int len = high-low+1;
            if(len>n){
                have[s2[low]]--;
                low++;
                len = high-low+1;
            }
            if(len==n && is_true(have,needed)){
                return true;
            }
        }
        return false;
    }
};
