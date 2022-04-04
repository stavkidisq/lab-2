#include "jsonreader.h"

JSONReader::JSONReader(const QString& fileName)
{
    fin.open(fileName.toLatin1().data());
}

JSONReader::~JSONReader()
{
    fin.close();
}
