class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto d2 = [](const vector<int>& p) -> int {
            return p.size() == 2 ? p[0] * p[0] + p[1] * p[1] : 0;
        };
        auto compare = [&d2](const vector<int>& p1,
                             const vector<int>& p2) -> bool {
            return d2(p1) < d2(p2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)>
            max_heap(compare);
        int i = 0;
        for (const vector<int>& p : points) {
            if (i < k) {
                max_heap.push(p);
                ++i;
            } else if (compare(p, max_heap.top())) {
                max_heap.pop();
                max_heap.push(p);
            }
        }
        vector<vector<int>> vv;
        while (!max_heap.empty()) {
            vv.push_back(max_heap.top());
            max_heap.pop();
        }
        return vv;
    }
};
