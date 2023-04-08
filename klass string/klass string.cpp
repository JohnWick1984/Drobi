// klass string.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
class String 
{
public:
    static int getCount() { return count; }

    String() : String(80) {}
    String(int size) : length(size) { data = new char[size]; count++; }
    String(const char* str) : String(strlen(str)) 
    {
        memcpy(data, str, length);
    }

    ~String() { delete[] data; count--; }

    void input() 
    {
        cin.getline(data, length);
    }

    void output() const
    {
        cout << data << endl;
    }

private:
    static int count;
    char* data;
    int length;
};

int String::count = 0;

int main() 
{
    String s1; 
    s1.input(); 
    s1.output(); 

    String s2(50); 
    s2.input();
    s2.output();

    String s3("Привет!"); 
    s3.output();

    cout << "Количество созданных строк: " << String::getCount() << endl;

    return 0;
}
