#include <cstring>

using namespace std;
class Bow { 
    float koefficient;
    string type;
    float base;
    bool shelf;

public:    
    static int bow_count;    
    static constexpr float ref_expansion = 76;
    Bow(int tension_, std::string type_, float base_, bool shelf_);
    Bow(const Bow& another);    
    ~Bow();
    
    static float tension(float koefficient, float base, float real_expansion);
    float tension(float real_expansion);
    float tension();
        
    float operator() (float a=ref_expansion);

    friend bool operator== (const Bow& bow1, const Bow& bow2);
};