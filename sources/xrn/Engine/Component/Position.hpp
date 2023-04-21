#pragma once

#include <xrn/Engine/Component/Detail/Vector3.hpp>

namespace xrn::engine::component { class Control; }
namespace xrn::engine::component { class Velocity; }

namespace xrn::engine::component {

///////////////////////////////////////////////////////////////////////////
/// \brief Position component
/// \ingroup component
///
/// \include Position.hpp <xrn/Engine/Component/Position.hpp>
///
///////////////////////////////////////////////////////////////////////////
class Position
    : public ::xrn::engine::component::detail::Vector3<Position>
{

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    EXPOSE_VECTOR3_METHODS(Position, true);




public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    Position();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    Position(
        ::glm::vec3 value
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    Position(
        float positionX
        , float positionY
        , float positionZ
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Update
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto update(
        ::xrn::Time deltaTime
        , const ::xrn::engine::component::Control& control
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto update(
        const ::xrn::engine::component::Control& control
        , const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto update(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Move
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveForward(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveBackward(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveRight(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveLeft(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveUp(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto moveDown(
        const ::xrn::engine::component::Velocity& value
        , const ::glm::vec3& direction
    ) -> Position&;



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Members
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    using ::xrn::engine::component::detail::Vector3<Position>::m_value;

};

} // namespace xrn::engine::component
