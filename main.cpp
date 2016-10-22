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

struct CMove{
    int column;
    int row;
    int rating;
};
void read_json(const string & str, int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
int * get_Pmove(int board [HEIGHT][WIDTH]);
bool is_valid_move(int & col, int board[HEIGHT][WIDTH]);
void play_rand(int board[HEIGHT][WIDTH]);
int score_row(int player, int row, int col, int board[HEIGHT][WIDTH]);
void get_Pmove(int board [HEIGHT][WIDTH], CMove * possible);
int get_Best_Move(CMove *Possible);
bool MoveWin( int board[HEIGHT][WIDTH],CMove  possible ,int player);


int main(int argc, char ** argv) {
    // std::cout << TEST_STR << std::endl;
    int exitM =-1;
    int board[HEIGHT][WIDTH];
    read_json(TEST_STR, board);
    print_board(board);

  //  cout << "Row 0 score: " << score_row(1, 0, 3, board) << endl;
    //cout << "Row 1 score: " << score_row(1, 1, 3, board) << endl;
    //cout << "Row 2 score: " << score_row(1, 2, 3, board) << endl;

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
//    exit(0);
    // read_json(TEST_STR, board);
    // print_board(board);
    if(argc > 1) {
        //  cout << "Got from input: " << argv[1] << endl;
        read_json(argv[2], board);
        print_board(board);
    }
    else{
        cout << "Invalid args" << endl;
    }
   //  string x = argv[4];// Get from input/ player-one
    std::string word = argv[4];
    int p;
    if(word.compare("player-one"))
    {
    p = 1;
    }else
        p = 2;

    //cout << x;
    CMove *x = new CMove[7];

    get_Pmove(board, x);


    //stage of the game check

    //winn checker
    //for each possible move
    CMove *z = x;
  while(z++)
  {
    if ( MoveWin(board, *z ,p))
      exitM = z->column;
  }
    if(exitM == -1) {


        //lose CMovechecker


        //look for 7 location

        //    return 1;

    play_rand(board);
        int a = get_Best_Move(x);
        a = 2;
    }
    exit( exitM );
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

int score_row(int player, int row, int col, int board[HEIGHT][WIDTH]) {
    int l_bound = (col - 3 < 0) ? 0 : col - 3;
    int r_bound = (col + 3 >= WIDTH) ? WIDTH - 1 : col + 3;
    int max_score = 0;
    int val;

    int sum = 0;
    for (int j = col; col <= r_bound; col++) {
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
        if ((sum < 0 ? sum * -1 : sum) > max_score) {
            max_score = sum;
        }
    }
    return max_score;
}

void get_Pmove( int board[HEIGHT][WIDTH], CMove* possible) {
//CMove*possible = X;
    int i = 0;

    for (int row = 6; row >= 0; row--) {
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == 0) {
                possible[i].column = col;
                possible[i].row = row;
                possible[i].rating = 0;// default value will update based on stage of the game
                // cout << "woo" << endl ;


            } else if (row == 0) {
                if (board[row][col] != 0) {
                    possible[i].column = col;
                    possible[i].rating = -10;
                }
                i++;
                if (i > WIDTH)
                    break;

            }
        }
        //return possible;
    }

}



    int get_Best_Move(CMove *pMoves) {
        return 1;
    }


    bool MoveWin(int board[HEIGHT][WIDTH], CMove possible, int player) {


        bool win;

        int c = possible.column;
        int r = possible.row;
        int lb ,rb , ub ,db;
       int w= 0;
        lb = (possible.column - 3 < 0 ? 0 : possible.column - 3);
        rb = (possible.column + 3 >= WIDTH ? WIDTH - 1 : possible.column + 3);
       //horizontal confirmation
        for(int k = lb; k +4 <= rb; k++ )
        {
            for (int j = k ; j < k+4; j ++)
            {
                if(board[j][r] == player )
                {
                    w++;
                }else if (board[j][r] == 0){
                    //w = 0;
                    continue;
                }else
                {
                    w=0;
                    break;}
            }
            if(w==3)
            {
                return true;
            }
            w=0;
        }

        //vertical



        //diagonal -l


        //diagonal -r





        return false;
    }
