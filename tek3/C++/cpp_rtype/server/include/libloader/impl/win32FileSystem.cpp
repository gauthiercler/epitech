//
// win32FileSystem.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/win32FileSystem.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  ven. janv. 19 23:05:28 2018 Anthony LECLERC
// Last update ven. janv. 19 23:05:28 2018 Anthony LECLERC
//

#include <windows.h>
#include <iostream>
#include "../FileSystem.hpp"

namespace rtype {
	namespace fs {

		const detail::Folder InvalidFolder { INVALID_HANDLE_VALUE };
		const detail::File InvalidFile { nullptr };

		/// @brief Basic implementation of Folder description instance, but it's not
		/// required to be the exact same. Only the FolderDescriptor interface
		/// is required to be implemented.
		class FolderDescriptor::Impl {
		public:
			Impl(char const *path) noexcept;
			~Impl() noexcept ;
			operator bool() const noexcept;

			bool reset() noexcept;

			bool hasNext() noexcept;

			FileIterator next() noexcept;
		private:

			bool validDir() const noexcept;

			std::string _path;
			detail::Folder _dir;
			WIN32_FIND_DATA _file;
			WIN32_FIND_DATA _data;
			BOOL _next = 1;

		};

		FolderDescriptor::Impl::Impl(char const *path) noexcept
			: _path(path), _dir(FindFirstFile((_path + "/*").c_str(), &_data))
		{
			if (validDir())
				_file = _data;
		}

		FolderDescriptor::Impl::~Impl() noexcept
		{
			if (validDir())
				FindClose(_dir);
		}

		FolderDescriptor::Impl::operator bool() const noexcept
		{
			return validDir();
		}

		bool FolderDescriptor::Impl::reset() noexcept
		{
			if (validDir())
			{
				FindClose(_dir);
				_dir = FindFirstFile((_path + "/*").c_str(), &_data);
				_next = 1;
				if (validDir()) {
					_file = _data;
					return (true);
				} else
					return (false);
			}
			return (false);
		}

		bool FolderDescriptor::Impl::validDir() const noexcept
		{
			return _dir != InvalidFolder;
		}

		bool FolderDescriptor::Impl::hasNext() noexcept
		{
			return _next > 0;
		}

		FileIterator FolderDescriptor::Impl::next() noexcept
		{
			_file = _data;
			_next = FindNextFile(_dir, &_data);
			return (FileIterator(&_file));
		}

		FolderDescriptor::FolderDescriptor(char const *path) :
			_pimpl(std::make_unique<Impl>(path))
		{}

		FolderDescriptor::operator bool() const
		{
			return !!(*_pimpl);
		}

		bool FolderDescriptor::reset()
		{
			return _pimpl->reset();
		}

		bool FolderDescriptor::hasNext()
		{
			return _pimpl->hasNext();
		}

		FileIterator FolderDescriptor::next()
		{
			return _pimpl->next();
		}

		FolderDescriptor::~FolderDescriptor() = default;


		FileIterator::FileIterator(detail::File file) noexcept :
			_filedesc(file)
		{}

		char const *FileIterator::name() noexcept
		{
			return (&static_cast<WIN32_FIND_DATA *>(_filedesc)->cFileName[0]);
		}

		std::fstream FileIterator::open() noexcept
		{
			return std::fstream(name());
		}

		bool FileIterator::isFile() noexcept
		{
			return (static_cast<WIN32_FIND_DATA *>(_filedesc)->dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY);
		}

		bool FileIterator::isDirectory() noexcept
		{
			return (static_cast<WIN32_FIND_DATA *>(_filedesc)->dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY);
		}


	}
}