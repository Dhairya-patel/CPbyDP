class LFUCache {

    int csize;          // max capacity
    int mn = INT_MAX;   // min freq
    
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if(m.count(key) == 0)
            return -1;
        int val = m[key].first, f = m[key].second;
        freq[f].erase(pos[key]);
        m[key].second++;
        freq[f + 1].push_back(key);
        pos[key] = --freq[f + 1].end();
        if(freq[mn].size() == 0)
            mn++;
        return val;
    }
    
    void put(int key, int value) {
        if(m.count(key) && get(key) != -1)
        {
            m[key].first = value;
            return;
        }
        if(m.size() >= csize)
        {
            // delete least freq used key 'k' completely
            int k = freq[mn].front();
            freq[mn].pop_front();
            pos.erase(k);
            m.erase(k);
        }
        // now new key is being added for the first time so freq of it is 1
        m[key] = {value, 1};
        freq[1].push_back(key);
        pos[key] = --freq[1].end();
        mn = 1;
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */