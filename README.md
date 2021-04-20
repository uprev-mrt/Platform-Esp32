# ESP32
>Requires: Modules/Platforms/Common

Following the example projects to create a template, you should end up with a main directory containing a component.mk file.

add the following lines to this coponent.mk, filling in the modules used... 

```make
CFLAGS+= -DMRT_PLATFORM=MRT_ESP32

COMPONENT_ADD_INCLUDEDIRS := Path/To/MrT/Modules  Path/To/MrtModules/<module-1-path> Path/To/MrtModules/<module-2-path> 

COMPONENT_SRCDIRS := Path/To/MrT/Modules  Path/To/MrtModules/<module-1-path> Path/To/MrtModules/<module-2-path> 
```
This is plannned to be improved so you dont have to list each module path