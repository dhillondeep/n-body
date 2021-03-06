#ifndef SIMVIEW_H
#define SIMVIEW_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <engine/EngineThread.h>
#include <memory>
#include <rendering/Renderer.h>

class SimView : public QOpenGLWidget {
    Q_OBJECT

  public:
    explicit SimView(QWidget *parent = nullptr);
    ~SimView() override;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

  private:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

  private:
    std::unique_ptr<Renderer> m_renderer;
    EngineThread m_engineThread;
};

#endif // SIMVIEW_H
