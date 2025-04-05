class data {
public:
    int val, apos, vpos;
    data(int v, int ap, int vp) {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

// Custom comparator for min-heap
class compare {
public:
    bool operator()(data a, data b) {
        return a.val > b.val; // min-heap
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        priority_queue<data, vector<data>, compare> pq;
        vector<int> ans;

        // Insert the first element of each array
        for (int i = 0; i < k; i++) {
            data d(arr[i][0], i, 0);
            pq.push(d);
        }

        while (!pq.empty()) {
            data curr = pq.top();
            pq.pop();

            ans.push_back(curr.val);

            int ap = curr.apos, vp = curr.vpos;

            if (vp + 1 < arr[ap].size()) {
                data d(arr[ap][vp + 1], ap, vp + 1);
                pq.push(d);
            }
        }

        return ans;
    }
};

