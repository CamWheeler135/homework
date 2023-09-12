class Class1 {
private:
    int year;

public:
    void set_year(int new_year) {
        this->year = new_year;
    }

    int get_year() const {
        return this->year;
    }
};