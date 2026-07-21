class Solution {
public:

    bool is_true(vector<int>& have, vector<int>& need){
        for(int i=0;i<256;i++){
            if(have[i]!=need[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(n<m) return {};
        vector<int> res;
        vector<int> have(256,0);
        vector<int> need(256,0);
        for(int i=0;i<m;i++){
            need[p[i]]++;
        }
        int low = 0;
        for(int high=0;high<n;high++){
            have[s[high]]++;
            int len = high-low+1;
            while(len>m){
                have[s[low]]--;
                low++;
                len = high-low+1;
            }
            if(len==m && is_true(have,need)){
                res.push_back(low);
                continue;
            }
        }
        return res;
    }
};
