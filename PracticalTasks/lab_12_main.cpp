#include <iostream>
using namespace std;
#define n 256

void reverse(char* phrase)
{
	char new_phrase[n];
	char* letter1st = new_phrase;
	for (char* letter = phrase; *letter != '\0'; letter++)
		if (letter[1] == ' ' || letter[1] == '\0')
		{
			for (char* word = letter; word >= phrase && *word != ' '; word--, letter1st++)
				*letter1st = *word;
			*(letter1st++) = ' ';
			letter++;
		}
	*letter1st = '\0';
	cout << new_phrase << endl;
}
/*______________________________*/
int main()
{
	char phrase[n];
	cout << "Input text: ";
	cin.getline(phrase, n);
	reverse(phrase);
}