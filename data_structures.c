#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define the structure of the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a function that initializes a linked list
Node* createLinkedList() {
    return NULL;
}

// Create a function that inserts a new node into the linked list
void insertNode(Node** head, int value) {
    // Create a new node and set its data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    }
    // Otherwise, insert the new node at the beginning of the list
    else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Create a function that removes a node from the linked list
void deleteNode(Node** head, int value) {
    Node* currentNode = *head;
    Node* previousNode = NULL;

    // Traverse the list to find the node with the specified value
    while (currentNode != NULL && currentNode->data != value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // If the value was not found, return
    if (currentNode == NULL) {
        return;
    }

    // If the node to be deleted is the head, update the head pointer
    if (previousNode == NULL) {
        *head = currentNode->next;
    }
    // Otherwise, update the pointers of the previous and next nodes
    else {
        previousNode->next = currentNode->next;
    }

    // Free the memory occupied by the deleted node
    free(currentNode);
}

// Create a function that traverses the linked list and prints out the data stored in each node
void printList(Node* head) {
    Node* currentNode = head;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

// Create a function that searches the linked list for a particular value and returns the node that contains that value
Node* searchList(Node* head, int value) {
    Node* currentNode = head;

    while (currentNode != NULL) {
        if (currentNode->data == value) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}

// Create a function that calculates the length of the linked list
int listLength(Node* head) {
    int count = 0;
    Node* currentNode = head;

    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

// Create a function that reverses the order of the nodes in the linked list
void reverseList(Node** head) {
    Node* previousNode = NULL;
    Node* currentNode = *head;
    Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    *head = previousNode;
}
// Define the structure of the stack
typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

// Create a function that initializes a stack with the specified capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Create a function that checks if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Create a function that checks if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Create a function that pushes an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Error: stack overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

// Create a function that pops an element from the stack and returns its value
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: stack underflow\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

// Create a function that returns the value at the top of the stack without removing it
int peekStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: stack underflow\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Create a function that prints out the contents of the stack
void printStack(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}





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
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Create a function that checks if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Create a function that adds an element to the back of the queue
void enqueue(Queue* queue, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Create a function that removes an element from the front of the queue and returns its value
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: queue underflow\n");
        return -1;
    }
    QueueNode* temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    free(temp);
    queue->size--;
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    return value;
}

// Create a function that returns the value at the front of the queue without removing
int peekQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: queue underflow\n");
        return -1;
    }
    return queue->front->data;
}

// Create a function that prints out the contents of the queue
void printQueue(Queue* queue) {
  if (queue == NULL || queue->front == NULL) {
    printf("Queue is empty\n");
    return;
  }

  QueueNode* current = queue->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}


// Define the structure of a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a function that creates a new binary tree node with the given data and left/right child nodes
TreeNode* createTreeNode(int data, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

// Create a function that inserts a new node into the binary tree
void insert(TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createTreeNode(data, NULL, NULL);
        return;
    }
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Create a function that searches for a value in the binary tree
TreeNode* search(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Create a function that traverses the binary tree in order and prints the node values
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Create a function that traverses the binary tree in preorder and prints the node values
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Create a function that traverses the binary tree in postorder and prints the node values
void postOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Create a function that finds the height of the binary tree
int height(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
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
HashEntry* createEntry(char* key, int value) {
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(entry->key, key);
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Create a function that creates a new hash table with the given size
HashTable* createTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->table = (HashEntry**)calloc(size, sizeof(HashEntry*));
    return table;
}

// Create a function that calculates the hash code for the given key
int hash(char* key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = hash + (int)key[i];
    }
    return hash % size;
}

// Create a function that inserts a new key-value pair into the hash table
void insert(HashTable* table, char* key, int value) {
    int index = hash(key, table->size);
    HashEntry* entry = table->table[index];
    while (entry != NULL && strcmp(entry->key, key) != 0) {
        entry = entry->next;
    }
    if (entry == NULL) {
        entry = createEntry(key, value);
        entry->next = table->table[index];
        table->table[index] = entry;
    } else {
        entry->value = value;
    }
}

// Create a function that retrieves the value associated with the given key from the hash table
int get(HashTable* table, char* key) {
    int index = hash(key, table->size);
    HashEntry* entry = table->table[index];
    while (entry != NULL && strcmp(entry->key, key) != 0) {
        entry = entry->next;
    }
    if (entry == NULL) {
        return -1;
    } else {
        return entry->value;
    }
}

// Create a function that removes the entry with the given key from the hash table
void removeEntry(HashTable* table, char* key) {
    int index = hash(key, table->size);
    HashEntry* prevEntry = NULL;
    HashEntry* entry = table->table[index];
    while (entry != NULL && strcmp(entry->key, key) != 0) {
        prevEntry = entry;
        entry = entry->next;
    }
    if (entry == NULL) {
        return;
    }
    if (prevEntry == NULL) {
        table->table[index] = entry->next;
    } else {
        prevEntry->next = entry->next;
    }
    free(entry->key);
    free(entry);
}
// Create a function that prints the contents of the hash table
void printTable(HashTable* table) {
for (int i = 0; i < table->size; i++) {
HashEntry* entry = table->table[i];
printf("Bucket %d: ", i);
while (entry != NULL) {
printf("(%s, %d) ", entry->key, entry->value);
entry = entry->next;
}
printf("\n");
}
}

