#include <bits/stdc++.h>
using namespace std;

class Player {
public:
    string name;
    int points;

    Player(string Name, int Points) {
        name = Name;
        points = Points;
    }

    friend ostream& operator<<(ostream& os, const Player& p) {
        os << p.name;
        return os;
    }
};

void clearScreen() {
    cout << "\x1B[2J\x1B[H";
}

int main() {
    cout << "========== Skrew Point Counter ==========\n\n";

    cout << "Enter the number of players: ";
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Invalid number of players!";
        cout << "\n\n";
        cout << "Try again? (Y/N) ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            clearScreen();
            main();
        }
        
        return 0;
    }

    if (n > 10) {
        cout << "Invalid number of players!";
        cout << "\n\n";
        cout << "Try again? (Y/N) ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            clearScreen();
            main();
        }
        return 0;
    }

    vector<Player> names;

    cout << "\nEnter the players' names: ";
    for (int i = 0; i < n; i++) {
        string NAME;
        cin >> NAME;
        names.push_back(Player(NAME, 0));
    }

    cout << "\nEnter the number of rounds: ";

    int rounds;
    cin >> rounds;

    clearScreen();

    for (int i = 0; i < rounds; i++) {
        cout << "========== Skrew Point Counter ==========\n\n";

        cout << "===== Round " << i + 1  << " =====\n" << endl;

        cout << left << setw(10) << "Player" << setw(10) << "Points" << endl;

        for (int j = 0; j < n; j++) {

            cout << left << setw(10) << names[j] << setw(10) << names[j].points << endl;
        }

        cout << "\nWho is the winner? ";

        string winner;
        cin >> winner;

        int winnerIndex = 0;

        for (int j = 0; j < n; j++) {
            if (names[j].name == winner) {
                names[j].points += 0;

                winnerIndex = j;
            }
        }

        cout << "\nEnter the points of the losers (in order): ";

        for (int j = 0; j < n; j++) {
            if (j == winnerIndex) {
                continue;
            }

            int Points;

            cin >> Points;

            names[j].points += Points;
        }

        clearScreen();
    }

    cout << "========== Skrew Point Counter ==========\n\n";

    cout << "Final Standings\n\n";

    cout << left << setw(10) << "Player" << setw(10) << "Points" << endl;

    int minPoints = names[0].points;

    int minIndex = 0;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << names[i] << setw(10) << names[i].points << endl;

        if (names[i].points < minPoints) {
            minPoints = names[i].points;
            minIndex = i;
        }
    }

    string point = " point!!!";

    if (names[minIndex].points == 1) {
      cout << "\nWinner is: " << names[minIndex] << " with " << names[minIndex].points << point;
    } else {
      cout << "\nWinner is: " << names[minIndex] << " with " << names[minIndex].points << " points!!!";
    }

    cout << "\n\n";

    cout << "GG!\n\n";

    cout << "Do you want to play again? (Y/N) ";

    char again;
    cin >> again;

    if (again == 'Y' || again == 'y') {
        clearScreen();
        main();
    }

    return 0;
}   