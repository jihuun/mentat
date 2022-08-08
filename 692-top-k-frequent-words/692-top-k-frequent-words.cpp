class myCompare {
    public:
    bool operator() (const pair<string, int> &p1, const pair<string, int> &p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /* generate hash map */
        unordered_map<string, int> freq;
        for (string w: words)
            freq[w]++;
        
        /* push string and freq value to heap */
        priority_queue<pair<string, int>, vector<pair<string, int> >, myCompare> pq;
        for (auto it: freq)
            pq.push(make_pair(it.first, it.second));
            //pq.push({it.first, it.second});
        
        /* pop k times */
        vector<string> ret;
        //for (int i = 0; i < k; i++) {
        while (k--) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};