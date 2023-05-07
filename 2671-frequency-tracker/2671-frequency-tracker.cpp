class FrequencyTracker {
public:
    unordered_map<int,int> freq;
    unordered_map<int,unordered_set<int>> mp;
    FrequencyTracker() {
    }
    
    void add(int num) {
        if(freq[num]){
            mp[freq[num]].erase(num);
        }
        mp[++freq[num]].emplace(num);
    }
    
    void deleteOne(int num) {
        if(freq[num]){
            mp[freq[num]].erase(num);
            int f=--freq[num];
            if(mp[f+1].size()==0){
                mp.erase(f+1);
            }
            if(f>0){
                mp[f].emplace(num);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return mp.find(frequency)!=mp.end() && mp[frequency].size()>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */