class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        
    }
};
class LRUCache {

public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* mru = new Node(0,0);
    Node* lru = new Node(0,0);

    LRUCache(int capacity) {
        this->cap = capacity;
        this->lru->next = this->mru;
        this->mru->prev = this->lru;
    }
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;


    }

    void insert(Node* node){
        Node* ourprev = mru->prev;
        ourprev->next = node;
        node->next = mru;
        mru->prev = node;
        node->prev = ourprev;
    }
    int get(int key) {
        if(this->cache.contains(key)){
            Node* node = this->cache[key];
            remove(node);
            insert(node);
            return node->val;

        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            remove(cache[key]);
            

        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > cap){
            Node* leastRU = this->lru->next;
            remove(leastRU);
            cache.erase(leastRU->key);

        }






        
    }
};
