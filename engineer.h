#ifndef ENGINEER_H
#define ENGINEER_H

#include<employe.h>

class Engineer : public Employe
{
public:
    QString post;
public:
    QString to_string();
public:
    Engineer(int _id, QString _fullName, int _year, Gender _gender, QString _post) : Employe(_id, _fullName, _year, _gender)
    {
        post = _post;
    }
};

#endif // ENGINEER_H
