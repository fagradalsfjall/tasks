#include "userdie.hpp"

float Userdie::calc(float halyavnost, float knowledge, float ability_to_cheat) {

    float userdie = 0;

    userdie += volume_of_tasks()/(knowledge + ability_to_cheat*halyavnost);
    userdie += control_works()*(1 - ability_to_cheat);
    userdie += attednance();

    return userdie;
}
