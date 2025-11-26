class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // array of tasks
        // number n which tells us how many tasks of other types there must be before repeating a task

        // always choose the task with the largest frequency left --> pq
        map<char, int> freq;
        priority_queue<pair<int, char>> availPq;
        queue<pair<int, pair<int, char>>> waitTimers;

        int numIntervals = 0;

        for (char task : tasks) {
            freq[task]++;
        }

        for (const auto& task : freq) {
            availPq.push({task.second, task.first});
        }

        while (!availPq.empty() || !waitTimers.empty()) {
            numIntervals++;
            if (!availPq.empty()) {
                auto [count, task] = availPq.top();
                availPq.pop();

                count--;

                if (count > 0) {
                    waitTimers.push({numIntervals + n, {count, task}});
                }
            }

            while (!waitTimers.empty() && waitTimers.front().first == numIntervals) {
                availPq.push(waitTimers.front().second);
                waitTimers.pop();
            }
        }

        return numIntervals;
    }
};
