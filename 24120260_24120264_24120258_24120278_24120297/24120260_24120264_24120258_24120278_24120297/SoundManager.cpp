#include "SoundManager.h"

// Global array to track loaded audio
bool audio_loaded[sobai] = { 0 };

// Current volume level
short volume = 400;

wstring getSongbyNum(short song) {
    switch (song) {
    case 1: return L"./Sounds/level-ii-short-236120.mp3";
    case 2: return L"./Sounds/move.mp3";
    case 3: return L"./Sounds/chose.mp3";
    case 4: return L"./Sounds/Win.mp3";
    case 5: return L"./Sounds/Draw.mp3";
    case 6: return L"./Sounds/Lose.mp3";
    default: return L"";
    }
}


short getVolume() {
    return volume;
}
void setVolume(short value) {
    value = (value > 1000) ? 1000 : (value < 0) ? 0 : value;
    volume = value;

    // Cập nhật âm lượng cho tất cả bài hát đã được tải
    for (int i = 0; i < sobai; i++) {
        if (audio_loaded[i]) {
            wstring name = getSongbyNum(i);
            mciSendString((L"setaudio " + name + L" volume to " + to_wstring(value)).c_str(), NULL, 0, NULL);
        }
    }
}

void openSound(short song) {
    if (song >= 0 && song < sobai && !audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        wstring command = L"open " + songName + L" type mpegvideo alias " + songName;
        mciSendString(command.c_str(), NULL, 0, NULL);
        audio_loaded[song] = true;
    }
}

void pauseSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"pause " + songName).c_str(), NULL, 0, NULL);
    }
}

void resumeSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"resume " + songName).c_str(), NULL, 0, NULL);
    }
}

void stopSound(short song) {
    if (song >= 0 && song < sobai) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"stop " + songName).c_str(), NULL, 0, NULL);
        mciSendString((L"close " + songName).c_str(), NULL, 0, NULL);
        audio_loaded[song] = false;
    }
}

void restartSound(short song) {
    if (song >= 0 && song < sobai && audio_loaded[song]) {
        wstring songName = getSongbyNum(song);
        mciSendString((L"seek " + songName + L" to 0").c_str(), NULL, 0, NULL);
    }
}

void playSound(short song, bool repeat) {
    if (song >= 0 && song < sobai && song != 0) {
        if (!audio_loaded[song]) {
            openSound(song);
        }

        restartSound(song);
        wstring songName = getSongbyNum(song);
        wstring command = L"play " + songName + (repeat ? L" repeat" : L"");

        mciSendString(command.c_str(), NULL, 0, NULL);
        setVolume(volume); // Ensure the volume is set after playing
    }
}
