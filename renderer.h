#ifndef RENDERER_H
#define RENDERER_H

#include <QWindow>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QElapsedTimer>

#include "input.h"

class QOpenGLContext;
class Shader;
class MainWindow;
class GameObject;
class Camera;
class Texture;

/// This inherits from QWindow to get access to the Qt functionality and
// OpenGL surface.
// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
// This is the same as using "glad" and "glw" from general OpenGL tutorials
class Renderer : public QWindow, protected QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    Renderer(const QSurfaceFormat &format, MainWindow *mainWindow);
    ~Renderer() override;

    QOpenGLContext *context() { return mContext; }

    void exposeEvent(QExposeEvent *) override;  //gets called when app is shown and resized

    bool mMove{false};     //Check if triangle should move
    void toggleWireframe(bool toggle);
    void toggleBackfaceCulling(bool toggle);

    class Light *mLight{nullptr};

private slots:
    void render();          //the actual render - function

private:
    void init();            //initialize things we need before rendering

    ///Helper function that uses QOpenGLDebugLogger or plain glGetError()
    void checkForGLerrors();

    ///calculates framerate on basis of a timer in render() function
    void calculateFramerate();

    ///Starts QOpenGLDebugLogger if possible
    void startOpenGLDebugger();

    void setCameraSpeed(float value);

    void handleInput();

    void setupPlainShader(int shaderIndex);
    GLint mMatrixUniform0{-1};
    GLint vMatrixUniform0{-1};
    GLint pMatrixUniform0{-1};

    void setupTextureShader(int shaderIndex);
    GLint mMatrixUniform1{-1};
    GLint vMatrixUniform1{-1};
    GLint pMatrixUniform1{-1};
    GLint mTextureUniform1{-1};

    void setupPhongShader(int shaderIndex);
    GLint mMatrixUniform2{-1};
    GLint vMatrixUniform2{-1};
    GLint pMatrixUniform2{-1};

    //other light shader variables
    GLint mLightColorUniform{-1};
    GLint mObjectColorUniform{-1};
    GLint mAmbientLightStrengthUniform{-1};
    GLint mLightPositionUniform{-1};
    GLint mCameraPositionUniform{-1};
    GLint mSpecularStrengthUniform{-1};
    GLint mSpecularExponentUniform{-1};
    GLint mLightPowerUniform{-1};
    GLint mTextureUniform2{-1};

    Texture *mTexture[4]{nullptr}; //We can hold 4 textures
    Shader *mShaderProgram[4]{nullptr}; //We can hold 4 shaders

    Camera *mCurrentCamera{nullptr};
    float mAspectratio{1.f};

    std::vector<GameObject*> mVisualObjects;

    Input mInput;
    float mCameraSpeed{0.05f};
    float mCameraRotateSpeed{0.1f};
    int mMouseXlast{0};
    int mMouseYlast{0};

    QOpenGLContext *mContext{nullptr};  //Our OpenGL context
    bool mInitialized{false};

    QTimer *mRenderTimer{nullptr};           //timer that drives the gameloop
    QElapsedTimer mTimeStart;               //time variable that reads the calculated FPS

    MainWindow *mMainWindow{nullptr};        //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger *mOpenGLDebugLogger{nullptr};  //helper class to get some clean debug info from OpenGL
    class Logger *mLogger{nullptr};         //logger - Output Log in the application

protected:
    //The QWindow that we inherit from have these functions to capture
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
};

#endif // RENDERER_H
