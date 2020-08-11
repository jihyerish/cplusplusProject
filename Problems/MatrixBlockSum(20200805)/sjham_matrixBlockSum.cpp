class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {     
        //  Solution 1
        for (int r = 0; r < mat.size(); r++){
            vector<int> ans_row;
            for (int c = 0; c < mat[r].size(); c++){
                ans_row.push_back(solve(mat, K, r, c));
            }
            ans.push_back(ans_row);
        }
        
        
        // Solution 2
        /*
        long long tot_sum = 0;
        for (auto r : mat){
            for (auto c : r){
                tot_sum += c;
            }
        }
        
        vector<vector<int>> ans;
        for (auto i = 0; i < mat.size(); i++){
            
            for (auto j = 0; j < mat[i].size(); j++){

            }    
        }*/
        
        return ans;
    }
private:
    // Solution 2
    //  Solution 1
    vector<vector<int>> ans;
    long long prev = 0;
    int solve(vector<vector<int>>& mat, int K, int r, int c){
        long long res = 0;
        if (r == 0 && c == 0){
            for (int i = 0; i <= K && i < mat.size(); i++){
                for (int j = 0; j <= K && j < mat[0].size(); j++){
                    res += mat[i][j];
                }
            }
        }
        else if (c == 0)
        {
            res += ans[r - 1][0];
            if (r - K >= 1){
                for (auto i = 0; i <= K && i < mat[0].size(); i++){
                    res -= mat[r - K - 1][i];
                }
            }
            if (r + K < mat.size()){
                for (auto i = 0; i <= K && i < mat[0].size(); i++){
                    res += mat[r + K][i];
                }
            }
        }
        else if (c > 0){
            res += prev;
            int min_row = (r - K > 0) ? r - K: 0;
            int max_row = (r + K < mat.size()) ? r + K : mat.size() - 1;
            
            if (c - K >= 1){
                for (auto j = min_row; j <= max_row; j++){
                    res -= mat[j][c - K - 1];
                }
            }
            if (c + K < mat[r].size()){
                for (auto j = min_row; j <= max_row; j++){
                    res += mat[j][c + K];
                }
            }
        }
        prev = res;
        return res;
    }
};
