#include <iostream>
#include <string>
//#include <c++/vector>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>

#define WIDTH 7
#define HEIGHT 6

using namespace std;

const string TEST_STR = "[[1,2,3,4,5,6,7],[8,9,0,1,2,3,4],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[2,2,0,0,0,0,0],[1,1,0,0,0,0,0]]";

struct CMove{
    int column;
    int rating;
};
void read_json(const string & str, int board[HEIGHT][WIDTH]);
void print_board(int board[HEIGHT][WIDTH]);
void get_Pmove(int board [HEIGHT][WIDTH], CMove * possible);
int get_Best_Move(CMove *Possible);



int main(int argc, char ** argv) {
    // std::cout << TEST_STR << std::endl;
    
    int board[HEIGHT][WIDTH];
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

    CMove *x = new CMove[7];

    get_Pmove(board, x);

    //stage of the game check

    //winn checker


    //lose CMovechecker


    //look for 7 location

    //    return 1;
    
    
    int a = get_Best_Move( x );
    a = 2;
    exit( a );
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


void get_Pmove( int board[HEIGHT][WIDTH], CMove* possible)
{
//CMove*possible = X;
    int i = 0;

    for(int row = 6; row >= 0; row--){
        for(int col = 0; col < WIDTH; col++){
            if( board[row][col] == 0) {
                possible[i].column = col;
                possible[i].rating = 5;// default value will update based on stage of the game
                cout << "woo" << endl ;
            i++;
                if(i> WIDTH)
                    break;
            }
            
        }
    }
    //return possible;
}


int get_Best_Move( CMove* pMoves)
{
    return 1;
}


