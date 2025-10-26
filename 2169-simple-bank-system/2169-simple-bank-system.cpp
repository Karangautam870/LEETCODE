class Bank {
public:
    map<long long,long long>mp;
    
    bool transfer(int ac1, int ac2, long long m) {
        if(mp.count(ac1) == 0 || mp[ac1] < m || mp.count(ac2) == 0){
            return 0;
        }
        
        mp[ac2] += m;
        mp[ac1] -= m;
        return 1;
    }
    
    bool deposit(int ac, long long m) {
        if(mp.count(ac) == 0){
            return 0;
        }

        mp[ac] += m;
        return 1;
    }
    
    bool withdraw(int ac, long long m) {
        if(mp.count(ac) == 0 || mp[ac] < m){
            return 0;
        }
        mp[ac] -=  m;
        return 1;
    }

    Bank(vector<long long>& bal) {
        for(int i = 0;i < bal.size();i++){
            mp[i + 1] = bal[i];
        }
    }
};
