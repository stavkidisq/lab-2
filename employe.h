#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <Gender.h>
#include <QString>

class Employe
{
public:
    int id;
    QString fullName;
    int year;
    Gender gender;

public:
    int getAge() const { return 2022 - year; }
    QString to_string();

public:
    Employe(int _id, QString _fullName, int _year, Gender _gender);
    ~Employe();
};

#endif // EMPLOYE_H
