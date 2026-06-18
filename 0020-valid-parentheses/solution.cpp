class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')) return false;
            if(s[i] == ')' && st.top()=='('){
                st.pop();
                continue;
            }
            else if(s[i] == '}' && st.top() == '{'){
                st.pop();
                continue;
            }
            else if(s[i]==']' && st.top()=='['){
                st.pop();
                continue;
            }
            else return false;

        }
        if(!st.empty()){
            return false;
        }
        return true;

        
    }
};
