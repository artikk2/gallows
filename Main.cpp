#include <iostream>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;

using std::string;

using std::vector;


const vector<string> words{ "car", "football", "administrator" };

int errors = 1;


string getWord();

string word = getWord();
std::vector<char> guessedWord(word.size(), '_');


void getCondition();

void getAnswer();


int main()
{
	cout << "Word: ";
	getCondition();

	while (errors < 10 && string(guessedWord.begin(), guessedWord.end()) != word) {
		getAnswer();
		getCondition();

		if (errors == 10)
		{
			cout << "you've lost!\n";
			exit(0);
		}
		if (string(guessedWord.begin(), guessedWord.end()) == word)
		{
			cout << "You win!\n";
			exit(0);
		}
	}
}


string getWord()
{
	srand(time(0));

	return words[rand() % 3];
}



void getCondition()
{
	for (char c : guessedWord)
	{
		cout << c << ' ';
	}
	cout << '\n';
}


void getAnswer()
{
	char symbol;
	cin >> symbol;

	bool found = false;

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == symbol)
		{
			system("cls");
			cout << "You guessed the letter, it's a letter \"" << symbol << "\"\n\n";

			found = true;

			guessedWord[i] = symbol;
		}
	}
	if (!found)
	{
		system("cls");
		cout << "You didn't guess! Do you have any attempts left " << 9 - errors << "\n\n";

		errors++;
	}

}