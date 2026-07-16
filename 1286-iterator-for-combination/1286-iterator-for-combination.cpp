class CombinationIterator {
public:
    vector<string> combinations;
    int index;

    void generate(string &characters, int combinationLength, int start, string current) {
        if (current.size() == combinationLength) {
            combinations.push_back(current);
            return;
        }

        for (int i = start; i < characters.size(); i++) {
            generate(characters, combinationLength, i + 1, current + characters[i]);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        generate(characters, combinationLength, 0, "");
    }

    string next() {
        return combinations[index++];
    }

    bool hasNext() {
        return index < combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */