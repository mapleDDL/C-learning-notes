class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 差分法
        vector<int> res(n,0);
        for (auto i = bookings.begin(); i != bookings.end(); i++) {
            res[(*i)[0]-1] += (*i)[2];
            if ((*i)[1] < n) {
                res[(*i)[1]] -= (*i)[2];
            }
        }

        for (int i = 1; i < n; i++) {
            res[i] += res[i-1];
        }
        return res;

    }
};