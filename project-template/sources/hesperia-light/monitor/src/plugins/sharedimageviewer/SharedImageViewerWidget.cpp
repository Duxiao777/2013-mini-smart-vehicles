/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include <algorithm>

#include "QtIncludes.h"

#include "core/macros.h"
#include "core/base/Lock.h"
#include "core/data/Container.h"
#include "core/wrapper/SharedMemoryFactory.h"

#include "plugins/sharedimageviewer/SharedImageViewerWidget.h"

namespace plugins {
    namespace sharedimageviewer {

        using namespace std;
        using namespace core::base;
        using namespace core::data;
        using namespace hesperia::data;
        using namespace hesperia::data::image;

        SharedImageViewerWidget::SharedImageViewerWidget(const PlugIn &/*plugIn*/, QWidget *prnt) :
                QWidget(prnt),
                m_sharedImageMemoryMutex(),
                m_sharedImage(),
                m_sharedImageMemory(),
                m_drawableImage(NULL),
                m_list(NULL),
				m_listOfAvailableSharedImages(),
				m_mapOfAvailableSharedImages() {

            // Set size.
            setMinimumSize(640, 480);

            QGridLayout *gridLayout = new QGridLayout(this);

            m_list = new QListWidget(this);
            connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(selectedSharedImage(QListWidgetItem*)));

            gridLayout->addWidget(m_list);

            setLayout(gridLayout);

            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(update()));
            const uint32_t fps = 25;
            timer->start(1000 / fps);
        }

        SharedImageViewerWidget::~SharedImageViewerWidget() {
            Lock l(m_sharedImageMemoryMutex);

            HESPERIA_CORE_DELETE_POINTER(m_drawableImage);
        }

        void SharedImageViewerWidget::selectedSharedImage(QListWidgetItem *item) {
        	if (item != NULL) {
        		// Retrieve stored shared image.
        		SharedImage si = m_mapOfAvailableSharedImages[item->text().toStdString()];

        		if ( (si.getWidth() * si.getHeight()) > 0 ) {
        			Lock l(m_sharedImageMemoryMutex);

        			cerr << "Using shared image: " << si.toString() << endl;
                    setWindowTitle(QString::fromStdString(si.toString()));

        			m_sharedImageMemory = core::wrapper::SharedMemoryFactory::getInstance().attachToSharedMemory(si.getName());
        			m_sharedImage = si;

        			// Remove the selection box.
        			m_list->hide();
        		}
        	}
        }

        void SharedImageViewerWidget::nextContainer(Container &c) {
            if (c.getDataType() == Container::SHARED_IMAGE) {
                SharedImage si = c.getData<SharedImage>();

                if ( ( (si.getWidth() * si.getHeight()) > 0) && (si.getName().size() > 0) ) {
                	// Check if this shared image is already in the list.
                	vector<string>::iterator result = std::find(m_listOfAvailableSharedImages.begin(), m_listOfAvailableSharedImages.end(), si.getName());
                	if (result == m_listOfAvailableSharedImages.end()) {
                		m_listOfAvailableSharedImages.push_back(si.getName());

                		QString item = QString::fromStdString(si.getName());
                		m_list->addItem(item);

                		// Store for further usage.
                		m_mapOfAvailableSharedImages[si.getName()] = si;
                	}
                }
            }
        }

        void SharedImageViewerWidget::paintEvent(QPaintEvent * /*evnt*/) {
            Lock l(m_sharedImageMemoryMutex);

            if ( (m_sharedImageMemory.isValid()) && (m_sharedImageMemory->isValid()) ) {
                m_sharedImageMemory->lock();

                HESPERIA_CORE_DELETE_POINTER(m_drawableImage);
                m_drawableImage = new QImage((uchar*)(static_cast<char*>(m_sharedImageMemory->getSharedMemory())), m_sharedImage.getWidth(), m_sharedImage.getHeight(), m_sharedImage.getBytesPerPixel() * m_sharedImage.getWidth(), QImage::Format_RGB888);
                if (m_drawableImage != NULL) {
                    *m_drawableImage = m_drawableImage->rgbSwapped();
                    QPainter widgetPainter(this);
                    widgetPainter.drawImage(0, 0, *m_drawableImage);
                }
                m_sharedImageMemory->unlock();
            }
        }

    }
} // plugins::sharedimageviewer
