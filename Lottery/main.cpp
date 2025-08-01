#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <string>

const int MIN = 1;
const int MAX = 100;
const std::string SCORE_FILE = "ranking.txt";

int getRandomNumber() {
    return MIN + std::rand() % (MAX - MIN + 1);
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void updateRanking(int attempts) {
    std::ifstream inFile(SCORE_FILE);
    int bestScore = 0;

    if (inFile.is_open()) {
        inFile >> bestScore;
        inFile.close();
    }

    if (bestScore == 0 || attempts < bestScore) {
        std::ofstream outFile(SCORE_FILE);
        if (outFile.is_open()) {
            outFile << attempts;
            outFile.close();
            std::cout << "Nowy rekord! (" << attempts << " prób)\n";
        }
    } else {
        std::cout << "Najlepszy wynik to: " << bestScore << " prób\n";
    }
}

void playGame() {
    int secretNumber = getRandomNumber();
    int guess = 0;
    int attempts = 0;

    std::cout << "Zgadnij liczbę z przedziału " << MIN << " - " << MAX << ":\n";

    while (true) {
        std::cout << "> ";
        std::cin >> guess;

        if (std::cin.fail()) {
            clearInputBuffer();
            std::cout << "Błąd: wpisz liczbę całkowitą.\n";
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            std::cout << "Za mało.\n";
        } else if (guess > secretNumber) {
            std::cout << "Za dużo.\n";
        } else {
            std::cout << "🎯 Trafiłeś w " << attempts << " próbach!\n";
            updateRanking(attempts);
            break;
        }
    }
}

bool askReplay() {
    std::string choice;
    std::cout << "\nCzy chcesz zagrać ponownie? (t/n): ";
    std::cin >> choice;
    return (choice == "t" || choice == "T");
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "=== Gra liczbowo-losowa ===\n\n";

    do {
        playGame();
    } while (askReplay());

    std::cout << "Dziękuję za grę!\n";
    return 0;
}