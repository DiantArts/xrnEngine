///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/System/UpdatePosition.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
::xrn::engine::system::UpdatePosition::UpdatePosition()
    : m_defaultDirection{
        ::glm::normalize(::glm::vec3(
            ::glm::cos(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
            , ::glm::sin(::glm::radians(0.0f))
            , ::glm::sin(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
        ))
    }
{}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdatePosition::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Position& position
    , ::xrn::OptRef<::xrn::engine::component::Control> control
    , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
    , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
) const
{
    if (control) {
        ::xrn::OptRef<const ::glm::vec3> direction;
        if (rotation) {
            rotation->updateDirection(control);
            direction = rotation->getDirection();
        } else {
            direction = m_defaultDirection;
        }

        if (velocity) {
            velocity->update(control);

            // TODO: acceleration with control not working
            if (acceleration) {
                velocity->apply(frameInfo.deltaTime, acceleration);
            }

            position.update(frameInfo.deltaTime, control, velocity, direction);
        } else {
            position.update(frameInfo.deltaTime, control, direction);
        }
        return;
    }
    if (velocity) {
        ::xrn::OptRef<const ::glm::vec3> direction;
        if (rotation) {
            rotation->updateDirection();
            direction = rotation->getDirection();
        } else {
            direction = m_defaultDirection;
        }

        if (acceleration) {
            velocity->apply(frameInfo.deltaTime, acceleration);
        }

        position.update(frameInfo.deltaTime, velocity, direction);
    }
}
