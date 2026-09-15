#include <string>

// ===================== MY VECTOR (dynamic array) ================
class MyVector {
    int* data;
    int cap;
    int len;
    void grow();
public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector&) = delete;
    MyVector& operator=(const MyVector&) = delete;

    void pushBack(int v);
    void insertAt(int pos, int v);
    bool deleteValue(int v);
    bool deleteAt(int pos);
    int get(int pos) const;
    int size() const;
    bool empty() const;
    void display() const;

    int* begin();             // pointer-as-iterator, start of range
    int* end();                // pointer-as-iterator, one past the end
};

// ===================== MY LIST (doubly linked list) ==============
struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;
};

class MyList {
    ListNode* head;
    ListNode* tail;
    int len;
public:
    MyList();
    ~MyList();
    MyList(const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    void pushFront(int v);
    void pushBack(int v);
    bool popFront();
    bool popBack();
    bool deleteValue(int v);
    int size() const;
    bool empty() const;
    void display() const; // traverses node-by-node (head -> tail)
};

// ===================== MY STACK (linked-list based, LIFO) ========
struct StackNode {
    int data;
    StackNode* next;
};

class MyStack {
    StackNode* topNode;
    int len;
public:
    MyStack();
    ~MyStack();
    MyStack(const MyStack&) = delete;
    MyStack& operator=(const MyStack&) = delete;

    void push(int v);
    bool pop(int& outVal);
    bool peek(int& outVal) const;
    int size() const;
    bool empty() const;
    void display() const; // top -> bottom, read-only traversal
};

// ===================== MY QUEUE (linked-list based, FIFO) ========
struct QueueNode {
    int data;
    QueueNode* next;
};

class MyQueue {
    QueueNode* head;
    QueueNode* tail;
    int len;
public:
    MyQueue();
    ~MyQueue();
    MyQueue(const MyQueue&) = delete;
    MyQueue& operator=(const MyQueue&) = delete;

    void enqueue(int v);
    bool dequeue(int& outVal);
    bool front(int& outVal) const;
    int size() const;
    bool empty() const;
    void display() const; // front -> back, read-only traversal
};

// ===================== MY MAP (key-value pairs, dynamic array) ===
struct KeyValue {
    std::string key;
    int value;
};

class MyMap {
    KeyValue* data;
    int cap;
    int len;
    void grow();
    int findIndex(const std::string& key) const;
public:
    MyMap();
    ~MyMap();
    MyMap(const MyMap&) = delete;
    MyMap& operator=(const MyMap&) = delete;

    void set(const std::string& key, int value); // insert or update
    bool remove(const std::string& key);
    bool get(const std::string& key, int& outValue) const;
    int size() const;
    bool empty() const;
    void displaySorted() const; // sorted by key, alphabetically
};

// ===================== MY SET (unique ints, dynamic array) =======
class MySet {
    int* data;
    int cap;
    int len;
    void grow();
    int findIndex(int v) const;
public:
    MySet();
    ~MySet();
    MySet(const MySet&) = delete;
    MySet& operator=(const MySet&) = delete;

    bool insert(int v);   // false if v is already present
    bool remove(int v);
    bool contains(int v) const;
    int size() const;
    bool empty() const;
    void displaySorted() const;
};

// ===================== HAND-WRITTEN ALGORITHMS ====================

void mySort(int* begin, int* end, bool ascending);
int* myFind(int* begin, int* end, int value);
bool myBinarySearch(int* begin, int* end, int value); // range must be sorted

// ===================== INPUT VALIDATION ========================
long long readIntValidated(const std::string& prompt, long long minv, long long maxv);
std::string readNonEmptyLine(const std::string& prompt);

// ===================== DISPLAY HELPERS ==========================
void printLine(char c = '=', int len = 70);
void printCenter(const std::string& text, int width = 70);
void pauseForUser();

// ===================== STL MANAGER ============================
class STLManager {
    MyVector myVector;
    MyList myList;
    MyStack myStack;
    MyQueue myQueue;
    MyMap myMap;
    MySet mySet;

public:
    void vectorOperations();
    void listOperations();
    void stackOperations();
    void queueOperations();
    void mapOperations();
    void setOperations();

    void sortVector();
    void searchVector();
    void frequencyCounter();
};

