/*
    Given an array of integers citations where citations[i] is the number of citations a 
    researcher received for their ith paper, return the researcher's h-index.

    According to the definition of h-index on Wikipedia: The h-index is defined as the 
    maximum value of h such that the given researcher has published at least h papers 
    that have each been cited at least h times.
*/

// timeComplexity: O(n) spaceComplexity: O(n)
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int n=citations.size();
            vector<int>temp(n+1,0);
            for(auto it:citations){
                if(it>n) temp[n]++;
                else temp[it]++;
            }
            int cnt=0;
            for(int i=n;i>=0;i--){
                cnt+=temp[i];
                if(i<=cnt) return i;
            }
            return 0;
        }
    };

// timeComplexity: O(n*log(n)) spaceComplexity: O(n)
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            priority_queue<int,vector<int>,greater<int>>pq;
            for(auto it : citations){
                pq.push(it);
            }
            int n=citations.size();
            for(int i=0;i<n;i++){
                int size=pq.size();
                if(pq.top()>=size){
                    return size;
                }
                pq.pop();
            }
            return 0;
        }
    };

// timeComplexity: O(n*log(n)) spaceComplexity: O(1)
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            sort(citations.begin(),citations.end());
            int n=citations.size();
            int temp=n;
            for(int i=0;i<n;i++){
                if(citations[i]>=temp){
                    return temp;
                }
                temp-=1;
            }
            return 0;
        }
    };