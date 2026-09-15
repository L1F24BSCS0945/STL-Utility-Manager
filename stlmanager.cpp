#include "stlmanager.h"
#include <iostream>
using namespace std;

// ============================================================
//  STL UTILITY MANAGER - IMPLEMENTATION
// ============================================================

// ===================== MY VECTOR ================================
MyVector::MyVector() : data(nullptr), cap(0), len(0) {}
MyVector::~MyVector() { delete[] data; }

void MyVector::grow() {
    int newCap = (cap == 0) ? 4 : cap * 2;
    int* newData = new int[newCap];
    for (int i = 0; i < len; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    cap = newCap;
}

void MyVector::pushBack(int v) {
    if (len == cap) grow();
    data[len++] = v;
}

void MyVector::insertAt(int pos, int v) {
    if (len == cap) grow();
    for (int i = len; i > pos; --i) data[i] = data[i - 1];
    data[pos] = v;
    ++len;
}

bool MyVector::deleteValue(int v) {
    for (int i = 0; i < len; ++i) {
        if (data[i] == v) return deleteAt(i);
    }
    return false;
}

bool MyVector::deleteAt(int pos) {
    if (pos < 0 || pos >= len) return false;
    for (int i = pos; i < len - 1; ++i) data[i] = data[i + 1];
    --len;
    return true;
}

int MyVector::get(int pos) const { return data[pos]; }
int MyVector::size() const { return len; }
bool MyVector::empty() const { return len == 0; }

void MyVector::display() const {
    cout << "  [ ";
    for (int i = 0; i < len; ++i) cout << data[i] << " ";
    cout << "]\n";
}

int* MyVector::begin() { return data; }
int* MyVector::end() { return data + len; }

// ===================== MY LIST ================================
MyList::MyList() : head(nullptr), tail(nullptr), len(0) {}

MyList::~MyList() {
    ListNode* cur = head;
    while (cur) { ListNode* nxt = cur->next; delete cur; cur = nxt; }
}

void MyList::pushFront(int v) {
    ListNode* node = new ListNode{ v, nullptr, head };
    if (head) head->prev = node; else tail = node;
    head = node;
    ++len;
}

void MyList::pushBack(int v) {
    ListNode* node = new ListNode{ v, tail, nullptr };
    if (tail) tail->next = node; else head = node;
    tail = node;
    ++len;
}

bool MyList::popFront() {
    if (!head) return false;
    ListNode* old = head;
    head = head->next;
    if (head) head->prev = nullptr; else tail = nullptr;
    delete old;
    --len;
    return true;
}

bool MyList::popBack() {
    if (!tail) return false;
    ListNode* old = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr; else head = nullptr;
    delete old;
    --len;
    return true;
}

bool MyList::deleteValue(int v) {
    ListNode* cur = head;
    while (cur) {
        if (cur->data == v) {
            if (cur->prev) cur->prev->next = cur->next; else head = cur->next;
            if (cur->next) cur->next->prev = cur->prev; else tail = cur->prev;
            delete cur;
            --len;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int MyList::size() const { return len; }
bool MyList::empty() const { return len == 0; }

void MyList::display() const {
    cout << "  [ ";
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) cout << cur->data << " ";
    cout << "]\n";
}

// ===================== MY STACK ================================
MyStack::MyStack() : topNode(nullptr), len(0) {}

MyStack::~MyStack() {
    StackNode* cur = topNode;
    while (cur) { StackNode* nxt = cur->next; delete cur; cur = nxt; }
}

void MyStack::push(int v) {
    topNode = new StackNode{ v, topNode };
    ++len;
}

bool MyStack::pop(int& outVal) {
    if (!topNode) return false;
    StackNode* old = topNode;
    outVal = old->data;
    topNode = old->next;
    delete old;
    --len;
    return true;
}

bool MyStack::peek(int& outVal) const {
    if (!topNode) return false;
    outVal = topNode->data;
    return true;
}

int MyStack::size() const { return len; }
bool MyStack::empty() const { return len == 0; }

void MyStack::display() const {
    cout << "  [ top -> ";
    for (StackNode* cur = topNode; cur != nullptr; cur = cur->next) cout << cur->data << " ";
    cout << "<- bottom ]\n";
}

// ===================== MY QUEUE ================================
MyQueue::MyQueue() : head(nullptr), tail(nullptr), len(0) {}

MyQueue::~MyQueue() {
    QueueNode* cur = head;
    while (cur) { QueueNode* nxt = cur->next; delete cur; cur = nxt; }
}

void MyQueue::enqueue(int v) {
    QueueNode* node = new QueueNode{ v, nullptr };
    if (tail) tail->next = node; else head = node;
    tail = node;
    ++len;
}

bool MyQueue::dequeue(int& outVal) {
    if (!head) return false;
    QueueNode* old = head;
    outVal = old->data;
    head = old->next;
    if (!head) tail = nullptr;
    delete old;
    --len;
    return true;
}

bool MyQueue::front(int& outVal) const {
    if (!head) return false;
    outVal = head->data;
    return true;
}

int MyQueue::size() const { return len; }
bool MyQueue::empty() const { return len == 0; }

void MyQueue::display() const {
    cout << "  [ front -> ";
    for (QueueNode* cur = head; cur != nullptr; cur = cur->next) cout << cur->data << " ";
    cout << "<- back ]\n";
}

// ===================== MY MAP ================================
MyMap::MyMap() : data(nullptr), cap(0), len(0) {}
MyMap::~MyMap() { delete[] data; }

void MyMap::grow() {
    int newCap = (cap == 0) ? 4 : cap * 2;
    KeyValue* newData = new KeyValue[newCap];
    for (int i = 0; i < len; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    cap = newCap;
}

int MyMap::findIndex(const string& key) const {
    for (int i = 0; i < len; ++i) if (data[i].key == key) return i;
    return -1;
}

void MyMap::set(const string& key, int value) {
    int idx = findIndex(key);
    if (idx != -1) { data[idx].value = value; return; }
    if (len == cap) grow();
    data[len].key = key;
    data[len].value = value;
    ++len;
}

bool MyMap::remove(const string& key) {
    int idx = findIndex(key);
    if (idx == -1) return false;
    for (int i = idx; i < len - 1; ++i) data[i] = data[i + 1];
    --len;
    return true;
}

bool MyMap::get(const string& key, int& outValue) const {
    int idx = findIndex(key);
    if (idx == -1) return false;
    outValue = data[idx].value;
    return true;
}

int MyMap::size() const { return len; }
bool MyMap::empty() const { return len == 0; }

void MyMap::displaySorted() const {
    // Simple selection sort over a temporary copy of indices, so the
    // map's own insertion order is left untouched.
    int* order = new int[len];
    for (int i = 0; i < len; ++i) order[i] = i;
    for (int i = 0; i < len - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < len; ++j)
            if (data[order[j]].key < data[order[minIdx]].key) minIdx = j;
        int tmp = order[i]; order[i] = order[minIdx]; order[minIdx] = tmp;
    }
    for (int i = 0; i < len; ++i)
        cout << "  " << data[order[i]].key << " -> " << data[order[i]].value << "\n";
    delete[] order;
}

// ===================== MY SET ================================
MySet::MySet() : data(nullptr), cap(0), len(0) {}
MySet::~MySet() { delete[] data; }

void MySet::grow() {
    int newCap = (cap == 0) ? 4 : cap * 2;
    int* newData = new int[newCap];
    for (int i = 0; i < len; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    cap = newCap;
}

int MySet::findIndex(int v) const {
    for (int i = 0; i < len; ++i) if (data[i] == v) return i;
    return -1;
}

bool MySet::insert(int v) {
    if (findIndex(v) != -1) return false;
    if (len == cap) grow();
    data[len++] = v;
    return true;
}

bool MySet::remove(int v) {
    int idx = findIndex(v);
    if (idx == -1) return false;
    for (int i = idx; i < len - 1; ++i) data[i] = data[i + 1];
    --len;
    return true;
}

bool MySet::contains(int v) const { return findIndex(v) != -1; }
int MySet::size() const { return len; }
bool MySet::empty() const { return len == 0; }

void MySet::displaySorted() const {
    int* sorted = new int[len];
    for (int i = 0; i < len; ++i) sorted[i] = data[i];
    mySort(sorted, sorted + len, true);
    cout << "  { ";
    for (int i = 0; i < len; ++i) cout << sorted[i] << " ";
    cout << "}\n";
    delete[] sorted;
}

// ===================== HAND-WRITTEN ALGORITHMS ====================
void mySort(int* begin, int* end, bool ascending) {
    // Bubble sort over the [begin, end) pointer range.
    for (int* i = begin; i != end; ++i) {
        for (int* j = begin; j < end - 1 - (i - begin); ++j) {
            bool shouldSwap = ascending ? (*j > *(j + 1)) : (*j < *(j + 1));
            if (shouldSwap) { int tmp = *j; *j = *(j + 1); *(j + 1) = tmp; }
        }
    }
}

int* myFind(int* begin, int* end, int value) {
    for (int* it = begin; it != end; ++it) if (*it == value) return it;
    return end;
}

bool myBinarySearch(int* begin, int* end, int value) {
    int lo = 0, hi = (int)(end - begin) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (begin[mid] == value) return true;
        if (begin[mid] < value) lo = mid + 1; else hi = mid - 1;
    }
    return false;
}

// ===================== INPUT VALIDATION ========================
static string trimCopy(const string& s) {
    size_t b = 0, e = s.size();
    while (b < e && (s[b] == ' ' || s[b] == '\t' || s[b] == '\r')) ++b;
    while (e > b && (s[e - 1] == ' ' || s[e - 1] == '\t' || s[e - 1] == '\r' || s[e - 1] == '\n')) --e;
    return s.substr(b, e - b);
}

static bool parseLongLocal(const string& s, long long& out) {
    string t = trimCopy(s);
    if (t.empty()) return false;
    bool neg = false; size_t i = 0;
    if (t[0] == '-' || t[0] == '+') { neg = (t[0] == '-'); i = 1; }
    if (i >= t.size()) return false;
    long long val = 0;
    for (; i < t.size(); ++i) {
        if (t[i] < '0' || t[i] > '9') return false;
        val = val * 10 + (t[i] - '0');
    }
    out = neg ? -val : val;
    return true;
}

long long readIntValidated(const string& prompt, long long minv, long long maxv) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) { cin.clear(); continue; }
        long long v;
        if (!parseLongLocal(line, v)) { cout << "  Invalid whole number, try again.\n"; continue; }
        if (v < minv || v > maxv) { cout << "  Value must be between " << minv << " and " << maxv << ".\n"; continue; }
        return v;
    }
}

