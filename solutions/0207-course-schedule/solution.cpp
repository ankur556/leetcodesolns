class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adj[i] holds all courses that depend on course 'i'
        vector<vector<int>> adj(numCourses);
        // inDegree[i] holds the number of prerequisites course 'i' has
        vector<int> inDegree(numCourses, 0);

        // 1. Build the graph and in-degree array
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course); 
            inDegree[course]++; 
        }

        // 2. Initialize the BFS queue with courses that have 0 prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;

        // 3. Process the queue (Standard BFS)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            coursesTaken++; // We successfully took this course

            // For every course that depends on 'curr', reduce its requirement count
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                
                // If it now has 0 prerequisites left, we can take it!
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we were able to take all courses, there are no cycles
        return coursesTaken == numCourses;
    }
};
