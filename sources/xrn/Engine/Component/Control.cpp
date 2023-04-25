#include <pch.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Component/Transform3d.hpp>
#include <xrn/Engine/Component/Direction.hpp>
#include <xrn/Engine/Component/Velocity.hpp>
#include <xrn/Engine/Configuration.hpp>


// ------------------------------------------------------------------ *structors

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Control::Control(
    bool ableToFly
)
    : m_ableToFly{ ableToFly }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Speed
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::getSpeed() const
    -> float
{
    return m_moveSpeed;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::setSpeed(
    float speed
) -> Control&
{
    m_moveSpeed = speed;
    return *this;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Start/stop moving
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingForward(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::forward] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingBackward(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::backward] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingRight(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::right] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingLeft(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::left] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingUp(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::up] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::startMovingDown(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::down] = true;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingForward(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::forward] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingBackward(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::backward] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingRight(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::right] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingLeft(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::left] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingUp(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::up] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMovingDown(
    const ::xrn::engine::component::Direction& direction
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState[Control::MovementState::down] = false;
    return this->updateAcceleration(direction, velocity);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::stopMoving(
    const ::xrn::engine::component::Direction& direction [[ maybe_unused ]]
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState.reset();
    velocity.removeAcceleration(m_acceleration);
    m_acceleration.set(::glm::vec3{ 0 });
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::immobilize(
    const ::xrn::engine::component::Direction& direction [[ maybe_unused ]]
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    m_movementState.reset();
    velocity.removeAcceleration(m_acceleration);
    m_acceleration.set(::glm::vec3{ 0 });
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::updateAcceleration(
    const ::xrn::engine::component::Direction& direction [[ maybe_unused ]]
    , ::xrn::engine::component::Velocity& velocity
) -> Control&
{
    velocity.removeAcceleration(m_acceleration);
    m_acceleration.set(::glm::vec3{ 0 });

    // bot top
    if (this->isAbleToFly()) {
        if (this->isMovingUp()) {
            if (!this->isMovingDown()) {
                m_acceleration += ::glm::vec3(0.0f, 1.0f, 0.0f);
            }
        } else if (this->isMovingDown()) {
            m_acceleration -= ::glm::vec3(0.0f, 1.0f, 0.0f);
        }
    }

    // left right
    if (this->isMovingLeft()) {
        if (!this->isMovingRight()) {
            m_acceleration -= ::glm::normalize(glm::cross(*direction, ::glm::vec3(0.0f, 1.0f, 0.0f)));;
        }
    } else if (this->isMovingRight()) {
        m_acceleration += ::glm::normalize(glm::cross(*direction, ::glm::vec3(0.0f, 1.0f, 0.0f)));;
    }

    // forward backward
    if (this->isMovingForward()) {
        if (!this->isMovingBackward()) {
            m_acceleration += *direction;
        }
    } else if (this->isMovingBackward()) {
        m_acceleration -= *direction;
    }

    if (m_acceleration.getX() == 0.f && m_acceleration.getY() == 0.f && m_acceleration.getZ() == 0.f) {
        return *this; // not any direction
    }

    m_acceleration.setMagnitude(this->getSpeed());
    velocity.applyAcceleration(m_acceleration);

    return *this;
}

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::xrn::engine::component::Control::getAcceleration() const
    -> const ::xrn::engine::component::Acceleration&
{
    return m_acceleration;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Check if moving
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingForward() const
    -> bool
{
    return m_movementState.test(Control::MovementState::forward);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingBackward() const
    -> bool
{
    return m_movementState.test(Control::MovementState::backward);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingRight() const
    -> bool
{
    return m_movementState.test(Control::MovementState::right);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingLeft() const
    -> bool
{
    return m_movementState.test(Control::MovementState::left);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingUp() const
    -> bool
{
    return m_movementState.test(Control::MovementState::up);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isMovingDown() const
    -> bool
{
    return m_movementState.test(Control::MovementState::down);
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Rotation
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotate(
    const ::glm::vec3& offset
) -> Control&
{
    return this->rotate(offset.x, offset.y, offset.z);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotate(
    const float rotationOffsetX
    , const float rotationOffsetY
    , const float rotationOffsetZ
) -> Control&
{
    return this->rotate(rotationOffsetX, rotationOffsetY, rotationOffsetZ);
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateX(
    const float offset
) -> Control&
{
    m_rotation.addX(offset * ::xrn::engine::configuration.sensitivity.x);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateY(
    const float offset
) -> Control&
{
    m_rotation.addY(offset * ::xrn::engine::configuration.sensitivity.y);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateZ(
    const float offset
) -> Control&
{
    m_rotation.addY(offset * ::xrn::engine::configuration.sensitivity.z);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateAbsolute(
    ::glm::vec3 rotation
) -> Control&
{
    m_rotation.set(::std::move(rotation));
    return *this;
}


///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateAbsolute(
    const float rotationX
    , const float rotationY
    , const float rotationZ
) -> Control&
{
    m_rotation.set(::glm::vec3{ rotationX, rotationY, rotationZ });
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateAbsoluteX(
    const float rotationX
) -> Control&
{
    m_rotation.setX(rotationX);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateAbsoluteY(
    const float rotationY
) -> Control&
{
    m_rotation.setY(rotationY);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::rotateAbsoluteZ(
    const float rotationZ
) -> Control&
{
    m_rotation.setY(rotationZ);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isRotated() const
    -> bool
{
    return m_rotation.getX() != 0.f || m_rotation.getY() != 0.f || m_rotation.getZ() != 0.f;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::resetRotatedFlag()
    -> Control&
{
    m_rotation.set(0.f);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::getRotation() const
    -> const ::xrn::engine::component::Rotation&
{
    return m_rotation;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Others
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Control::isAbleToFly() const
    -> bool
{
    return m_ableToFly;
}
