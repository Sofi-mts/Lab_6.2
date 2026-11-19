// Лабораторна робота № 6.2 (ітераційний спосіб)
// Опрацювання одновимірних масивів
// Варіант 8
// Кучер Софія
// Написати функцію, яка міняє місцями елементи одновимірного масиву a
// із n елементів цілого типу так, щоб вони розмістилися в зворотному
// порядку: a[n], a[n-1], ..., a[2], a[1].

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

// формування масиву випадковими числами з діапазону [Low, High]
void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* a, const int size) {
    for (int i = 0; i < size; i++) cout << setw(4) << a[i];
    cout << endl;
}

// розміщення елементів масиву в зворотному порядку:
// міняємо місцями i-й елемент з i-м від кінця, доки не дійдемо до середини
void Reverse(int* a, const int size) {
    for (int i = 0; i < size / 2; i++) {
        int tmp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = tmp;
    }
}

int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел

    const int n = 15;
    int a[n];

    int Low = -50;
    int High = 50;

    Create(a, n, Low, High);
    Print(a, n);

    Reverse(a, n);
    Print(a, n);

    system("pause");    // щоб вікно не закривалося одразу
    return 0;
}
