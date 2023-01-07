class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(),t.end());
        
        int score=0;
        int maxsc=0;
        int fdown=t.size()-1;
        int fup=0;
        while(fup<=fdown)
        {
            if(power>=t[fup])
            {
                power-=t[fup];
                score++;
                maxsc=max(maxsc,score);
                fup++;
            }
            else if(score>0)
            {
               score--;
                power+=t[fdown];
                fdown--;
            }
            else
                break;
            
        }
        return maxsc;
        
    }
};