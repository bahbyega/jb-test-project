#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QString>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow();
    ~MainWindow() override;

  private slots:
    void on_InputTextChanged();

  private:
    Ui::MainWindow *ui;

    void createActions();
};

#endif /* MAIN_WINDOW_HPP */