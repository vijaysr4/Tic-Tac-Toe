#include <iostream>
#include <vector>
#include <string>
#include "ttt_functions.hpp"
using namespace std;

int main() {
    vector<string> grid = start_grid();
    display_grid(grid);
    play_game(grid);
}