# Logger
Simple Logger

## Examples
* Simple Print
```
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.Print("Hello, World!");
	
	return 0;
}
```
Result: `[2:10:18]: Print Text`

---

* Print With Sub Text
```
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.AddText("Sub Text 1, ");
	Log.AddText("Sub Text 2, ");
	Log.AddText("Sub Text 3, ");
	Log.Print("Print Text");
  
	return 0;
}
```
Result: `[2:10:18]: Sub Text 1, Sub Text 2, Sub Text 3, Print Text`

---

```
#include "Logger.hpp"

int main()
{
	Logger Log;
	Log.Print("Error", LOG_ERROR);
	Log.Print("Critical Error", LOG_CRITICALERROR);
	Log.Print("Warning", LOG_WARN);
	Log.Print("Success", LOG_SUCCESS);
	Log.Print("Text", LOG_TEXT);
  
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
```
#include "Logger.hpp"

int main()
{
	Logger Log("Name");
	Log.Print("Print Text With Name");
  
	return 0;
}
```
Result: `Name[2:10:18]: Print Text With Name`

---

* Log All Print Data To File
```
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

![alt text](https://i.postimg.cc/0ytbMVjS/Example.png)
