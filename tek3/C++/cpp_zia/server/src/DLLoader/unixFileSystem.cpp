//
// Created by valentin on 08/02/18.
//

#include "DLLoader/FileSystem.hpp"

namespace zia {
	namespace fs {

		const detail::Folder InvalidFolder { nullptr };
		const detail::File InvalidFile { nullptr };

		/// @brief Implementation is free, but it must fill requirement of the
		/// FolderDescriptor interface.
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

			detail::Folder _dir;
			detail::File _file;

		};

		FolderDescriptor::Impl::Impl(char const *path) noexcept :
			_dir(opendir(path)), _file(nullptr)
		{
			if (validDir())
				_file = readdir(_dir);
		}

		FolderDescriptor::Impl::~Impl() noexcept
		{
			if (validDir())
				closedir(_dir);
		}

		FolderDescriptor::Impl::operator bool() const noexcept
		{
			return validDir();
		}

		bool FolderDescriptor::Impl::reset() noexcept
		{
			if (validDir())
			{
				rewinddir(_dir);
				_file = readdir(_dir);
				return true;
			}
			return false;
		}

		bool FolderDescriptor::Impl::validDir() const noexcept
		{
			return _dir != InvalidFolder;
		}

		bool FolderDescriptor::Impl::hasNext() noexcept
		{
			return _file != InvalidFile;
		}

		FileIterator FolderDescriptor::Impl::next() noexcept
		{
			if (validDir())
			{
				FileIterator it(_file);
				_file = readdir(_dir);
				return it;
			}
			return FileIterator(nullptr);
		}

		FolderDescriptor::FolderDescriptor(char const *path) :
			_pimpl(std::make_unique<Impl>(path))
		{}

		FolderDescriptor::~FolderDescriptor() = default;

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

		/// File iterators definition.

		FileIterator::FileIterator(detail::File file) noexcept :
			_filedesc(file)
		{}

		char const *FileIterator::name() noexcept
		{
			if (_filedesc != InvalidFile)
				return &_filedesc->d_name[0];
			return nullptr;
		}

		std::fstream FileIterator::open() noexcept
		{
			return std::fstream(name());
		}

		bool FileIterator::isFile() noexcept
		{
			if (_filedesc == InvalidFile)
				return false;
			return _filedesc->d_type == DT_CHR || _filedesc->d_type == DT_REG;
		}

		bool FileIterator::isDirectory() noexcept
		{
			if (_filedesc == InvalidFile)
				return false;
			return _filedesc->d_type == DT_DIR;
		}
	}
}



