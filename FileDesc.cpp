#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "FileDesc.h"

using namespace ni;

FileDesc::FileDesc(int fd) : m_fd(fd) {

}

FileDesc::FileDesc(const std::string& filePath, int mode) {
	m_fd = open(filePath.c_str(), mode);
}

FileDesc::FileDesc(const FileDesc& source) : m_fd(dup(source.m_fd)) {

}

FileDesc& FileDesc::operator=(const FileDesc& source) {
	if(&source != this) {
		m_fd = dup(source.m_fd);
	}
	return *this;
}

FileDesc::~FileDesc() {
	this->close();
}

FileDesc::operator int() const {
	return m_fd;
}

void FileDesc::close() {
	if(good()) {
		::close(m_fd);
	}
}

bool FileDesc::good() const {
	return m_fd != -1;
}