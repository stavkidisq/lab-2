#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <Gender.h>
#include <QString>
#include<json.hpp>
class Employe
{
public:
    int id;
    QString fullName;
    int year;
    Gender gender;

public:
    int getAge() const { return 2022 - year; }
    QString to_string() const;

public:
    bool operator<(const Employe& employe){
        return this->year > employe.year;
    }

    Employe(int _id, QString _fullName, int _year, Gender _gender);
    Employe();
    ~Employe();
};
void from_json(const nlohmann::json& j, Employe& employe);

#endif // EMPLOYE_H
