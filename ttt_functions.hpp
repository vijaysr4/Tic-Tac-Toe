#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> start_grid();
void display_grid(vector<string> grid);
void play_game(vector<string> &game_grid);
bool check_win(vector<string> check_grid, string check_symbol);