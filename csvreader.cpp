#include "csvreader.h"

CSVReader::CSVReader(const QString& fileName)
{
    fin.open(fileName.toLatin1().data());
}

CSVReader::~CSVReader()
{
    fin.close();
}

std::vector<QString> CSVReader::split(const QString& str, char c)
{
    std::vector<QString> v;
    int length = str.length();

    if (!str.isEmpty())
    {
        QString temp = "";
        for(int i = 0; i < length; i++)
        {
            if(str[i] == c)
            {
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp += str[i];
            }
        }

        v.push_back(temp);
    }

    return v;
}

Employe CSVReader::getEmploye(std::vector<QString> employeLine)
{
    try
    {
        // Create a class instance
        Employe employe(
                std::stoi(employeLine[0].toUtf8().constData()),
                employeLine[1],
                std::stoi(employeLine[2].toUtf8().constData()),
                static_cast<Gender>(std::stoi(employeLine[3].toUtf8().constData()))
                );

        return employe;
    }
    catch(std::logic_error &err)
    {
        throw CsvException("error", strnum);
    }
}

std::vector<Employe> CSVReader::readAll()
{
    std::vector<Employe> employes;
    Employe employe;

    while(!fin.eof())
    {
        std::string line;
        getline(fin, line);

        strnum++;

        if(line != "")
        {
            std::vector<QString> employeStr = split(QString::fromUtf8(line), ';');

            employes.push_back(getEmploye(employeStr));
        }
    }

    return employes;
}
