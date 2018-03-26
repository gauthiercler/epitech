/*
** DLLoaderManager.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/DLLoaderManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mars 11 12:52:53 2017 Anthony LECLERC
// Last update Fri Mar 17 21:34:49 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_DLLOADERMANAGER_HPP
# define CPP_ARCADE_DLLOADERMANAGER_HPP

# include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <server/include/spawner/SpawnerManager.hpp>
#include "DLInstanceLoader.hpp"
#include "DLLoaderFactory.hpp"
#include "FileSystem.hpp"
#include "shared/ECS/include/ISpawner.hpp"

#ifdef UNIX
#	include <dirent.h>
#endif

namespace rtype {
	namespace module {
		template <typename TInterface>
		class DLLoaderManager {
		public:

			using loader_type = DLInstanceLoader<TInterface>;
			typedef typename std::vector<std::unique_ptr<loader_type> > Loaders;
			typedef typename Loaders::iterator             iterator;
			typedef typename Loaders::const_iterator       const_iterator;

		private:
			std::string _folder;
			Loaders     _libs;

		public:
			DLLoaderManager() :
				_folder(), _libs()
			{}

			DLLoaderManager(char const *path) :
				_folder(), _libs()
			{
				loadLibraries(path);
			}

			~DLLoaderManager() = default;

			/*
			 * \brief iterator for Libraries -> from std::vector
			 */
			iterator
			begin()
			{ return _libs.begin(); }

			const_iterator
			begin() const
			{ return _libs.begin(); }

			iterator
			end()
			{ return _libs.end(); }

			const_iterator
			end() const
			{ return _libs.end(); }


			bool
			loadLibrary(std::string const& file)
			{
				std::cout << "Lib path: " << file << std::endl;
				if (std::none_of(_libs.begin(), _libs.end(),
					[&file](auto&& it) {
						return (it->path() == file);
					}))
				{
					auto loader = module::make::newFunctionLoader<TInterface>(file.c_str());
					if (!loader->isLoaded()) {
						return false;
					}
					_libs.push_back(std::move(loader));
					return true;
				}
				return false;
			}

			/// @brief Load all possible libraries in a folder,
			/// given a relative or alsolute path
			/// @param path
			/// @return Number of loaded libraries.
			std::size_t
			loadLibraries(char const *path)
			{
				fs::FolderDescriptor directory_view(path);

				if (!directory_view) {
					return 0;
				}

				std::size_t count { 0 };
				while (directory_view.hasNext()) {
					auto file = directory_view.next();
					if (file.isFile()) {
						std::string filepath(path);

						// Add folder path to the file name
						filepath.append(file.name());
						if (loadLibrary(filepath))
							++count;
					}
				}
				return count;
			}

			/*
			 * \brief Unload the library pointed by the iterator and remove it from _libs
			 * \param library	iterator to the library to be removed
			 */
			void
			removeLibrary(iterator& library)
			{
				_libs.erase(library);
			}

			void
			removeLibraries()
			{
				_libs.erase(_libs.begin(), _libs.end());
			}

			void
			removeLibraries(iterator begin, iterator end)
			{
				_libs.erase(begin, end);
			}

			/*
			 * if size == 0, then no library have been loaded
			 */
			size_t
			size() const
			{
				return _libs.size();
			}

			/// @brief Getter
			/// @param void
			/// @return vector of libraries

			std::vector<ecs::ISpawner *>
			getSpawners() {
				std::vector<ecs::ISpawner *> spawners;

				for (auto &library : _libs) {
					auto f = library->template loadFunction<ecs::ISpawner *(*)()>("getSpawner");
					if (f != nullptr)
						spawners.emplace_back(f());
				}
				return (spawners);
			}

			/// @brief Fill the SpawnerManager of Spawners
			/// @param SpawnerManager &
			/// @return void

			void fillSpawnerManager(rtypeserver::SpawnerManager &manager) {
				for (auto &library : _libs) {
					auto f = library->template loadFunction<ecs::ISpawner *(*)()>("getSpawner");
					if (f != nullptr)
						manager.addSpawner(f());
					else
						std::clog << "[ERROR] Failed to load function \"getSpawner\"." << std::endl;
				}
			}

		};
	}
}

#endif /* !CPP_ARCADE_DLLOADERMANAGER_HPP */
