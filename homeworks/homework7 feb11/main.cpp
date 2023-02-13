#include <stack>
#include <vector>
#include "iostream";

using namespace std;
//LeetCode problems

class Solution {
public:

    // 844. Backspace String Compare
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for (char ch: s) {

            if (ch == '#') {
                if (s1.empty())
                    continue;
                s1.pop();
            } else {
                s1.push(ch);
            }
        }

        for (char ch: t) {

            if (ch == '#') {
                if (s2.empty())
                    continue;
                s2.pop();
            } else {
                s2.push(ch);
            }
        }

        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top())
                return false;

            s1.pop();
            s2.pop();
        }

        if (!s1.empty() || !s2.empty())
            return false;

        return true;
    }


    // 20. Valid Parentheses
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for (auto i: s)  //iterate over each and every element
        {
            if (i == '(' or i == '{' or i == '[')
                st.push(i);  //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if (st.empty() or (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or
                    (st.top() == '[' and i != ']'))
                    return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();  //at last, it is possible that we left something into the stack unpair so return checking stack is empty or not..
    }

// 84. Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> &vec) {
        vector<int> a(vec.size());
        stack<pair<int, int>> s;

        // nearest smallest to left;
        for (int i = 0; i < vec.size(); i++) {
            while (s.size() && s.top().first >= vec[i]) s.pop();
            a[i] = s.empty() ? -1 : s.top().second;
            s.push({vec[i], i});
        }
        while (s.size()) s.pop();

        int maxrec = 0;
        // nearest smallest to right;
        for (int i = vec.size() - 1; i >= 0; i--) {
            while (s.size() && s.top().first >= vec[i]) s.pop();
            int j = s.empty() ? vec.size() : s.top().second;
            maxrec = max((j - a[i] - 1) * vec[i], maxrec);
            s.push({vec[i], i});
        }
        return maxrec;
    }




//    42. Trapping Rain Water

    int trap(vector<int>& height) {

        int n = height.size();

        int curr_lmax = 0;

        vector<int> lmax(n);

        for(int i = 0 ; i<n;i++){
            lmax[i]=curr_lmax;
            curr_lmax = max(height[i],curr_lmax);
        }

        int curr_rmax = 0;
        vector<int> rmax(n);

        for(int i = n-1; i>=0 ;i--){
            rmax[i]=curr_rmax;
            curr_rmax = max(height[i],curr_rmax);
        }


        int ans = 0;

        for(int i = 0; i<n;i++){
            int water = (min(lmax[i],rmax[i]))-height[i];
            if(water>0){
                ans = ans+water;
            }
        }

        return ans;

    }
};


int main() {
    Solution sol;
    string a = "ab#c", t = "ad#c";
    cout << sol.backspaceCompare(a, t) << "\n"; // expected 1

    string s = "()[]{}";
    cout << sol.isValid(s) << "\n"; // expected 1

    vector<int> s84 = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(s84) << "\n"; // expected 10


    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // expected 6
    cout << sol.trap(height);
    return 0;
}

