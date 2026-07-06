# DuckiDumper
one of my most useful shit i have ever made :)

> This is an OGFN Offset dumper, it uses byte pattern scanning via **Memcury** for offsets.

# Build from source
- 1.) Open `DuckiDumper.sln` in Visual Studio 2022.

- 2.) Set `Debug` to **`Release`**

- 3.) Configure the byte patterns and offset name you wanna find in **``opts.h``**. 

Config is self-explanatory:: 
```cpp
{"NameHere","PatternHere,false},
// if set to "true" it will skip that
``` 
- 4.) Build the DLL with **`Ctrl+Shift+B`**
- 5.) Inject the dll into the OG Fortnite process and it will log you every single scanned byte pattern you configured. Enjoy :))

### Find patterns
To  find byte patterns get them from [Reboot](https://github.com/Milxnor/Project-Reboot-3.0), [Erbium](https://github.com/plooshi/Erbium) or a Reverse Engineering tool.


---

 ## Credits
- [Kem0x](https://github.com/kem0x) for [Memcury](https://github.com/kem0x/Memcury) - memcury.h
