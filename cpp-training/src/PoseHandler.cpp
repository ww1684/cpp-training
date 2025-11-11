#include "PoseHandler.hpp"

namespace adas
{
void PoseHandler::Forward() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
    } else if (pose.heading == 'W') {
        --pose.x;
    } else if (pose.heading == 'N') {
        ++pose.y;
    } else if (pose.heading == 'S') {
        --pose.y;
    }
}

void PoseHandler::Backward() noexcept
{
    if (pose.heading == 'E') {
        --pose.x;
    } else if (pose.heading == 'W') {
        ++pose.x;
    } else if (pose.heading == 'N') {
        --pose.y;
    } else if (pose.heading == 'S') {
        ++pose.y;
    }
}

void PoseHandler::TurnLeft() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        pose.heading = 'W';
    } else if (pose.heading == 'W') {
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        pose.heading = 'E';
    }
}

void PoseHandler::TurnRight() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        pose.heading = 'W';
    } else if (pose.heading == 'W') {
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        pose.heading = 'E';
    }
}

Pose PoseHandler::Query() const noexcept
{
    return pose;
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}
bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}
bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}


//实现跑车的执行函数
void SportscarPoseHandler::Forward() noexcept
{
    if (pose.heading == 'E') {
        pose.x+=2;
    } else if (pose.heading == 'W') {
        pose.x-=2;
    } else if (pose.heading == 'N') {
        pose.y+=2;
    } else if (pose.heading == 'S') {
        pose.y-=2;
    }
}

void SportscarPoseHandler::Backward() noexcept
{
    if (pose.heading == 'E') {
        pose.x -= 2;
    } else if (pose.heading == 'W') {
        pose.x += 2;
    } else if (pose.heading == 'N') {
        pose.y -= 2;
    } else if (pose.heading == 'S') {
        pose.y += 2;
    }
}

void SportscarPoseHandler::TurnLeft() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'N';
        ++pose.y;
    } else if (pose.heading == 'N') {
        pose.heading = 'W';
        --pose.x;
    } else if (pose.heading == 'W') {
        pose.heading = 'S';
        --pose.y;
    } else if (pose.heading == 'S') {
        pose.heading = 'E';
        ++pose.x;
    }
}

void SportscarPoseHandler::TurnRight() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'S';
        --pose.y;
    } else if (pose.heading == 'S') {
        pose.heading = 'W';
        --pose.x;
    } else if (pose.heading == 'W') {
        pose.heading = 'N';
        ++pose.y;
    } else if (pose.heading == 'N') {
        pose.heading = 'E';
        ++pose.x;
    }
}

// 实现公交车的执行函数
void BusPoseHandler::Forward() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
    } else if (pose.heading == 'W') {
        --pose.x;
    } else if (pose.heading == 'N') {
        ++pose.y;
    } else if (pose.heading == 'S') {
        --pose.y;
    }
}

void BusPoseHandler::Backward() noexcept
{
    if (pose.heading == 'E') {
        --pose.x;
    } else if (pose.heading == 'W') {
        ++pose.x;
    } else if (pose.heading == 'N') {
        --pose.y;
    } else if (pose.heading == 'S') {
        ++pose.y;
    }
}

void BusPoseHandler::TurnLeft() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        ++pose.y;
        pose.heading = 'W';
    } else if (pose.heading == 'W') {
        --pose.x;
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        --pose.y;
        pose.heading = 'E';
    }
}

void BusPoseHandler::TurnRight() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        --pose.y;
        pose.heading = 'W';
    } else if (pose.heading == 'W') {
        --pose.x;
        pose.heading = 'N';
    } else if (pose.heading == 'N') {
        ++pose.y;
        pose.heading = 'E';
    }
}

bool PoseHandler::IsSportscar() const noexcept
{
    return sportscar;
}

bool PoseHandler::IsBus() const noexcept
{
    return bus;
}

}