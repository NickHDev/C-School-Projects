#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class DelimiterStack
{
private:
	struct DelimNode
	{
		char character;
		int lineNumber;
		int charCount;
		DelimNode* next;
	};
	DelimNode* top;
public:
	//Constructor
	DelimiterStack()
	{top = nullptr;}

	//Destructor
	~DelimiterStack();

	//Stack Operations
	void push(char, int, int);
	void pop(char&, int&, int&); // reference variables because three variables cannot be returned through return statement
	bool isEmpty();
};

int main()
{
	// variable declarations and initializations
	char getChar, currentChar;
	int lineNum = 0, getLineNum, count,getCharCount;
	DelimiterStack stack;
	string currentLine = "";

	do 
	{
		// parse the input line ignore non delimiters
		getline(cin,currentLine);
		count = 0;
		lineNum++;

		for (int x = 0; x < currentLine.length(); x++)
		{
			currentChar = currentLine[x];
			if (currentChar == '{' || currentChar == '[' || currentChar == '(')
			{
				stack.push(currentChar, lineNum, x);
				count++;
			}
			if (currentChar == '}' || currentChar == ']' || currentChar == ')')
			{
				stack.pop(getChar, getLineNum, getCharCount);
				count--;
				if (count != -1)
				{
					if (currentLine[x] == '}' && getChar == '{')
					{
						break;
					}
					else if (currentLine[x] == ']' && getChar == '[')
					{
						break;
					}
					else if (currentLine[x] == ')' && getChar == '(')
					{
						break;
					}
					else
					{
						cout << "Mismatched delimiter: " << currentChar << " found at line " << lineNum << ", "
							<< "char " << x + 1 << " does not match " << getChar << " found at line "
							<< getLineNum << ", char " << getCharCount + 1 << endl;
					}
				}
				else if (count = -1)
				{
					cout << "Right delimiter " << currentLine[x] << " at line " << lineNum << ", char " << x + 1 << " has no found left delimiter.\n";
				}
			}

		}
	}
	while (currentLine != "DONE");

	bool finalCheck = stack.isEmpty();
	if (finalCheck)
	{
		cout << "STACK EMPTY";
	}
	while (!finalCheck)
	{
		stack.pop(getChar, getLineNum, getCharCount);
		cout << "Left Delimiter " << getChar << " at line " << getLineNum << ", char " << getCharCount + 1
			<< " has no right delimiter";
		finalCheck = stack.isEmpty();
	}
}

//Destructor
DelimiterStack::~DelimiterStack()
{
	DelimNode* nodePtr, * nextNode;
	nodePtr = top;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
void DelimiterStack::push(char characterIn, int lineNum, int count)
{
	DelimNode* newNode = nullptr;
	
	newNode = new DelimNode;
	newNode->character = characterIn;
	newNode->lineNumber = lineNum;
	newNode->charCount = count;

	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}
void DelimiterStack::pop(char &characterIn, int &lineNum, int &count)
{
	DelimNode* temp = nullptr;

	if (isEmpty())
	{
		cout << "Empty Stack. \n";
	}
	else
	{
		characterIn = top->character;
		lineNum = top->lineNumber;
		count = top->charCount;
		temp = top->next;
		delete top;
		top = temp;
	}
}
bool DelimiterStack::isEmpty()
{
	bool status;
	if (!top)
	{status = true;}
	else
	{status = false;}
	return status;
}