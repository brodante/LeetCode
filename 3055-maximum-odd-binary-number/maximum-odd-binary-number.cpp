class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        int n=count(s.begin(),s.end(),'1');
        return string(n-1,'1')+string(s.size()-n,'0')+'1';
    }
};