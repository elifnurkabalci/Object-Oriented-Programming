#ifndef BOARDGAME_H
#define BOARDGAME_H
using namespace std;

class BoardGame2D{
public:
vector<vector<char> > vec;
int type;
void playUser(string *a);
void playUser();
void playAuto();
void playAutoAll();
void print();
friend ostream & operator<<(ostream& output, const BoardGame2D& obj);
bool endgame();
int boardScore();
void initialize();
static void playVector();
int ControlPegGame();
void Playpeg(int row, int col, string c);
void Playpuz(int row, int col, string c);
void Playklot(int row, int col, string c);
};

class PegSolitaire : public BoardGame2D{
public:
    void init(int m);
};

class EightPuzzle : public BoardGame2D{
public:
    void init();
};

class Klotski : public BoardGame2D{
public:
    void init();
};

#endif //BOARDGAME_H