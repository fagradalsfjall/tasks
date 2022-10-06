#include <iostream>
#include "bow.hpp"

using namespace std;

int Bow::bow_count=0;

 Bow::Bow(int tension_, std::string type_, float base_, bool shelf_) {    
        type = type_;
        base = base_;
        shelf = shelf_;
        koefficient = tension_/(ref_expansion - base);
        bow_count++;
    }

 Bow::~Bow(){
        bow_count--;
        cout << "закончили, собираем, собираемся, луков осталось " << bow_count << endl;
    } 

bool operator== (const Bow& bow1, const Bow& bow2) {       
    return bow1.koefficient == bow2.koefficient && bow1.type == bow2.type && bow1.base == bow2.base && bow1.shelf == bow2.shelf;
}

float Bow::tension(float real_expansion) {            
        return tension(koefficient, base, real_expansion);
    }

float Bow::tension(float koefficient, float base, float real_expansion) {    
        float result = koefficient * (real_expansion - base);
        
        return result;
    }

float Bow::tension() {
        float result = tension(ref_expansion);
        return result;
    }

Bow::Bow(const Bow& another) {        
        koefficient = another.koefficient;
        type = another.type;
        base = another.base;
        shelf = another.shelf;
    }

 float Bow::operator() (float a) {
        return tension(a);
    }

    
int main()
{ 

    float tension_2 = 19;
    float tension_3 = 22;
    std::string snake = string("snake");
    Bow snake18_1 = Bow(18, snake, 16, true);
    Bow snake18_2 = Bow(18, "snake", 16, true);
    Bow wooden = Bow(22, "long", 18, false);
    
    if (snake18_1 == snake18_2) {        
        cout << "луки одинаковые" << endl;    
    } else {
        cout << "луки разные" << endl;
    }
    
    cout << "snake18_1.tension(76): " << snake18_1.tension(76) << std::endl;

    cout << "snake18_1(66): " << snake18_1(66) << endl;
    cout << "snake18_1(): " << snake18_1() << endl;

    cout << "wooden.tension(): " << wooden.tension() << endl;
    cout << "Static tension(): " << Bow::tension(1, 15, 76) << endl;

    return 0;
}
