#include "employe.h"

Employe::Employe(int _id, QString _fullName, int _year, Gender _gender)
{
    id = _id;
    fullName = _fullName;
    year = _year;
    gender = _gender;
}

Employe::~Employe()
{

}
