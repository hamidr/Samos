#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Samos Machine");
    this->setMaximumSize(481,425);
    this->setMinimumSize(481,425);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_me_triggered()
{
    QMessageBox::about(this,QString("About author"),QString("Hamidreza Davoodi"));
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,QString("About Qt"));
}

void MainWindow::on_actionAbout_Samos_triggered()
{
    QMessageBox::about(this,QString("About Samos"),QString("An assembly-like or bytecode reader. GPLv3"));
}

bool MainWindow::on_actionSave_triggered()
{
    if ( currentFileName.isEmpty() )
        return MainWindow::on_actionSave_as_triggered();
    else
        return saveFile(currentFileName);
}

bool MainWindow::saveFile(const QString &fileName)
{

    QFile file(fileName);
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning( this, tr("Huh?!"), tr("Failed to save file."));
        return false;
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();

    currentFileName = fileName;
    ui->textEdit->document()->setModified(false);
    setWindowTitle( tr("%1[*] - %2" ).arg(fileName).arg(tr("SM")) );

    file.close();

    return true;
}

void MainWindow::on_pushButton_clicked()
{
              MainWindow::on_actionDebug_triggered();
}

bool MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save as"),currentFileName);
    if (filename.isEmpty())
        return false;
    else
        return saveFile(filename);
}

void MainWindow::on_actionDebug_triggered()
{
    QFile file(tr("input.sm"));
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QMessageBox::warning( this, tr("SM"), tr("Failed to create temp file!") );
        return;
    }
    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();
    
    // Sorry :| dependent API
    // WINDOWS.H 

    wchar_t PROGRAM[] = L"Samos.exe";
    wchar_t S_ARG[] = L"input.sm";

    STARTUPINFO startup_info;
    PROCESS_INFORMATION process_info;
				 
    ZeroMemory( &process_info, sizeof(process_info) );
    ZeroMemory( &startup_info, sizeof(startup_info) );
				 
    startup_info.cb = sizeof(startup_info);

    if ( CreateProcess( PROGRAM, S_ARG, 0, 0, 0, 0, 0, 0, &startup_info, &process_info ) == 0 )
    {
		ui->textEdit->setPlainText(tr("BOO"));
    }
    WaitForSingleObject( process_info.hProcess, INFINITE );
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName( this );
    if( filename.isEmpty() )
      return;

        loadFile( filename );

}

void MainWindow::loadFile(const QString &filename)
{
    QFile file(filename);

    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
      QMessageBox::warning( this, tr("SM"), tr("Failed to open file.") );
      return;
    }
    QTextStream stream(&file);
    ui->textEdit->setPlainText(stream.readAll());

    currentFileName = filename;
    ui->textEdit->document()->setModified(false);

    setWindowTitle( tr("%1[*] - %2" ).arg(filename).arg(tr("SM")) );
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
