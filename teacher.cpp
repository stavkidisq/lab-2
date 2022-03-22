#include "teacher.h"

QString Teacher::to_string()
{
    return QString::number(id) + "" + fullName + "" + QString::number(year)
            + "" + QString::number(gender) + "" + department;
}
