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
    : ::xrn::engine::component::detail::BasicType<float, Velocity>{ 0.f }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Velocity::Velocity(
    const float value
)
    : ::xrn::engine::component::detail::BasicType<float, Velocity>{ value }
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
    auto speedDirectionDivider{ 2.0f };

    // bot top
    if (control.isAbleToFly()) {
        if (control.isMovingUp()) {
            if (!control.isMovingDown()) {
                speedDirectionDivider /= 1.5f;
            }
        } else if (control.isMovingDown()) {
            speedDirectionDivider /= 1.5f;
        }
    }

    // left right
    if (control.isMovingLeft()) {
        if (!control.isMovingRight()) {
            speedDirectionDivider /= 1.5f;
        }
    } else if (control.isMovingRight()) {
        speedDirectionDivider /= 1.5f;
    }

    // forward backward
    if (speedDirectionDivider > 1.0f) {
        if (control.isMovingForward()) {
            if (!control.isMovingBackward()) {
                speedDirectionDivider /= 1.5f;
            }
        } else if (control.isMovingBackward()) {
            speedDirectionDivider /= 1.5f;
        } else if (speedDirectionDivider == 2.0f) {
            return *this; // not any direction
        }
    }

    // apply movement
    m_value =  control.getSpeed() * speedDirectionDivider / 100'000;
    return *this;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Velocity::apply(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Acceleration& acceleration
) -> Velocity&
{
    m_value += acceleration * deltaTime.get();
    return *this;
}
