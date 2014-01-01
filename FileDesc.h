#pragma once
#include <string>

namespace ni {
	class FileDesc {
	public:
		FileDesc(int fd);
		FileDesc(const std::string& filePath, int mode);
		FileDesc(const FileDesc& source);
		FileDesc& operator=(const FileDesc& source);
		~FileDesc();

		operator int() const;
		void close();
		bool good() const;
	private:
		int m_fd;
	};
}