class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans="";
        int sz=strs.size();
        if(sz==1)
            return strs[0];
        auto it = min_element(strs.begin(),strs.end(),[](const string &a, const string &b) {return a.size()<b.size();});
        
        string smol=*it;

        int j=smol.size();
        for(int i=0;i<sz;++i)
        {
            int k=0;
			while(k<j&&strs[i][k]==smol[k])
                ++k;
			j=k;
			if(j==0) 
                return "";
		}
		// return ans;
		return smol.substr(0, j);
    }
};