class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        int wordlen = words[0].size();
        int numofword = words.size();
        int totallen = wordlen*numofword;
        int slen = s.size();
        if(slen<totallen) return res;

        unordered_map<string,int> need;
        for(const string& w:words){
            need[w]++;
        }

        for(int i=0;i<wordlen;++i){
            int low =i;
            int count = 0;
            unordered_map<string,int> have;
            for(int high =i; high+wordlen<=slen;high+=wordlen){
                string sub = s.substr(high,wordlen);
                if(need.count(sub)){
                    have[sub]++;
                    count++;
                    while(have[sub]>need[sub]){
                        string wordleft = s.substr(low,wordlen);
                        have[wordleft]--;
                        count--;
                        low+=wordlen;
                    }
                    if(count==numofword){
                        res.push_back(low);
                    }
                    
                }
                else{
                    have.clear();
                    count = 0;
                    low = high+wordlen;
                }
            }
            
        }
        return res;
    }
};
