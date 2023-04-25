#pragma once

#include <xrn/Engine/Component/Acceleration.hpp>

namespace xrn::engine::component { class Transform3d; }
namespace xrn::engine::component { class Velocity; }
namespace xrn::engine::component { class Direction; }

namespace xrn::engine::component {

///////////////////////////////////////////////////////////////////////////
/// \brief Window wrapper for GLFW
/// \ingroup vulkan
///
/// \include Control.hpp <Component/Control.hpp>
///
///////////////////////////////////////////////////////////////////////////
class Control {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Control(
        bool ableToFly = true
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Speed
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getSpeed() const
        -> float;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto setSpeed(
        float speed
    ) -> Control&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Start/stop moving
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingForward(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingBackward(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingRight(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingLeft(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingUp(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingDown(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingForward(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingBackward(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingRight(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingLeft(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingUp(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingDown(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMoving(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto immobilize(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    auto updateAcceleration(
        const ::xrn::engine::component::Direction& direction
        , ::xrn::engine::component::Velocity& velocity
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getAcceleration() const
        -> const ::xrn::engine::component::Acceleration&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Check if moving
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingForward() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingBackward() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingRight() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingLeft() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingUp() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isMovingDown() const
        -> bool;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Rotation
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotate(
        const ::glm::vec3& offset
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotate(
        const float rotationXOffset
        , const float rotationYOffset
        , const float rotationZOffset
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateX(
        const float offset
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateY(
        const float offset
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateZ(
        const float offset
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief rotate ignoring the sensitivity
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateAbsolute(
        ::glm::vec3 rotation
    ) -> Control&;


    ///////////////////////////////////////////////////////////////////////////
    /// \brief rotate ignoring the sensitivity
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateAbsolute(
        const float rotationX
        , const float rotationY
        , const float rotationZ
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief rotate ignoring the sensitivity
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateAbsoluteX(
        const float rotationX
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief rotate ignoring the sensitivity
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateAbsoluteY(
        const float rotationY
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief rotate ignoring the sensitivity
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto rotateAbsoluteZ(
        const float rotationZ
    ) -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getRotation() const
        -> const ::xrn::engine::component::Rotation&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isRotated() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto resetRotatedFlag()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto resetRotation()
        -> Control&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Others
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isAbleToFly() const
        -> bool;



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Member variables
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Param
    ///////////////////////////////////////////////////////////////////////////
    float m_moveSpeed{ 100.f };
    ::xrn::engine::component::Rotation m_rotation{ 0.f };

    ///////////////////////////////////////////////////////////////////////////
    // Movement
    ///////////////////////////////////////////////////////////////////////////
    enum MovementState {
        forward
        , backward
        , left
        , right
        , up
        , down
    , };
    ::std::bitset<6> m_movementState;
    ::xrn::engine::component::Acceleration m_acceleration;

    bool m_ableToFly{ false };

};



} // namespace xrn::engine::component
