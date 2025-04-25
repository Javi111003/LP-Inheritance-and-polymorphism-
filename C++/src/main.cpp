# include <iostream>
# include <stdlib.h>
#include <vector>
using namespace std;

class Worker
{
protected:
    string Name;
    float Salary;
public:
    Worker(string, float);
    ~Worker() = default;  //Poner virtual en el destructor
    virtual void CollectSalary() const = 0;
};

Worker::Worker(string _name, float salary)
{
    Name = _name;
    Salary = salary;
}

class Teacher : public Worker //Mostrar herencia virtual
{
protected:
    int Experience;
public:
    Teacher(string _name, float _salary, int _exp) : Worker(_name, _salary)
    {
        Experience = _exp;
    }
    void CollectSalary() const override
    {
        float bonus = 100.0 * Experience;
        cout << "El Profesor "<<Name<<" cobra "<<Salary + bonus<<endl;
    }
    void Teach() const
    {
        cout <<"El Profesor "<<Name<<" imparte clases desde hace "<<Experience<< "años"<<endl;
    }
};

class Student : public Worker //mostrar herencia virtual
{
protected:
    string Faculty;
public:
    Student(string _name, float _salary, string _faculty) : Worker(_name, _salary)
    {
        Faculty = _faculty;
    }
    void CollectSalary() const override
    {
        cout << "El Alumno "<<Name<<" cobra "<<Salary<<endl;
    }
    void Learn() const
    {
        cout <<"El Alumno "<<Name<<" recibe clases en "<<Faculty<<endl;
    }
};

class AssistanStudent : public Teacher, public Student
{
public:
    AssistanStudent(string _name, float _salary, string _faculty, int _exp): 
    //Worker(_name, _salary),
    Teacher(_name, _salary, _exp),
    Student(_name, _salary, _faculty){}

    void CollectSalary() const override
    {
        float bonus = Experience * 50;
        cout<<"El alumno ayudante "<<Student::Name<<" cobra "<<Student::Salary + bonus<<endl;
    }
    void CompleteData()
    {
        Teach();
        Learn();
    }
    void Teach()
    {
        cout <<"El Alumno Ayudante "<<Teacher::Name<<" imparte clases desde hace "<<Experience<< "años"<<endl;
    }
    void Learn()
    {
        cout <<"El Alumno "<<Student::Name<<" recibe clases en "<<Faculty<<endl;
    }
};

class TrainedTeacher : public Student
{
public:
    void Learn()
    {
        cout<<"El Profesor "<<Name<<" aun recibe Preparacion"<<endl;
    }
    void Trainer()
    {
        cout<<"Falte a clases porque tenia que cocinar"<<endl;
    }
};


int main()
{
    // AssistanStudent as("Miguel", 200.0, "Matcom", 2);
    // as.CollectSalary();
    // as.CompleteData();

    // //Polimorfismo
    // Worker* workers[3];
    // workers[0] = new Teacher("Carlos", 4000.0, 6);
    // workers[1] = new Student("Javier", 200.0, "Matcom");
    // //workers[2] = new AssistanStudent("Miguel", 200.0, "Matcom", 2);

    // for(Worker* w : workers)
    // {
    //     w->CollectSalary();
    //     delete w;
    // }

    //Casteo
    // Worker* w1 = new Student("Kevin", 200, "Matcom");
    // TrainedTeacher* tt = static_cast<TrainedTeacher*>(w1);
    // tt->Trainer();

    // Teacher* t = static_cast<Teacher*>(w1); 
    // t->Teach();

    // vector<Worker*> staff;
    // staff.push_back(new Teacher("Yudivian", 6000, 8));
    // staff.push_back(new Student("Kendry", 200, "Matcom"));
    // staff.push_back(new AssistanStudent("Joel", 200, "Matcom", 2));
    
    // for (auto w : staff) {
    //     w->CollectSalary();
        
    //     if (auto t = dynamic_cast<Teacher*>(w)) {
    //         t->Teach();
    //     }
        
    //     if (auto s = dynamic_cast<Student*>(w)) {
    //         s->Learn();
    //     }
        
    //     if (auto ta = dynamic_cast<AssistanStudent*>(w)) {
    //         ta->CompleteData();
    //     }
    // }
    
    // // Limpieza
    // for (auto w : staff) delete w;
    return 0;
}