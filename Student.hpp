// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Course.hpp"


class CourseNode {
    public:
        Course course;
        CourseNode* next;
    
        CourseNode(const Course& c) : course(c), next(nullptr) {}
};


class Student {
    private:
        int id;
        std::string name;
        double gpa;
        CourseNode* courseHead;
        void clearCourses();
        void copyCourses(const Student& other);
    public:
        Student();
        Student(int studentID, const std::string &studentName, double studentGPA);
        Student(const Student& other);
        Student& operator = (const Student& other);
        ~Student();

        void setID(int studentId);
        void setName(const std::string &studentName);
        void setGPA( double studentGpa);

        int getID() const;
        std::string getName() const;
        double getGPA() const;

        void addCourse(const Course& Course);
        void displayCourses() const;
        void displayStudent() const;
   


};
#endif