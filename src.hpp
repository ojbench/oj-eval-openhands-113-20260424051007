

#include <iostream>
#include <cstdio>

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int length;

public:
    // Default constructor - construct an empty linked list
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}
    
    // Copy constructor - construct a linked list identical to the given one
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), length(0) {
        Node* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }
    
    // Destructor - ensure no memory leaks
    virtual ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        length = 0;
    }
    
    // Insert an element at the front of the list
    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    
    // Insert an element at the back of the list
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }
    
    // Remove an element from the front of the list
    T popFront() {
        if (head == nullptr) {
            return T(); // Return default-constructed value if empty
        }
        
        T value = head->data;
        Node* temp = head;
        
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        length--;
        return value;
    }
    
    // Remove an element from the back of the list
    T popBack() {
        if (tail == nullptr) {
            return T(); // Return default-constructed value if empty
        }
        
        T value = tail->data;
        Node* temp = tail;
        
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        length--;
        return value;
    }
    
    // Return the size of the linked list
    int size() const {
        return length;
    }
    
    // Output the linked list with elements separated by spaces, ending with a newline
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Virtual functions (guaranteed not to be called on LinkedList instances)
    virtual const char* name() const {
        return "";
    }
    
    virtual T peak() const {
        return T();
    }
    
    virtual T pop() {
        return T();
    }
    
    virtual void push(const T& val) {
    }
};

// Stack class derived from LinkedList
template <typename T>
class Stack : public LinkedList<T> {
public:
    // Return "Stack"
    const char* name() const override {
        return "Stack";
    }
    
    // Return the top element's value
    T peak() const override {
        return this->tail->data; // Top element is at the tail
    }
    
    // Pop the top element
    T pop() override {
        return this->popBack(); // Remove from the back (top)
    }
    
    // Push an element onto the stack
    void push(const T& val) override {
        this->pushBack(val); // Add to the back (top)
    }
};

// Queue class derived from LinkedList
template <typename T>
class Queue : public LinkedList<T> {
public:
    // Return "Queue"
    const char* name() const override {
        return "Queue";
    }
    
    // Return the front element's value
    T peak() const override {
        return this->head->data; // Front element is at the head
    }
    
    // Remove an element from the front
    T pop() override {
        return this->popFront(); // Remove from the front
    }
    
    // Add an element to the back
    void push(const T& val) override {
        this->pushBack(val); // Add to the back
    }
};

