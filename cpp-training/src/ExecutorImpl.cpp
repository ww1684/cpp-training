#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Command.hpp"
#include "Singleton.hpp"

namespace adas
{

Executor* Executor::NewExecutor(const std::string& type, const Pose& pose) noexcept
{
    if (type == "Car") {
        return new (std::nothrow) Car(pose);
    } else if (type == "Sportscar") {
        return new (std::nothrow) Sportscar(pose);
    } else if (type == "Bus") {
        return new (std::nothrow) Bus(pose);
    }
    return nullptr;
}

//car
Car::Car(const Pose& pose) noexcept : poseHandler(pose)
{
}

void Car::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(poseHandler); });
}

Pose Car::Query() const noexcept
{
    return poseHandler.Query();
}


//sportscar
Sportscar::Sportscar(const Pose& pose) noexcept : SportscarposeHandler(pose)
{
}

void Sportscar::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(SportscarposeHandler); });
}

Pose Sportscar::Query() const noexcept
{
    return SportscarposeHandler.Query();
}


//bus
Bus::Bus(const Pose& pose) noexcept : BusposeHandler(pose)
{
}

void Bus::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(BusposeHandler); });
}

Pose Bus::Query() const noexcept
{
    return BusposeHandler.Query();
}
}  // namespace adas