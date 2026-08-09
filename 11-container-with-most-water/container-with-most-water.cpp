class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN;
        int i=0;
        int j = height.size()-1;
        int actual =1;
        
           while(i<j) 
            if(height[i]>height[j]){
                actual= height[j];
                int distance = j-i;
                int area = actual * distance;
                if(area>max){
                max = area;
                }
         
                j--;
            }else{
                actual = height[i];
                int distance = j-i;
                int area = actual * distance;
                if(area>max){
                max = area;
                }
                i++;
                
            }
            
            
               return max;    
            
        }
        
    
};