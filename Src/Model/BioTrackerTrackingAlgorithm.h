#ifndef BIOTRACKERTRACKINGALGORITHM_H
#define BIOTRACKERTRACKINGALGORITHM_H

#include "Interfaces/IModel/IModelTrackingAlgorithm.h"
#include "Interfaces/IModel/IModelDataExporter.h"
#include "Interfaces/IModel/IModelAreaDescriptor.h"
#include "Interfaces/IModel/IModel.h"
#include "Interfaces/IController/IController.h"
#include "Utility/TrackedComponents/TrackedElement.h"
#include "Utility/TrackedComponents/TrackedTrajectory.h"
#include "TrackerParameter.h"
#include "../Config.h"
#include <opencv2/opencv.hpp>
#include <iostream>

class BioTrackerTrackingAlgorithm : public IModelTrackingAlgorithm
{
    Q_OBJECT
public:
    BioTrackerTrackingAlgorithm(IController *parent, IModel* parameter, IModel* trajectory);
	~BioTrackerTrackingAlgorithm();

Q_SIGNALS:
    void emitCvMatA(std::shared_ptr<cv::Mat> image, QString name);
	void emitDimensionUpdate(int x, int y);
	void emitTrackingDone(uint framenumber);

    // ITrackingAlgorithm interface
public Q_SLOTS:
	void doTracking(std::shared_ptr<cv::Mat> image, uint framenumber) override;
	void receiveAreaDescriptorUpdate(IModelAreaDescriptor *areaDescr);
    void receiveParametersChanged();
	void setCoordUnit(QString unit);
private:
	void refreshPolygon();
    void sendSelectedImage(std::map<std::string, std::shared_ptr<cv::Mat>>* images);

	void resetFishHistory(int noFish);

    TrackedTrajectory* _TrackedTrajectoryMajor;
	TrackerParameter* _TrackingParameter;
	IModelAreaDescriptor* _AreaInfo;

	int _imageX;
	int _imageY;

    std::shared_ptr<cv::Mat> _lastImage;
    uint _lastFramenumber;
	Config *_cfg;
	QString _coordUnit;
};

#endif // BIOTRACKERTRACKINGALGORITHM_H
