#pragma once

#include <xrn/Engine/Vulkan/FrameInfo.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Component/Position.hpp>
#include <xrn/Engine/Component/Rotation.hpp>
#include <xrn/Engine/Component/Velocity.hpp>
#include <xrn/Engine/Component/Acceleration.hpp>
#include <xrn/Engine/Component/Mass.hpp>

namespace xrn::engine::system {

///////////////////////////////////////////////////////////////////////////
/// \brief No clue what it does xD
/// \ingroup vulkan
///
/// \include UpdatePosition.hpp <UpdatePosition.hpp>
///
///////////////////////////////////////////////////////////////////////////
class UpdatePosition {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    static inline const ::glm::vec3 defaultDirection{
        ::glm::normalize(::glm::vec3(
            ::glm::cos(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
            , ::glm::sin(::glm::radians(0.0f))
            , ::glm::sin(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
        ))
    };



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Basic
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void operator()(
        ::xrn::engine::vulkan::FrameInfo& frameInfo
        , ::xrn::engine::component::Position& position
        , ::xrn::engine::component::Control& control
        , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
        , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
        , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
        , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void operator()(
        ::xrn::engine::vulkan::FrameInfo& frameInfo
        , ::xrn::engine::component::Position& position
        , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
        , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
        , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
        , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
    ) const;



private:

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void updatePosition(
        ::xrn::engine::vulkan::FrameInfo& frameInfo
        , ::xrn::engine::component::Position& position
        , const ::glm::vec3& direction
        , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
        , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
        , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
    ) const;



private:

    ::glm::vec3 m_gravity{ 0.f, -9.81f, 0.f };

};

} // namespace xrn::engine::system
