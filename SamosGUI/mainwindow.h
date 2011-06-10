#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QProcess>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_me_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionAbout_Samos_triggered();
    bool on_actionSave_triggered();
    void on_pushButton_clicked();
    bool on_actionSave_as_triggered();
    void on_actionDebug_triggered();
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

private:
    QString currentFileName;
    bool saveFile(const QString &);
    void loadFile(const QString &);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
