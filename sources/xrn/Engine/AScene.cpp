///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/AScene.hpp>
#include <xrn/Engine/Vulkan/Buffer.hpp>
#include <xrn/Engine/Configuration.hpp>
#include <xrn/Engine/Components.hpp>
#include "xrn/Engine/System/UpdatePosition.hpp"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::AScene::AScene(
    bool isCameraDetached
)
    : m_isCameraDetached{ isCameraDetached }
    // create the vulkan things (I dont remember what it does)
    , m_pDescriptorSetLayout{ ::xrn::engine::vulkan::descriptor::SetLayout::Builder{ m_device }
        .addBinding(0, ::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, ::VK_SHADER_STAGE_ALL_GRAPHICS)
        .build()
    }
    // Keep track of information to help vulkan
    , m_frameInfo{ m_descriptorSets, *this }
    , m_uboBuffers{ ::xrn::engine::vulkan::SwapChain::MAX_FRAMES_IN_FLIGHT }
    , m_draw3d{
        m_device
        , m_renderer.getSwapChainRenderPass()
        , m_pDescriptorSetLayout->getDescriptorSetLayout()
    }
    // draw lights and update their position
    , m_drawPointLight{
        m_device
        , m_renderer.getSwapChainRenderPass()
        , m_pDescriptorSetLayout->getDescriptorSetLayout()
    }
    , m_tickFrequencyTime{
        ::xrn::Time::createAsSeconds(1) / ::xrn::engine::Configuration::defaultTickFrequency
    }
    , m_player{ m_registry.create() }
    , m_camera{ m_isCameraDetached ? m_player : m_registry.create() }
    , m_mousePointer{ m_camera, m_window }
{
    // vulkan stuff
    m_pDescriptorPool = ::xrn::engine::vulkan::descriptor::Pool::Builder{ m_device }
        .setMaxSets(::xrn::engine::vulkan::SwapChain::MAX_FRAMES_IN_FLIGHT)
        .addPoolSize(::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, ::xrn::engine::vulkan::SwapChain::MAX_FRAMES_IN_FLIGHT)
        .build();

    for (auto& pUbo : m_uboBuffers) {
        pUbo = ::std::make_unique<::xrn::engine::vulkan::Buffer>(
            m_device
            , sizeof(::xrn::engine::vulkan::Ubo)
            , 1
            , ::VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT
            , ::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT
        );
        pUbo->map();
    }

    for (auto i{ 0uz }; i < m_descriptorSets.size(); ++i) {
        auto bufferInfo{ m_uboBuffers[i]->descriptorInfo() };
        ::xrn::engine::vulkan::descriptor::Writer{ *m_pDescriptorSetLayout, *m_pDescriptorPool }
            .writeBuffer(0, &bufferInfo)
            .build(m_descriptorSets[i]);
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Rule of 5
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::AScene::~AScene() = default;




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Events
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::onUpdate()
    -> bool
{
    return true;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::onPostUpdate()
    -> bool
{
    return true;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::onTick(
    ::xrn::Time deltaTime [[ maybe_unused ]]
) -> bool
{
    m_disableTick = true;
    XRN_NOTE("AScene::onTick has been disabled");
    return true;
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onKeyPressed(
    ::std::int16_t keyCode [[ maybe_unused ]]
)
{}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onKeyReleased(
    ::std::int16_t keyCode [[ maybe_unused ]]
)
{}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onMouseMoved(
    ::glm::vec2 _ [[ maybe_unused ]]
)
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// System Events
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onSystemKeyPressed(
    ::std::int16_t keyCode
)
{

    // default
    if (keyCode == ::xrn::engine::configuration.keyBinding.closeWindow) {
        return this->getWindow().close();
    }

    if (
        auto* playerController{ m_registry.try_get<::xrn::engine::component::Control>(m_player) };
        playerController
    ) {
        // move
        if (keyCode == ::xrn::engine::configuration.keyBinding.moveForward) {
            playerController->startMovingForward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveBackward) {
            playerController->startMovingBackward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveLeft) {
            playerController->startMovingLeft();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveRight) {
            playerController->startMovingRight();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveUp) {
            playerController->startMovingUp();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveDown) {
            playerController->startMovingDown();
            return;

        // move arrows
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveForward2) {
            playerController->startMovingForward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveBackward2) {
            playerController->startMovingBackward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveLeft2) {
            playerController->startMovingLeft();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveRight2) {
            playerController->startMovingRight();
            return;

        // look
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookUp) {
            playerController->rotateZ(-45 / 2);
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookDown) {
            playerController->rotateZ(45 / 2);
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookLeft) {
            playerController->rotateX(45 / 2);
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookRight) {
            playerController->rotateX(-45 / 2);
            return;
        }
    }
    return this->onKeyPressed(keyCode);

    XRN_INFO("Key ({}) is not bound to press", keyCode);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onSystemKeyReleased(
    ::std::int16_t keyCode
)
{
    if (
        auto* playerController{ m_registry.try_get<::xrn::engine::component::Control>(m_player) };
        playerController
    ) {
        // move
        if (keyCode == ::xrn::engine::configuration.keyBinding.moveForward) {
            playerController->stopMovingForward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveBackward) {
            playerController->stopMovingBackward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveLeft) {
            playerController->stopMovingLeft();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveRight) {
            playerController->stopMovingRight();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveUp) {
            playerController->stopMovingUp();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveDown) {
            playerController->stopMovingDown();
            return;

        // move arrows
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveForward2) {
            playerController->stopMovingForward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveBackward2) {
            playerController->stopMovingBackward();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveLeft2) {
            playerController->stopMovingLeft();
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.moveRight2) {
            playerController->stopMovingRight();
            return;

        // look
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookUp) {
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookDown) {
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookLeft) {
            return;
        } else if (keyCode == ::xrn::engine::configuration.keyBinding.lookRight) {
            return;
        }
    }
    return this->onKeyReleased(keyCode);

    XRN_INFO("Key ({}) is not bound to press", keyCode);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::onSystemMouseMoved(
    ::glm::vec2 offset
)
{
    m_mousePointer.updateRay(m_camera, m_window);

    return;
    if (m_isCameraDetached) {
        if (
            auto* playerController{ m_registry.try_get<::xrn::engine::component::Control>(m_player) };
            playerController
        ) {
            playerController->rotateX(-offset.x);
            playerController->rotateY(offset.y);
        }
    } else {
        this->onMouseMoved(offset);
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Getters/Setters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::setTickFrequency(
    ::std::size_t frequency
)
{
    m_tickFrequencyTime = ::xrn::Time::createAsSeconds(frequency) / 30;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getWindow()
    -> ::xrn::engine::vulkan::Window&
{
    return m_window;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getVulkanDevice()
    -> ::xrn::engine::vulkan::Device&
{
    return m_device;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getRegistry()
    -> ::entt::registry&
{
    return m_registry;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getCameraId()
    -> ::entt::entity
{
    return m_camera.getId();
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getPlayerId()
    -> ::entt::entity
{
    return m_player;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getMousePointer()
    -> ::xrn::engine::MousePointer&
{
    return m_mousePointer;
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::getFrameInfo()
    -> ::xrn::engine::vulkan::FrameInfo&
{
    return m_frameInfo;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::run()
{
    ::xrn::Clock clock, fpsClock;
    ::std::size_t fpsCount{ 0 };

    while (!m_window.shouldClose()) {
        ++fpsCount;
        if (fpsClock.getElapsed() >= ::xrn::Time::createAsSeconds(1)) {
            XRN_INFO("FPS: {}", fpsCount);
            m_frameInfo.fps = fpsCount;
            fpsCount = 0;
            fpsClock.reset();
        }

        m_frameInfo.deltaTime = clock.restart();

        m_window.handleEvents(*this);

        if (!this->onUpdate() || !this->update() || !this->onPostUpdate()) {
            m_window.close();
            break;
        }

        if (!m_disableTick && m_tickClock.getElapsed() >= m_tickFrequencyTime) {
            if (!this->onTick(m_tickClock.restart())) {
                m_window.close();
                break;
            }
        }

        this->draw();
        this->limitFrameRate();
    }

    ::vkDeviceWaitIdle(m_device.device());
}

float deltaT;

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::AScene::update()
    -> bool
{
    using Position = ::xrn::engine::component::Position;
    using Rotation = ::xrn::engine::component::Rotation;
    using Scale = ::xrn::engine::component::Scale;
    using Velocity = ::xrn::engine::component::Velocity;
    using Acceleration = ::xrn::engine::component::Acceleration;
    using Mass = ::xrn::engine::component::Mass;

    using Transform3d = ::xrn::engine::component::Transform3d;
    using PointLight = ::xrn::engine::component::PointLight;
    using Control = ::xrn::engine::component::Control;

    this->updateCamera();

    // control
    for (auto [entity, position] : m_registry.view<Position>().each()) {
        auto* rotation{ m_registry.try_get<Rotation>(entity) };
        auto* velocity{ m_registry.try_get<Velocity>(entity) };
        auto* acceleration{ m_registry.try_get<Acceleration>(entity) };
        auto* mass{ m_registry.try_get<Mass>(entity) };
        auto* control{ m_registry.try_get<Control>(entity) };

        if (control) {
            m_updatePosition(m_frameInfo, position, *control, rotation, velocity, acceleration, mass);
        } else {
            m_updatePosition(m_frameInfo, position, rotation, velocity, acceleration, mass);
        }
    }

    // transform (apply position rotation scale)
    for (auto [entity, transform] : m_registry.view<Transform3d>().each()) {
        auto* position{ m_registry.try_get<Position>(entity) };
        auto* rotation{ m_registry.try_get<Rotation>(entity) };
        auto* scale{ m_registry.try_get<Scale>(entity) };
        m_updateTransform3d(m_frameInfo, transform, position, rotation, scale);
    }

    {
        auto lightIndex{ 0uz };
        m_registry.view<PointLight, Position>().each(
            [&lightIndex](auto&, auto&) {
                ++lightIndex;
            }
        );
        m_frameInfo.ubo.numOfLights = lightIndex;
    }

    {
        auto& position{ m_registry.get<Position>(m_camera.getId()) };
        auto& rotation{ m_registry.get<Rotation>(m_camera.getId()) };
        m_camera.setViewDirection(*position, rotation.getDirection());
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::draw()
{

    if (!(m_frameInfo.commandBuffer = m_renderer.beginFrame())) {
        return;
    }
    m_frameInfo.frameIndex = static_cast<::std::size_t>(m_renderer.getFrameIndex());

    m_uboBuffers[m_frameInfo.frameIndex]->writeToBuffer(&m_frameInfo.ubo);
    m_uboBuffers[m_frameInfo.frameIndex]->flush();

    m_renderer.beginSwapChainRenderPass(m_frameInfo.commandBuffer);

    // draw lights
    m_drawPointLight.bind(m_frameInfo);
    m_registry.view<::xrn::engine::component::PointLight, ::xrn::engine::component::Position>().each(
        [this, lightIndex = 0](auto& pointLight, auto& position) mutable {
            m_drawPointLight(m_frameInfo, pointLight, position, lightIndex);
            ++lightIndex;
        }
    );

    // draw objects
    m_draw3d.bind(m_frameInfo);
    m_registry.view<::xrn::engine::component::Transform3d>().each([this](auto& transform){
        m_draw3d(m_frameInfo, transform);
    });

    m_renderer.endSwapChainRenderPass(m_frameInfo.commandBuffer);
    m_renderer.endFrame();
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::limitFrameRate()
{
    auto t{ ::xrn::Time::createAsSeconds(1) / ::xrn::engine::configuration.maxFrameRate };
    if (t > m_frameInfo.deltaTime) {
        ::std::this_thread::sleep_for((t - m_frameInfo.deltaTime).getAsChronoMilliseconds());
    }
}



///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::AScene::updateCamera()
{
    const float aspect{ m_renderer.getAspectRatio() };
    // m_camera.setOrthographicProjection(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    m_camera.setPerspectiveProjection(::glm::radians(50.0f), aspect, 0.1f, 1000.0f);
    // m_camera.setViewTarget(
        // { 0.0f, 0.0f, 0.0f }
        // , this->getPlayerComponent<::xrn::engine::component::Transform3d>().getPosition()
    // );

    m_frameInfo.projectionView = m_camera.getProjection() * m_camera.getView();
    m_frameInfo.ubo.projection = m_camera.getProjection();
    m_frameInfo.ubo.view = m_camera.getView();

    m_mousePointer.updateRay(m_camera);
}
