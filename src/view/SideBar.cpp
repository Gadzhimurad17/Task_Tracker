#include "view/SideBar.hpp"
#include <QIcon>
#include <QPushButton>

SidePannels::SideBar::SideBar(View::MainWindow *parent)
{
    container = new QWidget();
    layout = new QVBoxLayout(container);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 20, 10, 10);
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);

    this->setStyleSheet(R"(
        QWidget {
            background-color: #1f2126;
            border-right: 1px solid #2a2d34;
        }
    )");
    this->setWidget(container);
    parent->addDockWidget(Qt::LeftDockWidgetArea, this);
}

void SidePannels::SideBar::AddIcon(const char *name, const QString path)
{
    QPushButton *button = new QPushButton(name);
    button->setStyleSheet(R"(
        QPushButton {
            color: white;
            border-radius: 8px;
            padding: 8px;
            background: qlineargradient(
                x1:0, y1:0, x2:0, y2:1,
                stop:0 #3c82ff,
                stop:1 #2a5fd7
            );
        }

        QPushButton:hover {
            background: qlineargradient(
                x1:0, y1:0, x2:0, y2:1,
                stop:0 #4a8dff,
                stop:1 #336be0
            );
        }

        QPushButton:pressed {
            background-color: #244fb3;
        }
    )");
    QPixmap pixmap(path);
    QIcon buttonIcon(pixmap);
    if (pixmap.isNull())
    {
        qDebug() << "Не загрузилось";
    }
    button->setIcon(buttonIcon);
    layout->addWidget(button);
}

void SidePannels::SideBar::AddButton(const QString str)
{
    QPushButton *button = new QPushButton(str);
    button->setStyleSheet(R"(
        QPushButton {
            color: white;
            border-radius: 8px;
            padding: 8px;
            background: qlineargradient(
                x1:0, y1:0, x2:0, y2:1,
                stop:0 #3c82ff,
                stop:1 #2a5fd7
            );
        }

        QPushButton:hover {
            background: qlineargradient(
                x1:0, y1:0, x2:0, y2:1,
                stop:0 #4a8dff,
                stop:1 #336be0
            );
        }

        QPushButton:pressed {
            background-color: #244fb3;
        }
    )");
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout->addWidget(button);
}
void SidePannels::SideBar::Seperate()
{
    layout->addStretch();
}
