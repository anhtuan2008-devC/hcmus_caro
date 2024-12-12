#include "Menu.h"

int x = 50;
int y = 5;

void boxPlayGame() {
    BOX(55, 10, 21, 4);
    GotoXY(60, 10);
    cout << "PLAY GAME";
}
void boxLoadGame() {
    BOX(55, 10 + 4, 21, 4);
    GotoXY(60, 10 + 4);
    cout << "LOAD GAME";
}
void boxHelp() {
    BOX(55, 10 + 8, 21, 4);
    GotoXY(62, 10 + 8);
    cout <<"HELP";
}
void boxSetting() {
    BOX(55, 10 + 12, 21, 4);
    GotoXY(61, 10 + 12);
    cout << "SETTING";
}
void boxExit() {
    BOX(55, 10 + 16, 21, 4);
    GotoXY(62, 10 + 16);
    cout << "EXIT";
}

// Hàm hiển thị nội dung của menu
void hienthimenu() {
    system("color 70");
    trangtri();
    // Vẽ các hộp với nội dung menu
    boxPlayGame();
    boxLoadGame();
    boxHelp();
    boxSetting();
    boxExit();

    // Xử lý nhập liệu cho việc chọn menu
    int selection = 0, previousSelection = -1;
    while (true) {
        if (selection != previousSelection) {
        // Đổi màu cho ô được chọn
            for (int i = 0; i < 5; i++) {
                setColor(i == selection ? 124 : 112);
                if (i == 0) {
                    boxPlayGame();
                }
                else if (i == 1) {
                    boxLoadGame();
                }
                else if (i == 2) {
                    boxHelp();
                }
                else if (i == 3) {
                    boxSetting();
                }
                else {
                    boxExit();
                }
                previousSelection = selection;
            }
            Sleep(20);
        }
        char ch = _getch(); // Đọc ký tự từ người dùng
        playSound(2, 0);
        /*if (ch == 'o') {
            setVolume(getVolume() - 100);
        }
        if (ch == 'p') {
            setVolume(getVolume() + 100);
        }*/
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                playSound(3, 0);
                clearScreen();
                PorE();
                break;
            case 1:
                playSound(3, 0);
                clearScreen();
                LoadGame();
                break;
            case 2: {
                playSound(3, 0);
                clearScreen();
                menuHelp(); // Hiển thị trợ giúp
                break;     // Sau khi quay lại, không tiếp tục xử lý menu chính
            }
            case 3:
                playSound(3, 0);
                clearScreen();
                settingScreen();
                break;
            case 4:
                clearScreen();
                cout << "Ban da thoat!!!" << endl << endl << endl << endl << endl << endl;
                exit(100);
                break;
            }
            break;
        }

        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi tên lên (ASCII 72)
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 4) {
                selection++;
            }
        }
    }
}

