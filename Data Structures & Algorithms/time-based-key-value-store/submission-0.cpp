class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<string, int>>> ds;
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!ds.contains(key)) return "";

        vector<pair<string, int>> vec = ds[key];
        int l = 0;
        int r = vec.size() - 1;

        if (vec[r].second <= timestamp) return vec[r].first;
        if (vec[l].second > timestamp) return "";

        while (l < r) {
            int mid = (l + r) / 2;

            if (vec[mid].second <= timestamp && l != mid) l = mid;
            else r = mid;
        }

        return vec[l].first;
    }
};
