#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool reRun();

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
		cin.ignore();
		getline(cin, message, '\n');
		
		int messageLength = message.length();
		int foundNum;
		char currentChar;
		string morseTranslation;
		string morseString;

		cout << " ";
		for (int i = 0; i < messageLength; i++) {
			currentChar = toupper(message[i]);
			int j = 0;
			while (j < MORSESIZE && currentChar != LETTERMATCH[j]) {
				j++;
			}

			morseTranslation = MORSECODE[j];
			int letterCount = morseTranslation.length() + 1;
			cout << currentChar << setw(letterCount);
			morseString = morseString + " " + morseTranslation;
		}
		int MORSESTRINGSIZE = morseString.length();
		cout << endl << morseString;

		programOn = reRun();
	} while (programOn == true);

	return 0;
}

bool reRun()
{
	bool result; 	// true to end program, false to run again
	char runAgain;	// prompt for re-running program

	// prompt to run program again
	cout << "\n\nWould you like to run program again (Y/N) ? ";
	cin >> runAgain;

	// validate input for Y, y, N, or n
	while (toupper(runAgain) != 'Y' && toupper(runAgain) != 'N')
	{
		cout << "\n **  Invalid entry  **  Please enter 'Y' or 'N'\n\n";
		cout << "Would you like to run program again (Y/N) ? ";
		cin.ignore();  // clear keybard cache
		cin >> runAgain;
	}

	if (toupper(runAgain) == 'Y')
	{
		result = true;
		system("CLS");
	}
	else
		result = false;

	return result;
}