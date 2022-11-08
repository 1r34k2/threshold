#include <iostream>

using namespace std;

class Tram{
private:
    struct tram{
        string brand;
        int year;
    }t;
    Tram* next;
public:
    Tram(){
        t.brand = "";
        t.year = 0;
        next = nullptr;
    }
    Tram(string brand, int year){
        t.brand = brand;
        t.year = year;
        next = nullptr;
    }
    ~Tram(){ next = nullptr;}
    string GetBrand(){return t.brand;}
    int GetYear(){return t.year;}
    void SetBrand(string brand){t.brand = brand;}
    void SetYear(int year){t.year = year;}
    Tram* GetNext(){return next;}
    void SetNext(Tram* next){this->next = next;}
};