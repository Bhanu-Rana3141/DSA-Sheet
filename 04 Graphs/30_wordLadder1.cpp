#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
using namespace std;

// TC -> O(N * M) && SC - O(N * M) in case of unordered set
// O(N * M * LOG N) -> using set

int shortestSteps(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == endWord) return steps;

        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    q.push({word, steps + 1});
                    st.erase(word);   
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << shortestSteps(beginWord, endWord, wordList);

    return 0;
}