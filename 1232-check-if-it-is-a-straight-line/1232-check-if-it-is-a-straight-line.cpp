class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        set<double> st;
        bool ninty = false;
        
        for(int i =0;i<c.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                double dx = abs(c[i][0]-c[j][0]);
                double dy = abs(c[i][1]-c[j][1]);
                
                if(dx!=0)
                {
                    double slope = (double)(dy/dx);
                st.insert(slope);
                }
                else
                    st.insert(90);
            }
        }
        return (st.size() == 1)?1:0;
    }
};