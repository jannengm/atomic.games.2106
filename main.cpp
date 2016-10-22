#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <ctime>

#define WIDTH 7
#define HEIGHT 6

using namespace std;

const string TEST_STR = "[[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[2,2,2,2,1,1,1],[1,0,1,0,0,0,2],[1,2,1,1,2,2,1]]";

void read_json(const string & str, int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
int * get_Pmove(int board [HEIGHT][WIDTH]);
bool is_valid_move(int & col, int board[HEIGHT][WIDTH]);
void play_rand(int board[HEIGHT][WIDTH]);
int score_row(int player, int row, int col, int board[HEIGHT][WIDTH]);

int main(int argc, char ** argv) {
    // std::cout << TEST_STR << std::endl;
    
    int board[HEIGHT][WIDTH];
    read_json(TEST_STR, board);
    print_board(board);

    cout << "Row 0 score: " << score_row(1, 0, 3, board) << endl;
    cout << "Row 1 score: " << score_row(1, 1, 3, board) << endl;
    cout << "Row 2 score: " << score_row(1, 2, 3, board) << endl;

//    if(argc > 1) {
//        //  cout << "Got from input: " << argv[1] << endl;
//        read_json(argv[2], board);
//        print_board(board);
//        play_rand(board);
//    }
//    else{
//        cout << "Invalid args" << endl;
//    }
//    int a[] = get_Pmove(board);
    //    return 1;
//    exit(a);
    exit(0);
}

void read_json(const string & str, int board[HEIGHT][WIDTH]) {
    char ch;
    int size = HEIGHT * WIDTH;
    int iter = 0, row = 0, col = 0;
    
    for (int i = 0; i < size;) {
        ch = str.at(iter++);
        if (ch >= '0' && ch <= '9') {
            board[row][col++] = ch - '0';
            i++;
            if (col >= WIDTH) {
                row++;
                col = 0;
            }
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    cout << endl << endl;
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    
}


//int * get_Pmove( int board[HEIGHT][WIDTH])
//{
//    for(int row = 5; row < HEIGHT; row--){
//        for(int col = 0; col < WIDTH; col++){
//            if( board[row][col] == 0)
//                return col;
//
//
//        }
//    }
//}

void play_rand(int board[HEIGHT][WIDTH]){
    srand(time(NULL));
    int a;
    while(true){
        if( is_valid_move( (a = rand() % 7), board ) ){
            exit(a);
        }
        else{
            continue;
        }
    }
}

bool is_valid_move(int & col, int board[HEIGHT][WIDTH]){
    return board[0][col] == 0;
}

void foobar(int & row, int & col, int board[HEIGHT][WIDTH]){
    const int range = 4;

}

int score_row(int player, int row, int col, int board[HEIGHT][WIDTH]){
    int l_bound = (col - 3 < 0) ? 0 : col - 3;
    int r_bound = (col + 3 >= WIDTH) ? WIDTH - 1 : col + 3;
    int max_score = 0;
    int val;

    int sum = 0;
    for(int j = col; col <= r_bound; col++) {
        for (int i = l_bound; i < 4; i++) {
            val = board[i][col];
            if (val == player) {
                if (sum < 0) {
                    sum = 0;
                    break;
                } else {
                    sum++;
                }
            } else if (board[i][col] != player && board[i][col] != 0) {
                if (sum > 0) {
                    sum = 0;
                    break;
                } else {
                    sum--;
                }
            }
        }
        if( (sum < 0 ? sum * -1 : sum) > max_score ){
            max_score = sum;
        }
    }
    return max_score;

}
