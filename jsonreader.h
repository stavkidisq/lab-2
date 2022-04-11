#ifndef JSONREADER_H
#define JSONREADER_H

#include<QString>
#include<abstractreader.h>
#include<employe.h>
#include"json.hpp"
#include <iostream>
#include <fstream>

class JSONReader : public AbstractReader
{
private:
    int index = 0;
    nlohmann::json json;
    nlohmann::json::iterator it;
public:
    JSONReader(const QString& fileName);
    ~JSONReader();

    virtual AbstractReader& operator>>(Employe& employe) override
    {
        std::string strFullName;
        employe.id = 0;

        employe.id = it.value()["id"];
        strFullName = it.value()["fullName"];
        employe.gender = it.value()["gender"];
        employe.year = it.value()["year"];
        employe.fullName = QString::fromStdString(strFullName);

        if(it != json.end())
                it++;

        return *this;
    }
    virtual operator bool() const override
    {
        return !fin.eof();
    }

    std::vector<Employe> readAll() override
    {
        std::vector<Employe> employes;

        nlohmann::json json;

        fin >> json;

        for (auto& e: json)
        {
            auto c = e.get<Employe>();
            employes.push_back(std::move(c));
        }

        return employes;
    }

    bool is_open() override
    {
        return fin.is_open();
    }
};

#endif // JSONREADER_H
