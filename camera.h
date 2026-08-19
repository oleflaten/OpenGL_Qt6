#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
  Clean glm-based camera. Yaw/pitch drive mForward each frame and the view
  matrix is built with glm::lookAt.
  */
class Camera
{
public:
    Camera();

    void pitch(float degrees);
    void yaw(float degrees);
    void update();

    glm::mat4 mViewMatrix;
    glm::mat4 mProjectionMatrix;

    void setPosition(const glm::vec3 &position);
    void setSpeed(float speed);
    void updateHeigth(float deltaHeigth);
    void moveRight(float delta);

    glm::vec3 position() const;
    glm::vec3 up() const;

private:
    void updateForwardVector();

    glm::vec3 mPosition{0.f, 0.f, 0.f};
    glm::vec3 mForward{0.f, 0.f, -1.f};
    glm::vec3 mRight{1.f, 0.f, 0.f};
    glm::vec3 mUp{0.f, 1.f, 0.f};

    float mPitch{0.f};
    float mYaw{0.f};

    float mSpeed{0.f}; //camera will move by this speed along the mForward vector
};

#endif // CAMERA_H
