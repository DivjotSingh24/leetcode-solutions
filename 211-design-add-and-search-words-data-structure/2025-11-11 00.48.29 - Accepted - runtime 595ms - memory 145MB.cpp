class WordDictionary {
public:
    unordered_set<string> st;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        st.insert(word);
    }
    
    bool search(string word) {
        vector<int> pos;
        for(int i =0;i<word.size();i++){
            char ch = word[i];
            if(ch=='.') pos.push_back(i);
        }
        if(st.count(word)) return true;
        if(pos.size()==1){
            char ch = 'a';
            for(int i = 0;i<26;i++){
                word[pos[0]] = ch;
                if(st.count(word)) return true;
                ch++;
            }
        }
        if(pos.size()==2){
            char ch1 = 'a';
            for(int i = 0;i<26;i++){
                word[pos[0]] = ch1;
                ch1++;
                char ch2 = 'a';
                for(int j = 0;j<26;j++){
                    word[pos[1]] = ch2;
                    ch2++;
                    if(st.count(word)) return true;
                }
            }
        }
        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */