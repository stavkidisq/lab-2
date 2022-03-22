#include "engineer.h"

QString Engineer::to_string()
{
    return QString::number(id) + "" + fullName + "" + QString::number(year)
            + "" + QString::number(gender) + "" + post;
}
