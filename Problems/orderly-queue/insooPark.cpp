class Solution {
public:
    string orderlyQueue(string S, int K)
    {
        if (K == 0)
            return S;
        
        if (S.size() <= 1)
            return S;

        string buf = S;
        if (K == 1)
        {
            char min = S[0];
            for(int i = 1; i < S.size(); i++)
            {
                S.push_back(*(S.begin()));
                S.erase(S.begin());
                
                if (0 < buf.compare(S))
                    buf = S;
                    
            }
        }
        else
        {
            sort(buf.begin(), buf.end(), less<char>());
        }
        
        return buf;
    }
};