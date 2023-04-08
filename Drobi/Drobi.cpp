// Drobi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {}

    void input_fraction()
    {
        cout << "Введите числитель: ";
        cin >> numerator;
        cout << "Введите знаменатель: ";
        cin >> denominator;
    }

    int gcd(int a, int b)
    {
        if (b == 0) 
        {
            return a;
        }
        else 
        {
            return gcd(b, a % b);
        }
    }

    void simplify_fraction() 
    {
        int gcd_num = gcd(numerator, denominator);
        numerator /= gcd_num;
        denominator /= gcd_num;
    }

    Fraction operator+(const Fraction& other) 
    {
        Fraction result(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
        result.simplify_fraction();
        return result;
    }

    Fraction operator-(const Fraction& other) 
    {
        Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
        result.simplify_fraction();
        return result;
    }

    Fraction operator*(const Fraction& other) 
    {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        result.simplify_fraction();
        return result;
    }

    Fraction operator/(const Fraction& other) 
    {
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        result.simplify_fraction();
        return result;
    }

    void print_fraction()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction a, b, c, d, e;

    a.input_fraction();
    b.input_fraction();

    c = a + b;
    d = a - b;
    e = a * b;

    cout << "a + b = ";
    c.print_fraction();

    cout << "a - b = ";
    d.print_fraction();

    cout << "a * b = ";
    e.print_fraction();

    cout << "a / b = ";
    (a / b).print_fraction();

    return 0;
}