void trangtri() {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    // Lấy chiều rộng và chiều cao của cửa sổ console
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Chiều dài của chữ "CARO" là 7*4 (cho mỗi chữ), cộng thêm 3 khoảng cách giữa các chữ (3 khoảng trống)
    int textWidth = 7 * 4 + 3 * 3;  // 7 ký tự cho mỗi chữ và 3 khoảng cách giữa các chữ
    int textHeight = 5;  // Chữ "CARO" có 5 dòng (theo kích thước chữ)

    // Tính toán vị trí để căn giữa chữ "CARO" theo chiều ngang
    int startX = (consoleWidth - textWidth) / 2;
    int startY = 0;  // Đặt ở dòng đầu tiên (dòng 0)

    // Di chuyển đến vị trí căn giữa trên dòng đầu tiên
    setColor(124);
    GotoXY(startX, startY);

    int x = 25, y = 0;
    SetConsoleOutputCP(CP_UTF8);
    setColor(124);

    cout << u8R"(
                           ██████   █████  ███    ███ ███████      ██████  █████  ██████   ██████  
                          ██       ██   ██ ████  ████ ██          ██      ██   ██ ██   ██ ██    ██ 
                          ██   ███ ███████ ██ ████ ██ █████       ██      ███████ ██████  ██    ██ 
                          ██    ██ ██   ██ ██  ██  ██ ██          ██      ██   ██ ██   ██ ██    ██ 
                           ██████  ██   ██ ██      ██ ███████      ██████ ██   ██ ██   ██  ██████                                                                             
)";
    setColor(0);
    GotoXY(35, 7);
    cout << "       ";
    setColor(0);
    GotoXY(33, 8);
    cout << "           ";
    setColor(100);
    GotoXY(34, 8);
    cout << "         ";
    setColor(0);
    GotoXY(37, 8);
    cout << " ";
    setColor(0);
    GotoXY(32, 9);
    cout << "             ";
    setColor(100);
    GotoXY(33, 9);
    cout << "           ";
    setColor(0);
    GotoXY(36, 9);
    cout << " ";
    setColor(0);
    GotoXY(32, 10);
    cout << "             ";
    setColor(100);
    GotoXY(33, 10);
    cout << "           ";
    setColor(0);
    GotoXY(35, 10);
    cout << " ";
    setColor(0);
    GotoXY(31, 11);
    cout << "               ";
    setColor(0);
    GotoXY(32, 11);
    cout << "             ";
    setColor(100);
    GotoXY(33, 11);
    cout << " ";
    setColor(100);
    GotoXY(33, 11);
    cout << "           ";
    setColor(0);
    GotoXY(35, 11);
    cout << " ";
    setColor(0);
    GotoXY(31, 12);
    cout << "               ";
    setColor(100);
    GotoXY(32, 12);
    cout << "             ";
    setColor(0);
    GotoXY(35, 12);
    cout << " ";
    setColor(0);
    GotoXY(31, 13);
    cout << "              ";
    setColor(100);
    GotoXY(32, 13);
    cout << "            ";
    setColor(0);
    GotoXY(35, 13);
    cout << " ";
    // vẽ vùng trắng miệng 

    setColor(119);
    GotoXY(37, 13);
    cout << "      ";

    setColor(0);
    GotoXY(39, 13);
    cout << "   ";

    setColor(119);
    GotoXY(37, 12);
    cout << "      ";
    setColor(0);
    GotoXY(40, 12);
    cout << " ";
    setColor(119);
    GotoXY(38, 11);
    cout << "      ";
    // vẽ cửa sổ tâm hồn 
    setColor(60);
    GotoXY(38, 10);
    cout << " ";

    setColor(60);
    GotoXY(42, 10);
    cout << " ";

    // phần thân 

    setColor(0);
    GotoXY(32, 14);
    cout << "            ";
    setColor(119);
    GotoXY(38, 14);
    cout << "    ";
    setColor(0);
    GotoXY(30, 15);
    cout << "              ";
    setColor(0);
    GotoXY(28, 16);
    cout << "                ";
    setColor(0);
    GotoXY(27, 17);
    cout << "                 ";
    setColor(0);
    GotoXY(26, 18);
    cout << "                 ";
    setColor(0);
    GotoXY(24, 19);
    cout << "                   ";
    setColor(0);
    GotoXY(23, 20);
    cout << "                    ";
    setColor(0);
    GotoXY(22, 21);
    cout << "                     ";
    // phần trắng ngực 
    setColor(119);
    GotoXY(35, 16);
    cout << "      ";
    setColor(119);
    GotoXY(34, 17);
    cout << "        ";
    setColor(119);
    GotoXY(34, 18);
    cout << "        ";
    setColor(119);
    GotoXY(35, 19);
    cout << "      ";
    setColor(119);
    GotoXY(36, 20);
    cout << "    ";
    setColor(119);
    GotoXY(37, 21);
    cout << "  ";
    // vẽ nền vàng cho thân 
    setColor(100);
    GotoXY(31, 16);
    cout << "   ";
    setColor(100);
    GotoXY(32, 15);
    cout << "   ";
    setColor(100);
    GotoXY(32, 17);
    cout << "  ";
    setColor(100);
    GotoXY(32, 15);
    cout << "   ";
    setColor(100);
    GotoXY(31, 16);
    cout << "   ";
    setColor(100);
    GotoXY(30, 17);
    cout << "    ";
    setColor(100);
    GotoXY(29, 18);
    cout << "    ";
    setColor(100);
    GotoXY(30, 19);
    cout << "    ";
    setColor(100);
    GotoXY(31, 20);
    cout << "    ";
    setColor(100);
    GotoXY(29, 21);
    cout << "       ";
    // vẽ màu trắng thân


    //// đuôi
    setColor(0);
    GotoXY(5, 22);
    cout << "                                      ";

    setColor(119);
    GotoXY(8, 22);
    cout << "             ";

    setColor(0);
    GotoXY(5, 23);
    cout << "                                      ";

    setColor(119);
    GotoXY(9, 23);
    cout << "          ";


    setColor(0);
    GotoXY(5, 24);
    cout << "                                      ";

    setColor(119);
    GotoXY(10, 24);
    cout << "       ";

    setColor(0);
    GotoXY(7, 25);
    cout << "                                    ";

    setColor(119);
    GotoXY(11, 25);
    cout << "    ";

    setColor(0);
    GotoXY(8, 26);
    cout << "                                    ";
    setColor(0);
    GotoXY(10, 27);
    cout << "                                  ";
    // vẽ màu từ chân sau lên cổ 
    setColor(100);
    GotoXY(24, 27);
    cout << "    ";
    setColor(100);
    GotoXY(20, 26);
    cout << "  ";
    setColor(100);
    GotoXY(20, 25);
    cout << "     ";
    setColor(100);
    GotoXY(24, 24);
    cout << "   ";
    setColor(100);
    GotoXY(25, 23);
    cout << " ";
    setColor(119);
    GotoXY(32, 27);
    cout << "   ";
    setColor(119);
    GotoXY(31, 26);
    cout << "  ";
    setColor(100);
    GotoXY(28, 26);
    cout << "     ";
    setColor(100);
    GotoXY(30, 27);
    cout << "    ";
    setColor(100);
    GotoXY(27, 25);
    cout << "      ";
    setColor(100);
    GotoXY(19, 27);
    cout << "   ";
    setColor(119);
    GotoXY(41, 27);
    cout << "  ";
    setColor(119);
    GotoXY(40, 26);
    cout << "  ";
    setColor(119);
    GotoXY(38, 25);
    cout << "    ";
    setColor(119);
    GotoXY(39, 24);
    cout << "   ";
    setColor(100);
    GotoXY(35, 24);
    cout << "    ";


    setColor(0);
    GotoXY(30, 27);
    cout << "  ";
    setColor(0);
    GotoXY(30, 26);
    cout << " ";
    setColor(0);
    GotoXY(30, 25);
    cout << " ";
    setColor(119);
    GotoXY(33, 26);
    cout << "  ";
    setColor(119);
    GotoXY(32, 25);
    cout << "  ";
    setColor(100);
    GotoXY(31, 23);
    cout << "    ";
    setColor(20);
    GotoXY(33, 25);
    cout << "    ";



    // vẽ màu vùng trắng thân 





    setColor(0);
    GotoXY(15, 28);
    cout << "                              ";
    setColor(119);
    GotoXY(36, 27);
    cout << "  ";
    setColor(119);
    GotoXY(30, 28);
    cout << " ";// bàn chân 
    setColor(119);
    GotoXY(36, 28);
    cout << "    ";// bàn chân 

    SetConsoleOutputCP(437);
    setColor(112);

    // Reset màu sắc về mặc định
}

int xuLyMenu() {
    ShowBlinkingCursor(false);
    hienthimenu(); // Hiển thị menu
    return 0;
}