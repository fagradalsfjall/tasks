#include"userdie.hpp"

class Teorver: public Userdie<Teorver> {

public:
    float volume_of_tasks() const;
    float attendance() const;
    float control_works() const;

};