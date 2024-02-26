class Solution
{
public:
    vector<int> dailyTemperatures(std::vector<int>& t)
    {
        int n=t.size();
        vector<int>ans(n,0);
        stack<int> stack;
        for(int i=0;i<n;++i)
        {
            while(!stack.empty()&&t[stack.top()]<t[i])
            {
                int tmp=stack.top();
                stack.pop();
                ans[tmp]=i-tmp;
            }
            stack.push(i);
        }
        return ans;
    }
};