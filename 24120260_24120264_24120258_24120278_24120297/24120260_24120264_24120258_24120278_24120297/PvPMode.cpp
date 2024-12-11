#include "PvPMode.h"

void gameBackground() {
    SetConsoleOutputCP(CP_UTF8);
    setColor(116);
    /*GotoXY(_A[0][0].x + 49,_A[0][0].y);
    cout << "           ⠀⠀⠔⠶⠒⠉⠈⠸";
    GotoXY(_A[0][0].x + 49, _A[0][0].y);

    cout << u8R"(⠀⠀⠀
⠀                                                          ⠀⠀⠀⠀⠔⠶⠒⠉⠈⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                                                           ⠀⠀⠀⠀⠪⣦⢄⣀⡠⠁⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣤⣤⣤⣄⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀
                                       ⠀⠀⠀                   ⠀⠀⠀⠀⠈⠉⠀⠀⠀⣰⣶⣶⣦⠶⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠉⠉⢷⡔⠒⠚⢽⠃⠀⠀⠀⠀
                                                          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣰⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢅⢰⣾⠀⠀⠀⠀⠀
                                                          ⠀⠀⠀⠀⠀⠀⣀⡴⠞⠛⠉⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣧⠀⠀⠀⠀⠀
⠀                                                          ⣀⣀⣤⣤⡞⠋⠀⠀⠀⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠀
                                                          ⢸⡏⠉⣴⠏⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀
                                                          ⠈⣧⢰⠏⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠰⠯⠥⠠⠒⠄⠀⠀⠀⠀⠀⠀⢠⠀⣿⠀⠀⠀⠀
⠀                                                          ⠈⣿⠀⠀⠀⠀⠀⠀⠀⠈⡧⢀⢻⠿⠀⠲⡟⣞⠀⠀⠀⠀⠈⠀⠁⠀⠀⠀⠀⠀⢀⠆⣰⠇⠀⠀⠀⠀
⠀                                                          ⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⣧⡀⠃⠀⠀⠀⠱⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣂⡴⠋⠀⣀⡀⠀⠀
⠀                                                          ⠀⢹⡄⠀⠀⠀⠀⠀⠀⠀⠹⣜⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠒⠿⡻⢦⣄⣰⠏⣿⠀⠀
⠀                                                          ⠀⠀⢿⡢⡀⠀⠀⠀⠀⠀⠀⠙⠳⢮⣥⣤⣤⠶⠖⠒⠛⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢌⢻⣴⠏⠀⠀
⠀                                                          ⠀⠀⠀⠻⣮⣒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⣤⣀⣀⣀⣤⡴⠖⠛⢻⡆⠀⠀⠀⠀⠀⠀⢣⢻⡄⠀⠀
⠀                                                          ⠀⠀⠀⠀⠀⠉⠛⠒⠶⠶⡶⢶⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠞⠁⠀⠀⠀⠀⠀⠀⠈⢜⢧⣄⠀
⠀                                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃⠇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠉⢻⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠉⠈⣷
⠀                                                       ⠀⠀⠀⠀⠀⠀⣼⠟⠷⣿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠲⠶⢶⣶⠶⠶⢛⣻⠏⠙⠛⠛⠛⠁
⠀                                                       ⠀⠀⠀⠀⠀⠀⠈⠷⣤⣀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠉⠛⠓⠚⠋⠀⠀⠀⠀⠀⠀
⠀                                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣟⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀                                                     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⡟⡟⢻⡟⠛⢻⡄⠀⠀⣸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀                                                     ⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠈⠷⠧⠾⠀⠀⠀⠻⣦⡴⠏⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)";*/
    GotoXY(0, 20);
    cout << u8R"(                                                                                                                        
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣦⣴⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣀⣀⣀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠿⠟⠛⠛⠋⠉⠉⠉⠉⠉⠉⠛⠛⠛⠿⢷⣦⣤⣀⡹⠿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣴⣶⣶⣾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣿⣿⣶⣶⣶⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣴⣿⠟⠉⠀⠀⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠟⠀⠀⠀⠉⠙⢿⣦⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢦⣽⣿⡄⠀⠀⠀⠀⠀
⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣷⠀⠀⠀⠀⠀
⠀⠀⢰⣿⡏⣤⠀⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣻⡀⠀⠀⢤⢠⣼⣿⡆⠀⠀⠀⠀
⠀⠀⠀⢿⣿⠁⠀⠀⠀⠀⣴⡾⠁⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣀⠀⠀⠀⠀⠀⠈⢻⣇⠀⠀⠈⣇⣿⣿⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣿⠀⡀⣀⠀⢠⣿⠃⠀⠀⢀⣾⣿⣿⡿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡷⠀⠀⠀⠀⠀⢸⣿⠀⢠⣠⣿⣿⠇⠀⠀⠀⠀⠀
⠀⠀⠀⠈⢿⣷⣇⣽⠀⢈⡏⠀⠀⠀⠸⣿⣿⣿⣦⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣧⣤⠥⠀⠀⠀⠀⣿⣿⣧⣾⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠛⠿⣿⣧⣾⣿⡄⠀⠀⠀⠙⠿⠿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠛⠋⠀⠀⠀⠀⠀⢸⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⣿⡇⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢶⣼⣿⣀⣠⣤⣤⣤⣀⠀⠀⠀⠀⠀
⠀⠀⣠⣶⣾⠿⠛⠛⠻⢷⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⡿⠋⠉⠉⠉⠛⢿⣦⡀⠀⠀
⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠙⣿⡆⢀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣿⡟⠀⠀⠀⠀⠀⠀⠀⠹⣿⡆⠀
⣼⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣸⣷⣿⣷⣧⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⠀⢠⡾⣠⣇⣠⣿⣿⣿⡇⠀⢀⠀⠀⠀⢀⠀⠀⢹⣷⠀
⣿⣷⡀⠀⣷⠀⠀⠀⣼⣦⣴⣿⠏⠙⠻⠿⣷⡿⠷⣶⣶⡾⠿⠿⠷⢶⣶⣦⣤⣾⣿⣷⣿⣿⠿⠿⠛⠛⠙⠻⣿⣤⣾⣇⠀⢀⣸⣇⣀⣼⣿⠃
⠘⢿⣿⣾⣿⣷⣴⣾⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠻⠿⠿⠿⠟⠛⠛⠁⠀                                                           
)";
    /* setColor(125);*/
     /*GotoXY(0, 13);
     cout << u8R"(
 ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣴⣶⣶⣾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣿⣿⣶⣶⣶⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⠀⣴⣿⠟⠉⠀⠀⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠟⠀⠀⠀⠉⠙⢿⣦⠀⠀⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⣠⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢦⣽⣿⡄⠀⠀⠀⠀⠀
 ⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣷⠀⠀⠀⠀⠀
 ⠀⠀⢰⣿⡏⣤⠀⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣻⡀⠀⠀⢤⢠⣼⣿⡆⠀⠀⠀⠀
 )";*/
    GotoXY(0, 13);
    SetConsoleOutputCP(437);
    setColor(112);
}
void vienPlayer() {
    // Viền X
    BOX(18, 17, 16, 8);
    // Viền O
    BOX(89, 17, 16, 8);
    GotoXY(_A[0][0].x + 49, _A[0][0].y + 11);
    turnPlayer();   // Cập nhật giao diện theo lượt
    playSound(3, 0);
}

