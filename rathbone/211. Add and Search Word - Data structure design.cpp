//211. Add and Search Word - Data structure design
/***
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
***/

/***
Time: add / search: O(wordLength) average, For search -> max O(26^n)
Space: O(numOfTrieNode * 26) = O(numOfWords * wordLength * 26)
***/
//Solution
class Trie{
    public:
    bool isWord;
    Trie *children[26];
    Trie() {
        isWord = false;
        memset(children, NULL, sizeof(Trie*)*26);
    }
};
class WordDictionary {
private:
    Trie *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *cur = root;
        for(char c: word) {
            if(!cur->children[c-'a']) {
                cur->children[c-'a'] = new Trie();
            }
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word.c_str(), root);
    }
private:
    bool query(const char *word, Trie *node) {
        Trie *cur = node;
        for(int i=0;word[i];i++) {
            if(cur) {
                if(word[i]!='.') {
                    cur=cur->children[word[i]-'a'];
                } else {
                    Trie *temp=cur;
                    for(int j=0;j<26;j++) {
                        cur = temp->children[j];
                        if(query(word+i+1, cur)) {
                            return true;
                        }
                    }
                }
            } else {
                break;
            }
        }
        return cur && cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */