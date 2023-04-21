#include <compare>
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
    : m_position{ 0.0f, 0.0f, 0.0f }
    , m_isChanged{ true }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    ::glm::vec3 position
)
    : m_position{ ::std::move(position) }
    , m_isChanged{ true }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float positionX
    , const float positionY
    , const float positionZ
)
    : m_position{ positionX, positionY, positionZ }
    , m_isChanged{ true }
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
    ::xrn::engine::component::Velocity velocity;
    velocity.update(deltaTime, control);

    if (velocity == 0.f) {
        return *this;
    }

    ::fmt::print("{}\n", velocity);

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                this->moveUp(velocity, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(velocity, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(velocity, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(velocity, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(velocity, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(velocity, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::engine::component::Control& control
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
                this->moveUp(velocity, direction);
            }
        } else if (control.isMovingDown()) {
            this->moveDown(velocity, direction);
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            this->moveLeft(velocity, direction);
        }
    } else if (control.isMovingRight()) {
        this->moveRight(velocity, direction);
    }

    // forward backward
    if (control.isMovingForward()) {
        if (!control.isMovingBackward()) {
            this->moveForward(velocity, direction);
        }
    } else if (control.isMovingBackward()) {
        this->moveBackward(velocity, direction);
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    if (velocity == 0.f) {
        return *this;
    }

    this->moveForward(velocity, direction);
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
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_position += velocity.get() * direction;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveBackward(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_position -= velocity.get() * direction;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveRight(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_position -= ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * velocity.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveLeft(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction
) -> Position&
{
    m_position += ::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.0f, 1.0f, 0.0f })) * velocity.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveUp(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_position.y -= velocity.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveDown(
    const ::xrn::engine::component::Velocity& velocity
    , const ::glm::vec3& direction [[ maybe_unused ]]
) -> Position&
{
    m_position.y += velocity.get();
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::move(
    const ::glm::vec3& offset
) -> Position&
{
    m_position += offset;
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
    m_position += ::glm::vec3{ offsetX, offsetY, offsetZ };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveX(
    const float offset
) -> Position&
{
    m_position.x += offset;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveY(
    const float offset
) -> Position&
{
    m_position.y -= offset;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::moveZ(
    const float offset
) -> Position&
{
    m_position.z += offset;
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
    const float position
) -> Position&
{
    m_position = ::glm::vec3{ position, position, position };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::set(
    ::glm::vec3 position
) -> Position&
{
    m_position = ::std::move(position);
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
    m_position = ::glm::vec3{ positionX, positionY, positionZ };
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setX(
    const float position
) -> Position&
{
    m_position.x = position;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setY(
    const float position
) -> Position&
{
    m_position.y = position;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::setZ(
    const float position
) -> Position&
{
    m_position.z = position;
    m_isChanged = true;

    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::get() const
    -> const ::glm::vec3&
{
    return m_position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::get()
    -> ::glm::vec3&
{
    return m_position;
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
    if (auto cmp{ m_position.x <=> other }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_position.y <=> other }; cmp != 0) {
        return cmp;
    }
    return this->m_position.z <=> other;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator<=>(
    const ::glm::vec3& other
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_position.x <=> other.x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_position.y <=> other.y }; cmp != 0) {
        return cmp;
    }
    return this->m_position.z <=> other.z;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator<=>(
    const Position& other
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_position.x <=> other.m_position.x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_position.y <=> other.m_position.y }; cmp != 0) {
        return cmp;
    }
    return this->m_position.z <=> other.m_position.z;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator=(
    const float position
) -> Position&
{
    this->set(position);
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator=(
    ::glm::vec3 position
) -> Position&
{
    this->set(::std::move(position));
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+(
    const float position
) -> ::glm::vec3
{
    return m_position + position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+(
    ::glm::vec3 position
) -> ::glm::vec3
{
    return m_position + position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+=(
    const float position
) -> Position&
{
    m_position += position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator+=(
    ::glm::vec3 position
) -> Position&
{
    m_position += position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-(
    const float position
) -> ::glm::vec3
{
    return m_position - position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-(
    ::glm::vec3 position
) -> ::glm::vec3
{
    return m_position - position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-=(
    const float position
) -> Position&
{
    m_position -= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator-=(
    ::glm::vec3 position
) -> Position&
{
    m_position -= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*(
    const float position
) -> ::glm::vec3
{
    return m_position * position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*(
    ::glm::vec3 position
) -> ::glm::vec3
{
    return m_position * position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*=(
    const float position
) -> Position&
{
    m_position *= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*=(
    ::glm::vec3 position
) -> Position&
{
    m_position *= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/(
    const float position
) -> ::glm::vec3
{
    return m_position / position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/(
    ::glm::vec3 position
) -> ::glm::vec3
{
    return m_position / position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/=(
    const float position
) -> Position&
{
    m_position /= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator/=(
    ::glm::vec3 position
) -> Position&
{
    m_position /= position;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::operator const ::glm::vec3&() const
{
    return m_position;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::operator*()
    -> ::glm::vec3&
{
    return m_position;
}
