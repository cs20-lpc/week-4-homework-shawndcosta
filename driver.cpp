#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include <limits>
#include <sstream>
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

struct Node {
    Student student;
    Node* next;
    Node(const Student& s) : student(s), next(nullptr) {}
  };

class LinkedList {
  private:
    Node* head;
    int size;
  public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList(){
       clear();
    }


void insertStudent(const Student& student) {
  Node* newNode = new Node(student);
  if (head == nullptr){
    head = newNode;
  } else {
    Node* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = newNode;
  }
  size++;
  cout <<"student added"; 
}

bool deleteStudent(int id){
  if(head ==nullptr){
    return false;
  }
  if(head->student.getID() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }
  Node *current = head;
  while(current->next != nullptr &&current->next->student.getID() != id) {
    current = current->next;
  }
  if( current->next ==nullptr){
    return false;
  } 
  Node* temp = current->next;
  current->next = current->next->next;
  delete temp;
  size--;
  return true;

}

Node* searchByID(int id) {
  Node* current = head;
  while (current != nullptr) {
    if(current->student.getID() == id) {
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

void displayStudents(){
  if(head == nullptr){
    std::cout <<"no students" <<std::endl;
    return;
  }
 
  std::cout<<"Students: " << std::endl;
  Node* current = head;
  while(current != nullptr){
    current->student.displayStudent();
    std::cout << std::endl;
    current = current->next;
  }
}

int countStudents() const {
  return size;
}

bool addCourse(int id, const Course& course){
  Node* studentCourse = searchByID(id);
  if(studentCourse == nullptr) {
    return false;
  }
  studentCourse->student.addCourse(course);
  return true;
}
void clear(){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  size = 0;
  }
};
int getIntInput(const string& prompt) {
    string line;
    int value;
    
    while (true) {
        cout << prompt;
        if (getline(cin, line)) {
            stringstream ss(line);
            if (ss >> value && ss.eof()) {
                return value;
            }
        }
        cout << "Invalid input" << endl;
    }
}


double getDoubleInput(const string& prompt) {
    string line;
    double value;
    
    while (true) {
        cout << prompt;  
        if (getline(cin, line)) {
            stringstream ss(line);
            if (ss >> value && ss.eof()) {
                return value;
            }
        }
        cout << "Invalid input" << endl;
    }
}


string getStringInput(const string& prompt) {
    string value;
    cout << prompt;  
    getline(cin, value);
    return value;
}

int main()
  {
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
    LinkedList studentList;
    int choice;
    


  do {
    std::cout << "\n1. insert student" << std::endl;
    std::cout << "2. delete student" << std::endl;
    std::cout << "3 search student" << std::endl;
    std::cout << "4. display " << std::endl;
    std::cout << "5. count students" << std::endl;
    std::cout << "6. add  course" << std::endl;
    std::cout << "7. exit" << std::endl;


    choice = getIntInput("enter your choice: ");
    switch(choice) {
      case 1: {
        int id = getIntInput("enter id: ");
        std::string name = getStringInput("Enter Name: ");
        double gpa = getDoubleInput("enter gpa: ");
        if (gpa < 0.0 || gpa > 4.0) {
          std::cout << "invalid gpa" << std::endl;
        }
        Student newStudent(id, name, gpa);
        studentList.insertStudent(newStudent);
        break;
    }
      case 2: {

        int id = getIntInput("Enter ID: ");
        if (studentList.deleteStudent(id)){
          std::cout<< "deleted student number " << id << std::endl;
        } else {
          std::cout<< "Student number " << id << "not found" << std::endl;
        }
        break;
      }
      case 3: {
        int id = getIntInput("Enter ID: ");
        Node* studentNode = studentList.searchByID(id);
        if(studentNode != nullptr){
          studentNode->student.displayStudent();
          std::cout << std::endl;
        } else {
          std::cout<< "Student number " << id << "not found" << std::endl;
        }
        break;
      }
      case 4: {
        studentList.displayStudents();
        break;
      }

      case 5: {
        std::cout << "total students: " << studentList.countStudents() << std::endl;
        break;
      }
      case 6: {
        int id = getIntInput("enter ID: ");
        std:: string courseName = getStringInput("enter course: ");
        std:: string location = getStringInput("enter location: ");

        Course newCourse(courseName, location);
        if( studentList.addCourse(id, newCourse)) {
          std::cout << "Course added: " << std::endl;
        } else {
          std::cout<< "Student number " << id << "not found" << std::endl;
        }
        break;
      }
      case 7: {
        std::cout<< "exit" << std::endl;
        break;
      }
      default: {
        std::cout<< "invalid choice." << std::endl;
        break;
      }
    }
  } while (choice != 7);
  return 0;
}





