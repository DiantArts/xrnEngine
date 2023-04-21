#include <pch.hpp>
#include <xrn/Engine/Component/Position.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Component/Velocity.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position()
    : ::xrn::engine::component::detail::Vector3<Position>{ ::glm::vec3{ 0.f, 0.f, 0.f } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float value
)
    : ::xrn::engine::component::detail::Vector3<Position>{ ::glm::vec3{ value, value, value } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    ::glm::vec3 value
)
    : ::xrn::engine::component::detail::Vector3<Position>{ ::std::move(value) }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float valueX
    , const float valueY
    , const float valueZ
)
    : ::xrn::engine::component::detail::Vector3<Position>{
        ::glm::vec3{ valueX, valueY, valueZ }
    }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Update
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Control& control
    , const ::glm::vec3& direction
) -> Position&
{
    ::xrn::engine::component::Velocity velocity;
    velocity.update(control);

    if (velocity == 0.f) {
        return *this;
    }

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                this->moveUp(deltaTime, velocity, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(deltaTime, velocity, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(deltaTime, velocity, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(deltaTime, velocity, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(deltaTime, velocity, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(deltaTime, velocity, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Control& control
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    if (velocity == 0.f) {
        return *this;
    }

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                this->moveUp(deltaTime, velocity, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(deltaTime, velocity, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(deltaTime, velocity, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(deltaTime, velocity, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(deltaTime, velocity, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(deltaTime, velocity, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    if (velocity == 0.f) {
        return *this;
    }

    this->moveForward(deltaTime, velocity, direction);
    return *this;
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Position
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveForward(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_value += direction * velocity * deltaTime.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveBackward(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= direction * velocity * deltaTime.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveRight(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.f, 1.f, 0.f })) * velocity.get() * deltaTime.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveLeft(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_value += ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * velocity.get() * deltaTime.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveUp(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y -= velocity * deltaTime.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveDown(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y += velocity * deltaTime.get();
    this->setChangedFlag();

    return *this;
}
