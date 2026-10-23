class LRUCache {
public:
    class ListNode {
    public:
        int value, key;
        ListNode* next;
        ListNode* prev;

        ListNode(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, ListNode*> mpp;
    ListNode* head;
    ListNode* tail;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(ListNode* node) {
        ListNode* behind = tail->prev;
        behind->next = node;
        node->prev = behind;
        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        ListNode* node = mpp[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mpp.find(key) != mpp.end()) {
            ListNode* node = mpp[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }

        if (mpp.size() == cap) {
            ListNode* lru = head->next;
            remove(lru);
            mpp.erase(lru->key);
            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        mpp[key] = node;
        insert(node);
    }
};