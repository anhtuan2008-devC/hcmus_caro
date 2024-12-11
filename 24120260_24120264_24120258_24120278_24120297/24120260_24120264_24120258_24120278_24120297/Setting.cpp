#include "Setting.h"

void settingBackground() {
}

void settingText() {

}

void settingScreen() {
    settingBackground();
    settingText();
    while (1) {
        char ch = _getch(); // Đọc ký tự từ người dùng
        if (ch == 'd' or ch == 'D') {
            setVolume(getVolume() - 100);
            playSound(3, 0);
        }
        else if (ch == 'u' or ch == 'U') {
            playSound(3, 0);
            setVolume(getVolume() + 100);
        }
        else if (ch == 27) {
            playSound(3, 0);
            Sleep(50);
            clearScreen();
            xuLyMenu();
        }
        Sleep(20);
    }
}