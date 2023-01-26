/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int ind;
    string ser(TreeNode* root,string &s)
    {
        if(root==NULL)
        {
            s.push_back('N');
            return s;
        }
        s+=to_string(root->val);
        s.push_back(',');
        
        string l=ser(root->left,s);
         s.push_back(',');
        string r=ser(root->right,s);
        return r;
    }
    string serialize(TreeNode* root) {
        string s;
        return ser(root,s);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        ind=0;
        return des(s);    
    }
    TreeNode* des(string &s)
    {
           if(ind>=s.size())
           return NULL;
        
        if(ind<s.size() && s[ind]=='N')
        {
            ind+=2;
            return NULL;
        }
        string temp;
        while(ind<s.size() && s[ind]!=',')
        {
            temp.push_back(s[ind]);
            ind++;
        }
        TreeNode* root=new TreeNode(stoi(temp));
        ind+=1;
        root->left=des(s);
        root->right=des(s);
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));