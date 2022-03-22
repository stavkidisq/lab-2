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
public:
    CarCsvWriter(const CarCsvWriter&) = delete;
    CarCsvWriter& operator =(const CarCsvWriter&) = delete;
    CarCsvWriter(CarCsvWriter && writer)
    {
        this->fout = std::move(writer.fout);
    };
    CarCsvWriter operator =(CarCsvWriter &&writer)
    {
        return std::move(writer);
    };
};

#endif // CARCSVWRITER_H
