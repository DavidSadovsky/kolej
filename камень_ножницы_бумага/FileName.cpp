#include <iostream>
#include <vector>
#include <random>
#include <utility>
using namespace std;
int main() {
    random_device rd;            
    mt19937 gen(rd());           
    uniform_int_distribution<int> dist(0, 2);
    char options[] = { 's', 'p', 'c' };
	char answer;
	cout << "Let`s play a game, choose stone, paper or cut(s/p/c)\n";
    while (cin >> answer) {
        char random_char = options[dist(gen)];
        answer = tolower(answer);
        cout << "Your choose: " << answer << "\n";
        cout << "Bot choose: " << random_char << "\n";
        switch (answer) {
        case 's':
            if (random_char == 'p') {
                cout << "You lose!\n";
            }
            else if (random_char == 'c') {
                cout << "You win!\n";
            }
            else if (random_char == 's') {
                cout << "Tie!\n";
            }
            break;
        case 'p':
            if (random_char == 'p') {
                cout << "Tie!\n";
            }
            else if (random_char == 'c') {
                cout << "You lose!\n";
            }
            else if (random_char == 's') {
                cout << "You win!\n";
            }
            break;
        case 'c':
            if (random_char == 'p') {
                cout << "You win!\n";
            }
            else if (random_char == 'c') {
                cout << "Tie!\n";
            }
            else if (random_char == 's') {
                cout << "You lose!\n";
            }
            break;
        default:
            cout << "Error type, try again.";
            break;
        }
    }
}