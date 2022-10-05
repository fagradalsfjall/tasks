#include <iostream>

using namespace std;

struct Bow {
    
    float koefficient; //коэффициент, определяющий натяжение лука
    string type; //тип лука
    float base; //база - расстояние от тетивы до внутренней части рукоятки
    bool shelf; //наличие полочки для стрелы
        
    static constexpr float ref_expansion = 76;
    Bow(int tension_, string type_, float base_, bool shelf_) {    
        type = type_;
        base = base_;
        shelf = shelf_;
        koefficient = tension_/(ref_expansion - base);
    }
    
    ~Bow() {
        cout << "закончили, собираем, собираемся" << endl; //команды к окончанию стрельбы и тренировки
    }
    
    float tension(float real_expansion) {    
        float result = koefficient*(real_expansion - base);
        
        return result;
    }

    float tension() {
        float result = tension(ref_expansion);
        return result;
    }
    
    Bow(const Bow& another) {        
        koefficient = another.koefficient;
        type = another.type;
        base = another.base;
        shelf = another.shelf;
    }
    
    float operator() (float a=ref_expansion) {
        return tension(a);
    }

};

bool operator== (const Bow& bow1, const Bow& bow2) {       
    return bow1.koefficient == bow2.koefficient && bow1.type == bow2.type && bow1.base == bow2.base && bow1.shelf == bow2.shelf;
}


int main()
{
    float tension_2 = 19;
    float tension_3 = 22;
    Bow snake18_1 = Bow(18, "snake", 16, true);
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

    return 0;
}
