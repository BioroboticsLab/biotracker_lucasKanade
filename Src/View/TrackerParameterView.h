#ifndef TRACKERPARAMETERVIEW_H
#define TRACKERPARAMETERVIEW_H

#include "Interfaces/IView/IViewWidget.h"
#include "../Model/TrackerParameter.h"

namespace Ui {
	class TrackerParameterView;
}

class TrackerParameterView : public IViewWidget
{
    Q_OBJECT

public:
    explicit TrackerParameterView(QWidget *parent = 0, IController *controller = 0, IModel *model = 0);
    ~TrackerParameterView();

private slots:
	void on_pushButton_clicked();
    void on_rbCm_toggled(bool checked);
    void on_rbPx_toggled(bool checked);
	
public:
	signals:
    void trackingAreaType(int v);
    void parametersChanged();
    void emitCoordUnit(QString unit);

private:
    Ui::TrackerParameterView *ui;

    // IViewWidget interface
public slots:

    void getNotified();
};

#endif // TRACKERPARAMETERVIEW_H
