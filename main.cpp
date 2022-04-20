#include <iostream>
#include "bst.h"
#include <cstring>
#include <fstream>

#if 0
Justin Iness
4/20/2022
C++ Programming
Binary Search Tree
#endif

using namespace std;

void add(int num, node* &r) { // add numbers
	if (r == NULL) {
		r = new node(num);
	}
	else if (num < r->data) {
		add(num, r->left);
	}
	else if (num > r->data) {
		add(num, r->right);
	}	
	return;
}
void print(node* r, int level) { // print tree visually
	// emptee tree
	if (r == NULL) {
		return;
	}

	// increase spaces
	level += 1;

	// right 
	print(r->right, level);

	// current data and space
	for (int i = 1; i < level; i++) {
		cout << "   ";
	}
	cout << r->data << endl;

	// left
	print(r->left, level);
}
bool search(int num, node* r) { // search
	if (r == NULL) {
		cout << num << " not in tree." << endl;
		return false;
	}
	else if (r->data == num) {
		cout << num << " is in tree." << endl;
		return true;
	}
	else if (num < r->data) {
		if (search(num, r->left)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (num > r->data) {
		if (search(num, r->right)) {
			return true;
		}
		else {
			return false;
		}
	}	
}
void del(int num, node* &r) {	
	if (r == NULL) {
		cout << num << " not in tree." << endl;
	}
	else if (r->data == num) {
		cout << "Deleting " << num << endl;
		if (r->left == NULL || r->right == NULL) { // 1 long or 1 child lists
			if (r->left == NULL && r->right == NULL) { // 1 long list
				r = NULL; // del root
			}
			else { // one child lists
				if (r->left != NULL) { // left child
					r = r->left;
				}
				else if (r->right != NULL) { // right child
					r = r->right;
				}
			}
		}
		else { // list with 2 children
			 node* prevInList = r->left;
			 while (prevInList->right != NULL) {
				 prevInList = prevInList->right;
			 }
			 r->data = prevInList->data;
			 del(prevInList->data, r->left);
		}

	}
	else if (num < r->data) {
		del(num, r->left);
	}
	else if (num > r->data) {
		del(num, r->right);
	}	
}

int main() {
	node* root = NULL;
	//create new bst
	char input[5000];
	cout << "(FILE) or Command Line (INPUT)" << endl;
	cin.getline(input, 10);
	if (strcmp(input, "INPUT") == 0) { // input through command line
		cout << "Enter numbers separated by spaces. End your series of numbers with a \" -1\":" << endl;
		int number = 0;
		while (cin >> number) {
			if (number == (-1)) {
				break;
			}
			if (number != 0) {	
				add(number, root);
			}
		}
	}
	if (strcmp(input, "FILE") == 0) {
		fstream iFile;
		cout << "What is the file's name?" << endl;
		cin >> input;
		// open file and read numbers from it
		iFile.open(input, ios::in);
		if (!iFile) {
			cout << "Can't find " << input << ".  Try including .txt?" << endl;
			return 0;
		}
		else {
			cout << "opened file" << endl;
			int number = 0;
			while (iFile >> number) {
				if (number != 0) {
					add(number, root); //add number
				}
			}
		}	
	}
	while (true) {
		cout << "Enter a command (ADD), (SEARCH), (DELETE), (PRINT) or (QUIT): " << endl;
		cin >> input;
		if (strcmp(input, "ADD") == 0) { // Add students
			cout << "Enter a number to add: " << endl;
			int number = 0;
			cin >> number;
			if (number != 0) {
				add(number, root);
			}
		}
		else if (strcmp(input, "SEARCH") == 0) { // Search students
			cout << "Enter a number to search for: " << endl;
			int number = 0;
			cin >> number;
			if (number != 0) {
				search(number, root);
			}
			
		}
		else if (strcmp(input, "DELETE") == 0) { // Delete students
			cout << "Enter a number to delete: " << endl;
			int number = 0;
			cin >> number;
			if (number != 0) {
				del(number, root);
			}
		}
		else if (strcmp(input, "PRINT") == 0) { // Print students
			print(root, 0);
		}
		else if (strcmp(input, "QUIT") == 0) { // Quit program
			return 0;
		}
	}
}
