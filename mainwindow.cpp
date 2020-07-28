#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "regexer.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Regexer");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_regex_go_clicked()
{
    ui->result_edit->setText("");
    QString regex_pattern = ui->lineedit_regex->text();
    QString log_lines = ui->log_edit->toPlainText();
    RegExer rex(regex_pattern, log_lines);
    QString result_text = rex.match_pattern();
    ui->result_edit->setText(result_text);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgbox;
    msgbox.setWindowTitle("About this  Regexer");
    msgbox.setText("There are no named capture groups in C++ standard regex library - SORRY! :)\n\n Have fun!\n Markus");
    msgbox.exec();
}
