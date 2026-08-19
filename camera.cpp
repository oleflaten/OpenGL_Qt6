#include "camera.h"

Camera::Camera()
{
    mViewMatrix = glm::mat4(1.0f);
    mProjectionMatrix = glm::mat4(1.0f);
}

void Camera::pitch(float degrees)
{
     mPitch -= degrees;
    updateForwardVector();
}

void Camera::yaw(float degrees)
{
     mYaw -= degrees;
    updateForwardVector();
}

void Camera::updateForwardVector()
{
    float pitch = glm::radians(mPitch);
    float yaw = glm::radians(mYaw);

    mForward = glm::normalize(glm::vec3(
        glm::sin(yaw) * glm::cos(pitch),
        glm::sin(pitch),
        -glm::cos(yaw) * glm::cos(pitch)));

    mRight = glm::normalize(glm::cross(mForward, glm::vec3(0.f, 1.f, 0.f)));
    mUp = glm::normalize(glm::cross(mRight, mForward));
}

void Camera::update()
{
    mPosition -= mForward * mSpeed;

    mViewMatrix = glm::lookAt(mPosition, mPosition + mForward, mUp);
}

void Camera::setPosition(const glm::vec3 &position)
{
    mPosition = position;
    update();
}

void Camera::setSpeed(float speed)
{
    mSpeed = speed;
}

void Camera::updateHeigth(float deltaHeigth)
{
    mPosition.y += deltaHeigth;
}

void Camera::moveRight(float delta)
{
    mPosition += mRight * delta;
}

glm::vec3 Camera::position() const
{
    return mPosition;
}

glm::vec3 Camera::up() const
{
    return mUp;
}
