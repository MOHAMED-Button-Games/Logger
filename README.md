# Logger
Simple Header-Only Library For Logging

## Compilers
> x64 C++
- [X] MSVC
- [X] G++
- [X] Clang/LLVM

## Features
* Print Text With Sub Text, Time, Types, And Name
* Save All The Print Data Into A Log File After The Program Finishs Execution, Or At Any Point In The Program

## Docs
### Macros: 
- `LOG_ERROR`
- `LOG_CRITICALERROR`
- `LOG_WARN`
- `LOG_SUCCESS`
- `LOG_TEXT`

### Init: 
- `Logger(const std::string& Name, bool File = false)`
- > Logger Init
- `void Name(const std::string& Name)`
- > Set The Logger Name
- `void File(bool File, const std::string& Name = "", const std::string& Ext = ".log")`
- > Set The Logger File, For Changing The Name Only Use `FileName()` Instead

### Print: 
- `void AddText(AnyType Text)`
- > Add Sub Text, The Sub Text Will Be Printed Behind The Print Text
- `void Print(AnyType Text, int Type = LOG_TEXT, bool File = true)`
- > Print Text, The Type Arg Will Specify The Text Color, Outputted Text: Name[Time]: Sub Text + Text

### File: 
- `void FileName(const std::string& Name, const std::string& Ext = ".log")`
- > Change The File Name More Than One Time
- `void AddToFileData(const std::string& Data);`
- > Add Data To The File Data That Doesn't Necessarily Need To Be Printed
- `std::string FileData()`
- > Get The File Data, For Reasons Like File Compression, Printing All The Logs In The Console, etc...
- `void ClearFileData()`
- > What Data??
- `bool MakeFile()`
- > Output The Log File, Outputted Text: Name[Type][Time]: Sub Text + Text

## Examples
* Simple Print
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.Print("Hello, World!\n");
	
	system("Pause");
	return 0;
}
```
Result: `[2:10:18]: Hello, World!`

---

* Print With Sub Text
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.AddText("Sub Text 1, ");
	Log.AddText("Sub Text 2, ");
	Log.AddText("Sub Text 3, ");
	Log.Print("Print Text\n");
	
	system("Pause");
	return 0;
}
```
Result: `[2:10:18]: Sub Text 1, Sub Text 2, Sub Text 3, Print Text`

---

```cpp
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.Print("Error\n", LOG_ERROR);
	Log.Print("Critical Error\n", LOG_CRITICALERROR);
	Log.Print("Warning\n", LOG_WARN);
	Log.Print("Success\n", LOG_SUCCESS);
	Log.Print("Text\n", LOG_TEXT);
	
  	system("Pause");
	return 0;
}
```
Result: If Your OS is Windows The Text Will Appear in Colors
- Red: Error
- Red Background: Critical Error
- Yellow: Warning
- Green: Success
- White: Plain Text

---

* Print With Name
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log("Name");
	Log.Print("Print Text With Name\n");
	
	system("Pause");
	return 0;
}
```
Result: `Name[2:10:18]: Print Text With Name`

---

* Log All Print Data To File
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log("Name", true);
	Log.Print("Make Lots of Prints To Be Stored\n");
	for (int i = 0; i < 30; i++)
	{
		Log.AddText(i);
		Log.Print("\n");
	}

	Log.MakeFile();
	system("Pause");
	return 0;
}
```
Result: The File Should Be Outputted In The Program's Path, The Path And The Extension Can Be Changed

First Line: `Name[Text][2:26:41]: Make Lots of Prints To Be Stored`

![alt text](https://i.postimg.cc/0ytbMVjS/Example.png)

---

* Filter File Data
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log("Name", true);
	Log.Print("Text\n");
	Log.Print("Text\n");
	Log.Print("This Text Should Not Be Saved\n", LOG_TEXT, false);
	Log.Print("Text\n");
	Log.Print("This Text Should Not Be Saved\n", LOG_TEXT, false);
	
	Log.MakeFile();
	system("Pause");
	return 0;
}
```
Result: The File Should Be Filtered Of Any Unwanted Prints

Name.log
```
Name[Text][16:48:46]: Text
Name[Text][16:48:46]: Text
Name[Text][16:48:46]: Text
```
