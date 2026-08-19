#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QWidget;
class Renderer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    ///Slot called from the button in the mainwindow.ui file
    void on_movementButton_toggled(bool checked);
    ///Slot called from the button in the mainwindow.ui file
    void on_wireframeButton_toggled(bool checked);
    ///Slot called from the File->Exit menu in the mainwindow.ui file
    void on_fileExit_triggered();


    void on_backfaceButton_toggled(bool checked);

    void on_horizontalSlider_sliderMoved(int position);

private:
    ///called from the constructor. Initializes different parts of the program.
    void init();

    Ui::MainWindow *ui{nullptr};                //the GUI of the app
    QWidget *mRenderWindowContainer{nullptr};   //Qt container for the Renderer
    Renderer *mRenderWindow{nullptr};       //The class that actually renders OpenGL

    //Logger class uses private ui pointer from this class
    friend class Logger;
};

#endif // MAINWINDOW_H
