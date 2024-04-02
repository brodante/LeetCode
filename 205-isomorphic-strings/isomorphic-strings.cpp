class Solution {
public:
    bool isIsomorphic(string str1, string str2)
    {
        char hash[256];
        int n1=str1.size(),n2=str2.size();
        if(n1!=n2)
            return false;
        for(int i=0;i<n1;++i)
            hash[str1[i]]=str2[i];
        for(int i=0;i<n1;i++)
            if(str2[i]!=hash[str1[i]])
                return false;
        for(int i=0;i<n1;i++)
            hash[str2[i]]=str1[i];
        for(int i=0;i<n1;i++)
            if(str1[i]!=hash[str2[i]])
                return false;
        
        return true;
        
    }
};