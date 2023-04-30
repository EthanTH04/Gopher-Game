/*
Ethan Henderson
4/14/2023
Section 2 
*/

#include <iostream>
#include <time.h>

using namespace std;

const int row = 9;
const int col = 9;
int rowChoice;
int colChoice;
char tile[col][row];
char guessed[col][row];
bool gameOver = false;
bool gopherTile = false;
int moves;
void create_grid();
void create_gopher();
void grid_update(int, int);
void grid_draw();
void choice();

int main(){
    create_grid();
    create_gopher();
    
    do{
        choice();
        grid_draw();
    }while(gameOver != true);
    if (gopherTile == true){
        cout << endl << "You landed on a Gopher Tile. You have lost.";
    }
    else{
        cout << endl << "You made 90 moves without landing on a Gopher Tile. You won the game!";
    }
}

void create_grid(){
    for (int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < row; i++){
        cout << i;
        for (int j = 0; j < col; j++)
        {
            tile[i][j] = '+';
            cout << " " << tile[i][j];
        }
        cout << endl;
    }
}

void create_gopher(){
    for (int i = 0; i < 10; i++){
        int randrow = rand() % 10;  
        int randcol = rand() % 10;
        tile[randcol][randrow] = 'G';
    }
}
    
void grid_update(int c, int r){
    char t_number = '0';
    if (tile[c - 1][r + 1] == 'G'){
        t_number += 1;
    }
    if (tile[c - 1][r] == 'G'){
         t_number += 1;
    }
    if (tile[c - 1][r - 1] == 'G'){
         t_number += 1;
    }
    if (tile[c + 1][r] == 'G'){
         t_number += 1;
    }
    if (tile[c][r] == 'G'){
        gameOver = true;
        gopherTile = true;
    }
    else{
        moves += 1;
        if (moves >= 90){
            gameOver = true;
        }
    }
    if (tile[c - 1][r] == 'G'){
         t_number += 1;
    }
    if (tile[c + 1][r + 1] == 'G'){
         t_number += 1;
    }
    if (tile[c + 1][r] == 'G'){
         t_number += 1;
    }
    if (tile[c + 1][r - 1] == 'G'){
         t_number += 1;
    }
    //t_number = static_cast<char>(g_count);
    tile[c][r] = t_number;
    cout << endl;
}

void grid_draw(){
    for (int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < row; i++){
        cout << i + 1;
        for (int j = 0; j < col; j++)
        {
            if (tile[i][j] == 'G' && gopherTile != true)
                cout << " " << "+";
            else
                cout << " " << tile[i][j];
        }
        cout << endl;
    }
}

void choice(){
    cout << "Enter your 2 values: " << endl;
        cin >> colChoice;
        while(colChoice >= 10){
            cout << "Please input a number that is within the grid: ";
            cin >> colChoice;
        }
        cin >> rowChoice;
        while(rowChoice >= 10){
            cout << "Please input a number that is within the grid: ";
            cin >> rowChoice;
        }
        grid_update(colChoice - 1, rowChoice - 1);
}