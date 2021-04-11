#include "searcher.hpp"

Searcher::Searcher(const std::string filepath) : filepath(filepath)
{
}

bool Searcher::openedFileStream()
{
    fileStream.open(filepath);
    return fileStream.good();
}

void Searcher::setSearchStopped(bool _searchStopped)
{
    searchStopped = _searchStopped;
}

void Searcher::search(const QString &pattern)
{
    if (openedFileStream())
    {
        searchStopped = false;
        std::string line;

        while (std::getline(fileStream, line))
        {
            if (searchStopped)
                break;

            if (line.find(pattern.toStdString()) != std::string::npos)
            {
                emit foundWord(line);
                QThread::msleep(3); // smoothes the output
            }
        }

        fileStream.close();
    }
}