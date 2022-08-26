//Copyright(c) 2022 MOHAMED Button Games
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

//Additions.Fixes
//2.2

//Created: 8/25/22
#pragma once

#include <iostream> //std::cout, std::endl
#include <fstream>  //std::ofstream
#include <string>   //std::string, std::to_string
#include <ctime>    //std::time_t, std::tm, std::time, localtime_s
#include <math.h>   //floor

//I'm Pretty Sure That Nobody Uses Windows 32-Bit, Right?
#ifdef _WIN64
	#include <Windows.h> //HANDLE, SetConsoleTextAttribute
#endif

#define LOG_ERROR		  12
#define LOG_CRITICALERROR 64
#define LOG_WARN		  14
#define LOG_SUCCESS		  10
#define LOG_TEXT		  15

struct Logger
{
private:
	std::string _Name;
	std::string _SubText;
	const char* _Type(int Type);
#ifdef _WIN64
	HANDLE _Handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	std::time_t _Time = std::time(0);
	std::tm _TimeFormat{};
	std::string _TimeData;
	bool _File = false;
	std::string _FileName;
	std::string _FileData;
public:
	Logger();
	//Logger Init
	Logger(const std::string& Name, bool File = false);

	//Set The Logger Name
	void Name(const std::string& Name);

	//Set The Logger File
	void File(bool File, const std::string& Name = "", const std::string& Ext = ".log");

	//Add Sub Text, char|const char*|std::string|Numbers Overloads
	//The Sub Text Will Be Printed Behind The Print Text
	void AddText(char Text);
	void AddText(const char* Text);
	void AddText(const std::string& Text);
	template<class T> void AddText(T Text);

	//Print Text, char|const char*|std::string|Numbers Overloads
	//The Type Arg Will Specify The Text Color
	//Outputted Text: Name[Time]: Sub Text + Text
	void Print(char Text, int Type = LOG_TEXT, bool File = true);
	void Print(const char* Text, int Type = LOG_TEXT, bool File = true);
	void Print(const std::string& Text, int Type = LOG_TEXT, bool File = true);
	template<class T> void Print(T Text, int Type = LOG_TEXT, bool File = true);

	//Log File
	//Outputted Text: Name[Type][Time]: Sub Text + Text
	//Change The File Name More Than One Time
	void FileName(const std::string& Name, const std::string& Ext = ".log");
	//Get The File Data, For Reasons Like File Compression, Printing All The Logs In The Console, etc...
	std::string FileData();
	//What Data??
	void ClearFileData();
	//Output The Log File
	bool MakeFile();
};

inline Logger::Logger()
{
}

Logger::Logger(const std::string& Name, bool File)
{
	_Name = Name;
	_File = File;
	_FileName = Name + ".log";
}

inline void Logger::Name(const std::string& Name)
{
	_Name = Name;
	_FileName = Name + ".log";
}

inline void Logger::File(bool File, const std::string& Name, const std::string& Ext)
{
	_File = File;
	if (Name != "")
	{
		_FileName = Name + Ext;
	}
}

inline void Logger::AddText(char Text)
{
	_SubText += Text;
}

inline void Logger::AddText(const char* Text)
{
	_SubText += Text;
}

inline void Logger::AddText(const std::string& Text)
{
	_SubText += Text;
}

template<class T>
inline void Logger::AddText(T Text)
{
	double _Sum = floor(double(Text)) - double(Text);
	if (_Sum == 0)
	{
		_SubText += std::to_string(long(Text));
	}
	else
	{
		_SubText += std::to_string(double(Text));
	}
}

inline const char* Logger::_Type(int Type)
{
	switch (Type)
	{
	case LOG_ERROR:			return "[Error]";
	case LOG_CRITICALERROR: return "[Critical Error]";
	case LOG_WARN:			return "[Warning]";
	case LOG_SUCCESS:		return "[Success]";
	case LOG_TEXT:			return "[Text]";
	}
	return "[Text]";
}

inline void Logger::Print(char Text, int Type, bool File)
{
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, Type);
#endif
	_Time = std::time(0);
	localtime_s(&_TimeFormat, &_Time);
	_TimeData = '[' + std::to_string(_TimeFormat.tm_hour) + ':' + std::to_string(_TimeFormat.tm_min) + ':' + std::to_string(_TimeFormat.tm_sec) + ']';
	std::cout << _Name << _TimeData << ": " << _SubText << Text << std::endl;
	if (_File && File)
	{
		_FileData += _Name + _Type(Type) + _TimeData + ": " + _SubText;
		_FileData += Text;
		_FileData += "\n";
	}
	_SubText.clear();
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, LOG_TEXT);
#endif
}

inline void Logger::Print(const char* Text, int Type, bool File)
{
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, Type);
#endif
	_Time = std::time(0);
	localtime_s(&_TimeFormat, &_Time);
	_TimeData = '[' + std::to_string(_TimeFormat.tm_hour) + ':' + std::to_string(_TimeFormat.tm_min) + ':' + std::to_string(_TimeFormat.tm_sec) + ']';
	std::cout << _Name << _TimeData << ": " << _SubText << Text << std::endl;
	if (_File && File)
	{
		_FileData += _Name + _Type(Type) + _TimeData + ": " + _SubText;
		_FileData += Text;
		_FileData += "\n";
	}
	_SubText.clear();
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, LOG_TEXT);
#endif
}

inline void Logger::Print(const std::string& Text, int Type, bool File)
{
	Print(Text.c_str(), Type, File);
}

template<class T>
inline void Logger::Print(T Text, int Type, bool File)
{
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, Type);
#endif
	_Time = std::time(0);
	localtime_s(&_TimeFormat, &_Time);
	_TimeData = '[' + std::to_string(_TimeFormat.tm_hour) + ':' + std::to_string(_TimeFormat.tm_min) + ':' + std::to_string(_TimeFormat.tm_sec) + ']';
	std::cout << _Name << _TimeData << ": " << _SubText << Text << std::endl;
	if (_File && File)
	{
		_FileData += _Name + _Type(Type) + _TimeData + ": " + _SubText;
		double _Sum = floor(double(Text)) - double(Text);
		if (_Sum == 0)
		{
			_FileData += std::to_string(long(Text));
		}
		else
		{
			_FileData += std::to_string(double(Text));
		}
		_FileData += "\n";
	}
	_SubText.clear();
#ifdef _WIN64
	SetConsoleTextAttribute(_Handle, LOG_TEXT);
#endif
}

inline void Logger::FileName(const std::string& Name, const std::string& Ext)
{
	_FileName = Name + Ext;
}

inline std::string Logger::FileData()
{
	return _FileData;
}

inline void Logger::ClearFileData()
{
	_FileData.clear();
}

inline bool Logger::MakeFile()
{
	if (_File)
	{
		std::ofstream File(_FileName);
		if (File.fail())
		{
			return false;
		}
		File << _FileData;
		File.close();
		_FileData.clear();
		return true;
	}
	_FileData.clear();
	return false;
}