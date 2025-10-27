#include "ExecutorImpl.hpp"
#include <memory>
namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
    {
    }


    void ExecutorImpl::Execute(const std::string& commands) noexcept
    {
        for (const auto cmd : commands) {

            //定义bool型变量存储加速特征
            bool isFast=false;
            if(cmd=='F'){
                isFast=(!isFast);
            }

            if (cmd == 'M')
            {
                if(isFast)
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
                else
                {
                    std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                    cmder->DoOperate(*this);
                }
            }

            else if (cmd == 'L')
            {
                if(isFast)
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
                else 
                {
                    std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
                    cmder->DoOperate(*this);
                }
            }

            else if (cmd == 'R') {
                if(isFast)
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
                else
                {
                    std::unique_ptr<TurnRightCommand> cmder = std::make_unique<TurnRightCommand>();
                    cmder->DoOperate(*this);
                }
            }
        }
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return pose;
    }

}  // namespace adas