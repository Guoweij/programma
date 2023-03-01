#include <iostream>
using namespace std;
#include "SpeechManager.h"

int main() {
	SpeechManager sm;

	int choice = 0;

	while (true)
	{
		sm.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showScore();
			break;
		case 3:
			
			break;
		case 0: 
			sm.ExitSystem();
			break;
			

		default:
			break;
		}
	}
}