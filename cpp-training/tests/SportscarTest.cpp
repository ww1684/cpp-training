#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"


namespace adas
{
//正常状态下执行指令
TEST(SportscarTest, should_return_x_plus_2_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("M");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_y_plus_1_and_facing_is_N_given_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("L");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_y_minus_1_and_facing_is_S_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("R");
    // then
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

//B状态下执行指令
TEST(SportscarTest, should_return_x_minus_2_and_facing_is_E_given_command_is_BM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_y_plus_1_and_facing_is_S_given_command_is_BL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_y_minus_1_and_facing_is_N_given_command_is_BR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

//F状态下执行指令
TEST(SportscarTest, should_return_x_plus_4_and_facing_is_E_given_command_is_FM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("FM");
    // then
    const Pose target{4, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_x_plus_1_and_y_plus_1_and_facing_is_N_given_command_is_FL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_x_plus_1_and_y_minus_1_and_facing_is_S_given_command_is_FL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("FR");
    // then
    const Pose target{1, -1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

//BF状态下执行指令
TEST(SportscarTest, should_return_x_minus_4_and_facing_is_E_given_command_is_BFM_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BFM");
    // then
    const Pose target{-4, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_x_plus_1_and_y_plus_1_and_facing_is_S_given_command_is_BFL_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BFL");
    // then
    const Pose target{-1, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportscarTest, should_return_x_plus_1_and_y_minus_1_and_facing_is_N_given_command_is_BFR_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor("Sportscar", {0, 0, 'E'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{-1, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}