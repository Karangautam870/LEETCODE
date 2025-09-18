#define p pair<int,int>

class TaskManager {
public:

    struct Compare {
        bool operator()(const p& a, const p& b) const {
            if (a.first == b.first) return a.second < b.second; 
            return a.first < b.first;
        }
    };

    priority_queue<p, vector<p>, Compare> pq;
    unordered_map<int, int> taskIdToUserId;
    unordered_map<int, int> taskIdToPriority;


    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskIdToUserId[taskId] = userId;
        taskIdToPriority[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int userId = taskIdToUserId[taskId];
        taskIdToPriority[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskIdToUserId.erase(taskId);
        taskIdToPriority.erase(taskId);
    }

    int execTop() {

        while (!pq.empty()) {

            auto [priority, taskId] = pq.top();
            pq.pop();

            if (taskIdToPriority.count(taskId) && 
                taskIdToPriority[taskId] == priority) {

                int userId = taskIdToUserId[taskId];
                taskIdToUserId.erase(taskId);
                taskIdToPriority.erase(taskId);

                return userId;
            }
        }
        return -1; 
    }

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            add(userId, taskId, priority);
        }
    }
};
