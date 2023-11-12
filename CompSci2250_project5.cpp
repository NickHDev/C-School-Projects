
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SearchTree //class
{
private:
	struct TreeNode
	{
		string str = "";
		int count = 0;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;
	};

	TreeNode* root;

	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void displayInOrder(TreeNode*) const;
	
public:
	SearchTree()
	{
		root = nullptr;
	}
	~SearchTree()
	{
		destroySubTree(root);
	}
	void insertNode(string);
	void addLetter(TreeNode*);
	bool searchNode(string);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
};

void SearchTree::insertNode(string charNew) //create node to insert
{
	TreeNode* newNode = nullptr;
	newNode = new TreeNode;
	newNode->str = charNew;
	newNode->left = newNode->right = nullptr;
	newNode->count = 1;
	insert(root, newNode);
}

void SearchTree::insert(TreeNode*& nodePtr, TreeNode*& newNode) //insert node in tree
{
	if (nodePtr == nullptr)
		nodePtr = newNode;
	else if (newNode->str < nodePtr->str)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
	if (newNode->str == nodePtr->str)
	{
		addLetter(nodePtr);
	}
	
}
void SearchTree::addLetter(TreeNode* nodePtr) //add counter to number of letters
{
	nodePtr->count++;
}

void SearchTree::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout  << nodePtr->str << ": " << nodePtr->count << endl;
		displayInOrder(nodePtr->right);
	}
}

bool SearchTree::searchNode(string charToSearch) 
{
	TreeNode *nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->str == charToSearch)
			return true;
		else if (charToSearch < nodePtr->str)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

void SearchTree::destroySubTree(TreeNode* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

int main()
{	
	string data;//creating string and class objects
	fstream dataFile;
	SearchTree tree;

	int length;
	int count = 1;
	cout << "Input maximum string length to search for: ";
	cin >> length;
	while (length < 1) {   //checking input
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a positive integer.";
		cin >> length;
	}

	dataFile.open("datastream.txt", ios::in); //getting file
	getline(dataFile, data, '.');
	cout << data;

	for (int x = 0; x < data.length(); x++) // parseing characters in file
	{
		if (!isalpha(data[x]))
			data.erase(x);
		if (isupper(data[x]))
			data[x] = tolower(data[x]);
		tree.insertNode(data.substr(x,length));
	}

	tree.displayInOrder(); //display characters 
	
}

