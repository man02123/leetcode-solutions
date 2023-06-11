class SnapshotArray {
public://map<int,vector<int>> mp;
    vector<map<int,int>> x;
    int scnt =  0;
    SnapshotArray(int l) {
        x.resize(l);
        for(int i=0;i<l;i++)
            x[i][0]=0;
    }
    
    void set(int ind, int val) {
        x[ind][scnt] = val;
        
    }
    
    int snap() {
        scnt++;
        
        return scnt-1;
    }
    
    int get(int index, int snap_id) {
        
     if(x[index].find(snap_id) == x[index].end())
        {
            auto it = --x[index].lower_bound(snap_id);
            return it->second;
        }
        return x[index][snap_id];
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */