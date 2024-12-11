#include "LoadGame.h"

void SaveGame() {
    // L

    GotoXY(21, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(21, 3);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(220);
    GotoXY(26, 4);
    cout << char(223) << char(219);
    GotoXY(21, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    // A
    GotoXY(30, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(29, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(29, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // V
    GotoXY(38, 2);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(39, 5);
    cout << char(223) << char(219) << char(220) << char(219) << char(223);
    //E
    GotoXY(47, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(47, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(47, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(47, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);

    //G
    GotoXY(65, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(65, 3);
    cout << char(219) << char(219) << "   " << char(223) << char(223);
    GotoXY(65, 4);
    cout << char(219) << char(219) << " " << char(223) << char(223) << char(219) << char(219);
    GotoXY(65, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    //A
    GotoXY(75, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(74, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(74, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(74, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // M
    GotoXY(83, 2);
    cout << char(219) << char(219) << char(219) << char(220) << char(219) << char(219) << char(219);
    GotoXY(83, 3);
    cout << char(219) << char(219) << char(223) << char(219) << char(223) << char(219) << char(219);
    GotoXY(83, 4);
    cout << char(219) << char(219) << " " << char(223) << " " << char(219) << char(219);
    GotoXY(83, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    //E
    GotoXY(92, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(92, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(92, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(92, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);

    int saveCount = 0;
    string filename;
    while (saveCount <= 10) {
        box(40, 11, 50, 5, "Nhap ten file de luu game:");
        GotoXY(70, 12);
        cin >> filename;
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    file << _A[i][j].c << " ";
                }
                file << "\n";
            }
            file << (_TURN ? 1 : 0) << "\n";
            file.close();
            saveCount++;
            GotoXY(65, 20);
            cout << "Game da duoc luu" << endl;
            break;
        }
        else {
            cerr << "Khong the mo file de luu!" << endl;
        }
        break;
    }
    if (saveCount > 10) {
        GotoXY(65, 23);
        cout << "Da luu qua 10 lan" << endl;
        return;
    }
}


// Load game 
void LoadGame() {

    // L
    GotoXY(22, 2);
    cout << char(219) << char(219);
    GotoXY(22, 3);
    cout << char(219) << char(219);
    GotoXY(22, 4);
    cout << char(219) << char(219);
    GotoXY(22, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);
    // o
    GotoXY(29, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(29, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(29, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    // A
    GotoXY(39, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(38, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(38, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(38, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // D
    GotoXY(47, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(219) << char(220);
    GotoXY(47, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(47, 4);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(47, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(219) << char(223);
    //G
    GotoXY(65, 2);
    cout << char(220) << char(219) << char(223) << char(223) << char(223) << char(219) << char(220);
    GotoXY(65, 3);
    cout << char(219) << char(219) << "   " << char(223) << char(223);
    GotoXY(65, 4);
    cout << char(219) << char(219) << " " << char(223) << char(223) << char(219) << char(219);
    GotoXY(65, 5);
    cout << char(223) << char(219) << char(220) << char(220) << char(220) << char(219) << char(223);
    //A
    GotoXY(75, 2);
    cout << char(220) << char(219) << char(223) << char(219) << char(220);
    GotoXY(74, 3);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    GotoXY(74, 4);
    cout << char(219) << char(219) << char(254) << char(254) << char(254) << char(219) << char(219);
    GotoXY(74, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    // M
    GotoXY(83, 2);
    cout << char(219) << char(219) << char(219) << char(220) << char(219) << char(219) << char(219);
    GotoXY(83, 3);
    cout << char(219) << char(219) << char(223) << char(219) << char(223) << char(219) << char(219);
    GotoXY(83, 4);
    cout << char(219) << char(219) << " " << char(223) << " " << char(219) << char(219);
    GotoXY(83, 5);
    cout << char(219) << char(219) << "   " << char(219) << char(219);
    //E
    GotoXY(92, 2);
    cout << char(219) << char(219) << char(223) << char(223) << char(223) << char(223);
    GotoXY(92, 3);
    cout << char(219) << char(219) << char(220) << char(220);
    GotoXY(92, 4);
    cout << char(219) << char(219) << char(223) << char(223);
    GotoXY(92, 5);
    cout << char(219) << char(219) << char(220) << char(220) << char(220) << char(220);

    int i = 10;
    string directory = ".";
    GotoXY(50, 9);
    cout << "Danh sach cac gane da luu:\n";
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (filesystem::is_regular_file(entry) && entry.path().extension().empty()) {
            GotoXY(55, i);
            cout << entry.path().stem() << endl;
            i++;
        }
    }
    box(40, 20, 45, 5, "Nhap ten file de load game:");
    // hinh 1 
    GotoXY(10, 14);
    cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
    GotoXY(9, 15);
    cout << char(219) << "      " << char(220) << char(223);
    GotoXY(8, 16);
    cout << char(219) << "     " << char(220) << char(219) << char(220) << char(220) << char(220) << char(220);
    GotoXY(7, 17);
    cout << char(219) << "           " << char(220) << char(223);
    GotoXY(8, 18);
    cout << char(223) << char(223) << char(223) << char(223) << char(220) << "    " << char(220) << char(223);
    GotoXY(11, 19);
    cout << char(220) << char(223) << "  " << char(220) << char(223);
    GotoXY(10, 20);
    cout << char(220) << char(223) << " " << char(220) << char(223);
    GotoXY(11, 21);
    cout << char(223) << char(223);
    // hinh 2 
    GotoXY(95, 13);
    cout << char(220) << char(223) << char(223) << char(223) << char(223) << char(220) << char(220) << char(220) << char(220) << char(223) << char(223) << char(223) << char(223) << char(220);
    GotoXY(93, 14);
    cout << char(220) << char(223) << "              " << char(223) << char(220);
    GotoXY(93, 15);
    cout << char(219) << "                " << char(219);
    GotoXY(93, 16);
    cout << char(219) << "     " << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << "     " << char(219);
    GotoXY(94, 17);
    cout << char(223) << char(220) << char(220) << char(220) << char(223) << "      " << char(223) << char(220) << char(220) << char(220) << char(223);
    GotoXY(96, 15);
    cout << char(223) << char(219) << char(223) << " " << char(223) << "  " << char(223) << " " << char(223) << char(220) << char(223);
    GotoXY(97, 14);
    cout << char(220) << "        " << char(220);
    // hinh 1
    setColor(6);
    GotoXY(10, 15);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(9, 16);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(8, 17);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(223) << char(223);
    GotoXY(11, 18);
    cout << char(223) << char(223) << char(219) << char(219) << char(219) << char(219) << char(223);
    GotoXY(12, 19);
    cout << char(220) << char(219) << char(219) << char(223);
    GotoXY(11, 20);
    cout << char(220) << char(219) << char(223);
    string filename;
    char key;
    setColor(117);
    GotoXY(72, 21);

    filename = ""; // Xóa chuỗi filename trước mỗi lần nhập
    while (true) {
        key = _getch(); // Nhận phím từ người dùng

        if (key == 27) { // Nếu phím Esc được nhấn
            playSound(3, 0);
            clearScreen();
            xuLyMenu(); // Quay về Menu
        }
        else if (key == '\r') { // Nếu phím Enter được nhấn
            if (!filename.empty()) { // Chỉ xử lý nếu người dùng đã nhập gì đó
                break; // Thoát vòng lặp nhập filename
            }
        }
        else if (key == '\b') { // Nếu phím Backspace được nhấn
            if (!filename.empty()) {
                filename.pop_back(); // Xóa ký tự cuối cùng
                cout << "\b \b";    // Xóa trên màn hình
            }
        }
        else {
            filename += key; // Thêm ký tự vừa nhập vào filename
            cout << key;     // Hiển thị ký tự ra màn hình
        }
    }

    clearScreen();
    ifstream file(filename);
    if (file.is_open()) {
        ShowBlinkingCursor(true);
        system("color 70");
        fixConsoleWindow();
        ResetData();
        vienPlayer();
        DrawBoard(BOARD_SIZE);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int value;
                file >> value;
                if (value == -1) {
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    printf("%c", X());
                }
                if (value == 1) {
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    printf("%c", O());
                }

            }
        }
        int turn;
        file >> turn;
        _TURN = (turn == 1);

        file.close();

        bool validEnter = true;
        while (true) {
            char command = getInput();
            if (command) {
                command = toupper(command);
                if (command == 27) {
                    playSound(3, 0);
                    ExitGame();
                    break;
                }
                else {
                    if (command == 'A') {
                        MoveLeft();
                    }
                    else if (command == 'W') MoveUp();
                    else if (command == 'S') MoveDown();
                    else if (command == 'D') MoveRight();
                    else if (command == 13) {
                        switch (CheckBoard(_X, _Y)) {
                        case -1:
                            break;
                        case 1:
                            break;
                        case 0:
                            validEnter = false;
                            break;
                        }
                        if (validEnter) {
                            switch (ProcessFinish(TestBoard())) {
                            case -1: case 1: case 0:
                                if (AskContinue() != 'Y') {
                                    ExitGame();
                                    break;
                                }
                                else {
                                    StartGame();
                                    break;
                                }
                            }
                        }
                        validEnter = true;
                    }
                    else if (command == 'L') {
                        clearScreen();
                        SaveGame();
                        clearScreen();
                        break;
                    }
                }
            }
            Sleep(100);
        }

    }
    else {
        cerr << "Khong the mo file de load!" << endl;
        LoadGame();
    }
}
