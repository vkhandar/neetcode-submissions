class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;

    bool dfs(int course){
        if(visited.contains(course)) return false;
        if(preMap[course].empty()) return true;

        visited.insert(course);

        for(int pre :preMap[course]){
            if(!dfs(pre)){
                return false;
            }
        }

        visited.erase(course);
        preMap[course].clear();

        return true;


        
    }

    bool canFinish(int numCourses, vector<vector<int>>& preqs) {
        for(int i = 0; i<numCourses; ++i){
            preMap[i] = {};
        }

        for(vector<int> preq: preqs){
            preMap[preq[0]].push_back(preq[1]);
        }
        for(int i = 0; i<numCourses; ++i){
            if(!dfs(i)){
                return false;
            }
        }
        return true;

        
    }
};
