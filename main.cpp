#include <iostream>
#include "bst.h"
#include <cstring>
#include <fstream>

#if 0
Justin Iness
4/5/2022
C++ Programming
Heap
#endif

using namespace std;

void add(int num, node* &r) {
	if (r = NULL) {
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
void print(node* r, int level) {
	// emptee tree
	if (r == NULL) {
		return;
	}

	// Increase distance between levels
	level += 1;

	// Process right child first
	print(r->right, level);

	// Print current node after space
	cout << endl;
	for (int i = 1; i < level; i++) {
		cout<<" ";
	}
	cout << r->data << endl;

	// Process left child
	print(r->left, level);
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
				cout << number << endl;
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
					cout << number << endl;
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
			
		}
		else if (strcmp(input, "DELETE") == 0) { // Delete students

		}
		else if (strcmp(input, "PRINT") == 0) { // Print students
			print(root);
		}
		else if (strcmp(input, "QUIT") == 0) { // Quit program
			return 0;
		}
	}
}
