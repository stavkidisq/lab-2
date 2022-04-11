#include "employe.h"
#include<json.hpp>

Employe::Employe(int _id, QString _fullName, int _year, Gender _gender)
{
    id = _id;
    fullName = _fullName;
    year = _year;
    gender = _gender;
}

Employe::Employe()
{

}

QString Employe::to_string() const
{
    return QString::number(id) + ";" + fullName + ";" + QString::number(year) +";" + QString::number(gender);
}

Employe::~Employe()
{

}

void from_json(const nlohmann::json& j, Employe& employe)
{
    std::string strFullName;
    j.at("id").get_to(employe.id);
    j.at("fullName").get_to(strFullName);
    j.at("gender").get_to(employe.gender);
    j.at("year").get_to(employe.year);
    employe.fullName = QString::fromStdString(strFullName);
}
