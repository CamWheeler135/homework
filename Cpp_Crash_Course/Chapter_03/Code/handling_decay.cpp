#include <cstdio>

class University {
public:
    char name[256];
}; 

void print_college_names(University* university_ptr, size_t len_of_array) {
    for (int i = 0; i < len_of_array; i++) {
        printf("%s University\n", university_ptr[i].name);
    }
}

int main(void) {
    University array_of_unis[] = {"Edinburgh", "LSE", "Bath"};
    print_college_names(array_of_unis, sizeof(array_of_unis) / sizeof(array_of_unis[0]));

    
}

