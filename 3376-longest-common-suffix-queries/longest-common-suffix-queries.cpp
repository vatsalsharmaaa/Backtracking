class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;
    vector<string>* words;

    void updateNode(int node, int index) {

        if (trie[node].idx == -1 ||
            (*words)[index].size() < (*words)[trie[node].idx].size()) {

            trie[node].idx = index;
        }
    }

    void insert(string &s, int index) {

        int node = 0;

        updateNode(node, index);

        for (int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            updateNode(node, index);
        }
    }

    int search(string &s) {

        int node = 0;
        int ans = trie[0].idx;

        for (int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
            ans = trie[node].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = &wordsContainer;

        trie.reserve(500000 + 5);
        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};