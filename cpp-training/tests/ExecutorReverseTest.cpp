#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

// given_status_is_B_and_facing_is_E
//BM
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_B_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

//BL
TEST(ExecutorReverseTest, should_return_facing_S_given_status_is_B_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

//BR
TEST(ExecutorReverseTest, should_return_facing_N_given_status_is_B_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// given_status_is_F_and_facing_is_E
//FM
TEST(ExecutorReverseTest, should_return_x_plus_2_given_status_is_F_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

//FL
TEST(ExecutorReverseTest, should_return_x_plus_1_and_facing_N_given_status_is_F_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// FR
TEST(ExecutorReverseTest, should_return_x_plus_1_and_facing_S_given_status_is_F_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("FR");
    // then
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// given_status_is_BF_and_facing_is_E
// BFM
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_BF_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFM");
    // then
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

//BFL
TEST(ExecutorReverseTest, should_return_x_minus_1_and_facing_S_given_status_is_BF_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFL");
    // then
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

//BFR
TEST(ExecutorReverseTest, should_return_x_minus_1_and_facing_N_given_status_is_BF_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// given_status_is_BB_and_facing_is_N
//BBM
TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_BB_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // when
    executor->Execute("BBM");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// given_status_is_FF_and_facing_is_N
// FFM
TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_FF_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // when
    executor->Execute("FFM");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}