#ifndef CSVREADER_H
#define CSVREADER_H

#include <employe.h>
#include<QString>
#include<QFile>
#include <iostream>
#include <fstream>

#include<abstractreader.h>

class CSVReader : public AbstractReader
{
public:
    CSVReader(const QString& fileName);
    ~CSVReader();

    bool is_open () override { return fin.is_open(); }

    std::vector<Employe> readAll() override;
    Employe getEmploye(std::vector<QString> employeLine);
    std::vector<QString> split(const QString& str, char c);
public:
    CSVReader(const CSVReader&) = delete;
    CSVReader& operator =(const CSVReader&) = delete;
    CSVReader(CSVReader && reader)
    {
        this->fin = std::move(reader.fin);
    };
    CSVReader operator =(CSVReader &&reader)
    {
        return std::move(reader);
    };
};

#endif // CSVREADER_H
