#pragma once

template <typename Derived>
class Userdie{

public:
float volume_of_tasks() {
    Derived* own = static_cast<Derived *>(this);
    return own->volume_of_tasks();
};

float attendance() {
    Derived* own = static_cast<Derived *>(this);
    return own->attendance();
};

float control_works() {
    Derived* own = static_cast<Derived *>(this);
    return own->control_works();
};


float calc(float halyavnost, float knowledge, float ability_to_cheat) {

    float userdie = 0;

    userdie += volume_of_tasks()/(knowledge + ability_to_cheat*halyavnost);
    userdie += control_works()*(1 - ability_to_cheat);
    userdie += attendance();

    return userdie;
}


};