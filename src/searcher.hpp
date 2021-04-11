#ifndef SEARCHER_HPP
#define SEARCHER_HPP

#include <QObject>
#include <QString>
#include <QThread>
#include <fstream>
#include <iostream>
#include <string>

class Searcher : public QObject
{
    Q_OBJECT

  public:
    Searcher(const std::string filepath);
    ~Searcher() override;

    void search(const QString &pattern);
    bool openedFileStream();
    bool closedFileStream();

  signals:
    void foundWord(std::string word);

  private:
    std::ifstream fileStream;
    const std::string filepath;
};

#endif /* SEARCHER_HPP */