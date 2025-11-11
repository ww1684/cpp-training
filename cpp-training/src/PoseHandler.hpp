#pragma once
#include "Executor.hpp"

namespace adas
{
class PoseHandler
{
public:
    PoseHandler(const Pose& pose) noexcept : pose(pose){}
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;
    virtual ~PoseHandler() noexcept = default;

public:
    virtual void Forward(void) noexcept;
    virtual void Backward(void) noexcept;
    virtual void TurnLeft(void) noexcept;
    virtual void TurnRight(void) noexcept;

    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;

    void Reverse(void) noexcept;
    bool IsReverse(void) const noexcept;

    Pose Query(void) const noexcept;

    bool IsSportscar(void)const noexcept;
    bool IsBus(void) const noexcept;

    bool sportscar{false};
    bool bus{false};

protected:
    Pose pose;
    bool fast{false};
    bool reverse{false};

};

// 定义跑车的指令类
class SportscarPoseHandler : public PoseHandler
{
public:
    explicit SportscarPoseHandler(const Pose& pose) noexcept : PoseHandler(pose)
    {
        sportscar = true;
    }

public:
    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
};

// 定义公交车的指令类
class BusPoseHandler : public PoseHandler
{
public:
    explicit BusPoseHandler(const Pose& pose) noexcept : PoseHandler(pose)
    {
        bus = true;
    }

public:
    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
};

}  // namespace adas
