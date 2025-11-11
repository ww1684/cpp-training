#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
#include <functional>

namespace adas
{

class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
        } else {
            poseHandler.Forward();
        }
    }
};

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.PoseHandler::Backward();
            } else {
                poseHandler.PoseHandler::Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            if(poseHandler.IsBus()){
                poseHandler.Backward();
                poseHandler.Backward();
            }
            poseHandler.TurnRight();
            if (poseHandler.IsSportscar())
                poseHandler.Backward();
        } else {
            poseHandler.TurnLeft();
        }

    }
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.PoseHandler::Backward();
            } else {
                poseHandler.PoseHandler::Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            if (poseHandler.IsBus()) {
                poseHandler.Backward();
                poseHandler.Backward();
            }
            poseHandler.TurnLeft();
            if (poseHandler.IsSportscar())
                poseHandler.Backward();
        } else {
            poseHandler.TurnRight();
        }

    }
};

class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};

class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};

};  // namespace adas