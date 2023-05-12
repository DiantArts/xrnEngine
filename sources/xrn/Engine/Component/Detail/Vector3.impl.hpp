#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
#include <glm/geometric.hpp>
template <
    typename T
    , bool hasChangedFlag
> ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::Vector3(
    Vector3::Type value
)
    : ::xrn::engine::component::detail::BasicType<::glm::vec3, T, hasChangedFlag>{ ::std::move(value) }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Rule of 5
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::~Vector3() = default;

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::Vector3(
    Vector3&&
) noexcept = default;;

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator=(
    Vector3&&
) noexcept
    -> Vector3& = default;;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::set(
    const float value
) -> Vector3::ParentType&
{
    return this->set(::glm::vec3{ value, value, value });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::set(
    const float valueX
    , const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    return this->set(::glm::vec3{ valueX, valueY, valueZ });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setX(
    const float value
) -> Vector3::ParentType&
{
    return this->set(::glm::vec3{ value, this->getY(), this->getZ()});
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setY(
    const float value
) -> Vector3::ParentType&
{
    return this->set(::glm::vec3{ this->getX(), value, this->getZ() });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setZ(
    const float value
) -> Vector3::ParentType&
{
    return this->set(::glm::vec3{ this->getX(), this->getY(), value });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXY(
    const float valueX
    , const float valueY
) -> Vector3::ParentType&
{
    this->setX(valueX);
    return this->setY(valueY);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXY(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->setXY(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXZ(
    const float valueX
    , const float valueZ
) -> Vector3::ParentType&
{
    this->setX(valueX);
    return this->setZ(valueZ);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXZ(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->setXZ(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setYZ(
    const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    this->setY(valueY);
    return this->setZ(valueZ);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setYZ(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->setYZ(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::add(
    const float value
) -> Vector3::ParentType&
{
    return this->add(::glm::vec3{ value, value, value });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::add(
    const float valueX
    , const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    return this->add(::glm::vec3{ valueX, valueY, valueZ });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addX(
    const float value
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ value, 0, 0 });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addY(
    const float value
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ 0, value, 0 });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addZ(
    const float value
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ 0, 0, value });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addXY(
    const float valueX
    , const float valueY
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ valueX, valueY, 0 });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addXY(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->addXY(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addXZ(
    const float valueX
    , const float valueZ
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ valueX, 0, valueZ });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addXZ(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->addXZ(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addYZ(
    const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    return this->add(Vector3::Type{ 0, valueY, valueZ });
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::addYZ(
    const ::glm::vec2& value
) -> Vector3::ParentType&
{
    return this->addYZ(value.x, value.y);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getX() const
    -> float
{
    return this->get().x;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getY() const
    -> float
{
    return this->get().y;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getZ() const
    -> float
{
    return this->get().z;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getXY() const
    -> ::glm::vec2
{
    return ::glm::vec2{ this->get().x, this->get().y };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getXZ() const
    -> ::glm::vec2
{
    return ::glm::vec2{ this->get().x, this->get().z };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getYZ() const
    -> ::glm::vec2
{
    return ::glm::vec2{ this->get().y, this->get().z };
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Vectors operations
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setMagnitude(
    const float value
) -> Vector3::ParentType&
{

    return this->set(this->get() * (value / ::glm::length(this->get())));
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setLength(
    const float value
) -> Vector3::ParentType&
{
    if (::glm::length(this->get()) > value) {
        return this->set(::glm::normalize(this->get()) * value);
    } else {
        return static_cast<Vector3::ParentType&>(*this);
    }
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::dot(
    const ::glm::vec3& value
) -> Vector3::ParentType&
{
    return this->set(::glm::dot(this->get(), value));
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::normalize()
    -> Vector3::ParentType&
{
    return this->set(::glm::normalize(this->get()));
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getXNormal() const
    -> Vector3
{
    return Vector3{ ::glm::cross(this->get(), ::glm::vec3(1.f, 0.f, 0.f)) };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getYNormal() const
    -> Vector3
{
    return Vector3{ ::glm::cross(this->get(), ::glm::vec3(0.f, 1.f, 0.f)) };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getZNormal() const
    -> Vector3
{
    return Vector3{ ::glm::cross(this->get(), ::glm::vec3(0.f, 0.f, 1.f)) };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::reflect(
    const ::glm::vec3& normal
) -> Vector3::ParentType&
{
    return this->set(this->get() - 2 * ::glm::dot(this->get(), normal) * normal);
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Comparisons
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator<=>(
    const float rhs
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ this->get().x <=> rhs }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ this->get().y <=> rhs }; cmp != 0) {
        return cmp;
    }
    return this->get().z <=> rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator<=>(
    const Vector3::ParentType& rhs
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ this->get().x <=> rhs.get().x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ this->get().y <=> rhs.get().y }; cmp != 0) {
        return cmp;
    }
    return this->get().z <=> rhs.get().z;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator=(
    const float rhs
) -> Vector3::ParentType&
{
    return this->set(rhs);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator+(
    const float rhs
) const -> ::glm::vec3
{
    return this->get() + rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator+=(
    const float rhs
) -> Vector3::ParentType&
{
    return this->set(this->get() + rhs);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator-(
    const float rhs
) const -> ::glm::vec3
{
    return this->get() - rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator-=(
    const float rhs
) -> Vector3::ParentType&
{
    return this->set(this->get() - rhs);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator*(
    const float rhs
) const -> ::glm::vec3
{
    return this->get() * rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator*=(
    const float rhs
) -> Vector3::ParentType&
{
    return this->set(this->get() * rhs);
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator/(
    const float rhs
) const -> ::glm::vec3
{
    return this->get() / rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator/=(
    const float rhs
) -> Vector3::ParentType&
{
    return this->set(this->get() / rhs);
}
