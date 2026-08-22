class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string,int> freq;

        string word = "";
        string bestWord = "";
        int bestCount = 0;

        for(int i = 0; i <= paragraph.size(); i++){
            if(i < paragraph.size() && isalpha(paragraph[i])){
                word += tolower(paragraph[i]);
            } else {
                if(!word.empty()){
                    if(bannedSet.find(word) == bannedSet.end()){
                        freq[word]++;
                        if(freq[word] > bestCount){
                            bestCount = freq[word];
                            bestWord = word;
                        }
                    }
                    word = "";
                }
            }
        }

        return bestWord;
    }
};