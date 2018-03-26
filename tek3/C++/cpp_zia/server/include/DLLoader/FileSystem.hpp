//
// Created by valentin on 08/02/18.
//

#ifndef CPP_RTYPE_FILESYSTEM_HPP
#define CPP_RTYPE_FILESYSTEM_HPP

#include <fstream>
#include <memory>
#include "types.hpp"

namespace zia {
	namespace fs {

		extern const detail::File InvalidFile;
		extern const detail::Folder InvalidFolder;

		class FileIterator {
		public:
			/// @brief
			/// @param file
			FileIterator(detail::File) noexcept;

			/// @brief Get the name of the current cursor file/folder without
			/// the full path.
			/// @return
			char const *name() noexcept;

			/// @brief Tells if the cursor points to a file.
			/// @return
			bool isFile() noexcept;

			/// @brief Tells if the cursor points to a directory.
			/// @return
			bool isDirectory() noexcept;

			/// @brief
			/// @return
			std::fstream open() noexcept;
		private:
			detail::File _filedesc;
		};

		/// @brief Interface used to handle file iteration in a given directory.
		class FolderDescriptor {
		private:

			class Impl;
			std::unique_ptr<Impl> _pimpl;

		public:

			/// @brief Loads a directory and set the initial cursor value.
			/// @param path
			FolderDescriptor(char const *path);
			~FolderDescriptor();

			/// @brief Tells if the folder status is valid, e.g
			/// the folder opened correctly and the file cursor is not null.
			/// @return
			operator bool() const;

			/// @brief Returns the file cursor at the start of the folder.
			/// @return false if an error occured, true otherwise
			bool reset();

			/// @brief Tells if there is another file availaible.
			/// @return True if the cursor is still valid, false otherwise.
			bool hasNext();

			/// @brief Returns the current selected file and move the cursor
			/// to the next entry.
			/// @return Next file entry.
			FileIterator next();

		};

	}
}

#endif /* CPP_RTYPE_FILESYSTEM_HPP */
