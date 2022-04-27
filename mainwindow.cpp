#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <carcsvwriter.h>
#include<csvreader.h>
#include<jsonreader.h>
#include<qfiledialog.h>
#include<csvexception.h>
#include<qmessagebox.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchEmploye()
{
    ui->textBrowser->clear();

    std::sort(employes.begin(), employes.end());

    for(const auto& employe : employes)
    {
        if(employe.fullName == ui->editSearch->text() || ui->editSearch->text() == "")
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

void MainWindow::processFile(AbstractReader& reader)
{
    if(reader.is_open())
    {
        newReadAll(reader);
    }
}

void MainWindow::getFilePath()
{
    ui->textBrowser->clear();
    filePath = QFileDialog::getOpenFileName(0, "Open File", "", "*.csv *.json");

    QFileInfo inf(filePath);
    QString file_extenstion = inf.suffix();

    if(file_extenstion == "csv")
    {
        CSVReader csv(filePath);
        processFile(csv);
    }
    else if(file_extenstion == "json")
    {
        JSONReader json(filePath);
        processFile(json);
    }
}

void MainWindow::newReadAll(AbstractReader& reader)
{
    employes.clear();
    Employe employe;

    try
    {
        while(reader >> employe)
        {
            ui->textBrowser->appendGreen(employe.to_string());
            employes.push_back(employe);
        }
    }
    catch(CsvException &e)
    {
        ui->textBrowser->clear();
        ui->textBrowser->appendRed("Error at CSV line number: " + QString::number(e.getStrnum()));
    }
}
