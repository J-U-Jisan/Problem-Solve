class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ar[10];
        for(int i=0;i<9;i++){
            memset(ar, 0, sizeof(ar));
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    ar[board[i][j]-'0']++;        
                    if(ar[board[i][j]-'0']>1)
                        return false;
                }
                
            }
        }
        for(int j=0;j<9;j++){
            memset(ar, 0, sizeof(ar));
            for(int i=0;i<9;i++){
                if(board[i][j] != '.'){
                    ar[board[i][j]-'0']++;
                    if(ar[board[i][j]-'0']>1)
                        return false;
                }
            }
        }

        for(int i=0;i<7;i+=3){
            for(int j=0;j<7;j+=3){
                memset(ar,0,sizeof(ar));
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]!='.'){
                            ar[board[k][l]-'0']++;
                            if(ar[board[k][l]-'0']>1){
                                return false;
                            }
                                    
                        }
                    }
                }
                
            }
        }
        return true;
    }
};