// compsci2250Project2.cpp

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

struct Word 
{
	string english;
	string piglatin;
};

//prototypes
Word* splitSentence(const string words, int& size);
void convertToPigLatin(Word wordArray[], int size);
void displayPigLatin(const Word wordArr[], int size);

int main()
{
	int size = 1;
	Word words;
	Word *wordsArray = nullptr;
	wordsArray = new Word[size];

	cout << "Enter Sentence to convert to PigLatin. \n";
	getline(cin, words.english);

	wordsArray = splitSentence(words.english, size);//Split
	convertToPigLatin(wordsArray,size);//Convert to pig latin
	displayPigLatin(wordsArray, size);//Display Sentence
}

Word *splitSentence(const string words, int &size)
{
	size = words.length();
	int wordsCount = 0;
	int lastChar = 1;
	for(int x = 0;x < size;x++)//get how many words are in sentence
	{
		if(!isalpha(words[x]))
		{
			if (!lastChar)
			{
				wordsCount++;
				lastChar = 1;
			}
		}
		else
		{
			if (words[x] != '\n')
			{	
				lastChar = 0;
			}
		}
	}
	if(!lastChar) ++wordsCount;

	Word *wordsArray = nullptr;
	wordsArray = new Word[wordsCount];//dynamic word array struct

	string temp;
	int charNum = 0, startStr = 0,index = 0;
	bool isLastSpace = true;
	for(int x = 0; x <= size; x++)//allocate each word into each element into the Word struct array
	{
		if(!isalpha(words[x]))//letter check
		{
			if (isLastSpace == false)//was the last char a space
			{
				startStr = x - charNum;
				temp = (words.substr(startStr,charNum));//get the substring to allocate
				for (int x = 0; x < charNum; x++)//convert to lower case
				{
					temp[x] = tolower(temp[x]);
				}
				wordsArray[index].english = temp;//allocate into element
				charNum = 0;
				index++;
				isLastSpace = true;
			}
			
		}
		else
		{
			if (words[x] != '\n')
			{
				charNum++;
				isLastSpace = false;
			}
				
		}	
	}
	size = wordsCount;
	return wordsArray;
}
void convertToPigLatin(Word wordArray[], int size)
{
	int sizeOf = size;
	string temp;
	char frontChar;
	bool isVowel;
	for (int index = 0; index < sizeOf; index++)
	{
		temp = wordArray[index].english;

		if (temp.front() == 'a' || temp.front()== 'e' || temp.front()=='i'
			|| temp.front()== 'o' || temp.front()== 'u')
		{
			temp += "way";
		}
		else
		{
			frontChar = temp.front();
			temp.erase(0, 1);
			temp = temp + frontChar + "ay";
		}
		wordArray[index].piglatin = temp;
	}
}
void displayPigLatin(const Word wordArr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << wordArr[index].piglatin << " ";
	}
}