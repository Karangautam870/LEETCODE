class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        int n = w.size();
        if(n == 1){
            return w;
        }

        vector<string> ans;
        ans.push_back(w[0]);
        for(int i = 1; i < n;i++){
            
            string a = ans.back();             
            sort(a.begin(), a.end()); 
            string b = w[i];
            sort(b.begin(),b.end());

            if(a != b){
                ans.push_back(w[i]);
            }
        }
        return ans;
    }
};