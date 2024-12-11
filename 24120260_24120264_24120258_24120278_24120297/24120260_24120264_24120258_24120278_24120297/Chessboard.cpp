#include "Chessboard.h"

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _X, _Y;

int scoreX = 0;
int scoreO = 0;

int Xmove = 0;
int Omove = 0;

char X() {
    setColor(124);
    return 'X';
}

char O() {
    setColor(121);
    return 'O';
}

// Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ
void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2; // Tọa độ hoành độ màn hình bàn cờ
            _A[i][j].y = 2 * i + TOP; // Tọa độ tung độ màn hình bàn cờ
            _A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu
        }
    }
    _TURN = true;
    _X = _A[0][0].x;
    _Y = _A[0][0].y;

    Xmove = 0;
    Omove = 0;
}

void DrawBoard(int pSize) {
    // Vẽ ô bàn cờ với khung
    for (int i = 0; i < pSize; i++) {
        for (int j = 0; j < pSize - 1; j++) {
            GotoXY(_A[i][j].x - 1, _A[i][j].y - 1);
            printf("%c%c%c%c", 197, 196, 196, 196);
            GotoXY(_A[i][j].x - 1, _A[i][j].y);
            printf("%c   %c", 179, 179);
            GotoXY(_A[i][j].x - 1, _A[i][j].y + 1);
            printf("%c%c%c%c", 197, 196, 196, 196);
        }
    }
    for (int i = 0; i < pSize; i++) {
        for (int j = pSize - 1; j < pSize; j++) {
            GotoXY(_A[i][j].x - 1, _A[i][j].y - 1);
            printf("%c%c%c%c%c", 197, 196, 196, 196, 191);
            GotoXY(_A[i][j].x - 1, _A[i][j].y);
            printf("%c   %c", 179, 179);
            GotoXY(_A[i][j].x - 1, _A[i][j].y + 1);
            printf("%c%c%c%c%c", 197, 196, 196, 196, 217);
        }
    }
    for (int i = 1; i < pSize; i++) {
        for (int j = pSize - 1; j < pSize; j++) {
            GotoXY(_A[i][j].x - 1, _A[i][j].y - 1);
            printf("%c%c%c%c%c", 197, 196, 196, 196, 180);
        }
    }
    for (int j = 1; j < pSize; j++) {
        GotoXY(_A[0][j].x - 1, _A[0][j].y - 1);
        printf("%c", 194);
    }
    for (int j = 1; j < pSize; j++) {
        GotoXY(_A[11][j].x - 1, _A[11][j].y + 1);
        printf("%c", 193);
    }
    for (int i = 1; i < pSize; i++) {
        GotoXY(_A[i][0].x - 1, _A[i][0].y - 1);
        printf("%c", 195);
    }
    GotoXY(_A[0][0].x - 1, _A[0][0].y - 1);
    printf("%c", 218);
    GotoXY(_A[11][0].x - 1, _A[11][0].y + 1);
    printf("%c", 192);
    GotoXY(_A[0][0].x, _A[0][0].y);
}

void StartGame() {
    system("cls");
    ResetData();
    fixConsoleWindow();
    DrawBoard(BOARD_SIZE);
    scoreX = 0;
    scoreO = 0;
    displayScore(0);
    moveCount(0);
}

void GabageCollect() {
    
}

// Hàm thoát game
void ExitGame() {
    system("cls");
    GabageCollect();
    xuLyMenu();
    // Có thể lưu game trước khi exit
}

// Hàm kiểm tra xem có người thắng/thua hay hòa
int CheckWin(int player) {
    // Kiểm tra hàng
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j <= BOARD_SIZE - 5; j++) {
            if ((_A[i][j].c == player &&
                _A[i][j + 1].c == player &&
                _A[i][j + 2].c == player &&
                _A[i][j + 3].c == player &&
                _A[i][j + 4].c == player)) {
                markWinning(i, j, 0, 1, player);
                displayScore(player);
                return player; // Trả về người thắng
            }
        }
    }

    // Kiểm tra cột
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = 0; i <= BOARD_SIZE - 5; i++) {
            if ((_A[i][j].c == player &&
                _A[i + 1][j].c == player &&
                _A[i + 2][j].c == player &&
                _A[i + 3][j].c == player &&
                _A[i + 4][j].c == player)) {
                markWinning(i, j, 1, 0, player);
                displayScore(player);
                return player; // Trả về người thắng
            }
        }
    }

    // Kiểm tra đường chéo chính
    for (int i = 0; i <= BOARD_SIZE - 5; i++) {
        for (int j = 0; j <= BOARD_SIZE - 5; j++) {
            if ((_A[i][j].c == player &&
                _A[i + 1][j + 1].c == player &&
                _A[i + 2][j + 2].c == player &&
                _A[i + 3][j + 3].c == player &&
                _A[i + 4][j + 4].c == player)) {
                markWinning(i, j, 1, 1, player);
                displayScore(player);
                return player; // Trả về người thắng
            }
        }
    }

    // Kiểm tra đường chéo phụ
    for (int i = 4; i < BOARD_SIZE; i++) {
        for (int j = 0; j <= BOARD_SIZE - 5; j++) {
            if ((_A[i][j].c == player &&
                _A[i - 1][j + 1].c == player &&
                _A[i - 2][j + 2].c == player &&
                _A[i - 3][j + 3].c == player &&
                _A[i - 4][j + 4].c == player)) {
                markWinning(i, j, 1, -1, player);
                Sleep(1100);
                displayScore(player);
                return player; // Trả về người thắng
            }
        }
    }

    return 0; // Chưa ai thắng
}

