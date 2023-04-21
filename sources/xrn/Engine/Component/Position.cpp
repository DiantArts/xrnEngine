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
    ::glm::vec3 value
)
    : ::xrn::engine::component::detail::Vector3<Position>{ ::std::move(value) }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float positionX
    , const float positionY
    , const float positionZ
)
    : ::xrn::engine::component::detail::Vector3<Position>{
        ::glm::vec3{ positionX, positionY, positionZ }
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
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveBackward(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= value.get() * direction;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveRight(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value -= ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * value.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveLeft(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction
) -> Position&
{
    m_value += ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * value.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveUp(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y -= value.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveDown(
    const ::xrn::engine::component::Velocity& value
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_value.y += value.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::move(
    const ::glm::vec3& offset
) -> Position&
{
    m_value += offset;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::move(
    const float offsetX
    , const float offsetY
    , const float offsetZ
) -> Position&
{
    m_value += ::glm::vec3{ offsetX, offsetY, offsetZ };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveX(
    const float offset
) -> Position&
{
    m_value.x += offset;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveY(
    const float offset
) -> Position&
{
    m_value.y -= offset;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveZ(
    const float offset
) -> Position&
{
    m_value.z += offset;
    m_isChanged = true;

    return *this;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::set(
    const float value
) -> Position&
{
    m_value = ::glm::vec3{ value, value, value };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::set(
    ::glm::vec3 value
) -> Position&
{
    m_value = ::std::move(value);
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::set(
    const float positionX
    , const float positionY
    , const float positionZ
) -> Position&
{
    m_value = ::glm::vec3{ positionX, positionY, positionZ };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setX(
    const float value
) -> Position&
{
    m_value.x = value;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setY(
    const float value
) -> Position&
{
    m_value.y = value;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setZ(
    const float value
) -> Position&
{
    m_value.z = value;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::get() const
    -> const ::glm::vec3&
{
    return m_value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::get()
    -> ::glm::vec3&
{
    return m_value;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Changed flag
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::isChanged() const
    -> bool
{
    return m_isChanged;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::resetChangedFlag()
    -> Position&
{
    m_isChanged = false;
    return *this;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Comparisons
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator<=>(
    const float other
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_value.x <=> other }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_value.y <=> other }; cmp != 0) {
        return cmp;
    }
    return this->m_value.z <=> other;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator<=>(
    const ::glm::vec3& other
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_value.x <=> other.x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_value.y <=> other.y }; cmp != 0) {
        return cmp;
    }
    return this->m_value.z <=> other.z;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator<=>(
    const Position& other
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_value.x <=> other.m_value.x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_value.y <=> other.m_value.y }; cmp != 0) {
        return cmp;
    }
    return this->m_value.z <=> other.m_value.z;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator=(
    const float value
) -> Position&
{
    this->set(value);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator=(
    ::glm::vec3 value
) -> Position&
{
    this->set(::std::move(value));
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+(
    const float value
) -> ::glm::vec3
{
    return m_value + value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+(
    ::glm::vec3 value
) -> ::glm::vec3
{
    return m_value + value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+=(
    const float value
) -> Position&
{
    m_value += value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+=(
    ::glm::vec3 value
) -> Position&
{
    m_value += value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-(
    const float value
) -> ::glm::vec3
{
    return m_value - value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-(
    ::glm::vec3 value
) -> ::glm::vec3
{
    return m_value - value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-=(
    const float value
) -> Position&
{
    m_value -= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-=(
    ::glm::vec3 value
) -> Position&
{
    m_value -= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*(
    const float value
) -> ::glm::vec3
{
    return m_value * value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*(
    ::glm::vec3 value
) -> ::glm::vec3
{
    return m_value * value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*=(
    const float value
) -> Position&
{
    m_value *= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*=(
    ::glm::vec3 value
) -> Position&
{
    m_value *= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/(
    const float value
) -> ::glm::vec3
{
    return m_value / value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/(
    ::glm::vec3 value
) -> ::glm::vec3
{
    return m_value / value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/=(
    const float value
) -> Position&
{
    m_value /= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/=(
    ::glm::vec3 value
) -> Position&
{
    m_value /= value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::operator const ::glm::vec3&() const
{
    return m_value;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*()
    -> ::glm::vec3&
{
    return m_value;
}
