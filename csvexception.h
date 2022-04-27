#ifndef CSVEXCEPTION_H
#define CSVEXCEPTION_H

#include<QString>


class CsvException : public std::exception
{
private:
    QString _err;
    int _strnum;
public:
    CsvException(const QString &err, int strnum)
        : std::exception(),
        _err(err),
        _strnum(strnum){};
    virtual const char* what() const noexcept override
    {
        return (char*)_err.toLocal8Bit().data();
    }

    int getStrnum() const
    {
        return _strnum;
    }

    void setStrnum(int newStrnum)
    {
        _strnum = newStrnum;
    }
};

#endif // CSVEXCEPTION_H