void turnPlayer() {
    if (!_TURN) {
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(20, 17);
        cout << u8" ██╗  ██╗";
        GotoXY(20, 18);
        cout << u8" ╚██╗██╔╝  ";
        GotoXY(20, 19);
        cout << u8"  ╚███╔╝ ";
        GotoXY(20, 20);
        cout << u8"  ██╔██╗ ";
        GotoXY(20, 21);
        cout << u8" ██╔╝ ██╗";
        GotoXY(20, 22);
        cout << u8" ╚═╝  ╚═╝";
        SetConsoleOutputCP(437);

        // An O
        SetConsoleOutputCP(CP_UTF8);
        setColor(120);
        GotoXY(91, 17);
        cout << u8"  ██████╗ ";
        GotoXY(91, 18);
        cout << u8" ██╔═══██╗";
        GotoXY(91, 19);
        cout << u8" ██║   ██║";
        GotoXY(91, 20);
        cout << u8" ██║   ██║";
        GotoXY(91, 21);
        cout << u8" ╚██████╔╝";
        GotoXY(91, 22);
        cout << u8"  ╚═════╝";
        SetConsoleOutputCP(437);
    }
    else {
        // An X
        SetConsoleOutputCP(CP_UTF8);
        setColor(120);
        GotoXY(20, 17);
        cout << u8" ██╗  ██╗";
        GotoXY(20, 18);
        cout << u8" ╚██╗██╔╝  ";
        GotoXY(20, 19);
        cout << u8"  ╚███╔╝ ";
        GotoXY(20, 20);
        cout << u8"  ██╔██╗ ";
        GotoXY(20, 21);
        cout << u8" ██╔╝ ██╗";
        GotoXY(20, 22);
        cout << u8" ╚═╝  ╚═╝";
        SetConsoleOutputCP(437);
        // Hien thi O
        SetConsoleOutputCP(CP_UTF8);
        setColor(121);
        GotoXY(91, 17);
        cout << u8"  ██████╗ ";
        GotoXY(91, 18);
        cout << u8" ██╔═══██╗";
        GotoXY(91, 19);
        cout << u8" ██║   ██║";
        GotoXY(91, 20);
        cout << u8" ██║   ██║";
        GotoXY(91, 21);
        cout << u8" ╚██████╔╝";
        GotoXY(91, 22);
        cout << u8"  ╚═════╝";
        SetConsoleOutputCP(437);
    }
    setColor(112);
}

