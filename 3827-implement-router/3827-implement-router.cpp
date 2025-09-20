class Router {
public:
    map<vector<int>, int> mpp; // to track duplicates
    queue<vector<int>> queue;
    unordered_map<int, vector<int>> timestamps; // for timestamps tracking
    unordered_map<int, int> mp;
    int lt; 

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        // checking for duplicate
        if (mpp.count(packet)){
            return false;
        }

        if (queue.size() >= lt) { 
            vector<int> res = queue.front();
            mpp.erase(res);
            int temp = res[1];
            mp[temp]++;
            queue.pop();
        }

        queue.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty()) {
            return {};
        }
        vector<int> res = queue.front();

        queue.pop();
        mpp.erase(res);

        int temp = res[1];
        mp[temp]++;

        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (timestamps.count(destination) == 0) {
            return 0;
        }

        auto& p = timestamps[destination];
        int temp = mp[destination];

        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);

        return (left - right);
    }
    Router(int memoryLimit) { 
        lt = memoryLimit; 
    }
};