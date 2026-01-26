leetcode 210
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph: prereq -> course
        for(auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        // Add courses with no prerequisites
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            
            for(int nextCourse : graph[course]) {
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If all courses can be taken
        if(order.size() == numCourses) {
            return order;
        }
        
        return {};  // Impossible to finish all courses
    }
};
