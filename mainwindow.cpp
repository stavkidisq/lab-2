#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<csvreader.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create CSVReader class instance.
    CSVReader csv("D:\\QtProjects\\Lab2\\database.csv");

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
    for(const auto& employe : employes)
    {
        if(employe.fullName == ui->editSearch->text())
        {
            ui->textBrowser->append(QString::number(employe.id) + ", " + employe.fullName
                                    + ", " + QString::number(employe.year) +", " + QString::number(employe.gender));
        }
    }
}

