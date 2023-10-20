/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:vector<int >res;
    int cnt ;
    int itr;
    NestedIterator(vector<NestedInteger> &nl) {
     
        itr =0;
        cnt =0;
        for(auto it: nl){
            
             NestedInteger x = it;
            
            if(x.isInteger() == true){
                res.push_back(x.getInteger());
            }
            else
                dfs(x.getList());
                
            
        }
        // for(auto it: res)
        //     cout<<it;
        cnt = res.size();
       
    }
    void dfs(vector<NestedInteger> &y){
        for(auto it:y){
            
        if(it.isInteger()){
            res.push_back(it.getInteger());
        }
        
        auto z = it.getList();
        dfs(z);
        }
    }
    
    int next() {
        return res[itr++];
    }
    
    bool hasNext() {
        if(itr < cnt)
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */