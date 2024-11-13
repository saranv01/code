struct Ds {
    int key;
    int value;
    Ds* prev;
    Ds* next;
    Ds(int da, int db, Ds* p, Ds* n) {
        key = da;
        value = db;
        prev = p;
        next = n;
    }
    Ds(int da, int db) {
        key = da;
        value = db;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int size;
    unordered_map<int, Ds*> mp;
    stack<int> stk;
    Ds* f;
    Ds* r;
    int capacity;
public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity=capacity;
        f = new Ds(-1, -1);
        r = new Ds(-1, -1);
        f->next = r;
        r->prev = f;
    }

void add(int key, int value) {
    Ds* temp = new Ds(key, value, f, f->next);
    f->next->prev = temp;
    f->next = temp;

    mp[key] = temp;

}
    int get(int key) {

        if (mp.find(key) != mp.end()) {
            // give the value
            Ds* temp = mp[key];
            int val = temp->value;
            // update its accessed recently


            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->prev = f;
            temp->next = f->next;
            f->next->prev = temp;
            f->next = temp;

            return val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {

            if(mp.find(key) != mp.end()) {
                Ds* temp = mp[key];
                temp->value = value;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = f;
                temp->next = f->next;
                f->next->prev = temp;
                f->next = temp;
            
        } else {
            if(size==capacity){
            Ds* lr = r->prev;
            lr->prev->next = r;
            r->prev = lr->prev;
            mp.erase(lr->key);
            delete lr;
            size--;            
            }
            add(key, value); 
            size++;  
        }
    }
    ~LRUCache() {
    Ds* current = f->next;
    while (current != r) {
        Ds* temp = current;
        current = current->next;
        delete temp;  // Free memory for each node
    }
    delete f;  // Delete dummy head
    delete r;  // Delete dummy tail
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */