#include "mainwindow.hpp"
#include "../build/ui_mainwindow.h"

const std::string FILEPATH = "words.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    searcher = new Searcher(FILEPATH);

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

    connect(searcher, &Searcher::foundWord, this, &MainWindow::updateResult);
}

void MainWindow::on_InputTextChanged()
{
    stopAnySearch();

    if (ui->inputText->text().size() > 0)
    {
        const QString pattern = ui->inputText->text();

        // run search asynchronously
        qRegisterMetaType<std::string>("std::string");
        QtConcurrent::run(searcher, &Searcher::search, pattern);
    }
}

void MainWindow::stopAnySearch()
{
    searcher->setSearchStopped(true);
    QCoreApplication::processEvents();
    ui->outputText->clear();
}

void MainWindow::updateResult(const std::string word)
{
    QString str = QString::fromStdString(word);
    ui->outputText->appendPlainText(str);
}