class FoodRatings {
public:
    unordered_map<string, int> rating;
    unordered_map<string, string> foodToCountry;

    struct Compare {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    map<string,
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>>
        mps;

    void changeRating(string food, int newRating) {
        rating[food] = newRating;
        string nation = foodToCountry[food];
        mps[nation].push({newRating, food});
    }

    string highestRated(string country) {
        auto& pq = mps[country];

        while (!pq.empty()) {
            auto top = pq.top();

            // if rating is valid
            if (rating[top.second] == top.first) {
                return top.second;
            }

            pq.pop();
        }
        return "";
    }

    FoodRatings(vector<string>& foods, vector<string>& country,
                vector<int>& ratings) {
        int n = foods.size();

        for (int i = 0; i < n; i++) {
            rating[foods[i]] = ratings[i];
            foodToCountry[foods[i]] = country[i];
            mps[country[i]].push({ratings[i], foods[i]});
        }
    }
};
