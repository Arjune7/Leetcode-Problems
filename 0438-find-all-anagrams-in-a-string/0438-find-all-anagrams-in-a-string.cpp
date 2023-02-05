class Solution {
public:
    
    //Checking if the frequency of fs and fp are same for checking anagram
    bool isAnagram(int fs[],int fp[]){
        for(int i=0;i<26;i++){
            //If any point the frequency is not same then return false;
            if(fs[i]!=fp[i]){
                return false;
            }
        }
        //If the frequency is same return the true
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        //Ans vector for storing the index
        vector<int>ans;
        
        int n=s.size(),m=p.size();
        //fs would contain the frequency of char of string s of length size m
        //fp would contain the frequency of char of string p 
        int fs[26]={0},fp[26]={0};
        //Storing the frequency of string p in fp array
        for(int i=0;i<m;i++){
            fp[p[i]-'a']++;
        }
        
        //Traversing the s string we encounter 3 situations
            //1. if my length till index i is less than the m-1 length 
                //then just increase the frequency 
            //2. if the index i equal to m-1 then we will check if it is anagram or not
            //3. if the index i greater than m-1 then
                //a. we remove the i-m th char from our frequency arr fs
                //b. we add the i th char in our frequency array fs.
                //c. we will check if it is anagram to p
        for(int i=0;i<n;i++){
            //first condition
            if(i<m-1){
                fs[s[i]-'a']++;
            }
            //second condition
            else if(i==m-1){
                fs[s[i]-'a']++;
                //checking if they are anagram
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
            //third condition
            else{
                fs[s[i-m]-'a']--;
                fs[s[i]-'a']++;
                //checking if they are anagram
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
        }
        //returning the ans vector
        return ans;
    }
};