#include "luyuException.h"
#include <sstream>

luyuException::luyuException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* luyuException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* luyuException::GetType() const noexcept
{
	return "luyu Exception";
}

int luyuException::GetLine() const noexcept
{
	return line;
}

const std::string& luyuException::GetFile() const noexcept
{
	return file;
}

std::string luyuException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}