string readNonEmptyLine(const string& prompt) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) { cin.clear(); continue; }
        line = trimCopy(line);
        if (!line.empty()) return line;
        cout << "  This field cannot be empty.\n";
    }
}

// ===================== DISPLAY HELPERS ==========================
void printLine(char c, int len) {
    for (int i = 0; i < len; ++i) cout << c;
    cout << "\n";
}

void printCenter(const string& text, int width) {
    int len = (int)text.size();
    int pad = (width - len) / 2;
    if (pad < 0) pad = 0;
    for (int i = 0; i < pad; ++i) cout << ' ';
    cout << text << "\n";
}

void pauseForUser() {
    cout << "\nPress Enter to return to the menu...";
    string dummy;
    getline(cin, dummy);
}

// ===================== VECTOR OPERATIONS ========================
void STLManager::vectorOperations() {
    while (true) {
        printLine('=');
        printCenter("VECTOR OPERATIONS  (size: " + to_string(myVector.size()) + ")");
        printLine('=');
        cout << "  1. Insert element (push back)\n";
        cout << "  2. Insert at position\n";
        cout << "  3. Delete by value\n";
        cout << "  4. Delete by position\n";
        cout << "  5. Access element by index\n";
        cout << "  6. Display all\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 6);

        if (choice == 0) return;

        if (choice == 1) {
            long long v = readIntValidated("  Value to insert: ", -1000000, 1000000);
            myVector.pushBack((int)v);
            cout << "  Inserted " << v << " at the end.\n";
        }
        else if (choice == 2) {
            long long pos = readIntValidated("  Position (0-" + to_string(myVector.size()) + "): ", 0, (long long)myVector.size());
            long long v = readIntValidated("  Value to insert: ", -1000000, 1000000);
            myVector.insertAt((int)pos, (int)v);
            cout << "  Inserted " << v << " at position " << pos << ".\n";
        }
        else if (choice == 3) {
            long long v = readIntValidated("  Value to delete: ", -1000000, 1000000);
            cout << (myVector.deleteValue((int)v) ? "  Deleted first occurrence of " + to_string(v) + ".\n"
                : "  Value " + to_string(v) + " not found.\n");
        }
        else if (choice == 4) {
            if (myVector.empty()) cout << "  Vector is empty.\n";
            else {
                long long pos = readIntValidated("  Position (0-" + to_string(myVector.size() - 1) + "): ", 0, (long long)myVector.size() - 1);
                myVector.deleteAt((int)pos);
                cout << "  Deleted element at position " << pos << ".\n";
            }
        }
        else if (choice == 5) {
            if (myVector.empty()) cout << "  Vector is empty.\n";
            else {
                long long pos = readIntValidated("  Position (0-" + to_string(myVector.size() - 1) + "): ", 0, (long long)myVector.size() - 1);
                cout << "  Element at index " << pos << " = " << myVector.get((int)pos) << "\n";
            }
        }
        else if (choice == 6) {
            if (myVector.empty()) cout << "  Vector is empty.\n"; else myVector.display();
        }
        pauseForUser();
    }
}

