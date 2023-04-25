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
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdatePosition::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Position& position
    , ::xrn::engine::component::Velocity& velocity
    , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
    , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
) const
{
    if (acceleration) {
        if (mass && mass->get() != 0.f) {
            acceleration->addForce(mass->get() * m_gravity);
            velocity.applyAcceleration(frameInfo.deltaTime, acceleration, mass);
        } else {
            velocity.applyAcceleration(frameInfo.deltaTime, acceleration);
        }
    }
    velocity.setLength(velocity.getMaximumSpeed());
    position.update(frameInfo.deltaTime, velocity);
}
