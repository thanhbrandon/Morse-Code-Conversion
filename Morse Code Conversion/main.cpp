#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool reRun(); // function prototype for reRun function

int main() {

	bool programOn = true;
	do {
		static int MORSESIZE = 40; // Value of number of characters
		static char LETTERMATCH[40] = { ' ',',','.',' ? ','0','1','2','3','4','5',
										'6','7','8','9','A','B','C','D','E', 'F',
										'G','H','I','J','K','L','M','N','O','P',
										'Q','R','S','T','U','V','W','X','Y','Z'}; // Array of chars that can be translated
		static string MORSECODE[40] = { " ","--..--",".-.-.-","..--..","-----",".----","..-- - ","...--",".... - ",".....",
										"-.....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.",
										"--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
										"--.-",".-.","...","-","..","...-",".--","-..-","-.--","--.." }; // Array of strings of the translated chars

		string message = ""; // Initializes message string

		cout << "Please enter message to be converted into Morse Code,\n";
		cout << "no more than 255 characters in length.\n\n";
		cout << "ENTER message : ";
		getline(cin, message, '\n'); // Gets message to translate from user
		
		int messageLength = message.length(); // Message length
		char currentChar; // Variable to hold current character
		string morseTranslation; // Variable to hold translation of current character
		string morseString; // Variable to hold translation of the message

		cout << " ";
		for (int i = 0; i < messageLength; i++) {
			currentChar = toupper(message[i]); // Makes the current char uppercase
			int j = 0;
			while (j < MORSESIZE && currentChar != LETTERMATCH[j]) { // While loop finds the match in the Lettermatch array
				j++;
			}

			morseTranslation = MORSECODE[j]; 
			int letterCount = morseTranslation.length() + 1; // Adds the number of spaces for the character output
			cout << currentChar << setw(letterCount); // Outputs Current char to match with the morse code
			morseString = morseString + " " + morseTranslation; // Adds to full translation
		}
		
		cout << endl << morseString; // Prints translated morse code

		programOn = reRun(); // Asks user if they want to run the program again
		cin.ignore();
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
		system("CLS"); // Clears console
	}
	else
		result = false;

	return result;
}