// ===================== LIST OPERATIONS ========================
void STLManager::listOperations() {
    while (true) {
        printLine('=');
        printCenter("LIST OPERATIONS  (size: " + to_string(myList.size()) + ")");
        printLine('=');
        cout << "  1. Insert at front\n";
        cout << "  2. Insert at back\n";
        cout << "  3. Delete from front\n";
        cout << "  4. Delete from back\n";
        cout << "  5. Delete by value\n";
        cout << "  6. Display all (front -> back)\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 6);

        if (choice == 0) return;

        if (choice == 1) {
            long long v = readIntValidated("  Value to insert: ", -1000000, 1000000);
            myList.pushFront((int)v);
            cout << "  Inserted " << v << " at the front.\n";
        }
        else if (choice == 2) {
            long long v = readIntValidated("  Value to insert: ", -1000000, 1000000);
            myList.pushBack((int)v);
            cout << "  Inserted " << v << " at the back.\n";
        }
        else if (choice == 3) {
            cout << (myList.popFront() ? "  Removed front element.\n" : "  List is empty.\n");
        }
        else if (choice == 4) {
            cout << (myList.popBack() ? "  Removed back element.\n" : "  List is empty.\n");
        }
        else if (choice == 5) {
            long long v = readIntValidated("  Value to delete: ", -1000000, 1000000);
            cout << (myList.deleteValue((int)v) ? "  Deleted first occurrence of " + to_string(v) + ".\n"
                : "  Value " + to_string(v) + " not found.\n");
        }
        else if (choice == 6) {
            if (myList.empty()) cout << "  List is empty.\n"; else myList.display();
        }
        pauseForUser();
    }
}

