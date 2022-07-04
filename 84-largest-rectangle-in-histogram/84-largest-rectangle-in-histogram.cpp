class Solution {
    private:
    vector<int> next_small(vector<int> arr)
    {   stack<int>s;
        s.push(-1);
         int n=arr.size();
         vector<int> next(n);
        for(int i=n-1;i>=0;i--)
        {   int top=s.top();
            while(top!=-1 && arr[top]>=arr[i])
            {
                s.pop();
                top=s.top();
            }
             if(top==-1 || arr[top]<arr[i]){
                 next[i]=top;
                 s.push(i);
             }
        }
     return next;
    }
    vector<int> prev_small(vector<int> arr)
    {   stack<int>s;
        s.push(-1);
         int n=arr.size();
         vector<int> prev(n);
        
        for(int i=0;i<n;i++)
        {   int top=s.top();
            while(top!=-1 && arr[top]>=arr[i])
            {
                s.pop();
                top=s.top();
            }
             if(top==-1 || arr[top]<arr[i]){
                 prev[i]=top;
                 s.push(i);
             }
        }
     return prev;
    }
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        vector<int>n,p;
        n=next_small(heights);
        p=prev_small(heights);
        for(int i=0;i<heights.size();i++)
        {
            int length=heights[i];
            if(n[i]==-1)
            {
                n[i]=heights.size();
            }
            int breadth=n[i]-p[i]-1;
            int area=length*breadth;
            max_area=max(max_area,area);
        }
        return max_area;
    }
};