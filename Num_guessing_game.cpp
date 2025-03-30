#include <iostream>
#include <ctime>

void greeting() {

	std::cout << "Welocome to the Number Guessing Game!\nI'm thinking of a number between 1 and 100.\nThe number of attampts depends on the difficulty level\n\n";

}

int getDifficultyLevel() {

	int choice;
	std::cout << "Please select the difficulty level: \n1. Easy (10 chances)\n2. Medium (5 chances)\n3. Hard(3 chances)\n";
	std::cin >> choice;
	return choice;

}

void theGame(int chances) {

	int guessed_number{ rand() % 100 + 1 }, users_number{};

	for (int attempt = 0; attempt <= chances; ++attempt) {
		std::cout << "Please enter a number: ";
		std::cin >> users_number;

		if (users_number == guessed_number) {
			std::cout << "Congratulations! You guessed the correct number in " << attempt << " attempts!";
			return;
		}
		else if (users_number > guessed_number) {
			std::cout << "Incorrect! The number is less than " << users_number << " .\n";
		}
		else {
			std::cout << "Incorrect! The number is greater than " << users_number << " .\n";
		}

	}

	std::cout << "You are run of attepmts! The guessed number was " << guessed_number << " .\n";

}

int main() {
	
	srand(static_cast<int>(time(0)));
	greeting();

	change_difficulty:

	int difficulty_level{ getDifficultyLevel() }, chances{};

	switch (difficulty_level) {
		case 1:
			std::cout << "You have selected the Easy difficulty level.\n";
			chances = 10;
			break;
		case 2:
			std::cout << "You have selected the Medium difficulty level.\n";
			chances = 5;
			break;
		case 3:
			std::cout << "You have selected the Hard difficulty level.\n";
			chances = 3;
			break;
		default:
			std::cout << "\nThis is incorrect difficulty level.\n\n";
			goto change_difficulty;
	}

	theGame(chances);

	return 0;
}