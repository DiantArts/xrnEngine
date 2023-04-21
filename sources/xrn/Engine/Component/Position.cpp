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
    ::xrn::Time deltaTime
    , const ::xrn::engine::component::Control& control
    , const ::glm::vec3& direction
) -> Position&
{
    ::xrn::engine::component::Velocity value;
    value.update(deltaTime, control);

    if (value == 0.f) {
        return *this;
    }

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                this->moveUp(value, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(value, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(value, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(value, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(value, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(value, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::engine::component::Control& control
    , const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    if (value == 0.f) {
        return *this;
    }

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                this->moveUp(value, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(value, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(value, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(value, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(value, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(value, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    if (value == 0.f) {
        return *this;
    }

    this->moveForward(value, direction);
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
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value += value.get() * direction;
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveBackward(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= value.get() * direction;
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveRight(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * value.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveLeft(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value += ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * value.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveUp(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y -= value.get();
    this->setChangedFlag();

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveDown(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y += value.get();
    this->setChangedFlag();

    return *this;
}
