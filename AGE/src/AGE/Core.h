#pragma once
/*
Author: Adam Osama Mekhail
Date: November 21st 2019
Description: Allows the dll to be linked to other solutions 
Copyright (c) AGE 2019
*/

#ifdef AGE_PLATFORM_WINDOWS
	#ifdef AGE_BUILD_DLL
		#define AGE_API __declspec(dllexport)
	#else
		#define AGE_API __declspec(dllimport)
	#endif
#else
	#error Adam Game Engine only supports Windows!
#endif