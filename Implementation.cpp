#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
        }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        
        root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
            {
                parent->children[val] = new TrieNode();
            }
            parent = parent->children[val];
        }
        parent->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        int n = word.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = word[i]-'a';
            if(parent->children[val]==NULL)
            {
                return false;
            }
            parent = parent->children[val];
        }
        return parent->isEnd;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        int n = prefix.size();
        TrieNode* parent = root;
        for(int i=0; i<n; i++)
        {
            int val = prefix[i]-'a';
            if(parent->children[val]==NULL)
            {
                return false;
            }
            parent = parent->children[val];
        }
        return true;
        
    }
};
// 2

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isLeaf;
    TrieNode(char ch){
        data= ch;
        for(int i=0;i<26;i++)
        children[i]=NULL;
        isLeaf=false;
    }
};

void insert( TrieNode *root, string key)
{
   if(key.length() == 0){
        root->isLeaf = true;
        return;
   }
   
   int index = key[0] - 'a';
   TrieNode *child;
   

// when word is present
   if(root->children[index] != NULL){
       child = root->children[index];
   }
 // when word is absent
   else{
       child = new TrieNode(key[0]);
       root->children[index] = child;
   }
   
   insert(child, key.substr(1));
}


bool search( TrieNode *root, string key) 
{
   if(key.length() == 0){
       return root->isLeaf;
   }
   
   int index = key[0] - 'a';
   TrieNode *child;
   

// when word is present
   if(root->children[index] != NULL){
       child = root->children[index];
   }

// when word is absent
   else{
       return false;
   }  
   return search(child, key.substr(1));
}
int main(){
    return 0;
}   

// search fucntion 
 bool searchHelper(string word,TrieNode*node) 
{
  for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->children)
                    if(c && searchHelper(word.substr(i+1), c)) return true;
                return false;
            }
            int idx = ch - 'a';
            if(node->children[idx]==NULL) return false;
            node = node->children[idx];
        }
        return node->isterminal;
}
    bool search(string word) {
       return searchHelper(word,root);
    }