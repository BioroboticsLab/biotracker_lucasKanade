#include "Config.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <QStringList>
#include <iostream>
#include <QFile>
#include <QDir>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <QStandardPaths>

template<typename Stream>
Stream &operator>>(Stream& s, QString& q)
{
    std::string tmp;
    s >> tmp;
    q = tmp.data();
	return s;
}

template<typename Stream>
Stream &operator<<(Stream& s, QString const& q)
{
	return s << q.toStdString();
}

void Config::load(QString dir, QString file)
{
    using namespace boost::property_tree;

    auto tree = ptree{};
    QDir d(dir);
    d.mkpath(dir);
    QFile fin(dir + "/" + file);

    if(!fin.exists()) 
    {       
        fin.open(QIODevice::ReadWrite);
        fin.close();
    }
    
    read_ini((dir + "/" + file).toStdString(), tree);

    Config* config = this;

    std::string globalPrefix = "General.";
    config->WndSize = tree.get<int>(globalPrefix+"WndSize",config->WndSize);
    config->EnableView = tree.get<int>(globalPrefix+"EnableView",config->EnableView);
    config->EnableMove = tree.get<int>(globalPrefix+"EnableMove",config->EnableMove);
    config->EnableRemove = tree.get<int>(globalPrefix+"EnableRemove",config->EnableRemove);
    config->EnableSwap = tree.get<int>(globalPrefix+"EnableSwap",config->EnableSwap);
    config->EnableAdd = tree.get<int>(globalPrefix+"EnableAdd",config->EnableAdd);
    config->EnableRotate = tree.get<int>(globalPrefix+"EnableRotate",config->EnableRotate);
}

void Config::save(QString dir, QString file)
{
    using namespace boost::property_tree;

    auto tree = ptree{};
    Config *config = this;

    std::string globalPrefix = "General.";
    tree.put(globalPrefix+"WndSize", config->WndSize);
    tree.put(globalPrefix+"EnableView", config->EnableView);
    tree.put(globalPrefix+"EnableMove", config->EnableMove);
    tree.put(globalPrefix+"EnableRemove", config->EnableRemove);
    tree.put(globalPrefix+"EnableSwap", config->EnableSwap);
    tree.put(globalPrefix+"EnableAdd", config->EnableAdd);
    tree.put(globalPrefix+"EnableRotate", config->EnableRotate);

    write_ini((dir + "/" + file).toStdString(), tree);
}