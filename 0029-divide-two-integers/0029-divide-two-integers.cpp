class Solution
{
    private:
    using lli = long long;
    public:
        int divide(int dividend, int divisor)
        {
            if(divisor==0)
                return 0;
            if(dividend == INT_MIN && divisor == -1)
                return INT_MAX;
            
            bool isNeg = (dividend<0)^(divisor<0); //result is negative if the dividend and divisor have opposite signs
            
            lli a=abs((lli)dividend);
            lli b=abs((lli)divisor);

            lli ans=0;

            while(a>=b)
            {
                lli tmp=b, multiple=1;

                while(a>=(tmp<<1))
                {
                    tmp<<=1;
                    multiple<<=1;
                }

                a-=tmp;
                ans+=multiple;
            }
            if(isNeg)
                ans=-ans;
            return (ans>INT_MAX)?INT_MAX:(ans<INT_MIN)?INT_MIN:ans;
        }
};