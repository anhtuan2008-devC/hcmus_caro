#include "Setting.h"

// Hàm vẽ thanh âm lượng
void drawVolumeBar(short volume) {
    const int barLength = 50; // Kích thước thanh âm lượng
    int volumeWidth = (volume / 1000.0) * barLength;  // Tính chiều rộng của thanh âm lượng

    GotoXY(10, 5);  // Di chuyển con trỏ đến vị trí vẽ thanh âm lượng
    cout << "Volume: [";  // In phần đầu của thanh âm lượng

    // Vẽ phần thanh âm lượng đầy (với mã ASCII 219)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  // Màu xanh lá cây
    for (int i = 0; i < volumeWidth; i++) {
        cout << char(219);  // Dùng mã ASCII 219 để vẽ thanh đầy
    }

    // Vẽ phần thanh âm lượng trống (màu xám, với mã ASCII 176)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // Màu xám
    for (int i = volumeWidth; i < barLength; i++) {
        cout << char(176);  // Dùng mã ASCII 176 cho thanh trống
    }

    cout << "] " << volume << "/1000" << endl;  // In giá trị âm lượng
}

// Hàm vẽ hướng dẫn sử dụng
void drawInstructions() {
    GotoXY(10, 8);  // Di chuyển con trỏ đến vị trí (10, 8) để hiển thị hướng dẫn
    cout << "Instructions:" << endl;
    GotoXY(10, 9);
    cout << "Press 'u' to increase volume" << endl;
    GotoXY(10, 10);
    cout << "Press 'd' to decrease volume" << endl;
    GotoXY(10, 11);
    cout << "Press 'ESC' to exit" << endl;
}

void handleVolume() {
    short volume = 500; // Giá trị âm lượng ban đầu

    while (true) {
        // Chỉ vẽ lại những phần cần thiết
        drawVolumeBar(volume);  // Vẽ lại thanh âm lượng
        drawInstructions();  // Vẽ hướng dẫn

        // Tăng giảm âm lượng bằng cách nhấn phím
        if (_kbhit()) {
            char ch = _getch();  // Đọc phím nhấn
            if (ch == 'p') {  // Nếu nhấn phím 'p'
                volume = min(volume + 50, 1000);  // Tăng âm lượng, tối đa là 1000
            }
            else if (ch == 'o') {  // Nếu nhấn phím 'o'
                volume = max(volume - 50, 0);  // Giảm âm lượng, tối thiểu là 0
            }
            else if (ch == 27) {  // Nếu nhấn phím ESC (mã ASCII là 27)
                break;  // Thoát khỏi vòng lặp
            }
        }

        Sleep(100);  // Thời gian chờ (giảm tải CPU)
    }
}
void settingScreen() {
    short volume = getVolume(); // Lấy giá trị âm lượng hiện tại từ hệ thống

    while (true) {
        // Vẽ lại thanh âm lượng và hướng dẫn
        drawVolumeBar(volume);
        drawInstructions();

        // Đọc ký tự từ người dùng
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'd' || ch == 'D') {  // Giảm âm lượng
                playSound(3, 0);
                volume = max(volume - 50, 0);  // Giới hạn dưới là 0
                setVolume(volume);  // Cập nhật lại âm lượng hệ thống
            }
            else if (ch == 'u' || ch == 'U') {  // Tăng âm lượng
                playSound(3, 0);
                volume = min(volume + 50, 1000);  // Giới hạn trên là 1000
                setVolume(volume);  // Cập nhật lại âm lượng hệ thống
            }
            else if (ch == 27) {  // Thoát
                playSound(3, 0);
                Sleep(50);
                clearScreen();
                xuLyMenu();  // Quay lại menu chính
                break;
            }
        }

        Sleep(20);  // Giảm tải CPU
    }
}
