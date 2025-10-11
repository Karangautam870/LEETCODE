class ExamTracker {
public:
    vector<int> times;
    vector<long long> scores;

    void record(int time, int score) {
        times.push_back(time);
        scores.push_back(score + scores.back());
    }

    long long totalScore(int startTime, int endTime) {
        int l = lower_bound(times.begin(), times.end(), startTime) -
                times.begin() - 1;

        int r = upper_bound(times.begin(), times.end(), endTime) -
                times.begin() - 1;

        return scores[r] - scores[l];
    }
    ExamTracker() {
        times.push_back(0);
        scores.push_back(0);
    }
};