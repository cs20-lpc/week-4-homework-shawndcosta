// TODO:  Student class methods implementation here.
#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student() : id(0) , name(""), gpa(0.0), courseHead(nullptr){}
Student::Student(int StudentID, const std::string &studentName, double studentGPA)
    : id(StudentID) , name(studentName), gpa(studentGPA), courseHead(nullptr) {}

Student::Student(const Student& other)
    : id(other.id), name(other.name), gpa(other.gpa), courseHead(nullptr){
    copyCourses(other);
    }
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        gpa = other.gpa;
        clearCourses();
        copyCourses(other);  

    }
    return *this;
}
Student::~Student() {
    clearCourses();
}



void Student::setID(int studentId){
    id = studentId;
}
void Student::setName(const std::string &studentName){
    name = studentName;
}
void Student::setGPA( double studentGPA){
    gpa = studentGPA;
}

int Student::getID() const{
    return id;
}
std::string Student::getName() const{
    return name;
}
double Student::getGPA() const{
    return gpa;
}
void Student::clearCourses() {
    while (courseHead != nullptr) {
        CourseNode* temp = courseHead;
        courseHead = courseHead->next;
        delete temp;
    }
}
void Student::copyCourses(const Student& other) {
    if (other.courseHead == nullptr) {
        return;
    }
    
    CourseNode* otherCurrent = other.courseHead;
    while (otherCurrent != nullptr) {
        addCourse(otherCurrent->course);
        otherCurrent = otherCurrent->next;
    }
}
void Student::addCourse(const Course& Course){
    CourseNode *newNode = new CourseNode(Course);
    if (courseHead == nullptr) {
        courseHead = newNode;
    } else {
        CourseNode * current = courseHead;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}
void Student::displayCourses() const{
    if(courseHead == nullptr){
        std::cout <<"none";
        return;
    }
    CourseNode* current = courseHead;
    while(current != nullptr){
        current->course.displayCourse();
        current = current->next;

    }
}
void Student::displayStudent() const{
  
    std::cout << name << ": " << id << ": " << gpa;
    if (courseHead != nullptr) {
        std::cout << std::endl << "  Courses: ";
        displayCourses();
    } else {
        std::cout << " None";
    }
}




















