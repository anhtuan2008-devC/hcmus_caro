#include "PvEMode.h"

void BotMove() {
    Sleep(1000);
    srand(static_cast<unsigned>(time(0))); // Khởi tạo seed cho random
    int x, y;
    do {
        x = rand() % BOARD_SIZE; // Random tọa độ x
        y = rand() % BOARD_SIZE; // Random tọa độ y
    } while (_A[x][y].c != 0);   // Kiểm tra ô có trống hay không

    _A[x][y].c = 1; // Máy luôn đánh O (giá trị 1)
    GotoXY(_A[x][y].x + 1, _A[x][y].y);
    cout << O(); // Hiển thị nước đi của máy
}

void PlayWithBot() {
    ShowBlinkingCursor(true);
    system("color 70");
    fixConsoleWindow();
    StartGame();
    vienPlayer();
    int x = 0, y = 0; // Tọa độ bắt đầu (trên bàn cờ)
    bool isPlaying = true;
    int result;

    while (isPlaying) {
        if (_TURN) {
            // Lượt người chơi
            bool validMove = false;
            while (!validMove) {
                GotoXY(_A[x][y].x, _A[x][y].y); // Di chuyển con trỏ đến vị trí hiện tại
                char key = _getch(); // Đợi người chơi nhập phím

                switch (key) {
                case 27:
                    playSound(3, 0);
                    ExitGame();
                    break;
                case 72: // Mũi tên lên
                    if (x > 0) { x--; playSound(2, 0); }
                    break;
                case 80: // Mũi tên xuống
                    if (x < BOARD_SIZE - 1) { x++; playSound(2, 0); }
                    break;
                case 75: // Mũi tên trái
                    if (y > 0) { y--; playSound(2, 0); }
                    break;
                case 77: // Mũi tên phải
                    if (y < BOARD_SIZE - 1) { y++; playSound(2, 0); }
                    break;
                case 13: // Phím Enter
                    if (_A[x][y].c == 0) { // Nếu ô trống
                        _A[x][y].c = -1; // Người chơi luôn đánh X (giá trị -1)
                        GotoXY(_A[x][y].x + 1, _A[x][y].y);
                        cout << X(); // Hiển thị nước đi
                        playSound(3, 0);
                        setColor(112);
                        moveCount(-1);
                        validMove = true; // Thoát khỏi vòng lặp
                    }
                    break;
                default:
                    break;
                }
            }
            _TURN = false;
        }
        else {
            // Lượt máy
            BotMove();
            setColor(112);
            moveCount(1);
            _TURN = true;
        }

        // Kiểm tra trạng thái trò chơi
        result = TestBoard();
        if (result != 2) {
            isPlaying = false;
        }
    }

    // Kết thúc trò chơi
    if (result == -1) {
        Sleep(500);
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(124);
        GotoXY(85, 2);
        cout << u8"██╗  ██╗ ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"╚██╗██╔╝ ██║    ██║██║████╗  ██║██║";
        GotoXY(86, 4);
        cout << u8"╚███╔╝  ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(86, 5);
        cout << u8"██╔██╗  ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"██╔╝ ██╗ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(85, 7);
        cout << u8"╚═╝  ╚═╝  ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(650);
    }
    else if (result == 1) {
        Sleep(500);
        SetConsoleOutputCP(CP_UTF8);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(150);
        setColor(121);
        GotoXY(86, 2);
        cout << u8"█████╗  ██╗    ██╗██╗███╗   ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔══██╗ ██║    ██║██║████╗  ██║██║";
        GotoXY(85, 4);
        cout << u8"██║  ██║ ██║ █╗ ██║██║██╔██╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║  ██║ ██║███╗██║██║██║╚██╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"╚█████╔╝ ╚███╔███╔╝██║██║ ╚████║██╗";
        GotoXY(86, 7);
        cout << u8"╚════╝   ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝";
        Sleep(650);
    }
    else {
        Sleep(500);
        SetConsoleOutputCP(CP_UTF8);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(120);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(150);
        setColor(122);
        GotoXY(85, 2);
        cout << u8"█████╗ █████╗  █████╗ ██╗    ██╗██╗";
        GotoXY(85, 3);
        cout << u8"██╔═██╗██╔═██╗██╔══██╗██║    ██║██║";
        GotoXY(85, 4);
        cout << u8"██║ ██║█████╔╝███████║██║ █╗ ██║██║";
        GotoXY(85, 5);
        cout << u8"██║ ██║██╔═██╗██╔══██║██║███╗██║╚═╝";
        GotoXY(85, 6);
        cout << u8"█████╔╝██║ ██║██║  ██║╚███╔███╔╝██╗";
        GotoXY(85, 7);
        cout << u8"╚════╝ ╚═╝ ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝";
        Sleep(650);
    }
    SetConsoleOutputCP(437);
    //char key = _getch(); // Đợi người chơi nhập phím
    if (AskContinue() != 'Y') {
        playSound(3, 0);
        ExitGame();
    }
    else {
        continueGame();
        vienPlayer();
        gameText();
        GotoXY(_A[0][0].x, _A[0][0].y);
    }
}