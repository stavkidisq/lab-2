#ifndef CARCSVWRITER_H
#define CARCSVWRITER_H

#include <employe.h>
#include <QString>
#include <iostream>
#include <fstream>
#include <employe.h>

class CarCsvWriter
{
    std::ofstream fout;
public:
    CarCsvWriter(const QString& fileName);
    ~CarCsvWriter();

    bool is_open()const { return fout.is_open(); }
    void writeEmploye(std::vector<Employe>& employe);
};

#endif // CARCSVWRITER_H
