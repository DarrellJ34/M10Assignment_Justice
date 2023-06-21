// Make a binary tree for employees
// Allow user to enter in an ID to see if it matches the tree

#include <iostream>
using namespace std;

struct Node {
public:
    int idNumber;
    string employeeName;
    Node *left;
    Node *right;

    Node(int idNumber, string employeeName) { // Constructor for an employee
        this->idNumber = idNumber;
        this->employeeName = employeeName;
    }

    Node *makeNode(int idNumber, string employeeName) { //Makes new node
        Node *newNode = new Node(idNumber, employeeName);
        newNode->idNumber = idNumber;
        newNode->left = newNode->right = nullptr;
        return newNode;
    };
};

void testTree(Node* root){

    if(root == nullptr) return; // Recursion to traverse the tree

    int userID; // User enters ID
    cout << "Enter an ID number: ";
    cin >> userID;

    if(userID == root->idNumber){ // Tests to see if id is correct
        cout << "Correct" << endl;
        return; // Ends if id is correct
    }else{
        cout << "Incorrect" << endl; // Uses recursion to run again if incorrect, until whole tree is traversed
        cout << root->idNumber << endl;
        testTree(root->left);
        testTree(root->right);
    }
}

int main() {

    Node employee1(1017, "Debbie Reese"); // Creating instances of the employee class
    Node employee2(1021, "John Williams");
    Node employee3(1057, "Bill Witherspoon");
    Node employee4(1275, "George McMullen");
    Node employee5(1899, "Ashley Smith");
    Node employee6(2487, "Jennifer Twain");
    Node employee7(3769, "Sophia Lancaster");
    Node employee8(4218, "Josh Plemmons");


    // Making root
    Node* root = employee1.makeNode(1017, "Debbie Reese");
    // Making children of root
    root->left= employee2.makeNode(1021, "John Williams");
    root->right=employee3.makeNode(1057, "Bill Witherspoon");
    // Making children of employee 2, employees 4 and 5
    root->left->left=employee4.makeNode(1275, "George McMullen");
    root->left->right = employee5.makeNode(1899, "Ashley Smith");
    // Making children of employee 2, employees 6 and 7
    root->right->left=employee6.makeNode(2487, "Jennifer Twain");
    root->right->right= employee7.makeNode(3769, "Sophia Lancaster");
    // Making final leaf of the tree, will do employee 8 as a child of employee 7
    root->right->right->left = employee8.makeNode(4218, "Josh Plemmons");

    testTree(root);
    return 0;
}
