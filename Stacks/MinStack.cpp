/*https://leetcode.com/problems/min-stack/*/


class MinStack {
public:
    stack <long long> st; 
    long long mini=INT_MIN; 
    int size=0; 
    
    MinStack() { 
        //st.clear(); 
    }
    
    void push(int val) {
        if(st.empty()){
           mini=val;
           st.push(val); 
        }
        else {
            if (mini < val){
                st.push(val); 
            }
            else {
                st.push(2LL*val-mini);
                mini=val; 
            }
        }
        size++; 
    }
    
    void pop() {
        if (st.empty()) return; 
        else {
            if (st.top()>=mini){ 
                st.pop();
            }
            else{
                 mini=2LL*mini-st.top();
                st.pop();
            }
        }
        size--; 
    }
    
    int top() {
        if (st.top()>mini){
            return st.top(); 
        }
        else {
            return mini; 
        }
        
    }
    
    int getMin() {
        if (size>0) return (int)mini; 
        return -1; 
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */