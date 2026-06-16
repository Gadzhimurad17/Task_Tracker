#pragma once
#include <QString>
#include <QVector>

#include <QDockWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include "View.hpp"
namespace SidePannels {
class SideBar : public QDockWidget
{
public:
    SideBar(View::MainWindow *parent);

    void AddIcon(const char *name, const QString path);
    void AddButton(const QString str);
    void Seperate();

private:
    QVBoxLayout *layout;
    QWidget *container;
};

} // namespace SidePannels