class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>>m1;
    
	vector<int>v1(0,s.length());
   
   for(int i=0;i<s.length();i++){
       
	   if(m1.find(s[i])==m1.end()){
            
			pair<int,int>p1={i,i};

            m1.insert({s[i],p1});
        }
        else{
            m1[s[i]].second=i;
        }
  
  }
    int max1=m1[s[0]].second;                       //variable to store the maxindex value for 1st element of string
    int presum=0;                                          //to store prefix sum of elements of vector to obtain the length of stored partition
    
	for(int i=0;i<s.length();i++){                    

        if(m1[s[i]].second>max1){                  //if we find a character whose maxvalue > current maxvalue then we update the current maxvalue
            max1=m1[s[i]].second;
       }
        if(i==max1){                                         //if i reaches the current max value then we see that the maxlength partition is formed so we take               
		if(v1.size()==0){                                    //the length of it and push then the value is pushed back to the resultant vector 
                v1.push_back(i+1);                      //if first element is being inserted we do not need presum
         }
            else{
            presum+=v1.back();                     
            v1.push_back((i+1)-presum);      // else we push the i+1th (as the string is 0indexed) - presum
             }
                max1=m1[s[i+1]].second;       //then we finally update the current maxvalue as s[i+1] th element maxvalue
        }
     }
    
    return v1;
    }
};