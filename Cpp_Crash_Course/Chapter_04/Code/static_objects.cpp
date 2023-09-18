#include <iostream>

static int nuclear_power = 200;

void power_up_reactor(int nuclear_isotopes) {
    nuclear_power += nuclear_isotopes;
    const auto waste_heat = nuclear_power * 20;
    if (waste_heat > 5000) {
        std::cout << "Warning! Reactor overheating!\n";
    }
}

int main() {
    power_up_reactor(10);
    power_up_reactor(20);
    power_up_reactor(30);
}