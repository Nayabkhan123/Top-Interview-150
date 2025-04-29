/*
    Given an input string s, reverse the order of the words.

    A word is defined as a sequence of non-space characters. The words in s will be separated 
    by at least one space.

    Return a string of the words in reverse order concatenated by a single space.

    Note that s may contain leading or trailing spaces or multiple spaces between two words. 
    The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans="";
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            int j=i+1;
            while(j<n && s[j]!=' ') j++;
            if(ans.size()==0) ans=s.substr(i,j-i);
            else ans=s.substr(i,j-i) + ' ' + ans;
            i=j+1;
        }
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        vector<string>temp;
        int n = s.size();
        string str;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(str.size())
                temp.push_back(str);
                str="";
            }
            else{
                str.push_back(s[i]);
            }
        }
        if(str.size()) temp.push_back(str);
        string ans="";
        for(int i=temp.size()-1;i>=0;i--){
            ans+=temp[i];
            if(i==0) continue;
            ans+=' ';
        }
        return ans;
    }
};