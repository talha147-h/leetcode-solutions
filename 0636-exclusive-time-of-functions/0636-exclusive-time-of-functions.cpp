
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int m = logs.size();
        string funcId, type, timestamp;
        vector<vector<int>> intlog;
        int functionId, typesore, time;

        for (int i = 0; i < m; i++) {
            stringstream ss(logs[i]);

            getline(ss, funcId, ':');
            getline(ss, type, ':');
            getline(ss, timestamp, ':');

            functionId = stoi(funcId);

            if (type == "start") typesore = 1;
            else typesore = 0;

            time = stoi(timestamp);

            intlog.push_back({functionId, typesore, time});
        }

        vector<int> ans(n, 0);

        // {functionId, startTime, childTime}
        stack<vector<int>> st;

        for (int i = 0; i < intlog.size(); i++) {
            int id = intlog[i][0];
            int type = intlog[i][1];
            int time = intlog[i][2];

            if (type == 1) {
                st.push({id, time, 0});
            }
            else {
                vector<int> curr = st.top();
                st.pop();

                int totalTime = time - curr[1] + 1;
                int exclusive = totalTime - curr[2];

                ans[curr[0]] += exclusive;

                if (!st.empty()) {
                    st.top()[2] += totalTime;
                }
            }
        }

        return ans;
    }
};
