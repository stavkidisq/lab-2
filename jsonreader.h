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
public:
    JSONReader(const QString& fileName);
    ~JSONReader();

    std::vector<Employe> readAll() override
    {
        std::vector<Employe> employes;

        std::ifstream f("cars.json");
        nlohmann::json json;

        f >> json;

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
