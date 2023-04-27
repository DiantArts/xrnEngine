#include <pch.hpp>
#include <xrn/Engine/Component/Transform3d.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Transform3d::Transform3d(
    ::std::shared_ptr<::xrn::engine::vulkan::Model> model
)
    : m_model{ model }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Matrix
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateMatrix(
    const ::xrn::engine::component::Position& position
    , const ::xrn::engine::component::Rotation& rotation
    , const ::xrn::engine::component::Scale& scale
)
{
    const float c3{ ::glm::cos(::glm::radians(rotation.getZ())) };
    const float s3{ ::glm::sin(::glm::radians(rotation.getZ())) };
    const float c2{ ::glm::cos(::glm::radians(rotation.getX())) };
    const float s2{ ::glm::sin(::glm::radians(rotation.getX())) };
    const float c1{ ::glm::cos(::glm::radians(rotation.getY())) };
    const float s1{ ::glm::sin(::glm::radians(rotation.getY())) };

    m_matrix = ::glm::mat4{
        {
            scale.getX() * (c1 * c3 + s1 * s2 * s3)
            , scale.getX() * (c2 * s3)
            , scale.getX() * (c1 * s2 * s3 - c3 * s1)
            , 0.0f
        }
        , {
            scale.getY() * (c3 * s1 * s2 - c1 * s3)
            , scale.getY() * (c2 * c3)
            , scale.getY() * (c1 * c3 * s2 + s1 * s3)
            , 0.0f
        }
        , {
            scale.getZ() * (c2 * s1)
            , scale.getZ() * (-s2)
            , scale.getZ() * (c1 * c2)
            , 0.0f
        }
        , { position.getX(), position.getY(), position.getZ(), 1.0f }
    };
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateMatrix(
    const ::xrn::engine::component::Position& position
    , const ::xrn::engine::component::Rotation& rotation
)
{
    this->updateMatrix(position, rotation, ::xrn::engine::component::Scale{ 1.0f });
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateMatrix(
    const ::xrn::engine::component::Position& position
    , const ::xrn::engine::component::Scale& scale
)
{
    this->updateMatrix(position, ::xrn::engine::component::Rotation{ 0.0f }, scale);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateMatrix(
    const ::xrn::engine::component::Position& position
)
{
    this->updateMatrix(
        position
        , ::xrn::engine::component::Rotation{ 0.0f }
        , ::xrn::engine::component::Scale{ 1.0f }
    );
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Transform3d::getMatrix() const
    -> const ::glm::mat4&
{
    return m_matrix;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Normal Matrix
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateNormalMatrix(
    const ::xrn::engine::component::Rotation& rotation
    , const ::xrn::engine::component::Scale& scale
)
{
    const float c3{ ::glm::cos(::glm::radians(rotation.getZ())) };
    const float s3{ ::glm::sin(::glm::radians(rotation.getZ())) };
    const float c2{ ::glm::cos(::glm::radians(rotation.getX())) };
    const float s2{ ::glm::sin(::glm::radians(rotation.getX())) };
    const float c1{ ::glm::cos(::glm::radians(rotation.getY())) };
    const float s1{ ::glm::sin(::glm::radians(rotation.getY())) };
    const ::glm::vec3 inversedScale{ 1.0f / *scale };

    m_normalMatrix = ::glm::mat3{
        {
            inversedScale.x * (c1 * c3 + s1 * s2 * s3)
            , inversedScale.x * (c2 * s3)
            , inversedScale.x * (c1 * s2 * s3 - c3 * s1)
        }
        , {
            inversedScale.y * (c3 * s1 * s2 - c1 * s3)
            , inversedScale.y * (c2 * c3)
            , inversedScale.y * (c1 * c3 * s2 + s1 * s3)
        }
        , {
            inversedScale.z * (c2 * s1)
            , inversedScale.z * (-s2)
            , inversedScale.z * (c1 * c2)
        }
    };
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateNormalMatrix(
    const ::xrn::engine::component::Rotation& rotation
)
{
    return this->updateNormalMatrix(rotation, ::xrn::engine::component::Scale{ 1.0f });
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Transform3d::updateNormalMatrix(
    const ::xrn::engine::component::Scale& scale
)
{
    return this->updateNormalMatrix(::xrn::engine::component::Rotation{ 0.0f }, scale);
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Transform3d::getNormalMatrix() const
    -> const ::glm::mat3&
{
    return m_normalMatrix;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Model
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Transform3d::getModel() const
    -> ::xrn::engine::vulkan::Model&
{
    return *m_model;
}
