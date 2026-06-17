lc 126

class Solution {
public:
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string &beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } else {
            for (auto &par : parents[word]) {
                dfs(par, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_map<string, int> level;
        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < temp.size(); i++) {
                char original = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (!dict.count(temp))
                        continue;

                    // First time discovered
                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    }
                    // Another shortest parent found
                    else if (level[temp] == currLevel + 1) {
                        parents[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};
