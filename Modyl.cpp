#include <iostream>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::string

// Функция для отображения игрового поля
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) {
                cout << " | "; // Разделитель между клетками
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---------"; // Разделитель между строками
            cout << endl;
        }
    }
    cout << endl; // Дополнительный отступ после отображения поля
}

// Функция для проверки победителя
char checkWinner(char board[SIZE][SIZE]) {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

// Функция для проверки, заполнено ли поле
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Функция для проверки, является ли строка числом
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}