#pragma once
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QWidget>
namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    explicit MainWindow();
    ~MainWindow();
    void createGlobalWindow();
protected:
};
} // namespace View