// ===================== STACK OPERATIONS ========================
void STLManager::stackOperations() {
    while (true) {
        printLine('=');
        printCenter("STACK OPERATIONS  (size: " + to_string(myStack.size()) + ")");
        printLine('=');
        cout << "  1. Push\n";
        cout << "  2. Pop\n";
        cout << "  3. Peek (Top)\n";
        cout << "  4. Display all (top -> bottom)\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 4);

        if (choice == 0) return;

        if (choice == 1) {
            long long v = readIntValidated("  Value to push: ", -1000000, 1000000);
            myStack.push((int)v);
            cout << "  Pushed " << v << ".\n";
        }
        else if (choice == 2) {
            int v;
            cout << (myStack.pop(v) ? "  Popped: " + to_string(v) + "\n" : "  Stack is empty.\n");
        }
        else if (choice == 3) {
            int v;
            cout << (myStack.peek(v) ? "  Top: " + to_string(v) + "\n" : "  Stack is empty.\n");
        }
        else if (choice == 4) {
            if (myStack.empty()) cout << "  Stack is empty.\n"; else myStack.display();
        }
        pauseForUser();
    }
}

// ===================== QUEUE OPERATIONS ========================
void STLManager::queueOperations() {
    while (true) {
        printLine('=');
        printCenter("QUEUE OPERATIONS  (size: " + to_string(myQueue.size()) + ")");
        printLine('=');
        cout << "  1. Enqueue\n";
        cout << "  2. Dequeue\n";
        cout << "  3. Front\n";
        cout << "  4. Display all (front -> back)\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 4);

        if (choice == 0) return;

        if (choice == 1) {
            long long v = readIntValidated("  Value to enqueue: ", -1000000, 1000000);
            myQueue.enqueue((int)v);
            cout << "  Enqueued " << v << ".\n";
        }
        else if (choice == 2) {
            int v;
            cout << (myQueue.dequeue(v) ? "  Dequeued: " + to_string(v) + "\n" : "  Queue is empty.\n");
        }
        else if (choice == 3) {
            int v;
            cout << (myQueue.front(v) ? "  Front: " + to_string(v) + "\n" : "  Queue is empty.\n");
        }
        else if (choice == 4) {
            if (myQueue.empty()) cout << "  Queue is empty.\n"; else myQueue.display();
        }
        pauseForUser();
    }
}

