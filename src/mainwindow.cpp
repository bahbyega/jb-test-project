#include "mainwindow.hpp"
#include "../build/ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    connect(ui->inputText, &QLineEdit::textChanged, this,
            &MainWindow::on_InputTextChanged);
}

void MainWindow::on_InputTextChanged()
{
    const QString text = ui->inputText->text();
    ui->outputText->setPlainText(text);
}