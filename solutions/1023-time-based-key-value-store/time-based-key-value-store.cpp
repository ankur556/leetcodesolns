class TimeMap {
public:
    int binser(vector<pair<int,string>> & a,int val){
        int l=0;
        int r=a.size()-1;
        int mid=l+(r-l)/2;
        int bst=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(a[mid].first>val){r=mid-1;}
            else if(a[mid].first<=val){bst=mid;l=mid+1;}
            //else{return mid;}
        }
        //if(r<a.size()){return r;}
        
        return bst;
    }
    unordered_map<string,vector<pair<int,string>>> val;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        val[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(binser(val[key],timestamp)==-1){return "";}
       return val[key][binser(val[key],timestamp)].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */