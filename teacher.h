#ifndef TEACHER_H
#define TEACHER_H

#include <employe.h>

class Teacher : public Employe
{
public:
    QString department;
    QString to_string();
    Teacher(int _id, QString _fullName, int _year, Gender _gender, QString _department) : Employe(_id, _fullName, _year, _gender)
    {
        department = _department;
    }
};

#endif // TEACHER_H
