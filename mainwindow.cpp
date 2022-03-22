#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <carcsvwriter.h>
#include<csvreader.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create CSVReader class instance.
    CSVReader csv("D:\\QtProjects\\Lab4\\Lab_2\\database.csv");

    //.csv should be file is open.
    if(csv.is_open())
    {
        //Read all objects from .csv file.
        employes = csv.readAll();

        //Sort employes vector.
        std::sort(employes.begin(), employes.end(), [](const Employe &employe1, const Employe &employe2){
            return employe1.year > employe2.year;
         });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchEmploye()
{
    ui->textBrowser->clear();

    for(const auto& employe : employes)
    {
        if(employe.fullName == ui->editSearch->text())
        {
            ui->textBrowser->appendGreen(QString::number(employe.id) + ", " + employe.fullName
                                    + ", " + QString::number(employe.year) +", " + QString::number(employe.gender));
        }
    }

    if(ui->textBrowser->toPlainText() == "")
        ui->textBrowser->appendRed("Nothing was founded!");
}

void MainWindow::addEmploye()
{
    ui->textBrowser->clear();

    QString id = ui->editId->text();
    QString fullName = ui->editFullName->text();
    QString yearOfBirth = ui->editYearOfBirth->text();
    Gender gender = static_cast<Gender>(ui->comboGender->currentIndex());

    if(id != QString() && fullName != QString() && yearOfBirth != QString())
    {
        Employe employe(id.toInt(), fullName, yearOfBirth.toInt(), gender);

        employes.push_back(employe);

        CarCsvWriter csv("D:\\QtProjects\\Lab4\\Lab_2\\database.csv");

        if(csv.is_open())
            csv.writeEmploye(employes);

        ui->editId->clear();
        ui->editFullName->clear();
        ui->editYearOfBirth->clear();
    }
    else
    {
        ui->textBrowser->clear();
        ui->textBrowser->append("Enter the data correctly!");
    }
}
