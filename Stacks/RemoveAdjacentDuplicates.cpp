/* https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/ */


class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack <pair<char,int>> st; 
        if (k==1) return ""; 
        string ans=""; 
        
        for (int i=0; i<s.size(); i++){
            if (st.empty()){
                st.push({s[i],1}); 
            }
            else {
                if (st.top().first==s[i]){
                    if (st.top().second+1==k){
                        while(!st.empty() && st.top().first==s[i]){
                            st.pop(); 
                        }
                    }
                    else {
                        st.push({s[i],st.top().second+1}); 
                    }
                }
                else{
                    st.push({s[i],1}); 
                }
            }
        }
        
        while(!st.empty()){
            ans+=st.top().first; 
            st.pop(); 
        }
        
        reverse(ans.begin(), ans.end()); 
        
        return ans; 
        
    }
};