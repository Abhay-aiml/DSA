class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int siz = a.size();
        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < siz; i++) {
            if (a[i] < 0)
                neg.push_back(a[i]);
            else
                pos.push_back(a[i]);
        }

        vector<int> result;

        if (neg.size() == 0) {
            // no negative elements, just square everything in pos
            for (int i = 0; i < pos.size(); i++)
                result.push_back(pos[i] * pos[i]);
        }
        else if (pos.size() == 0) {
            // no positive elements, square neg in reverse (since abs values shrink left to right)
            for (int i = neg.size() - 1; i >= 0; i--)
                result.push_back(neg[i] * neg[i]);
        }
        else {
            // merge neg (walked backward) and pos (walked forward) by squared value
            int i = neg.size() - 1;  // start from the negative closest to zero
            int j = 0;               // start from the smallest positive
            while (i >= 0 && j < pos.size()) {
                int negSq = neg[i] * neg[i];
                int posSq = pos[j] * pos[j];
                if (negSq < posSq) {
                    result.push_back(negSq);
                    i--;
                } else {
                    result.push_back(posSq);
                    j++;
                }
            }
            while (i >= 0) {
                result.push_back(neg[i] * neg[i]);
                i--;
            }
            while (j < pos.size()) {
                result.push_back(pos[j] * pos[j]);
                j++;
            }
        }

        return result;
    }
};