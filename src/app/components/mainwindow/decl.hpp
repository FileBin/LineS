#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qobject.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // Forward declaration of the generated UI class
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // This slot will be connected manually or via auto-connection if named on_<objectname>_<signal>
    void on_myButton_clicked(bool checked);
    
private:
    QString button_text;
    Ui::MainWindow *ui; // Pointer to the generated UI object
};

#endif // MAINWINDOW_H