#include <iostream>
#include <string>

class Tilda {
private:
    int age;
public:
    Tilda(int init_age) { // Constructor
        if (!set_age(init_age)) {
            age = 0;
        }
    }

    bool set_age(int new_age) {
        if (new_age < 0) {
            return false;
        }
        else {
            age = new_age;
            return true;
        }
    }

    int get_age() {
        return age;
    }

    void increment_age() {
        age ++;
    }
};

int main(void) {
    Tilda tilda(12);
    std::cout << tilda.get_age() << std::endl;

    Tilda wont_work(-11);
    std::cout << wont_work.get_age() << std::endl;
}

