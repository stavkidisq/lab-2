#include "carcsvwriter.h"

CarCsvWriter::CarCsvWriter(const QString& fileName)
{
    fout.open(fileName.toLatin1().data());
}

CarCsvWriter::~CarCsvWriter()
{
    fout.close();
}

void CarCsvWriter::writeEmploye(std::vector<Employe>& employes)
{
    if(fout.is_open())
    {
        for(const Employe& employe : employes)
        {
            fout << employe.id << ";" << employe.fullName.toLatin1().data()
                 << ";" << employe.year << ";" << employe.gender << std::endl;
        }
    }
}
