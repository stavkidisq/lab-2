#ifndef STUDENT_H
#define STUDENT_H

#include <employe.h>

class Student : public Employe
{
public:
    QString group;
public:
    QString to_string();
public:
    Student(int _id, QString _fullName, int _year, Gender _gender, QString _group) : Employe(_id, _fullName, _year, _gender)
    {
        group = _group;
    }
};

#endif // STUDENT_H
