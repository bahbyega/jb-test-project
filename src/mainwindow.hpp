#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QString>
#include <QtConcurrent/QtConcurrentRun>
#include <iostream>

#include "searcher.hpp"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

  private slots:
    void on_InputTextChanged();
    void updateResult(const std::string);

  private:
    Ui::MainWindow *ui;
    Searcher *searcher;

    void createActions();
};

#endif /* MAIN_WINDOW_HPP */