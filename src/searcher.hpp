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

    void search(const QString &pattern);
    bool openedFileStream();
    void setSearchStopped(bool stopped);

  signals:
    void foundWord(std::string word);

  private:
    std::ifstream fileStream;
    const std::string filepath;

    bool searchStopped;
};

#endif /* SEARCHER_HPP */