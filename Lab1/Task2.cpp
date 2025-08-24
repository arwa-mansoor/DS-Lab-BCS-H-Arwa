#include <iostream>
using namespace std;

class Exam{
    private:
        string *studentName;
        string *examDate;
        float *score;

    public:
        Exam(string name, string date, float score){
            studentName = new string(name);
            examDate = new string(date);
            this->score = new float(score);
        }
        void setName(string name){
            studentName = new string(name);
        }
        void setDate(string date){
            examDate = new string(date);
        }
        void setScore(float score){
            this->score = new float(score); 
        }

        void displayDetails(){
            cout << "Student Name: " << *studentName << endl;
            cout << "Exam Date: " << *examDate << endl;
            cout << "Score: " << *score << endl;
        }

        ~Exam(){
            delete studentName;
            delete examDate;
            delete score;
        }

};

int main(){
    Exam student1("Ali", "18/08/2025", 96.7);
    cout << "Student 1\n";
    student1.displayDetails();
            
    Exam student2 = student1;
    cout << "Student 2\n";
    student2.displayDetails();

    student2.setName("Sara");
    student2.setDate("19/08/2025");
    student2.setScore(88.5);
    cout << "Student 2\n";
    student2.displayDetails();

    return 0;

}
