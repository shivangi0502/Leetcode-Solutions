class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int n = word.length();
        for(int i=0;i<n;i++){
            freq[word[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int sum =0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            int push = (i/8)+1;
            sum += freq[i]*push;
        }
        return sum;
    }
};
