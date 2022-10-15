class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //approach1--> USING HASHMAP
        map<char,int> mp;
        int cnt=0,mx=0;int j=0;
        int freq[26]={0};int i=0;
        for(i=0;i<s.length();i++){
            char ch=s[i];
            
            if(mp[ch-'a']==0){
                cnt++;
                mx=max(mx,cnt);
                
            }
            else{
                //cout<<cnt<<" ^ ";
                mx=max(mx,i-j);
                while(s[j]!=ch){
                    mp[s[j]-'a']--;
                    j++;
                }
                mp[s[i]-'a']--;
                j++;
                cout<<j<<" "<<i<<endl;
                cnt=0;
            }
            mp[s[i]-'a']++;
        }
         mx=max(mx,i-j);
     
        return mx;
            
       
    }
};
