/*
** Parser.hpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/client/includes/server/Parser.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 16:56:25 2017 Montagne Valentin
** Last update Thu Jun 22 16:56:26 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_PARSER_HPP
#define PSU_2016_ZAPPY_PARSER_HPP

#include			<vector>
#include			<regex>
#include			<string>

namespace 			zappy {

  enum class 			ParseType {
    MAP_SIZE,
    CELL_CONTENT,
    PLAYER_SPAWN,
    PLAYER_POSITION,
    PLAYER_LEVEL,
    PLAYER_INVENTORY,
    PLAYER_END,
    PLAYER_BROADCAST,
    SPAWN_INCANTATION,
    INCANTATION_END,
    EGG_SPAWN,
    EGG_END,
    RECEIVE_TIME,
    END_OF_THEGAME,
    SERVER_MSG,
    UNKNOWN
  };

  class 			Parser {

  public:

    using Dictionnary = const std::vector<std::pair<ParseType, std::regex>>;

  private:

    ParseType _info;
    std::vector<std::string> _list;
    Dictionnary _dico =
      {
	// X : position x | Y : position y
	// f : food (int) | l : linemate (int) | d : deraumere (int) | s: sibur (int) | m : mendiane (int) | p : phiras (int) | t : thystame (int)
	// N : Nom de team
	// O : Orientation (N:1, E:2, S:3, O:4)
	// #n : Numéro de player sur le serveur (int)
	// L : Level du joueur / incantation (int)
	// M : Message
	// R : 0 ou 1
	// I : 0 -> food | 1 -> linemate | 2 -> deraumere | 3 -> sibur | 4 : mendiane |
	// #e : Numéro de l'oeuf
	// T : Unité de temps

	{ParseType::MAP_SIZE, std::regex("^msz(?:[\\s]+[\\d]+){2}$")}, //msz X Y : taille de la map
	{ParseType::CELL_CONTENT, std::regex("^bct(?:[\\s]+[\\d]+){9}$")}, //bct X Y f l d s m p t : Contenu d'une tile
	{ParseType::PLAYER_SPAWN, std::regex("^pnw(?:[\\s]+[\\d]+){5}[\\s]+[\\S]+$")},  //pnw #n X Y O L N : Connection joueur
	{ParseType::PLAYER_POSITION, std::regex("^ppo(?:[\\s]+[\\d]+){4}$")}, //ppo #n X Y O : Position d'un joueur
	{ParseType::PLAYER_LEVEL, std::regex("^plv(?:[\\s]+[\\d]+){2}$")}, //plv #n L : Niveau du joueur
	{ParseType::PLAYER_INVENTORY, std::regex("^pin(?:[\\s]+[\\d]+){8}$")}, //pin #n f l d s m p t : Inventaire du joueur
	{ParseType::PLAYER_END, std::regex("^pex[\\s]+[\\d]+$")}, //pex #n : Player exclu
	{ParseType::PLAYER_BROADCAST, std::regex("^pbc[\\s]+[\\d]+(?:[\\s]+[\\S]+)+$")}, // pbc #n M : Player envoie broadcast
	{ParseType::SPAWN_INCANTATION, std::regex("^pic(?:[\\s]+[\\d]+){3}$")}, //pic X Y L : Lancement d'un incantation
	{ParseType::INCANTATION_END, std::regex("^pie(?:[\\s]+[\\d]+){2}[\\s]+[0-1]$")}, //pie X Y R : Fin d'incantation
	{ParseType::EGG_SPAWN, std::regex("^enw(?:[\\s]+[\\d]+){3}[\\s]+[\\S]+$")}, //enw #e X Y N : Oeuf pondu sur la carte par la team
	{ParseType::EGG_END, std::regex("^eex[\\s]+[\\d]+$")}, //eex #e : L'oeuf est partie
	{ParseType::RECEIVE_TIME, std::regex("^sgt[\\s]+[\\d]+$")}, //sgt T : Donne l'unité de temps
	{ParseType::END_OF_THEGAME, std::regex("^seg[\\s]+[\\S]+$")}, //seg N : Fin du jeu
	{ParseType::SERVER_MSG, std::regex("^smg(?:[\\s]+[\\S]+)+$")}, //smg M : Message du serveur
      };

  public:

    Parser();
    ~Parser();
    void parse(const std::string &line);
    void reset(void);
    const ParseType &getType(void) const;
    const std::vector<std::string> &getArgs(void) const;
    std::string& operator[](std::size_t idx);
    const std::string &operator[](std::size_t idx) const;
  };

}

#endif /* !PSU_2016_ZAPPY_PARSER_HPP */
