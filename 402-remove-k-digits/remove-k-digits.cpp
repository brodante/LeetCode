class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if(k>=num.size())
            return "0";


        for(int i=0;i<(num.size()-1)&&k!=0;i++)
        {
            cout<<num[i]<<" hahah "<<num[i+1];
            if(num[i]>num[i+1])
            {
                num.erase(i,1);
                i-=2; //fu*k cuz I will be incremented by the loop so to counter that +=2, spend 20mins figuring this shi
                k--;
            }
            i=i<0?-1:i;
        }
        while(num[0]=='0')
            num.erase(0,1);

        if(num.empty())
            return "0";

        if(k>=num.size())
            return "0";

        if(k>0)
            return num.substr(0,num.size()-k);
        return num;
    }
};