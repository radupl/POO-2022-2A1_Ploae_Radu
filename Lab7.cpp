#include <iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long int k) {
    return k - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int f) {
    return (f - 32) * ((float)5 / 9);
}

template <class T>
class Stack{

    T List[100];
    int count;

public:

    Stack() { count = 0; memset(List, 0, sizeof(List)); }
    void Push(T value) { List[count++] = value; }
    T Pop() { return List[--count]; }

    void show() {
        for (int i = 0; i < count; i++)
            cout << List[i] << " ";
        cout << endl;
    }

    void remove(int index) {

        for (int i = index; i < count; i++)
            List[i] = List[i + 1];
        count--;
    }

    void insert(T el, int index) {

        if (index > count) {
            List[count] = el;
            count++;
            return;
        }
        for (int i = count; i >= index; i--)
            List[i] = List[i - 1];
        List[index] = el;
        count++;
    }
};

int main() {

    Stack<double> s;
    s.Push(1); s.Push(2); s.Push(3); s.Push(4); s.Push(5); s.Push(6);
    s.show();
    s.Pop();
    s.show();
    s.remove(2);
    s.show();
    s.insert(3.37, 2); //elementul 3.37 pe pozitia 2
    s.show();
/*
    Output:
    1 2 3 4 5 6
    1 2 3 4 5
    1 2 4 5
    1 2 3.37 4 5
*/

    /*float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << endl;
    cout << b; */

    return 0;
}

