#include <iostream>

void power_up_reactor(int nuclear_isotopes) {
    static int nuclear_power = 200;
    nuclear_power += nuclear_isotopes;
    const auto waste_heat = nuclear_power * 20;
    if (waste_heat > 5000) {
        std::cout << "Warning! Reactor overheating!\n";
    }
    std::cout << "Current power: " << nuclear_power << '\n';
}

int main(void) {
    power_up_reactor(10);
    power_up_reactor(20);
    power_up_reactor(30);
}