// ===================== MAP OPERATIONS ========================
void STLManager::mapOperations() {
    while (true) {
        printLine('=');
        printCenter("MAP OPERATIONS  (size: " + to_string(myMap.size()) + ")");
        printLine('=');
        cout << "  1. Insert / Update key-value pair\n";
        cout << "  2. Delete by key\n";
        cout << "  3. Search by key\n";
        cout << "  4. Display all (sorted by key)\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 4);

        if (choice == 0) return;

        if (choice == 1) {
            string key = readNonEmptyLine("  Key: ");
            long long v = readIntValidated("  Value: ", -1000000, 1000000);
            int existing;
            bool existed = myMap.get(key, existing);
            myMap.set(key, (int)v);
            cout << "  " << (existed ? "Updated" : "Inserted") << " \"" << key << "\" -> " << v << ".\n";
        }
        else if (choice == 2) {
            string key = readNonEmptyLine("  Key to delete: ");
            cout << (myMap.remove(key) ? "  Deleted \"" + key + "\".\n" : "  Key \"" + key + "\" not found.\n");
        }
        else if (choice == 3) {
            string key = readNonEmptyLine("  Key to search: ");
            int v;
            cout << (myMap.get(key, v) ? "  \"" + key + "\" -> " + to_string(v) + "\n"
                : "  Key \"" + key + "\" not found.\n");
        }
        else if (choice == 4) {
            if (myMap.empty()) cout << "  Map is empty.\n"; else myMap.displaySorted();
        }
        pauseForUser();
    }
}