void gameText() {
    // Viet chu
        //X
    setColor(120);
    GotoXY(22, 25);
    cout << "W - up";
    GotoXY(22, 26);
    cout << "S - down";
    GotoXY(22, 27);
    cout << "A - left";
    GotoXY(22, 28);
    cout << "D - right";
    GotoXY(18, 29);
    cout << "Space - tick";
        
        //O
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(93, 25);
    cout << u8"⭡ - up";
    GotoXY(93, 26);
    cout << u8"⭣ - down";
    GotoXY(93, 27);
    cout << u8"⭠ - left";
    GotoXY(93, 28);
    cout << u8"⭢ - right";
    GotoXY(89, 29);
    cout << "Enter - tick";
    SetConsoleOutputCP(437);

    // To mau chu
        // X
    setColor(124);
    GotoXY(22, 25);
    cout << "W";
    GotoXY(22, 26);
    cout << "S";
    GotoXY(22, 26);
    cout << "S";
    GotoXY(22, 27);
    cout << "A";
    GotoXY(22, 28);
    cout << "D";
    GotoXY(18, 29);
    cout << "Space";
        // O
    setColor(121);
    SetConsoleOutputCP(CP_UTF8);
    GotoXY(93, 25);
    cout << u8"⭡";
    GotoXY(93, 26);
    cout << u8"⭣";
    GotoXY(93, 27);
    cout << u8"⭠";
    GotoXY(93, 28);
    cout << u8"⭢";
    GotoXY(89, 29);
    cout << "Enter";
    SetConsoleOutputCP(437);
         // khac
    setColor(132);
    GotoXY(55, 29);
    cout << "Esc - pause";
    setColor(112);
}
// Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin) {
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí thích hợp
    switch (pWhoWin) {
    case -1:
        Sleep(1100);
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(57, 0);
        cout << u8R"(
                                          ██╗  ██╗    ██╗    ██╗██╗███╗   ██╗██╗                             
                                          ╚██╗██╔╝    ██║    ██║██║████╗  ██║██║                           
                                           ╚███╔╝     ██║ █╗ ██║██║██╔██╗ ██║██║                       
                                           ██╔██╗     ██║███╗██║██║██║╚██╗██║╚═╝                       
                                          ██╔╝ ██╗    ╚███╔███╔╝██║██║ ╚████║██╗                            
                                          ╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝                                            )";
        break;
    case 1:
        Sleep(1100);
        SetConsoleOutputCP(CP_UTF8);
        setColor(121);
        GotoXY(57, 0);
        cout << u8R"(
                                          ██████╗     ██╗    ██╗██╗███╗   ██╗██╗                                     
                                         ██╔═══██╗    ██║    ██║██║████╗  ██║██║                                  
                                         ██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║██║                                
                                         ██║   ██║    ██║███╗██║██║██║╚██╗██║╚═╝                                  
                                         ╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║██╗                                   
                                          ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝                                           )";
        break;
    case 0:
        Sleep(1100);
        SetConsoleOutputCP(CP_UTF8);
        setColor(122);
        GotoXY(57, 0);
        cout << u8R"(
                                         ██████╗ ██████╗  █████╗ ██╗    ██╗██╗                                           
                                         ██╔══██╗██╔══██╗██╔══██╗██║    ██║██║                                            
                                         ██║  ██║██████╔╝███████║██║ █╗ ██║██║                                           
                                         ██║  ██║██╔══██╗██╔══██║██║███╗██║╚═╝                                            
                                         ██████╔╝██║  ██║██║  ██║╚███╔███╔╝██╗                                          
                                         ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝                                            )";
        break;
    case 2:
        _TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
        break;
    }
    GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
    SetConsoleOutputCP(437);
    return pWhoWin;
}