int TestBoard() {
    // Kiểm tra nếu bàn cờ đầy
    bool full = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == 0) {
                full = false;
                break;
            }
        }
        if (!full) break;
    }
    if (full) return 0; // Hòa

    // Kiểm tra điều kiện thắng cho cả hai người chơi
    for (int player = -1; player <= 1; player += 2) {
        if (CheckWin(player) == player) {
            return player; // Trả về người thắng
        }
    }

    return 2; 
}

int CheckBoard(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
                _A[i][j].c = (_TURN == true) ? -1 : 1; // Cập nhật giá trị
                GotoXY(_A[i][j].x - 1, _A[i][j].y);
                printf("  %c ", (_TURN) ? X() : O());
                GotoXY(_A[i][j].x - 1, _A[i][j].y);
                setColor(112);
                printf("%c", 179);
                return _A[i][j].c;
            }
        }
    }
    return 0; 
}

void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;
        GotoXY(_X, _Y);
        playSound(2, 0);
        Sleep(10);
    }
}

void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;
        GotoXY(_X, _Y);
        playSound(2, 0);
        Sleep(10);
    }
}

void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;
        GotoXY(_X, _Y);
        playSound(2, 0);
        Sleep(10);
    }
}

void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;
        GotoXY(_X, _Y);
        playSound(2, 0);
        Sleep(10);
    }
}

// Hàm kiểm tra phím được nhấn
char getInput() {
    _getch();
    if (GetAsyncKeyState(VK_UP) & 0x8000) return 'W';
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) return 'S';
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) return 'A';
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) return 'D';
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) return 27; 
    if (GetAsyncKeyState(VK_RETURN) & 0x8000) return 13; 
    if (GetAsyncKeyState(0x57) & 0x8000) return 'W';
    if (GetAsyncKeyState(0x53) & 0x8000) return 'S';
    if (GetAsyncKeyState(0x41) & 0x8000) return 'A';
    if (GetAsyncKeyState(0x44) & 0x8000) return 'D';
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) return 13;
    if (GetAsyncKeyState(0x4C) & 0x8000) {
        return 'L';  
    }
    return 0; 
}

void markWinning(int startX, int startY, int dirX, int dirY, int player) {
    for (int i = 0; i < 5; i++) {
        int x = startX + i * dirX;
        int y = startY + i * dirY;
        GotoXY(_A[x][y].x, _A[x][y].y);
        if (player == -1) {
            setColor(79);
            printf(" X ");
        }
        else if (player == 1) {
            setColor(159);
            printf(" O ");
        }
    }
    setColor(112);
}
void displayScore(int player) {
    if (player == -1) {
        scoreX++;
    }
    else if (player == 1) {
        scoreO++;
    }
    box(20, 14, 11, 3, " ");
    box(92, 14, 11, 3, " ");
    setColor(124);
    GotoXY(21, 12);
    printf("X SCORE");
    GotoXY(24, 14);
    printf("%d", scoreX);
    setColor(121);
    GotoXY(93, 12);
    printf("O SCORE");
    GotoXY(96, 14);
    printf("%d", scoreO);
    setColor(112);
}
void moveCount(int player) {
    if (player == -1) {
        Xmove++;
    }
    else if (player == 1) {
        Omove++;
    }
    setColor(79);
    GotoXY(19, 9);
    printf("X MOVES: [%d]", Xmove);
    setColor(159);
    GotoXY(90, 9);
    printf("O MOVES: [%d]", Omove);
    setColor(112);
}
void continueGame() {
    system("cls");
    ResetData();
    fixConsoleWindow();
    DrawBoard(BOARD_SIZE);
    moveCount(0);
    displayScore(0);
}


