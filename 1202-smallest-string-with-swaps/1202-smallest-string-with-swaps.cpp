class Solution {
public:
    bool visited[100005]={0};
    vector<int>v[100005];
    string input;
    string pro="";
    vector<int>index;
    void dfs(int source){
        visited[source] = true;
        pro+=input[source];
        index.push_back(source);
        for(int i=0;i<v[source].size();i++){
            if(!visited[v[source][i]])
                dfs(v[source][i]);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        input = s;
        for(int i=0;i<pairs.size();i++){
            v[pairs[i][0]].push_back(pairs[i][1]);
            v[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<s.size();i++){
            if(!visited[i]){
                dfs(i);
                sort(pro.begin(),pro.end());
                sort(index.begin(),index.end());
                
                for(int i=0;i<pro.size();i++){
                    s[index[i]] = pro[i];
                }
                pro = "";
                index.clear();
            }
        }
        return s;
    }
};