int AskContinue() {
    setColor(112);
    box(45, 10, 33, 3, " ");
    GotoXY(46, 10);
    printf("Press Y/N to Play Again/Back"); // Nhập Y để chơi tiếp hoặc nhập N để quay về Menu
    char response = _getch();
    return toupper(response);
}

int PlayWithPlayer() {
    ShowBlinkingCursor(true);
    system("color 70");
    StartGame();
    vienPlayer();
    gameText();
    GotoXY(_A[0][0].x + 1, _A[0][0].y);
    bool validEnter = true;
    while (true) {
        char command = getInput(); // Lấy đầu vào từ phím
        if (command) {
            command = toupper(command);
            if (command == 27) { // ESC để thoát
                playSound(3, 0);
                Sleep(10);
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
                else if (command == 13) { // Nhấn Enter để đánh dấu
                    switch (CheckBoard(_X, _Y)) {
                    case -1:
                        playSound(3, 0);
                        vienPlayer();
                        moveCount(-1);
                        break; // Quân X đã được vẽ
                    case 1:
                        playSound(3, 0);
                        vienPlayer();
                        moveCount(1);
                        break; // Quân O đã được vẽ
                    case 0:
                        validEnter = false; // Ô đã được đánh dấu
                        break;
                    }
                    if (validEnter) {
                        switch (ProcessFinish(TestBoard())) {
                        case -1: case 1: case 0:
                            if (AskContinue() != 'Y') {
                                playSound(3, 0);
                                ExitGame();
                                return 0;
                            }
                            else if(AskContinue() != 'N') {
                                continueGame();
                                vienPlayer();
                                gameText();
                                GotoXY(_A[0][0].x, _A[0][0].y);
                                break;
                            }
                            else {
                                break;
                            }
                        default:
                                break;
                        }
                    }
                    validEnter = true; // Mở khóa
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