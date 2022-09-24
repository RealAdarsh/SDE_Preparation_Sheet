/* https://leetcode.com/problems/largest-rectangle-in-histogram/ */




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int N=heights.size(); 
        vector <int> leftSmall(N); 
        vector <int> rightSmall(N); 
        int area=0;
        
        stack <pair<int,int>> st; 
        
        for (int i=0; i<N; i++){
            if (st.empty()){
                leftSmall[i]=-1; 
                st.push({heights[i],i}); 
            }
            else{
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop(); 
                }
                
                if (st.empty()){
                    leftSmall[i]=-1; 
                }
                else{
                    leftSmall[i]=st.top().second; 
                }
                
                st.push({heights[i],i}); 
                
            }
        }
        
        
        while(!st.empty()) st.pop(); 
        
        for (int i=N-1; i>=0; i--){
            if (st.empty()){
                rightSmall[i]=N; 
                st.push({heights[i],i}); 
            }
            else{
                while(!st.empty()&& st.top().first>=heights[i]){
                    st.pop(); 
                }
                
                if (st.empty()){
                    rightSmall[i]=N; 
                }
                else{
                    rightSmall[i]=st.top().second; 
                }
                
                st.push({heights[i],i}); 
            }
        }
        
        
        
        for (int i=0; i<N; i++){
            int end=rightSmall[i]-1; 
            int start=leftSmall[i]+1; 
            int width=end-start+1;
            int height=heights[i]; 
            
            area=max(area, height*width); 
            
        }
        
        return area; 
        
    }
};