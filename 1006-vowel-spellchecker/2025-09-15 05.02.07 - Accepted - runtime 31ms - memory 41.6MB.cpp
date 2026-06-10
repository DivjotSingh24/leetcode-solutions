#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact_word;
        unordered_map<string, string> case_ins;
        unordered_map<string, string> vowel;

        for(string& word: wordlist){
            exact_word.insert(word);

            string low_word = word;
            transform(low_word.begin(), low_word.end(), low_word.begin(), ::tolower);
            if(case_ins.find(low_word) == case_ins.end()){
                case_ins[low_word] = word;
            }

            string no_vowel = low_word;
            for(char& c: no_vowel){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c== 'u'){
                c = '|';}
            }
            if(vowel.find(no_vowel) == vowel.end()){
                vowel[no_vowel] = word;
            }

        }

        vector<string> result;
        for(string& q: queries){
            if(exact_word.count(q)){
                result.push_back(q);
                continue;
            }
            string low_q = q;
            transform(low_q.begin(), low_q.end(), low_q.begin(), ::tolower);
            if(case_ins.count(low_q)){
                result.push_back(case_ins[low_q]);
                continue;
            }
            string no_vowel = low_q;
            for(char& c: no_vowel){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c== 'u'){
                c = '|';}
            }
            if(vowel.count(no_vowel)){
                result.push_back(vowel[no_vowel]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }
};