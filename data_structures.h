#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Define the structure of the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a function that initializes a linked list
Node* createLinkedList();

// Create a function that inserts a new node into the linked list
void insertNode(Node** head, int value);

// Create a function that removes a node from the linked list
void deleteNode(Node** head, int value);

// Create a function that traverses the linked list and prints out the data stored in each node
void printList(Node* head);

// Create a function that searches the linked list for a particular value and returns the node that contains that value
Node* searchList(Node* head, int value);

// Create a function that calculates the length of the linked list
int listLength(Node* head);

// Create a function that reverses the order of the nodes in the linked list
void reverseList(Node** head);

// Define the structure of the stack
typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

// Create a function that initializes a stack with the specified capacity
Stack* createStack(int capacity);

// Create a function that checks if the stack is empty
int isEmpty(Stack* stack);

// Create a function that checks if the stack is full
int isFull(Stack* stack);

// Create a function that pushes an element onto the stack
void push(Stack* stack, int value);

// Create a function that pops an element from the stack and returns its value
int pop(Stack* stack);

// Create a function that returns the value at the top of the stack without removing it
int peekStack(Stack* stack);

// Create a function that prints out the contents of the stack
void printStack(Stack* stack);


// Define the structure of a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define the structure of the queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Create a function that initializes an empty queue
Queue* createQueue();

// Create a function that checks if the queue is empty
int isQueueEmpty(Queue* queue);

// Create a function that adds an element to the rear of the queue
void enqueue(Queue* queue, int value);

// Create a function that removes an element from the front of the queue and returns its value
int dequeue(Queue* queue);

// Create a function that returns the value at the front of the queue without removing it
int peekQueue(Queue* queue);

// Create a function that prints out the contents of the queue
void printQueue(Queue* queue);

// Define the structure of a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a function that creates a new binary tree node with the given data and left/right child nodes
TreeNode* createTreeNode(int data, TreeNode* left, TreeNode* right);

// Create a function that inserts a new node into the binary tree
void insert(TreeNode** root, int data);

// Create a function that searches for a value in the binary tree
TreeNode* search(TreeNode* root, int data);

// Create a function that traverses the binary tree in order and prints the node values
void inOrder(TreeNode* root);

// Create a function that traverses the binary tree in preorder and prints the node values
void preOrder(TreeNode* root);

// Create a function that traverses the binary tree in postorder and prints the node values
void postOrder(TreeNode* root) ;

// Create a function that finds the height of the binary tree
int height(TreeNode* root);

// Define the structure of a hash table entry
typedef struct HashEntry {
    char* key;
    int value;
    struct HashEntry* next;
} HashEntry;

// Define the structure of a hash table
typedef struct HashTable {
    int size;
    HashEntry** table;
} HashTable;


// Create a function that creates a new hash table entry with the given key and value
HashEntry* createEntry(char* key, int value);


// Create a function that creates a new hash table with the given size
HashTable* createTable(int size);

// Create a function that calculates the hash code for the given key
int hash(char* key, int size);

// Create a function that inserts a new key-value pair into the hash table
void insert(HashTable* table, char* key, int value);

// Create a function that retrieves the value associated with the given key from the hash table
int get(HashTable* table, char* key);

// Create a function that removes the entry with the given key from the hash table
void removeEntry(HashTable* table, char* key);

// Create a function that prints the contents of the hash table
void printTable(HashTable* table);
#endif

