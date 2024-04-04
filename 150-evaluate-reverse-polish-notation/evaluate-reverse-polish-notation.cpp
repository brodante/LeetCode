class Solution {
private:
    bool opr(string &t)
    {
        if(t=="/"||t=="*"||t=="-"||t=="+")
            return true;
        return false;
    }
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> tmp;
        for(int i=0;i<tokens.size();++i)
        {
            if(opr(tokens[i]))
            {
                int x=tmp.top();
                tmp.pop();
                int y=tmp.top();
                tmp.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        tmp.push(y+x);
                        break;
                    case '-':
                        tmp.push(y-x);
                        break;
                    case '*':
                        tmp.push(y*x);
                        break;
                    case '/':
                        tmp.push(y/x);
                        break;
                }
            }
            else
                tmp.push(stoi(tokens[i]));
        }
        return tmp.top(); 
    }
};