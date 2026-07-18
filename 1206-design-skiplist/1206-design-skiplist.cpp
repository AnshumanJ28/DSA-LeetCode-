class Skiplist {
    class Node {
    public:
        int val;
        vector<Node*> forward;

        Node(int val, int level) {
            this->val = val;
            forward.resize(level + 1, nullptr);
        }
    };

    const int MAX_LEVEL = 16;
    int level;
    Node* head;

    int randomLevel() {
        int lvl = 0;
        while ((rand() & 1) && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    Skiplist() {
        level = 0;
        head = new Node(-1, MAX_LEVEL);
    }

    bool search(int target) {
        Node* curr = head;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < target)
                curr = curr->forward[i];
        }

        curr = curr->forward[0];

        return curr && curr->val == target;
    }

    void add(int num) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* curr = head;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }

        int newLevel = randomLevel();

        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++)
                update[i] = head;
            level = newLevel;
        }

        Node* node = new Node(num, newLevel);

        for (int i = 0; i <= newLevel; i++) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* curr = head;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }

        curr = curr->forward[0];

        if (!curr || curr->val != num)
            return false;

        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != curr)
                break;
            update[i]->forward[i] = curr->forward[i];
        }

        delete curr;

        while (level > 0 && head->forward[level] == nullptr)
            level--;

        return true;
    }
};