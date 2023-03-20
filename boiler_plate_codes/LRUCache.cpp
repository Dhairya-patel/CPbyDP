class LRUCache {

    list<int>dq;
    unordered_map<int, pair<list<int>::iterator, int>>mp;

    int csize;

public:
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        auto itr = mp[key].first;
        int val = mp[key].second;
        dq.erase(itr);
        mp.erase(key);
        dq.push_front(key);
        mp[key].first = dq.begin();
        mp[key].second = val;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            auto itr = mp[key].first;
            dq.erase(itr);
            mp.erase(key);
        }
        dq.push_front(key);
        mp[key].first = dq.begin();
        mp[key].second = value;
        if(dq.size() > csize)
        {
            int k = dq.back();
            mp.erase(k);
            dq.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */