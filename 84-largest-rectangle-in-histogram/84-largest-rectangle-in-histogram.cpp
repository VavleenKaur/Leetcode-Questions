class Solution {
public:
    void prevSmaller(vector<int>&heights, vector<int>&prev_sm)
    {
        stack<int>s;
        for(int i=0;i<heights.size();i++)
        {  
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
                
                
            }
            if(s.empty()) 
            {
                prev_sm[i]=-1;
                s.push(i);
            }
            else if(heights[s.top()]<heights[i])
            {
                prev_sm[i]=s.top();
                s.push(i);
            }
         
        }
    }
    void nextSmaller(vector<int>&heights, vector<int>&next_sm)
    {
        stack<int>s;
        for(int i=heights.size()-1;i>=0;i--)
        {   
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
                
            }
            if(s.empty()) 
            {next_sm[i]=-1;
             s.push(i);
            }
            else if(heights[s.top()]<heights[i])
            {
                next_sm[i]=s.top();
                s.push(i);
                
            }
         
        }
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev_sm(n,0),next_sm(n,0);
        int max_area=0;
        prevSmaller(heights,prev_sm);
         nextSmaller(heights,next_sm);
        for(int i=0;i<n;i++)
        {
            
            if(next_sm[i]==-1)
            {
                next_sm[i]=heights.size();
            }
           int breadth=next_sm[i]-prev_sm[i]-1;
            
           int area=breadth*heights[i];
            max_area=max(max_area,area);
            
        }
        return max_area;
        
}
};