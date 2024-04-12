class Solution {
public:
    int trap(vector<int>& A)
    {
        int n=A.size();
        int left=0,right=n-1;
        int ans=0;
        int maxleft=0, maxright=0;
        while(left<=right)
        {
            if(A[left]<=A[right])
            {
                if(A[left]>=maxleft)
                    maxleft=A[left];
                else
                    ans+=maxleft-A[left];
                left++;
            }
            else
            {
                if(A[right]>=maxright)
                    maxright= A[right];
                else
                    ans+=maxright-A[right];
                right--;
            }
        }
        return ans;
    }
};
