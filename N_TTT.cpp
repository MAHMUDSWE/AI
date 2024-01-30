#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
public:
    TicTacToe(int size) : currentPlayer(Player::X), N(size), board(size) {}

    void playGame()
    {
        while (!board.isTerminal())
        {
            board.print();
            makeMove();
            if (board.isTerminal())
                break;
            switchPlayer();
        }

        board.print();
        announceResult();
    }

private:
    enum Player
    {
        X,
        O,
        Empty
    };

    struct Move
    {
        int row, col;
    };

    class Board
    {
    public:
        Board(int size) : state(size, vector<Player>(size, Player::Empty)), N(size) {}

        void print()
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (state[i][j] == Player::X)
                        cout << "X ";
                    else if (state[i][j] == Player::O)
                        cout << "O ";
                    else
                        cout << "_ ";
                }
                cout << endl;
            }
        }

        bool isFull()
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (state[i][j] == Player::Empty)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        bool isWin(Player player)
        {
            for (int i = 0; i < N; ++i)
            {
                bool rowWin = true;
                bool colWin = true;
                for (int j = 0; j < N; ++j)
                {
                    if (state[i][j] != player)
                        rowWin = false;
                    if (state[j][i] != player)
                        colWin = false;
                }
                if (rowWin || colWin)
                    return true;
            }

            bool diag1Win = true;
            bool diag2Win = true;
            for (int i = 0; i < N; ++i)
            {
                if (state[i][i] != player)
                    diag1Win = false;
                if (state[i][N - i - 1] != player)
                    diag2Win = false;
            }

            return diag1Win || diag2Win;
        }

        bool isTerminal()
        {
            return isWin(Player::X) || isWin(Player::O) || isFull();
        }

        vector<vector<Player>> state;

    private:
        int N;
    };

    Player currentPlayer;
    int N;
    Board board;

    void makeMove()
    {
        Move move = getPlayerMove();
        while (board.state[move.row][move.col] != Player::Empty)
        {
            cout << "Invalid move. Try again." << endl;
            move = getPlayerMove();
        }
        board.state[move.row][move.col] = currentPlayer;
    }

    Move getPlayerMove()
    {
        Move move;
        cout << "Player " << (currentPlayer == Player::X ? "X" : "O") << ", enter your move (row and column): ";
        cin >> move.row >> move.col;
        return move;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }

    void announceResult()
    {
        if (board.isWin(Player::X))
        {
            cout << "Player X wins!" << endl;
        }
        else if (board.isWin(Player::O))
        {
            cout << "Player O wins!" << endl;
        }
        else
        {
            cout << "It's a draw!" << endl;
        }
    }
};

int main()
{
    int boardSize;
    cout << "Enter the size of the board: ";
    cin >> boardSize;

    TicTacToe game(boardSize);
    game.playGame();

    return 0;
}
