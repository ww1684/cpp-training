#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{
//普通类
class Car final : public Executor
{
public:
    explicit Car(const Pose& pose) noexcept;
    ~Car() noexcept = default;
    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    PoseHandler poseHandler;
};

//跑车类
class Sportscar final : public Executor
{
public:
    explicit Sportscar(const Pose& pose) noexcept;
    ~Sportscar() noexcept = default;
    Sportscar(const Sportscar&) = delete;
    Sportscar& operator=(const Sportscar&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    SportscarPoseHandler SportscarposeHandler;
};

//公交车类
class Bus final : public Executor
{
public:
    explicit Bus(const Pose& pose) noexcept;
    ~Bus() noexcept = default;
    Bus(const Bus&) = delete;
    Bus& operator=(const Bus&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    BusPoseHandler BusposeHandler;
};
}