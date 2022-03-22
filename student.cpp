#include "student.h"

QString Student::to_string()
{
    return QString::number(id) + "" + fullName + "" + QString::number(year)
            + "" + QString::number(gender) + "" + group;
}
