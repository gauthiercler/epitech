/*
** FSA.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSA/FSA.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jun 20 13:35:06 2017 Gauthier Cler
** Last update Tue Jun 20 13:35:06 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_FSA_HPP
#define PSU_2016_ZAPPY_FSA_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE 50
#define FUSION_MAX_VECTOR_SIZE 50

#include <iostream>

#include "definitions.hpp"
#include "configuration.hpp"

#include <FSM/transitions/ActionPickupFood.hpp>
#include <FSM/transitions/ActionMove.hpp>
#include <FSM/transitions/ActionDropAllStonesOnCell.hpp>
#include <FSM/transitions/ActionBroadcastCallForPlayer.hpp>
#include <FSM/transitions/ActionStartIncantation.hpp>
#include <FSM/events/EventStartComputation.hpp>
#include <FSM/states/StateMovingTowardsStone.hpp>
#include <FSM/transitions/ActionPickupStone.hpp>
#include <FSM/guards/GuardHasEnoughFoodForIncantation.hpp>
#include <FSM/guards/GuardEnoughStonesOnCellForIncantation.hpp>
#include <FSM/transitions/ActionPickupExtraRessourcesOnCell.hpp>
#include <FSM/transitions/ActionFork.hpp>
#include <FSM/guards/GuardPlayersCallForIncantationTimeout.hpp>

#include "FSM/states/StateCallingForIncantation.hpp"
#include "FSM/states/StateCheckingIncantation.hpp"
#include "FSM/states/StateCheckingPosition.hpp"
#include "FSM/states/StateCheckingTeamMessage.hpp"
#include "FSM/states/StateFoodIsOnCell.hpp"
#include "FSM/states/StateIsCheckingFood.hpp"
#include "FSM/states/StateIsCheckingStones.hpp"
#include "FSM/states/StateIsLookingForFood.hpp"
#include "FSM/states/StateIsLookingForPlayers.hpp"
#include "FSM/states/StateisLookingForStones.hpp"
#include "FSM/states/StateMovingTowardsIncantation.hpp"
#include "FSM/states/StateMovingTowardsFood.hpp"
#include "FSM/states/StateRemovingStone.hpp"
#include "FSM/states/StateStartingIncantation.hpp"
#include "FSM/states/StateStoneIsOnCell.hpp"

#include "FSM/guards/GuardCorrectLevelForIncantation.hpp"
#include "FSM/guards/GuardEnoughPlayersForIncantation.hpp"
#include "FSM/guards/GuardExactStonesOnCellForIncantation.hpp"
#include "FSM/guards/GuardFoodIsOnCell.hpp"
#include "FSM/guards/GuardHasEnoughFood.hpp"
#include "FSM/guards/GuardHasMessage.hpp"
#include "FSM/guards/GuardHasStonesForIncantation.hpp"
#include "FSM/guards/GuardOnCellOfIncantation.hpp"
#include "FSM/guards/GuardPlayerIsOnCell.hpp"
#include "FSM/guards/GuardStoneIsOnCell.hpp"

#include "classes/Parser.hpp"

namespace ai {

  extern bool 	running;

  namespace msm = boost::msm;
  namespace msmf = boost::msm::front;
  namespace mpl = boost::mpl;
  namespace euml = msmf::euml;

  struct FSM : public msmf::state_machine_def<FSM>
  {

    typedef StateIsCheckingFood			initial_state;

    unsigned int				level = 1;
    std::vector<ai::Cell>			vision;
    ai::Inventory				inventory;
    Direction					direction = Direction::RANDOM;
    Direction					orientation = Direction::NONE;
    Inventory					neededItems;

    bool					seekFood = false;
    bool					seekIncantation = false;
    unsigned int				nbSeeksForIncantation = 0;

    ai::Broadcast				incantationCall;
    unsigned int				nbCallsForIncantation = 0;
    bool					isCallingForIncantation = false;
    bool					canFork = false;

    std::string					teamName;
    unsigned long				remainingSpots;
    std::pair<unsigned int, unsigned int>	mapSize;
    std::string					programName;
    std::string					port;
    std::string					host;

    struct transition_table:mpl::vector<
      msmf::Row<initial_state, EventStartComputation, StateIsLookingForFood, msmf::none, euml::Not_<GuardHasEnoughFood>>,
      msmf::Row<initial_state, EventStartComputation, StateCheckingTeamMessage, msmf::none, GuardHasEnoughFood>,
      msmf::Row<StateIsLookingForFood, msmf::none, StateFoodIsOnCell, msmf::none, euml::And_<GuardFoodIsOnCell, euml::Not_<GuardPlayerIsOnCell>>>,
      msmf::Row<StateIsLookingForFood, msmf::none, StateMovingTowardsFood, msmf::none, euml::Or_<euml::Not_<GuardFoodIsOnCell>, GuardPlayerIsOnCell>>,
      msmf::Row<StateFoodIsOnCell, msmf::none, initial_state, ActionPickupFood, msmf::none>,
      msmf::Row<StateMovingTowardsFood, msmf::none, initial_state, ActionMove, msmf::none>,
      msmf::Row<StateCheckingTeamMessage, msmf::none, StateCheckingPosition, msmf::none, GuardHasMessage>,
      msmf::Row<StateCheckingTeamMessage, msmf::none, StateIsCheckingStones, msmf::none, euml::Not_<GuardHasMessage>>,
      msmf::Row<StateIsCheckingStones, msmf::none, StateIsLookingForPlayers, msmf::none, euml::And_<GuardHasStonesForIncantation, GuardHasEnoughFoodForIncantation>>,
      msmf::Row<StateIsCheckingStones, msmf::none, StateisLookingForStones, msmf::none, euml::Or_<euml::Not_<GuardHasStonesForIncantation>, euml::Not_<GuardHasEnoughFoodForIncantation>>>,
      msmf::Row<StateisLookingForStones, msmf::none, StateStoneIsOnCell, msmf::none, euml::And_<GuardStoneIsOnCell, euml::Not_<GuardPlayerIsOnCell>>>,
      msmf::Row<StateStoneIsOnCell, msmf::none, initial_state, ActionMove, msmf::none>,
      msmf::Row<StateStoneIsOnCell, msmf::none, initial_state, ActionPickupStone, GuardStoneIsOnCell>,
      msmf::Row<StateisLookingForStones, msmf::none, StateMovingTowardsStone, msmf::none, euml::Or_<euml::Not_<GuardStoneIsOnCell>, GuardPlayerIsOnCell>>,
      msmf::Row<StateMovingTowardsStone, msmf::none, initial_state, ActionMove, msmf::none>,
      msmf::Row<StateIsLookingForPlayers, msmf::none, StateCheckingForIncantation, ActionDropAllStonesOnCell, GuardEnoughPlayersForIncantation>,
      msmf::Row<StateIsLookingForPlayers, msmf::none, StateCallingForIncantation, msmf::none, euml::Not_<GuardEnoughPlayersForIncantation>>,
      msmf::Row<StateCallingForIncantation, msmf::none, initial_state, ActionBroadcastCallForPlayer, GuardPlayersCallForIncantationTimeout>,
      msmf::Row<StateCallingForIncantation, msmf::none, initial_state, ActionFork, euml::Not_<GuardPlayersCallForIncantationTimeout>>,
      msmf::Row<StateCheckingForIncantation, msmf::none, StateStartingIncantation, msmf::none, GuardExactStonesOnCellForIncantation>,
      msmf::Row<StateCheckingForIncantation, msmf::none, StateRemovingStone, msmf::none, euml::Not_<GuardExactStonesOnCellForIncantation>>,
      msmf::Row<StateRemovingStone, msmf::none, StateCheckingForIncantation, ActionPickupExtraRessourcesOnCell, GuardEnoughStonesOnCellForIncantation>,
      msmf::Row<StateRemovingStone, msmf::none, initial_state, msmf::none, euml::Not_<GuardEnoughStonesOnCellForIncantation>>,
      msmf::Row<StateStartingIncantation, msmf::none, initial_state, ActionStartIncantation, msmf::none>,
      msmf::Row<StateCheckingPosition, msmf::none, initial_state, msmf::none, GuardOnCellOfIncantation>,
      msmf::Row<StateCheckingPosition, msmf::none, StateMovingTowardsIncantation, msmf::none, euml::Not_<GuardOnCellOfIncantation>>,
      msmf::Row<StateMovingTowardsIncantation, msmf::none, initial_state, ActionMove, msmf::none>
    > {};

    template <class fsm,class event>
    void no_transition(event const&, fsm&,int state)
    {
      std::cout << "no transition for " << state << std::endl;
    }
    template <class FSM,class Event>
    void exception_caught (Event const&,FSM&,std::exception& )
    {
      std::cerr << "Error Occurred, Exiting" << std::endl;
      std::exit(1);
    }

  };

  typedef msm::back::state_machine<FSM>	machine;
}

#endif //PSU_2016_ZAPPY_FSA_HPP