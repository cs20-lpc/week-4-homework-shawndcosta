// TODO:  Course class methods implementation here.
#include "Course.hpp"
#include <iostream>
using namespace std;

Course::Course() : courseName("") , courseLocation(""){}
Course::Course(const std::string &name, const std::string& location)
    : courseName(name), courseLocation(location){}
Course::Course(const Course& other)
    : courseName(other.courseName), courseLocation(other.courseLocation){}
Course::~Course() {}
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        courseName = other.courseName;
        courseLocation = other.courseLocation;
    }
    return *this;
}




std::string Course::getCourseName() const{
    return courseName;
}
std::string Course::getCourseLocation() const{
    return courseLocation;
}
void Course::setCourseName(const std::string &name) {
    courseName = name;
}
void Course::setCourseLocation(const std::string &location){
    courseLocation = location;
}
void Course::displayCourse() const{
    cout << courseName << " " << courseLocation;
}


















