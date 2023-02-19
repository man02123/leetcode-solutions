class Solution {
public:
    int minMaxDifference(int num) {
        string temp=to_string(num);
        int i=0;
        while(i<temp.size() && temp[i]=='9')
            i++;
       
        char c=temp[i];
        
       for(int j=0;j<temp.size();j++)
           if(temp[j]==c)
               temp[j]='9';
        
        int x=stoi(temp);
        
        string temp2=to_string(num);
        
        char l=temp2[0];
        for(int k=0;k<temp2.size();k++)
            if(temp2[k]==l)
                temp2[k]='0';
        
        int y=stoi(temp2);
       
       
        //cout<<x<<" "<<y;
        
        return x-y;
            
        
    }
};