#include <iostream>
#include <cassert>
#include <cmath>

/**********************************************
Declared node blueprint
**********************************************/
struct Node {
    int value;
    Node* prev;
    Node* next;
    
    // Constructor
    Node(int num) : value(num), prev(nullptr), next(nullptr) {}
};

class LLInteger {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    LLInteger() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor
    ~LLInteger() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // Get head and tail
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
    int getSize() const { return size; }
    
    /**********************************************
    appends item to list head
    **********************************************/
    void appendNodeToHead(int value) {
        Node* newNode = new Node(value);
        
        newNode->next = head;
        if (head) // if list was not empty
            head->prev = newNode;
            
        head = newNode; // update head
        
        if (!tail) // Appending first node to empty list
            tail = head; // update tail to point to head since only one node
            
        size++;
    }
    
    /**********************************************
    appends item to list tail
    **********************************************/
    void appendNodeToTail(int value) {
        if (!head) { // Appending first node to empty list
            appendNodeToHead(value);
            return;
        }
        
        Node* newNode = new Node(value);
        
        tail->next = newNode;
        newNode->prev = tail;
        
        tail = newNode;  // set the new node as the last node
        size++;
    }
    
    /**********************************************
    Display List contents
    **********************************************/
    void display() const {
        if (!head) {
            std::cout << "Integer list is empty! First create a new integer" << std::endl;
            return;
        }
        
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value;
        }
        std::cout << std::endl;
    }
};

/**********************************************
Creates a linked list integer from user input
**********************************************/
LLInteger* createLLInteger() {
    LLInteger* list = new LLInteger();
    
    std::cout << "Enter positive integer to be added: ";
    int number;
    if (!(std::cin >> number) || number < 0) {
        std::cerr << "Invalid input. Must be a positive integer." << std::endl;
        delete list;
        exit(1);
    }
    
    // Handle the case of zero
    if (number == 0) {
        list->appendNodeToHead(0);
        return list;
    }
    
    while (number) {
        int digit = number % 10;
        number = number / 10;
        
        list->appendNodeToHead(digit);
    }
    std::cout << std::endl;
    
    return list;
}

/**********************************************
Add two linkedlists integers and return sum
**********************************************/
LLInteger* addTwoLLIntegers(LLInteger* num1, LLInteger* num2) {
    LLInteger* sum = new LLInteger();
    
    Node* l1 = num1 ? num1->getTail() : nullptr;
    Node* l2 = num2 ? num2->getTail() : nullptr;
    
    int carry = 0;
    
    while (l1 || l2) {
        int digitSum = carry;
        
        if (l1) {
            digitSum += l1->value;
            l1 = l1->prev;
        }
        
        if (l2) {
            digitSum += l2->value;
            l2 = l2->prev;
        }
        
        carry = digitSum / 10;
        sum->appendNodeToHead(digitSum % 10);
    }
    
    if (carry) // Don't forget about last carry
        sum->appendNodeToHead(carry);
        
    return sum;
}

/**********************************************
Main Entry
**********************************************/
int main() {
    std::cout << "\nProgram to add two linkedlist based integers" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    LLInteger* num1 = createLLInteger();
    LLInteger* num2 = createLLInteger();
    
    LLInteger* sum = addTwoLLIntegers(num1, num2);
    
    std::cout << "The sum is: ";
    sum->display();
    
    // Cleanup (no need to call destroyLLInteger as destructors handle this)
    delete num1;
    delete num2;
    delete sum;
    
    return 0;
}