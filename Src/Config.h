#pragma once

#include "IConfig.h"
#include <QString>
#include <map>

class Config : public IConfig
{
public:

    int WndSize = 31;
    int EnableView = 1;
    int EnableMove = 1;
    int EnableRemove = 1;
    int EnableSwap = 1;
    int EnableAdd = 1;
    int EnableRotate = 0;

    void load(QString dir, QString file = "config.ini") override;
    void save(QString dir, QString file) override;
    
    static const QString DefaultArena;
};
