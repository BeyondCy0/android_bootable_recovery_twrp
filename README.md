
·Chinese`

## zh-CN 中文和英文切换版本由 @sndnvaps 修改

    参考 @syhost的代码进行修改

## 中文字库的生成文件，经过一些修改（目的是为了生成graphics.c 中需要的参数，并解决编译出错)

	真实双系统已经完成95%了，能满足一般用户的需求了。

	界面的翻译已经完成98%了，剩下的已经无关紧要了。



    参考 @M1cha 和 @ivan19871002 (秋叶随风) 两位大神的代码进行再一步修改而成。

# 版本 2.7.0.0 

----------------------------------------------------------------------


`English`

## Support Display English and Chinese modify by @sndnvaps 

	Thanks @syhost twrp_cn2.4 origin project 

## Modify gen chinese character header file(font_cn_32x32.h), add some needs vars to complite graphics to fix build errors

	TrueDualBoot func has complete 95%. suit for normal user.

	Translation English to Chinese has complete 98%.


## Thanks @M1cha & @ivan19871002(秋叶随风) for TrueDualBoot feature 

# Version 2.7.0.0 


------------------------------------------------------------------------

## TODO:

 - [x] Support Chinese and English (支持中文和英文双语言切换,在高级功能里面)
 - [x] Support xiaomi device    (支持小米手机)
 - [x] Add TDB(TrueDualBoot) Feature to twrp (真实双系统功能)
 - [x] Parse Active system_num(PAS) from `misc` partition (获取当前激活系统)
 - [x] Detected Dual system mode(`DSM`) or One system mode(`OSM`) (判断双系统模式 或 单系统模式)


-------------------------------------------------------------------------

**Team Win Recovery Project (TWRP)**

The goal of this branch is to rebase TWRP onto AOSP while maintaining as much of the original AOSP code as possible. This goal should allow us to apply updates to the AOSP code going forward with little to no extra work.  With this goal in mind, we will carefully consider any changes needed to the AOSP code before allowing them.  In most cases, instead of changing the AOSP code, we'll create our own functions instead.  The only changes that should be made to AOSP code should be those affecting startup of the recovery and some of the make files.

If there are changes that need to be merged from AOSP, we will pull the change directly from AOSP instead of creating a new patch in order to prevent merge conflicts with AOSP.

This branch is under final testing and will be used shortly for public builds, but has not officially been released.

You can find a compiling guide [here](http://forum.xda-developers.com/showthread.php?t=1943625 "Guide").

[More information about the project.](http://www.teamw.in/project/twrp2 "More Information")

If you have code changes to submit those should be pushed to our gerrit instance.  A guide can be found [here](http://teamw.in/twrp2-gerrit "Gerrit Guide").

  
