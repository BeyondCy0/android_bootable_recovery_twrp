`Chinese`

## zh-CN 中文和英文切换版本由 [@sndnvaps][1] 修改

参考 [@syhost][3] 的 [https://github.com/syhost/TWRP_CN][5] 项目

## 中文字库的生成文件，经过一些修改（目的是为了生成graphics.c 中需要的参数，并解决编译出错)


# 版本: 2.7.0.0 

----------------------------------------------------------------------


  `English`

## Multiple Languages support port by [@sndnvaps][1]

Thanks [@syhost][3] twrp_cn2.4 origin project 

## Modify gen chinese character header file(font_cn_32x32.h), add some needs vars to complite graphics to fix build errors


## Thanks [@M1cha][2] & [@ivan19871002][4] for TrueDualBoot feature 

# Version: 2.7.0.0 


-------------------------------------------------------------------------

**Team Win Recovery Project (TWRP)**

The goal of this branch is to rebase TWRP onto AOSP while maintaining as much of the original AOSP code as possible. This goal should allow us to apply updates to the AOSP code going forward with little to no extra work.  With this goal in mind, we will carefully consider any changes needed to the AOSP code before allowing them.  In most cases, instead of changing the AOSP code, we'll create our own functions instead.  The only changes that should be made to AOSP code should be those affecting startup of the recovery and some of the make files.

If there are changes that need to be merged from AOSP, we will pull the change directly from AOSP instead of creating a new patch in order to prevent merge conflicts with AOSP.

This branch is under final testing and will be used shortly for public builds, but has not officially been released.

You can find a compiling guide [here](http://forum.xda-developers.com/showthread.php?t=1943625 "Guide").

[More information about the project.](http://www.teamw.in/project/twrp2 "More Information")

If you have code changes to submit those should be pushed to our gerrit instance.  A guide can be found [here](http://teamw.in/twrp2-gerrit "Gerrit Guide").

 [1]: https://github.com/sndnvaps
 [2]: https://github.com/M1cha
 [3]: https://github.com/syhost
 [4]: https://github.com/ivan19871002
 [5]: https://github.com/syhost/TWRP_CN
 