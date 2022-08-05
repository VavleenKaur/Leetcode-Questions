class Solution {
public:
    void rec(vector<vector<int>>& image, int x, int y,int color, int startcolor,int m , int n)
    {
        if(x<0 || y<0 || x>=m || x>=n || image[x][y]!=startcolor || image[x][y]==color) return;
        image[x][y]=color;
        rec(image,x+1,y,color,startcolor,m,n);
        rec(image,x,y+1,color,startcolor,m,n);
        rec(image,x,y-1,color,startcolor,m,n);
        rec(image,x-1,y,color,startcolor,m,n);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rec(image,sr,sc,color,image[sr][sc],image.size(),image[0].size());
        return image;
    }
};