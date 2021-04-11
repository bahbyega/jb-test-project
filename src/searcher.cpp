#include "searcher.hpp"

Searcher::Searcher(const std::string filepath) : filepath(filepath)
{
}

Searcher::~Searcher()
{
    fileStream.close();
}

bool Searcher::openedFileStream()
{
    fileStream.open(filepath);
    return fileStream.good();
}

bool Searcher::closedFileStream()
{
    fileStream.close();
    return !fileStream.good();
}

void Searcher::search(const QString &pattern)
{
    std::string line;

    while (std::getline(fileStream, line))
    {
        if (line.find(pattern.toStdString()) != std::string::npos)
        {
            emit foundWord(line + "\n");
        }
    }
}