//
// CodeWriter.h
//
// $Id: //poco/1.3/PageCompiler/src/CodeWriter.h#1 $
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef CodeWriter_INCLUDED
#define CodeWriter_INCLUDED


#include "Poco/Poco.h"
#include <ostream>


class Page;


class CodeWriter
	/// This class implements the code generator for
	/// generating C++ header and implementation files 
	/// from C++ Server Pages.
{
public:
	CodeWriter(const Page& page, const std::string& clazz);
		/// Creates the CodeWriter, using the given Page.

	~CodeWriter();
		/// Destroys the PageReader.

	virtual void writeHeader(std::ostream& ostr, const std::string& headerFileName);
		/// Writes the header file contents to the given stream.

	virtual void writeImpl(std::ostream& ostr, const std::string& headerFileName);
		/// Writes the implementation file contents to the given stream.

	const Page& page() const;
		/// Returns a const reference to the Page.
		
	const std::string& clazz() const;
		/// Returns the name of the handler class.

protected:
	virtual void writeHeaderIncludes(std::ostream& ostr);
	virtual void writeHandlerClass(std::ostream& ostr);
	virtual void writeHandlerMembers(std::ostream& ostr);
	virtual void writeFactoryClass(std::ostream& ostr);
	virtual void writeImplIncludes(std::ostream& ostr);
	virtual void writeConstructor(std::ostream& ostr);
	virtual void writeHandler(std::ostream& ostr);
	virtual void writeFactory(std::ostream& ostr);
	virtual void writeSession(std::ostream& ostr);
	virtual void writeForm(std::ostream& ostr);
	virtual void writeRequest(std::ostream& ostr);
	virtual void writeManifest(std::ostream& ostr);
	
	void beginGuard(std::ostream& ostr, const std::string& headerFileName);
	void endGuard(std::ostream& ostr, const std::string& headerFileName);
	void beginNamespace(std::ostream& ostr);
	void endNamespace(std::ostream& ostr);
	void handlerClass(std::ostream& ostr, const std::string& base, const std::string& ctorArg);
	void factoryClass(std::ostream& ostr, const std::string& base);
	void factoryImpl(std::ostream& ostr, const std::string& arg);

private:
	CodeWriter();
	CodeWriter(const CodeWriter&);
	CodeWriter& operator = (const CodeWriter&);

	const Page& _page;
	std::string _class;
};


//
// inlines
//
inline const Page& CodeWriter::page() const
{
	return _page;
}


inline const std::string& CodeWriter::clazz() const
{
	return _class;
}


#endif // CodeWriter_INCLUDED
