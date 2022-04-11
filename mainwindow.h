#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<employe.h>
#include<abstractreader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void searchEmploye();
    void addEmploye();
    void processFile(AbstractReader& reader);
    void newReadAll(AbstractReader& reader);
    void getFilePath();

private:
    Ui::MainWindow *ui;

    std::vector<Employe> employes;
    QString filePath;
};
#endif // MAINWINDOW_H
