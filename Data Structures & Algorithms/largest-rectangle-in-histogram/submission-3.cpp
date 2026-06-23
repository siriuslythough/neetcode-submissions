class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st1;
        stack<int> st2;
        vector<int> pse(heights.size(), 0);
        vector<int> nse(heights.size(), 0);
        nse[heights.size()-1] = heights[heights.size()-1];

        // PSE and NSE indices should be stored because that keeps complexity in control, otehrwise parsing till you find PSE NSE is gonna go into O(N^2)-ish

        for(int i = 0; i<heights.size(); i++){ //its about storing previous smallest element's index, not the element itself, because for element you need to go check for the element with while loops. Index allows you to make direct calculation.
            while(!st1.empty() && heights[st1.top()]>=heights[i]){// here you compare the heights on those indices
                st1.pop();
            }
            if(st1.empty()) pse[i] = -1;
            else pse[i] = st1.top();
            st1.push(i);
        }
        for(int j = heights.size()-1; j>=0; j--){//its about storing previous smallest element's index, not the element itself, because for element you need to go check for the element with while loops. Index allows you to make direct calculation.
            while(!st2.empty() && heights[st2.top()]>=heights[j]){// here you compare the heights on those indices
                st2.pop();
            }
            if(st2.empty()) nse[j] = heights.size(); // Here you were supposed to locate it to out of right hand size, that is heights.size(), not -1
            else nse[j] = st2.top();
            st2.push(j);
        }
        int max_area = 0;
        int curr_area = 0;
        int l;
        int r;
        int width;
        for(int k = 0; k<heights.size(); k++){
            l = pse[k];
            r = nse[k];
            width = r-l-1;
            curr_area = heights[k]*width;
            max_area = max(curr_area, max_area);
        }
        return max_area;
    }
};
