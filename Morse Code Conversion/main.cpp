#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	bool programOn = true;
	do {
		static int MORSESIZE = 40;
		static char LETTERMATCH[40] = { ' ',',','.',' ? ','0','1','2','3','4','5',
										'6','7','8','9','A','B','C','D','E', 'F',
										'G','H','I','J','K','L','M','N','O','P',
										'Q','R','S','T','U','V','W','X','Y','Z'};
		static string MORSECODE[40] = { " ","--..--",".-.-.-","..--..","-----",".----","..-- - ","...--",".... - ",".....",
										"-.....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.",
										"--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
										"--.-",".-.","...","-","..","...-",".--","-..-","-.--","--.." };




		string message = "";
		int count = 0;

		cout << "Please enter message to be converted into Morse Code,\n";
		cout << "no more than 255 characters in length.\n\n";
		cout << "ENTER message : ";
		getline(cin, message);

		int messageLength = message.length();
		int foundNum;
		char currentChar;
		string morseTranslation;
		string morseString;

		for (int i = 0; i < messageLength; i++) {
			currentChar = toupper(message[i]);
			int j = 0;
			while (j < MORSESIZE && currentChar != LETTERMATCH[j]) {
				j++;
			}
			morseTranslation = MORSECODE[j];
			morseString = morseString + " " + morseTranslation;
		}
		int MORSESTRINGSIZE = morseString.length();

		int currentLetter = 0;
		int letterCount = 0;
		for (int i = 0; i < MORSESTRINGSIZE; i++) {
			currentChar = toupper(message[currentLetter]);
			if (morseString[i] != ' ') {
				letterCount++;
			}
			else if (morseString[i] == ' ') {
				cout << setw(letterCount / 2) << currentChar << setw(letterCount / 2);
				letterCount = 0;
				currentLetter++;
			}
			if (currentLetter == messageLength) {
				break;
			}
		}

		cout << endl << morseString;


		char playAgain = 'B';
		while (playAgain != 'y' && playAgain != 'n') { // while loop ask if players want to play again
			cout << "\nWould you like to run the program again? (y/n) ";
			cin >> playAgain;
			playAgain = tolower(playAgain);
			if (playAgain != 'y' && playAgain != 'n') {
				cout << "Invalid Response!\n";
			}
		}
		if (playAgain == 'n') {
			programOn = false;
		}

		system("cls");
	} while (programOn == true);

	return 0;
}
