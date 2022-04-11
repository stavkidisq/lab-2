#include "carcsvwriter.h"

CarCsvWriter::CarCsvWriter(const QString& fileName)
{
    fout.open(fileName.toLatin1().data());
}

CarCsvWriter::~CarCsvWriter()
{
    fout.close();
}

std::ostream& operator<<(std::ostream& _fout, const Employe& employe)
{
    _fout << employe.to_string().toLatin1().data();
    return _fout;
}

void CarCsvWriter::writeEmploye(std::vector<Employe>& employes)
{
    if(fout.is_open())
    {
        for(const Employe& employe : employes)
        {
            fout << employe << std::endl;
        }
    }
}
