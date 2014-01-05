
#ifndef DEBUGLOGGER_H_
#define DEBUGLOGGER_H_

#include <iostream>

namespace shafeen {
namespace debug {

// THIS IS A SINGLETON CLASS USED TO LOG DEBUG OUTPUT
class DebugLogger 
{
public:

	static DebugLogger& getInstance();

	DebugLogger& operator<< (int val);
	DebugLogger& operator<< (const char *);
	DebugLogger& operator<< (const void *);

	// this is the function signature of std::endl
	typedef std::basic_ostream<char, std::char_traits<char> > scldl_CoutType;
	typedef scldl_CoutType& (*scldl_StandardEndLine)(scldl_CoutType&);
	DebugLogger& operator<<(scldl_StandardEndLine manip);

	void setOutputStream(std::ostream *);

	/*
	 * Disable the default copy constructor and copy assignment operator.
	 */
	DebugLogger(const DebugLogger&) = delete;
	DebugLogger& operator=(const DebugLogger&) = delete;
	DebugLogger(DebugLogger&&) = delete;
	DebugLogger& operator=(DebugLogger&&) = delete;

private:
	DebugLogger();
	virtual ~DebugLogger();

	std::ostream * ostream_ptr;

};

} /* namespace debug */
} /* namespace shafeen */
#endif /* DEBUGLOGGER_H_ */
