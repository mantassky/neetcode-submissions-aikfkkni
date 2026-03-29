class LRUCache {
public:
    struct Node {
        int value;
        int prevKey;
        int nextKey;
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // pair of value and nextKey
    unordered_map<int, Node> cache;
    int capacity;
    int oldestKey = -1;
    int newestKey = -1;
    
    int get(int key) {
        if (!cache.contains(key)) return -1;
        Node res = cache[key];
        if (key == newestKey)
            return res.value;
        
        // stitch neighbours
        if (res.nextKey != -1)
            cache[res.nextKey].prevKey = res.prevKey;

        if (res.prevKey != -1)
            cache[res.prevKey].nextKey = res.nextKey;
        else if (res.nextKey != -1)
            oldestKey = res.nextKey;

        cache[key].nextKey = -1;
        // put in front
        if (newestKey != -1)
            cache[newestKey].nextKey = key;

        cache[key].prevKey = newestKey;
        newestKey = key;
        return cache[key].value;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key].value = value;
            this->get(key);
            return;
        } 

        cache[key] = {value, newestKey, -1};

        if (newestKey != -1)
            cache[newestKey].nextKey = key;

        if (cache.size() > capacity) {
            int newOldest = cache[oldestKey].nextKey;
            cache.erase(oldestKey);
            cache[newOldest].prevKey = -1;
            oldestKey = newOldest;
        }

        if (cache.size() == 1) oldestKey = key;
        newestKey = key;
    }
};
