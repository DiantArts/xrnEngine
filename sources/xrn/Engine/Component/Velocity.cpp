#include <glm/geometric.hpp>
#include <pch.hpp>
#include <xrn/Engine/Component/Velocity.hpp>
#include <xrn/Engine/Component/Control.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Velocity::Velocity()
    : ::xrn::engine::component::detail::Vector3<Velocity>{ ::glm::vec3{ 0.f, 0.f, 0.f } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Velocity::Velocity(
    const float value
)
    : ::xrn::engine::component::detail::Vector3<Velocity>{ ::glm::vec3{ value, value, value } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Velocity::Velocity(
    ::glm::vec3 value
)
    : ::xrn::engine::component::detail::Vector3<Velocity>{ ::std::move(value) }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Velocity::Velocity(
    const float valueX
    , const float valueY
    , const float valueZ
)
    : ::xrn::engine::component::detail::Vector3<Velocity>{
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
auto ::xrn::engine::component::Velocity::update(
    const ::xrn::engine::component::Control& control
) -> Velocity&
{
    // search the number of directions moving in and removing speed when multiple direction at once
    // auto speedDirectionDivider{ 2.f };

    // bot top
    // if (control.isAbleToFly()) {
        // if (control.isMovingUp()) {
            // if (!control.isMovingDown()) {
                // speedDirectionDivider /= 1.5f;
            // }
        // } else if (control.isMovingDown()) {
            // speedDirectionDivider /= 1.5f;
        // }
    // }

    // left right
    // if (control.isMovingLeft()) {
        // if (!control.isMovingRight()) {
            // speedDirectionDivider /= 1.5f;
        // }
    // } else if (control.isMovingRight()) {
        // speedDirectionDivider /= 1.5f;
    // }

    // forward backward
    // if (speedDirectionDivider > 1.f) {
        // if (control.isMovingForward()) {
            // if (!control.isMovingBackward()) {
                // speedDirectionDivider /= 1.5f;
            // }
        // } else if (control.isMovingBackward()) {
            // speedDirectionDivider /= 1.5f;
        // } else if (speedDirectionDivider == 2.f) {
            // return *this; // not any direction
        // }
    // }

    // apply movement
    // m_value =  control.getSpeed() * speedDirectionDivider / 100'000;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::updateDirection(
    const ::glm::vec3& direction
) -> Velocity&
{
    return this->set(::glm::length(this->get()) * ::glm::normalize(direction));
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::applyAcceleration(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Acceleration& acceleration
) -> Velocity&
{
    return this->add(*acceleration * deltaTime.getAsSeconds());
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::applyAcceleration(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Acceleration& acceleration
    , const ::xrn::engine::component::Mass& mass
) -> Velocity&
{
    return this->add((*acceleration / mass) * deltaTime.getAsSeconds());
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Update
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateForward(
    // const ::glm::vec3& direction
// ) -> Velocity&
// {
    // return this->add(direction);
// }

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateBackward(
    // const ::glm::vec3& direction
// ) -> Velocity&
// {
    // return this->add(-direction);
// }

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateRight(
    // const ::glm::vec3& direction
// ) -> Velocity&
// {
    // return this->add(-::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.f, 1.f, 0.f })));
// }

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateLeft(
    // const ::glm::vec3& direction
// ) -> Velocity&
// {
    // return this->add(::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.f, 1.f, 0.f })));
// }

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateUp(
    // const ::glm::vec3& direction [[ maybe_unused ]]
// ) -> Velocity&
// {
    // m_value.y -= velocity.getY() * deltaTime.getAsSeconds();
    // return this->add(-::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.f, 0.f, 1.f })));
// }

///////////////////////////////////////////////////////////////////////////
// auto ::xrn::engine::component::Velocity::updateDown(
    // const ::glm::vec3& direction [[ maybe_unused ]]
// ) -> Velocity&
// {
    // m_value.y += velocity.getY() * deltaTime.getAsSeconds();
    // return this->add(::glm::normalize(::glm::cross(direction, ::glm::vec3{ 0.f, 0.f, 1.f })));
// }




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::setMaximumSpeed(
    float value
) -> Velocity&
{
    m_maximumSpeed = value;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::getMaximumSpeed() const
    -> float
{
    return m_maximumSpeed;
}
