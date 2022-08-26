# Logger
Simple Header-Only Library For Logging

## Compilers
> x64 C++
- [X] MSVC
- [ ] GCC (Not Tested)
- [X] Clang/LLVM

## Features
* Print Text With Sub Text, Time, Types, And Name
* Save All The Print Data Into A Log File After The Program Finishs Execution, Or At Any Point In The Program

## Examples
* Simple Print
```cpp
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.Print("Hello, World!");
	
	system("Pause");
	return 0;
}
```
Result: `[2:10:18]: Print Text`

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
	Log.Print("Print Text");
	
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
	Log.Print("Error", LOG_ERROR);
	Log.Print("Critical Error", LOG_CRITICALERROR);
	Log.Print("Warning", LOG_WARN);
	Log.Print("Success", LOG_SUCCESS);
	Log.Print("Text", LOG_TEXT);
	
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
	Log.Print("Print Text With Name");
	
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
	Log.Print("Make Lots of Prints To Be Stored");
	for (int i = 0; i < 30; i++)
	{
		Log.Print(i);
	}

	Log.MakeFile();
	system("Pause");
	return 0;
}
```
Result: The File Should Be Outputted In The Program's Path, The Path And The Extension Can Be Changed

First Line: `Name[Text][2:26:41]: Make Lots of Prints To Be Stored`

![alt text](https://i.postimg.cc/0ytbMVjS/Example.png)
