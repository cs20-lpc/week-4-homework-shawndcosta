// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course{ 
    private:
        std::string courseName;
        std::string courseLocation;
    public:
        Course();
        Course(const std::string &name, const std::string& location);

        Course(const Course& other);
        ~Course();
        
        Course& operator=(const Course& other);

        std::string getCourseName() const;
        std::string getCourseLocation() const;

        void setCourseName(const std::string &name);
        void setCourseLocation(const std::string &location);

        void displayCourse() const;
};

#endif
