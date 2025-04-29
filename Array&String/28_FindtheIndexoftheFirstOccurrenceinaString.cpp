/*
    Given two strings needle and haystack, return the index of the first occurrence of 
    needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n=haystack.size(),m=needle.size();
            for(int i=0;i<=n-m;i++){
                if(needle == haystack.substr(i,m)){
                    return i;
                }
            }
            return -1;
        }
    };