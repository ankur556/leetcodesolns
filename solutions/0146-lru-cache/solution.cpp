#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    int capacity;
    // List stores keys and values: {key, value}
    // Front = LRU (Least Recently Used), Back = MRU (Most Recently Used)
    list<pair<int, int>> lruList; 
    
    // Map stores Key -> Iterator (pointer) to the node in the list
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        // 1. Check if key exists in map (O(1))
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        // 2. Move the accessed node to the back of the list (MRU)
        // splice() moves the node instantly without copying or shifting
        lruList.splice(lruList.end(), lruList, cacheMap[key]);

        // 3. Return the value
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        // Case 1: Key already exists
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update the value
            cacheMap[key]->second = value;
            // Move to back (MRU)
            lruList.splice(lruList.end(), lruList, cacheMap[key]);
            return;
        }

        // Case 2: Key is new. Check capacity.
        if (lruList.size() == capacity) {
            // Identify the LRU element (at the front)
            int lruKey = lruList.front().first;
            // Remove from list
            lruList.pop_front();
            // Remove from map
            cacheMap.erase(lruKey);
        }

        // Add new element to the back (MRU)
        lruList.push_back({key, value});
        // Save the pointer (iterator) to this new node in the map
        // std::prev(lruList.end()) gets the iterator to the last element we just added
        cacheMap[key] = prev(lruList.end());
    }
};
