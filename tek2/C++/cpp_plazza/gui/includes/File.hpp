/*
** File.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/File.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 24 20:21:29 2017 Vincent DUSAUTOIR
** Last update Mon Apr 24 20:21:29 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_FILE_HPP
#define CPP_PLAZZA_FILE_HPP

#include <string>
#include <fstream>
#include <sstream>

namespace plazza {

  /**
   * @brief Class used for files manipulation
   */
  class			File {
    bool		_open;
    std::string		_filename;
    std::stringstream	_buffer;

  public:
    /**
     * @brief Class constructor
     */
    File();

    /**
     * @brief Class constructor using a filename
     * @param filename
     */
    File(const std::string &filename);
    ~File();

    /**
     * @brief return actual loaded filename
     * @return const std::string
     */
    const std::string	&getFilename() const;

    /**
     * @brief Load file provided as parameter
     * @param string
     */
    void		load(const std::string &string);

    /**
     * @brief Check if file is loaded
     * @return
     */
    bool		isOpen() const;

    /**
     * @brief Get loaded file buffer
     * @return std::string
     */
    std::string		getBuffer() const;

    /**
     * @brief Define file state
     * @param open
     */
    void		setOpen(const bool open);
  };

}

#endif //CPP_PLAZZA_FILE_HPP
