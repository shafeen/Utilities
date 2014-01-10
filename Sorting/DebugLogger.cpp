
#include "DebugLogger.h"

namespace shafeen {
namespace debug {

DebugLogger::DebugLogger() 
: ostream_ptr(nullptr)
{}

DebugLogger::~DebugLogger()
{}

void DebugLogger::setOutputStream(std::ostream * new_ostream_ptr)
{
	this->ostream_ptr = new_ostream_ptr;
}

DebugLogger& DebugLogger::operator<< (int val)
{
	if ( this->ostream_ptr != nullptr ) {
		*(this->ostream_ptr) << val;
	}
	return *this;
}

DebugLogger& DebugLogger::operator<< (const char * str)
{
	if ( this->ostream_ptr != nullptr ) {
		*(this->ostream_ptr) << str;
	}
	return *this;
}

DebugLogger& DebugLogger::operator<< (const void * ptr)
{
	if ( this->ostream_ptr != nullptr ) {
		*(this->ostream_ptr) << ptr;
	}
	return *this;
}

DebugLogger& DebugLogger::operator<<(scldl_StandardEndLine manip)
{
	if ( this->ostream_ptr != nullptr ) {
		manip(*(this->ostream_ptr));
	}
	return *this;
}

DebugLogger& DebugLogger::getInstance()
{
	static DebugLogger instance;
	return instance;
}

} /* namespace debug */
} /* namespace shafeen */
