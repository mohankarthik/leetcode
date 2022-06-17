#include "../../../../common/Includes.h"

class Solution {
private:
    
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int n = recipes.size();
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for (auto recipe: recipes) {
            indegree[recipe] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            for (auto ing: ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for (auto supply: supplies) {
            q.push(supply);
        }
        
        vector<string> answer;
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            for (string recipe: graph[curr]) {
                indegree[recipe]--;
                if (indegree[recipe] <= 0) {
                    q.push(recipe);
                }
            }
        }
        
        for(auto recipe: recipes) {
            if (indegree[recipe] <= 0) {
                answer.push_back(recipe);
            }
        }

        return answer;
    }
};