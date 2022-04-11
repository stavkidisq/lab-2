#include "jsonreader.h"

JSONReader::JSONReader(const QString& fileName)
{
    fin.open(fileName.toLatin1().data());
    fin >> json;
    it = json.begin();
}

JSONReader::~JSONReader()
{
    fin.close();
}
