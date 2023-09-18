#include <iostream>

class NuclearReactor {
public:

    static int reactor_power;

    static void power_up_reactor(int nuclear_isotopes) {
        reactor_power += nuclear_isotopes;
        const auto waste_heat = reactor_power * 20;
        if (waste_heat > 5000) {
            std::cout << "Warning, reactor overheating!" << std::endl;
        }
        std::cout << "Reactor power: " << reactor_power << std::endl;
    }
};

int NuclearReactor::reactor_power = 1000;

int main(void) {
    NuclearReactor::power_up_reactor(10);
    NuclearReactor::power_up_reactor(20);
    NuclearReactor::power_up_reactor(30);
}