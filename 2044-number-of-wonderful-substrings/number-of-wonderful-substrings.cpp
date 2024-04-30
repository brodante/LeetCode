class Solution {
private:
    typedef long long ll;
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<ll, ll> mpp;

        mpp[0]=1;
        int cum_xor=0;

        ll ans=0;
        for(char &it:word)
        {
            int shift=it-'a'; //binary rep of char e.g a = 0001, b= 0010, c= 0100
            cum_xor^= (1<<shift);
            ans+=mpp[cum_xor]; //all char count is even

            for(char i='a';i<='j';++i)
            {
                shift= i-'a';
                ll tmp= cum_xor ^ (1<<shift);
                ans+=mpp[tmp];
            }
            ++mpp[cum_xor];
        }
        return ans;
    }
};