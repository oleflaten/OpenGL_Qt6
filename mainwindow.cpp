#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSurfaceFormat>
#include <QDebug>

#include "renderer.h"
#include "logger.h"
#include "light.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    //this sets up what's in the mainwindow.ui - the GUI
    ui->setupUi(this);
    init(); //initializes parts of the program
}

MainWindow::~MainWindow()
{
    delete mRenderWindow;
    delete ui;
}

void MainWindow::init()
{
    //This will contain the setup of the OpenGL surface we will render into
    QSurfaceFormat format;

    //OpenGL v 4.1 - (Ole Flatens Mac does not support higher than this - sorry!)
    //you can try other versions, but then have to update RenderWindow and Shader
    //to inherit from other than QOpenGLFunctions_4_1_Core
    //(The 3DProgramming course does not use anything from higher than 4.1, so please don't change it)
    format.setVersion(4, 1);
    //Using the main profile for OpenGL - no legacy code permitted
    format.setProfile(QSurfaceFormat::CoreProfile);
    //A QSurface can be other types than OpenGL
    format.setRenderableType(QSurfaceFormat::OpenGL);

    //This should activate OpenGL debug Context used in RenderWindow::startOpenGLDebugger().
    //This line (and the startOpenGLDebugger() and checkForGLerrors() in RenderWindow class)
    //can be deleted, but it is nice to have some OpenGL debug info!
    format.setOption(QSurfaceFormat::DebugContext);

    // The surface will need a depth buffer - (not requiered to set in glfw-tutorials)
    format.setDepthBufferSize(24);

    //Set the number of samples used for multisampling
    //Same as glfwWindowHint(GLFW_SAMPLES, 4);
    //https://learnopengl.com/Advanced-OpenGL/Anti-Aliasing
    format.setSamples(4);

    //Just prints out what OpenGL format we try to get
    // - this can be deleted
    qDebug() << "Requesting surface format: " << format;

    //We have a surface format for the OpenGL window, so let's make it:
    mRenderWindow = new Renderer(format, this);

    //Check if renderwindow did initialize, else prints error and quit
    if (!mRenderWindow->context()) {
        qDebug() << "Failed to create context. Can not continue. Quits application!";
        delete mRenderWindow;
        return;
    }

    //The OpenGL RenderWindow got made, so continuing the setup:
    //We put the RenderWindow inside a QWidget so we can put in into a
    //layout that is made in the .ui-file
    // (Qt has a QOpenGLWidget but that forces us to use more Qt specific OpenGL-stuff
    //  So we make a renderwindow manually to get more freedom)
    mRenderWindowContainer = QWidget::createWindowContainer(mRenderWindow);
    //OpenGLLayout is made in the mainwindow.ui-file!
    ui->OpenGLLayout->addWidget(mRenderWindowContainer);

    //sets the keyboard input focus to the RenderWindow when program starts
    // - can be deleted, but then you have to click inside the renderwindow to get the focus
    mRenderWindowContainer->setFocus();

    //feed in MainWindow to the logger - has to be done, else logger will crash program
    Logger::getInstance()->setMainWindow(this);;
}

//Example of a slot called from the button on the top of the program.
void MainWindow::on_movementButton_toggled(bool checked)
{
    if(checked)
    {
        mRenderWindow->mMove = true;
        ui->movementButton->setText("Stop movement");
    }
    else
    {
        mRenderWindow->mMove = false;
        ui->movementButton->setText("Start movement");
    }
}

void MainWindow::on_wireframeButton_toggled(bool checked)
{
    mRenderWindow->toggleWireframe(checked);

    if(checked)
        ui->wireframeButton->setText("Show shaded");
    else
        ui->wireframeButton->setText("Show wireframe");
}

void MainWindow::on_backfaceButton_toggled(bool checked)
{
    mRenderWindow->toggleBackfaceCulling(checked);

    if(checked)
        ui->backfaceButton->setText("Hide backface");
    else
        ui->backfaceButton->setText("Show backface");
}

//File menu Exit closes the program
void MainWindow::on_fileExit_triggered()
{
    close();       //Shuts down the whole program
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    mRenderWindow->mLight->mSpecularStrenght = position/100.f;
}

