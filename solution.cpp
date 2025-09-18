
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if(size == capacity){
        throw "List full";
    }
    names[size] = name;
    gpas[size] = gpa;

    size++;
}


// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
    *gpaPtr = newGpa;
}
// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
    std::cout << name << ": " << gpa << std::endl;
}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
    std::cout << size << "SIZE" << std::endl;
    if(size == 0){
        throw "No students";
    }
    double sum = 0.0;
    for(int i = 0; i < size; ++i){
        sum += gpas[i];
    }

    return sum/size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                try{
                    char buf[100];            
                    std::cout << "Enter a student: ";
                    std::cin >> buf;
                    size_t len = strnlen(buf, 100);
                    char* name = new char[len + 1];
                    strcpy(name, buf);
                    double gpa;
                    std::cout << "Enter a gpa: ";
                    std::cin >> gpa;
                    addStudent(name, gpa, names, gpas, size, capacity);
                }catch(const char* err){
                    std::cout << err << std::endl;
                }
                break;
            }
            case 2: {
                try{
                    int studentNum;
                    std::cout << "Enter student index/number: " << std::endl;
                    std::cin >> studentNum;
                    double gpa;
                    std::cout << "Enter New Gpa: " << std::endl;
                    std::cin >> gpa;
                    updateGPA(&gpas[studentNum], gpa);
                }catch(const char* err){
                    std::cout << err << std::endl;
                }
                break;
            }
            case 3: {
                try{
                    for(int i = 0; i < size; ++i){
                        printStudent(names[i], gpas[i]);
                    }
                }catch(const char* err){
                    std::cout << err << std::endl;
                }
                break;
            }
            case 4: {
                try{
                    std::cout << "Average GPA: " << static_cast<int>(averageGPA(gpas, size)) << std::endl;
                }catch(const char* err){
                    std::cout << err << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);
    // TODO: free memory
    for(int i = 0; i < size; ++i){
        delete[] names[i];
    }
    return 0;
}