// ===================== SET OPERATIONS ========================
void STLManager::setOperations() {
    while (true) {
        printLine('=');
        printCenter("SET OPERATIONS  (size: " + to_string(mySet.size()) + ")");
        printLine('=');
        cout << "  1. Insert element\n";
        cout << "  2. Delete element\n";
        cout << "  3. Search element\n";
        cout << "  4. Display all (sorted, unique)\n";
        cout << "  0. Back to Main Menu\n";
        long long choice = readIntValidated("  Choice: ", 0, 4);

        if (choice == 0) return;

        if (choice == 1) {
            long long v = readIntValidated("  Value to insert: ", -1000000, 1000000);
            cout << (mySet.insert((int)v) ? "  Inserted " + to_string(v) + ".\n"
                : "  " + to_string(v) + " already exists in the set (duplicates ignored).\n");
        }
        else if (choice == 2) {
            long long v = readIntValidated("  Value to delete: ", -1000000, 1000000);
            cout << (mySet.remove((int)v) ? "  Deleted " + to_string(v) + ".\n" : "  " + to_string(v) + " not found.\n");
        }
        else if (choice == 3) {
            long long v = readIntValidated("  Value to search: ", -1000000, 1000000);
            cout << (mySet.contains((int)v) ? "  " + to_string(v) + " IS in the set.\n"
                : "  " + to_string(v) + " is NOT in the set.\n");
        }
        else if (choice == 4) {
            if (mySet.empty()) cout << "  Set is empty.\n"; else mySet.displaySorted();
        }
        pauseForUser();
    }
}

// ===================== UPGRADE: SORTING ========================
void STLManager::sortVector() {
    printLine('=');
    printCenter("SORT VECTOR");
    printLine('=');

    if (myVector.empty()) { cout << "  Vector is empty - nothing to sort.\n"; printLine('='); return; }

    cout << "  Before:"; myVector.display();
    long long choice = readIntValidated("  1. Ascending  2. Descending\n  Choice: ", 1, 2);
    mySort(myVector.begin(), myVector.end(), choice == 1);
    cout << "  After: "; myVector.display();
    printLine('=');
}

// ===================== UPGRADE: SEARCHING ========================
void STLManager::searchVector() {
    printLine('=');
    printCenter("SEARCH VECTOR");
    printLine('=');

    if (myVector.empty()) { cout << "  Vector is empty - nothing to search.\n"; printLine('='); return; }

    long long v = readIntValidated("  Value to search for: ", -1000000, 1000000);

    int* found = myFind(myVector.begin(), myVector.end(), (int)v);
    if (found != myVector.end())
        cout << "  Linear search:  found at index " << (found - myVector.begin()) << ".\n";
    else
        cout << "  Linear search:  not found.\n";

    // Binary search needs sorted data - copy into a temp buffer so the
    // user's own vector order is left untouched.
    int n = myVector.size();
    int* copyBuf = new int[n];
    for (int i = 0; i < n; ++i) copyBuf[i] = myVector.get(i);
    mySort(copyBuf, copyBuf + n, true);
    bool present = myBinarySearch(copyBuf, copyBuf + n, (int)v);
    delete[] copyBuf;

    cout << "  Binary search:  " << (present ? "found" : "not found")
        << " (on a sorted copy of the vector).\n";
    printLine('=');
}

// ===================== UPGRADE: FREQUENCY COUNTER ========================
void STLManager::frequencyCounter() {
    printLine('=');
    printCenter("FREQUENCY COUNTER");
    printLine('=');

    if (myVector.empty()) { cout << "  Vector is empty - nothing to count.\n"; printLine('='); return; }

    // A small local key(int)-value(count) table, built the same way MyMap
    // is, just specialised to int keys for this one-off tally.
    int n = myVector.size();
    int* values = new int[n];
    int* counts = new int[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; ++i) {
        int v = myVector.get(i);
        int idx = -1;
        for (int j = 0; j < uniqueCount; ++j) if (values[j] == v) { idx = j; break; }
        if (idx == -1) { values[uniqueCount] = v; counts[uniqueCount] = 1; ++uniqueCount; }
        else counts[idx]++;
    }

    // Selection sort the tally by value for a clean, ordered display.
    for (int i = 0; i < uniqueCount - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < uniqueCount; ++j) if (values[j] < values[minIdx]) minIdx = j;
        int tv = values[i]; values[i] = values[minIdx]; values[minIdx] = tv;
        int tc = counts[i]; counts[i] = counts[minIdx]; counts[minIdx] = tc;
    }

    cout << "  Value      Frequency\n";
    cout << "  ---------------------\n";
    for (int i = 0; i < uniqueCount; ++i)
        cout << "  " << values[i] << "\t\t" << counts[i] << "\n";

    delete[] values;
    delete[] counts;
    printLine('=');
}