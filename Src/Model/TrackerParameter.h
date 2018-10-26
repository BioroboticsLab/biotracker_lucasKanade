#ifndef TRACKERPARAMETER_H
#define TRACKERPARAMETER_H


#include "Interfaces/IModel/IModel.h"
#include "Interfaces/IController/IController.h"
#include "ParamNames.h"
#include "../Config.h"

class TrackerParameter : public IModel
{
    Q_OBJECT
public:
    TrackerParameter(IController *parent = 0);

	int getWndSize() { return m_wndSize; };
	void setWndSize(int x) {
        m_wndSize = x;
		Q_EMIT notifyView();
	};
    
	void setAll(
		int wndSize)
	{
        m_wndSize = wndSize;
		_cfg->WndSize = wndSize;
		Q_EMIT notifyView();
	};



private:

	int m_wndSize;
	Config *_cfg;
};

#endif // TRACKERPARAMETER_H
