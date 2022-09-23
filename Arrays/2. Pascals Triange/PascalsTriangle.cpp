#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> generate(int numRows) {
    vector <vector <int>> sol; 
    
    for (int i=0; i<numRows; i++){
        vector <int> row(i+1,1); 
        
        for (int j=1; j<i; j++){
            row[j]=sol[i-1][j-1] + sol[i-1][j]; 
        }
        
        sol.push_back(row); 
    }
    
    return sol; 
    
}

int main(){

	//input 

	int N; 
	cin>>N; 

	vector <vector<int>> sol= generate(N); 

	// output

	for (int i=0;i<sol.size(); i++){
		for (int j=0; j<sol[i].size(); j++){
			cout << sol[i][j] << " "; 
		}
		cout << endl; 
	}

	return 0; 
}