class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans;
        int i;
        stack<char> st;
        for(i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]==st.top()){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
