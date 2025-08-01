#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) break;
        cout << "Błąd: podaj liczbę.\n";
        clearInput();
    }
    return value;
}

int getInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) break;
        cout << "Błąd: podaj liczbę całkowitą.\n";
        clearInput();
    }
    return value;
}

void showMenu() {
    cout << "\n========== KALKULATOR ==========\n";
    cout << "1. Dodawanie\n";
    cout << "2. Odejmowanie\n";
    cout << "3. Mnożenie\n";
    cout << "4. Dzielenie\n";
    cout << "5. Potęgowanie\n";
    cout << "6. Pierwiastkowanie\n";
    cout << "7. Silnia\n";
    cout << "8. Logarytm dziesiętny\n";
    cout << "9. Sinus\n";
    cout << "10. Cosinus\n";
    cout << "11. Tangens\n";
    cout << "12. Wyjście\n";
    cout << "===============================\n";
}

double factorial(int n) {
    if (n < 0) return nan("");
    double result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

int main() {
    int choice;

    do {
        showMenu();
        choice = getInt("Wybierz operację (1-12): ");

        switch (choice) {
            case 1: {
                double a = getNumber("Podaj pierwszą liczbę: ");
                double b = getNumber("Podaj drugą liczbę: ");
                cout << "Wynik: " << a + b << endl;
                break;
            }
            case 2: {
                double a = getNumber("Podaj pierwszą liczbę: ");
                double b = getNumber("Podaj drugą liczbę: ");
                cout << "Wynik: " << a - b << endl;
                break;
            }
            case 3: {
                double a = getNumber("Podaj pierwszą liczbę: ");
                double b = getNumber("Podaj drugą liczbę: ");
                cout << "Wynik: " << a * b << endl;
                break;
            }
            case 4: {
                double a = getNumber("Podaj dzielną: ");
                double b;
                do {
                    b = getNumber("Podaj dzielnik (≠ 0): ");
                    if (b == 0) cout << "Dzielenie przez 0 jest niedozwolone.\n";
                } while (b == 0);
                cout << "Wynik: " << a / b << endl;
                break;
            }
            case 5: {
                double base = getNumber("Podaj podstawę: ");
                double exp = getNumber("Podaj wykładnik: ");
                cout << "Wynik: " << pow(base, exp) << endl;
                break;
            }
            case 6: {
                double a;
                do {
                    a = getNumber("Podaj liczbę do pierwiastkowania (≥ 0): ");
                    if (a < 0) cout << "Nie można pierwiastkować liczby ujemnej.\n";
                } while (a < 0);
                cout << "Wynik: " << sqrt(a) << endl;
                break;
            }
            case 7: {
                int n = getInt("Podaj liczbę całkowitą ≥ 0: ");
                if (n < 0) {
                    cout << "Silnia z liczby ujemnej nie istnieje.\n";
                } else {
                    cout << "Wynik: " << factorial(n) << endl;
                }
                break;
            }
            case 8: {
                double x;
                do {
                    x = getNumber("Podaj liczbę dodatnią: ");
                    if (x <= 0) cout << "Logarytm działa tylko na liczbach dodatnich.\n";
                } while (x <= 0);
                cout << "Wynik: " << log10(x) << endl;
                break;
            }
            case 9: {
                double deg = getNumber("Podaj kąt w stopniach: ");
                cout << "Wynik: " << sin(deg * M_PI / 180.0) << endl;
                break;
            }
            case 10: {
                double deg = getNumber("Podaj kąt w stopniach: ");
                cout << "Wynik: " << cos(deg * M_PI / 180.0) << endl;
                break;
            }
            case 11: {
                double deg = getNumber("Podaj kąt w stopniach: ");
                cout << "Wynik: " << tan(deg * M_PI / 180.0) << endl;
                break;
            }
            case 12:
                cout << "Zamykanie kalkulatora...\n";
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }

    } while (choice != 12);

    return 0;
}