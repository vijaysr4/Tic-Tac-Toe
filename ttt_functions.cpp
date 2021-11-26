#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> start_grid() {
    vector<string> start_grid = {};
    for (int i = 1; i < 10; i++) {
        start_grid.push_back(to_string(i));
    }
    return start_grid;
}

// Grid display function
void display_grid(vector<string> grid) {
    cout << "----------------------------\n\n";
    cout << "     *     *     \n";
    cout << "  " + grid[0] + "  *  " + grid[1] + "  *  " + grid[2] + " \n";
    cout << "     *     *     \n";
    cout << "*****************\n";
    cout << "     *     *     \n";
    cout << "  " + grid[3] + "  *  " + grid[4] + "  *  " + grid[5] + " \n";
    cout << "     *     *     \n";
    cout << "*****************\n";
    cout << "     *     *     \n";
    cout << "  " + grid[6] + "  *  " + grid[7] + "  *  " + grid[8] + " \n";
    cout << "     *     *     \n";
    cout << "------------------------------\n";
}


bool check_win(vector<string> check_grid, string check_symbol) {
    string win_cond = check_symbol + check_symbol + check_symbol;
    vector<string> win_lines;

    // Horizontal win lines
    win_lines.push_back(check_grid[0] + check_grid[1] + check_grid[2]);
    win_lines.push_back(check_grid[3] + check_grid[4] + check_grid[5]);
    win_lines.push_back(check_grid[6] + check_grid[7] + check_grid[8]);

    // Vertical win lines
    win_lines.push_back(check_grid[0] + check_grid[3] + check_grid[6]);
    win_lines.push_back(check_grid[1] + check_grid[4] + check_grid[7]);
    win_lines.push_back(check_grid[2] + check_grid[5] + check_grid[8]);

    // Diagonal win lines
    win_lines.push_back(check_grid[0] + check_grid[4] + check_grid[8]);
    win_lines.push_back(check_grid[2] + check_grid[4] + check_grid[6]);

    for (string line:win_lines) {
        if (line == win_cond) {
            return true;
        }
    }
    return false;
}

void play_game(vector<string> &game_grid) {
    // Initializing variables for gameplay
    int player = 0;
    vector<string> symbols = {"X" , "O"};
    int choice;
    int turns = 0;

    while (turns < 9) {
        // Player input
        cout << "Player " << player + 1 << " turn\n";
        cout<< "Choose a numbered square to play.\n Your symbol is " + symbols[player] + " .\n";
        cin >> choice;

        // Check for valid choice
        if (choice < 1 || choice > 9) {
            cout << "Invalid number.\n";
            // Keeping the same player turn
            player = !player;
            turns--;
        }
        else if (game_grid[choice - 1] == "X" || game_grid[choice - 1] == "O") {
            cout << "This square is already filled.\n";
            // Keeping the same player turn
            player = !player;
            turns--;
        } else {
            game_grid[choice - 1] = symbols[player];
        }
        display_grid(game_grid);
        if (check_win(game_grid, symbols[player])) {
            cout << "Player " << player + 1 << " wins!\n";
            break;
        }
        turns++;
        player = !player;
    }
    if (!check_win(game_grid, symbols[player])) {
        cout << "Game Over!, It's a draw\n ";
    }
}
