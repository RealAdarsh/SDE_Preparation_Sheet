/* https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/ */


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack <int> st; 
        int n=prices.size(); 
        vector <int> sol(n); 
        
        for (int i=n-1; i>=0; i--){
            if (st.empty()){
                st.push(prices[i]);
                sol[i]=prices[i]; 
            }
            else {
                while(!st.empty()&& st.top()>prices[i]){
                    st.pop(); 
                }
                
                if (st.empty()){
                    sol[i]=prices[i]; 
                }
                else {
                    sol[i]=prices[i]-st.top(); 
                }
                
                st.push(prices[i]);
            }
        }
        
        return sol; 
        
    }
};