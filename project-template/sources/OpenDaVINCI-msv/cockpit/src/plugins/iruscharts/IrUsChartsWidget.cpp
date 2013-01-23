/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifdef PANDABOARD
#include <stdc-predef.h>
#endif

#include <cmath>
#include <sstream>

#include "core/data/Constants.h"
#include "core/data/Container.h"

#include "QtIncludes.h"

#include "plugins/iruscharts/IrUsChartsWidget.h"

namespace cockpit {

    namespace plugins {

        namespace iruscharts {

            using namespace std;
            using namespace core::base;
            using namespace core::data;

#ifndef PANDABOARD
            IrUsChartsWidget::IrUsChartsWidget(const PlugIn &/*plugIn*/, const core::base::KeyValueConfiguration &kvc, QWidget *prnt) :
                QWidget(prnt),
                m_listOfPlots(),
                m_listOfPlotCurves(),
                m_listOfData(),
#else
            IrUsChartsWidget::IrUsChartsWidget(const PlugIn &/*plugIn*/, const core::base::KeyValueConfiguration &/*kvc*/, QWidget *prnt) :
                QWidget(prnt),
#endif
                m_data() {

                // Set size.
                setMinimumSize(640, 480);

#ifndef PANDABOARD
                // Setup point distance sensors.
                for (uint32_t i = 0; i < kvc.getValue<uint32_t>("irus.numberOfSensors"); i++) {
                    stringstream sensorID;
                    sensorID << "irus.sensor" << i << ".id";
                    uint16_t id(kvc.getValue<uint16_t>(sensorID.str()));

                    stringstream sensorName;
                    sensorName << "irus.sensor" << i << ".name";
                    string name(kvc.getValue<string>(sensorName.str()));

                    stringstream sensorDistanceFOV;
                    sensorDistanceFOV << "irus.sensor" << i << ".distanceFOV";
                    const double distanceFOV = kvc.getValue<double>(sensorDistanceFOV.str());

                    stringstream desc;
                    desc << name << " (ID: " << id << ") [m]";

                    // Setup plot.
                    QwtPlot *plot = new QwtPlot(this);
                    plot->setAxisScale(QwtPlot::yLeft, -2, distanceFOV);
                    plot->setMinimumSize(350, 300);
                    plot->setCanvasBackground(Qt::white);
                    plot->setFrameStyle(QFrame::NoFrame);
                    plot->setLineWidth(0);
                    plot->setAxisTitle(QwtPlot::xBottom, "t");
                    plot->setAxisTitle(QwtPlot::yLeft, desc.str().c_str());
                    m_listOfPlots.push_back(plot);

                    // Setup data interface.
                    IrUsChartData *dataInterface = new IrUsChartData(m_data, id);
                    m_listOfData.push_back(dataInterface);

                    // Setup data curve.
                    QwtPlotCurve *curve = new QwtPlotCurve();
                    curve->setRenderHint(QwtPlotItem::RenderAntialiased);
                    curve->setData(*dataInterface);
                    curve->attach(plot);
                }

                QScrollArea *scrollArea = new QScrollArea(this);
                QWidget *widgetForScrolling = new QWidget(scrollArea);

                // Combine all plots.
                QHBoxLayout *plotsLayout = new QHBoxLayout(widgetForScrolling);

                vector<QwtPlot*>::iterator it = m_listOfPlots.begin();
                for(;it < m_listOfPlots.end(); it++) {
                    plotsLayout->addWidget((*it));
                }

                widgetForScrolling->setLayout(plotsLayout);
                scrollArea->setWidget(widgetForScrolling);

                QHBoxLayout *mainLayout = new QHBoxLayout(this);
                mainLayout->addWidget(scrollArea);

                setLayout(mainLayout);
#endif
                // Timer for sending data regularly.
                QTimer* timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
                timer->start(50);
            }

            IrUsChartsWidget::~IrUsChartsWidget() {}

            void IrUsChartsWidget::TimerEvent() {
#ifndef PANDABOARD
                vector<QwtPlot*>::iterator it = m_listOfPlots.begin();
                for(;it < m_listOfPlots.end(); it++) {
                    (*it)->replot();
                }
#endif
            }

            void IrUsChartsWidget::nextContainer(Container &container) {
                if (container.getDataType() == Container::USER_DATA_0) {
                    msv::SensorBoardData sbd = container.getData<msv::SensorBoardData>();

                    m_data.push_back(sbd);

                    if (m_data.size() > 10*15) {
                        m_data.pop_front();
                    }
                }
            }

        }
    }
}

