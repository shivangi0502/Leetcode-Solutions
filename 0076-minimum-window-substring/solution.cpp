class Solution {
public:
    bool is_true(vector<int> &have, vector<int> &needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false;
            }
        
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> have(256,0);
        vector<int> needed(256,0);
        int m = s.size();
        int n = t.size();
        for(int i=0;i<n;i++){
            needed[t[i]]++;
        }
        int low = 0;
        int start = 0;
        int res = INT_MAX;
        for(int high=0;high<m;high++){
            have[s[high]]++;
            while(is_true(have,needed)){
                int len = high-low+1;
                if(res>len){
                    res=len;
                    start = low;
                }
                
                have[s[low]]--;
                low++;
            }
        }
        if(res==INT_MAX){
            return "";
        }
        return s.substr(start,res);
    }
};
