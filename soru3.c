#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

#define ALPHABET_SIZE 26
// Trie düğümü
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Yeni bir Trie düğümü oluşturma fonksiyonu
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node) {
        int i;
        node->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

// Trie'ye kelime ekleme fonksiyonu
void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* temp = root;
    while (*word) {
        int index = *word - 'a';
        if (!temp->children[index]) {
            temp->children[index] = createNode();
        }
        temp = temp->children[index];
        word++;
    }
    temp->isEndOfWord = true;
}

// Trie'de kelime arama fonksiyonu
bool search(struct TrieNode* root, const char* word) {
    struct TrieNode* temp = root;
    while (*word) {
        int index = *word - 'a';
        if (!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
        word++;
    }
    return (temp != NULL && temp->isEndOfWord);
}

int main() {
    struct TrieNode* root = createNode();

    // Trie'ye kelimeler ekleme
    insert(root, "hello");
    insert(root, "world");
    insert(root, "apple");
    insert(root, "app");

    // Kelime arama
    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("%s\n", search(root, "world") ? "Found" : "Not Found");
    printf("%s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("%s\n", search(root, "app") ? "Found" : "Not Found");
    printf("%s\n", search(root, "banana") ? "Found" : "Not Found");

    return 0;
}