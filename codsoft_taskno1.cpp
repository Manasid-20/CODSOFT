#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int randomNumber, guess;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Keep asking until the correct guess
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the correct number: "
                 << randomNumber << endl;
        }

    } while (guess != randomNumber);

    return 0;
}

