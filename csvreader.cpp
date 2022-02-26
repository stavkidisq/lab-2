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
    // Create a class instance
    Employe employe(employeLine[0].toInt(), employeLine[1],
            employeLine[2].toInt(), static_cast<Gender>(employeLine[3].toInt()));

    return employe;
}

std::vector<Employe> CSVReader::readAll()
{
    std::vector<Employe> employes;

    while(!fin.eof())
    {
        std::string line;
        getline(fin, line);

        if(line != "")
        {
            std::vector<QString> employeStr = split(QString::fromUtf8(line), ';');

            employes.push_back(getEmploye(employeStr));
        }
    }

    return employes;
}
