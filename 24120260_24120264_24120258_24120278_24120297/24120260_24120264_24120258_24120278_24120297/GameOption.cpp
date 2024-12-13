﻿#include "GameOption.h"

void PorEBackground() {
    SetConsoleOutputCP(CP_UTF8);
    printAsciiArt("PorEBg.txt", 0, 1);
    setColor(Green);
    printAsciiArt("Dog.txt", 68, 0);
    setColor(Yellow);
    printAsciiArt("Magic.txt", 38, 2);
    setColor(Blue2);
    printAsciiArt("Woof.txt", 45, 21);
    setColor(Pink);
    printAsciiArt("Meow.txt", 70, 25);
    SetConsoleOutputCP(437);
    setColor(Red);
    GotoXY(64, 26);
    cout << "VS";
}

void BackChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt("Clear.txt", 78, 0);
    veconmeo(78, 5);
    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);
}

void PvPChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt("Clear.txt", 78, 0);
    setColor(Black);
    printAsciiArt("PvP.txt", 80, 5);
    setColor(White);
    GotoXY(112, 18);
    cout << u8"▒▒";
    GotoXY(113, 19);
    cout << u8"▒";
    GotoXY(113, 20);
    cout << u8"▒▒";
    GotoXY(113, 21);
    cout << u8"▒▒";
    GotoXY(113, 22);
    cout << u8"▒▒";
    GotoXY(113, 23);
    cout << u8"▒▒";
    setColor(Yellow2);
    GotoXY(85, 12);
    cout << u8"▒▒▒▒▒▒▒▒";
    GotoXY(90, 13);
    cout << u8"▒▒▒";
    GotoXY(90, 14);
    cout << u8"▒▒▒▒";
    GotoXY(84, 13);
    cout << u8"▒";
    GotoXY(84, 14);
    cout << u8"▒";
    GotoXY(84, 15);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(93, 15);
    cout << u8"▒▒▒▒▒";
    GotoXY(84, 16);
    cout << u8"▒▒▒▒▒▒▒";
    GotoXY(92, 16);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(84, 17);
    cout << u8"▒▒▒▒▒▒";
    GotoXY(85, 13);
    cout << u8"▓";
    GotoXY(89, 13);
    cout << u8"▓";
    GotoXY(93, 13);
    cout << u8"▓▓";
    GotoXY(85, 14);
    cout << u8"▓";
    GotoXY(89, 14);
    cout << u8"▓";
    GotoXY(94, 14);
    cout << u8"▓";
    GotoXY(98, 14);
    cout << u8"▓";
    GotoXY(98, 15);
    cout << u8"▓▓";
    GotoXY(98, 16);
    cout << u8"▓▓";
    GotoXY(90, 17);
    cout << u8"▓";
    GotoXY(92, 17);
    cout << u8"▓▓▓▓▓▓▓▓▓▓▓";
    GotoXY(89, 18);
    cout << u8"▓▓▓▓▓▓▓▓▓";
    setColor(Red2);
    GotoXY(90, 15);
    cout << u8"▒▒▒▒";
    GotoXY(91, 16);
    cout << u8"▓";
    GotoXY(91, 17);
    cout << u8"▓";
    setColor(Yellow);
    GotoXY(80, 22);
    cout << u8"███";
    GotoXY(86, 21);
    cout << u8"██";
    GotoXY(88, 20);
    cout << u8"███████";
    GotoXY(95, 19);
    cout << u8"██████";
    GotoXY(101, 18);
    cout << u8"███████";
    GotoXY(108, 17);
    cout << u8"████";
    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);
}

void PvEChar() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(White);
    printAsciiArt("Clear.txt", 78, 0);
    setColor(Pink2);
    printAsciiArt("PvE.txt", 80, 3);

    SetConsoleOutputCP(437);
    setColor(Black);
    GotoXY(0, 0);
}
void boxPvP() {
    BOX(50, 7, 26, 5);
    GotoXY(54, 8);
    cout << "Player VS Player";
}

void boxPvE() {
    BOX(50, 12, 26, 5);
    GotoXY(52, 13);
    cout << "Player VS Environment";
}

void boxBack() {
    BOX(50, 17, 26, 5);
    GotoXY(60, 18);
    cout << "Back";
}
void gameOptionScreen() {
    fixConsoleWindow();
    PorEBackground();
    boxPvP();
    boxPvE();
    boxBack();
    int selection = 0, previousSelection = -1;
    while (true) {
        // Đổi màu và thực thi hành động dựa trên lựa chọn
        if (selection != previousSelection) {
            // Chỉ vẽ lại nếu có thay đổi
            for (int i = 0; i < 3; i++) {
                setColor(i == selection ? 124 : Black);
                if (i == 0) boxPvP();
                else if (i == 1) boxPvE();
                else boxBack();
            }
            previousSelection = selection;
        }

        // Thực thi hành động theo lựa chọn
        switch (selection) {
        case 0:
            PvPChar();
            break;
        case 1:
            PvEChar();
            break;
        case 2:
            BackChar();
            break;
        }

        Sleep(20);

        char ch = _getch(); // Đọc ký tự từ người dùng

        if (ch == 27) { // Phím Escape để thoát
            playSound(3, 0);
            clearScreen();
            menuScreen();
            break;
        }
        playSound(2, 0);
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                playSound(3, 0);
                clearScreen();
                PlayWithPlayer();
                break;
            case 1:
                playSound(3, 0);
                clearScreen();
                PlayWithBot();
                break;
            case 2:
                playSound(3, 0);
                clearScreen();
                menuScreen();
                break;
            }
        }
        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi ten len (ASCII 72)
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 2) {
                selection++;
            }
        }
    }
}
void veconmeo(int x, int y) {
    // Khai báo mảng 12x14 với các giá trị đã cho
    int matrix[38][41] = {
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 0, 15, 15, 0, 12, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 0, 0, 0, 0, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 12, 0, 0, 0, 0, 12, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 0, 12, 0, 14, 14, 0, 12, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 12, 15, 15, 15, 15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 12, 0, 0, 0, 0, 12, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 0, 15, 15, 0, 12, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 0, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 12, 12, 12, 12, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 12, 12, 12, 12, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 15, 15, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 12, 12, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 0, 0, 0, 0, 15, 15 },
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 12, 0, 0, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 0, 0, 12, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15,15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15,15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 6, 6, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15,15, 15},
        {15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 6, 6, 6, 6, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15,15},
        {15, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 0, 15, 0, 15, 15, 6, 6, 6, 6, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15},
        {0, 0, 0, 12, 12, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 0, 15, 15, 15, 6, 6, 6, 6, 15, 15, 0, 15, 0, 15, 15, 15, 0, 15, 15, 15},
        {0, 0, 0, 12, 12, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 15, 15, 15, 15, 15, 15, 6, 6, 6, 6, 15, 15, 15, 0, 15, 15, 15, 15, 0, 0, 15, 15},
        {0, 0, 0, 12, 12, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 6, 6, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15},
        {15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15},
        {15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 15, 15, 0, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 12, 12, 12, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 12, 12, 15, 15, 0, 15, 15},
        {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 15}
    };

    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < 38; i = i + 2)
    {
        GotoXY(x, y + i / 2);
        for (int x = 0; x < 41; x++)
        {
            SSetColor(matrix[i][x], matrix[i + 1][x]);
            cout << u8"▄";
        }cout << endl;
    }
    SetConsoleOutputCP(437);
}