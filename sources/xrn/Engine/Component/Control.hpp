#pragma once

namespace xrn::engine::component { class Transform3d; }

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
    // Start moving
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingForward()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingBackward()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingRight()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingLeft()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingUp()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto startMovingDown()
        -> Control&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Stop moving
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingForward()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingBackward()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingRight()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingLeft()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingUp()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMovingDown()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto stopMoving()
        -> Control&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto immobilize()
        -> Control&;



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
        -> const ::glm::vec3&;

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
    ::glm::vec3 m_rotation{ .0f };

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
    bool m_ableToFly{ false };
    bool m_isRotated{ true };

};



} // namespace xrn::engine::component
