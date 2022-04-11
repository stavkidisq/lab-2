#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<QString>
#include<employe.h>
#include<iostream>
#include<fstream>

class AbstractReader
{
public:
    std::ifstream fin;
public:
    virtual std::vector<Employe> readAll() = 0;
    virtual bool is_open() = 0;
    virtual AbstractReader& operator>>(Employe& employe) = 0;
    virtual operator bool() const = 0;
};

#endif // ABSTRACTREADER_H
