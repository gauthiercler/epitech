cmake_minimum_required(VERSION 3.7)
project(PSU_2016_zappy)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")


include_directories(.)

cmake_minimum_required(VERSION 2.8.4)

find_package(Boost 1.64.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(SOURCES
        main.cpp
        classes/Parser.cpp
        classes/Parser.hpp
        classes/Inventory.hpp
        classes/Response.hpp
        classes/AResponse.hpp
        classes/AResponse.cpp
        classes/Error.hpp
        FSM/FSM.hpp
        FSM/definitions.hpp
        FSM/states/StateIsCheckingFood.hpp
        FSM/states/StateIsLookingForFood.hpp
        FSM/states/StateFoodIsOnCell.hpp
        FSM/states/StateCheckingTeamMessage.hpp
        FSM/states/StateIsCheckingStones.hpp
        FSM/states/StateisLookingForStones.hpp
        FSM/states/StateStoneIsOnCell.hpp
        FSM/states/StateIsLookingForPlayers.hpp
        FSM/states/StateCallingForIncantation.hpp
        FSM/states/StateCheckingIncantation.hpp
        FSM/states/StateRemovingStone.hpp
        FSM/states/StateStartingIncantation.hpp
        FSM/states/StateCheckingPosition.hpp
        FSM/states/StateMovingTowardsIncantation.hpp
        FSM/states/StateMovingTowardsFood.hpp
        FSM/states/StateMovingTowardsStone.hpp
        FSM/guards/GuardHasEnoughFood.hpp
        FSM/guards/GuardFoodIsOnCell.hpp
        FSM/guards/GuardHasMessage.hpp
        FSM/guards/GuardHasStonesForIncantation.hpp
        FSM/guards/GuardStoneIsOnCell.hpp
        FSM/guards/GuardPlayerIsOnCell.hpp
        FSM/guards/GuardEnoughPlayersForIncantation.hpp
        FSM/guards/GuardExactStonesOnCellForIncantation.hpp
        FSM/guards/GuardCorrectLevelForIncantation.hpp
        FSM/guards/GuardOnCellOfIncantation.hpp
        FSM/transitions/ActionMove.hpp
        FSM/transitions/ActionPickupFood.hpp
        FSM/transitions/ActionDropAllStonesOnCell.hpp
        FSM/transitions/ActionPickupStone.hpp
        FSM/transitions/ActionStartIncantation.hpp
        FSM/transitions/ActionBroadcastCallForPlayer.hpp
        FSM/events/EventStartComputation.hpp
        classes/Engine.cpp
        classes/Engine.hpp
        classes/Socket.cpp
        classes/Socket.hpp
        classes/IOStreamHandler.cpp
        classes/IOStreamHandler.hpp
        classes/SelectType.hpp
        classes/ResponseHandler.cpp
        classes/ResponseHandler.hpp
        classes/OptionHandler.cpp
        classes/OptionHandler.hpp
        classes/LevelRequirement.hpp
        classes/LevelRequirement.cpp
        classes/Random.cpp
        classes/Random.hpp
        FSM/configuration.hpp
        FSM/guards/GuardHasEnoughFoodForIncantation.hpp
        FSM/guards/GuardEnoughStonesOnCellForIncantation.hpp
        FSM/transitions/ActionPickupExtraRessourcesOnCell.hpp
        FSM/DistanceCalculator.hpp
        FSM/transitions/ActionFork.hpp
        classes/Broadcast.hpp
        FSM/guards/GuardPlayersCallForIncantationTimeout.hpp)

add_executable(zappy_ai
      ${SOURCES})

if(Boost_FOUND)
    target_link_libraries(zappy_ai ${Boost_LIBRARIES} pthread boost_thread boost_regex boost_program_options)
endif()
target_include_directories(zappy_ai PRIVATE ai/classes/)

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)
