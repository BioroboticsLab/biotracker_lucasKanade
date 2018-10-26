#include "TrackerParameter.h"
#include "../Controller/ControllerTrackingAlgorithm.h"

TrackerParameter::TrackerParameter(IController *parent) :
    IModel(parent)
{
	_cfg = static_cast<ControllerTrackingAlgorithm*>(parent)->getConfig();
	m_wndSize = _cfg->WndSize;


    Q_EMIT notifyView();
}
