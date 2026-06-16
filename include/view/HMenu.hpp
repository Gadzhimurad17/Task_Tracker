#include <QMenu>
#include <QMenuBar>
#include <QWidget>
namespace HorisontalMenu {
class HMenu : QWidget
{
    QMenu *menu_;

public:
    HMenu(QWidget *parent = nullptr)
    {
        menu_ = new QMenu(this);
        menu_->addAction("Add");
        menu_->show();
    }
};

} // namespace HorisontalMenu