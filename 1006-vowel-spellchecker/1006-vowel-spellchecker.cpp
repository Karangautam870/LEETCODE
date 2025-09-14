
class Solution {
public:
    string toLower(string& s) {
        string t = s;
        for (char& c : t) {
            c = tolower(c);
        }
        return t;
    }

    string devowel(string& s) {
        string t = s;
        for (char& c : t) {
            if (isVowel(c)) {
                c = '*';
            }
        }
        return t;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<string> spellchecker(vector<string>& wordlist,vector<string>& queries){

        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        for (string word : wordlist) {
            exact.insert(word);

            string lower = toLower(word);

            if (caseMap.count(lower) == 0) {
                caseMap[lower] = word;
            }

            string dev = devowel(lower);
            if (!vowelMap.count(dev)) {
                vowelMap[dev] = word;
            }
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
            } else {
                string lower = toLower(q);
                if (caseMap.count(lower)) {
                    ans.push_back(caseMap[lower]);
                } else {
                    string dev = devowel(lower);

                    if (vowelMap.count(dev)) {
                        ans.push_back(vowelMap[dev]);
                    } else {
                        ans.push_back("");
                    }
                }
            }
        }
        return ans;
    }
};
