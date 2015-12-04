# Introduction #

This page collect updates to:

Roeland M.H. Merks and Michael A. Guravage (2013)  "Building Simulation Models of Developing Plant Organs Using VirtualLeaf", in: De Smet, I.(ed.), Plant Organogenesis: Methods and Protocols, Methods in Molecular Biology, vol. 959, pp. 333-352.


# 2.1 Required Software: C++ Compiler and Libraries #

If you are on a Windows system, make sure that your have
compatible  versions of MinGW and Qt. Qt versions 4.6.4 and 4.8 2 both
expect g++ version 4.4.0.

Install MinGW following the instructions at
http://mingw.org/wiki/HOWTO_Install_the_MinGW_GCC_Compiler_Suite.
Select "MinGW Shell" from the Windows start menu and type the command:
"g++ -v".

If the version number is not 4.4.0, download the file:

http://virtualleaf.googlecode.com/files/gcc-full-4.4.0-mingw32-bin-2.tar.lzma,
open it with a tool such as 7Zip and copy its contents over your
existing MinGW installation, e.g.,   "c:\MinGW".

Next edit the file
"c:\MinGW\include\w32api.h" and change  the "W32API\_VERSION" to 3.13
and "W32API\_Minor\_VERSION" to 13. Now QT should install without
complaint.'

# Some issues collected by Robbert Geerts #

Used Platform: Fedora (Linux)
Used Editors: Kate/gedit

General issues: (most have to do with PDF to text and can't be helped, so these are more like remarks)
  * The “” characters in the PDF file (“”) are different from the ones used in the editor, when Copy-Pasting, rewrite them in the editor to avoid this. Same goes for the – (should be -)
  * Sometimes, (for me atleast) it's not really clear whether you need to start again from an empty model (or use the // to make the compiler think this) or if you can add it all to the same file. (Also see lined issues below).
  * Sometimes, the code in the PDF breaks into multiple lines, so you may want to use backspace to make this look cleaner.
  * Sometimes, I'm not sure whether the Grow cells youd be on or not, especially in the later parts (for example the wave traveling motion model doesn't explicitily say this).
  * References and links are not clickable (for me) the links do work, even though some were not working.

**Starting from Paragraph 3.2:**

  * P3.2 Point 6 (line 241): Minor inconcistency with the name “MyModel” and “mymodel”, linux (and C++) can be very itchy about the use of capital letters. (The sentence 'reflecting the name you choose' actually warns a little for this)
  * P3.3 Point 7 (line 297) It says Pi.h, while the file is called pi.h (No capital p)
  * P3.4 Point 9, be carefull with those – and - when copy-pasting.
  * P3.4 Point 17/18 There seems to be a problem if you don't deactivate (//) all the other added code as well, else you still get an error/crash. I solved this by reading another (tutorial) leaf and waiting until it has 8 leaves. Then I saved it and used it later on. (On a side note, I did forget to see if it had chemicals set, so I actually had to manually add random numbers from another leaf to get the random chemicals).
  * P3.4 Point 19, What I see is that the cells spread (reddish) from the initial venature cell and in a very short time turn all the other cells red as well (within a reach of about 15 cells) followed by turning green and not growing anymore (this is because they won't divide if they don't have the auxin). Only if I turn the rd/dt to about 1, the growing celles have a chance to outrun the red 'plague' a little before they also become red. This probably had to do with the code, because I'm not sure at the moment which code should and which code shouldn't be enabled.
  * P3.5 Point 4, this only works if you have the Meinhardt reactions disabled, since those reactions require 4 chems instead of 2. Else, virtual leaf crashes/closes, with no given error.
  * P3.5 Point 6 (line 592) “MyAuxinModel” shouild be “MyModel” (or “mymodel”), else the compiler does not recognize this as using the previously made function.
  * P3.5 Point 8, mildly confusing, since it always uses the “mymodel” name and now it starts with “traveling wave motion” model. You can ded uce that it's the model your working with, but it confused me the first time I read it.
  * P3.5 Point 10, Where first you were told to close VirtualLeaf etc, this part skips all the parts in between and goes directly to adding the new code. (Personally, I don't mind, but it goes from like slowly driving to racing in a race car)
  * P3.5 Point 11, previously, “the first value of D” was used, where it now just becomes D[0](0.md). Also, the other variables are sometimes confusing when trying to set them in the parameters section at first. They do allow you to see which value of the reaction you're actually setting though. (Also, the previous times you had to set the parameters, they were in the order of the parameters in the “Edit Parameters” section. This time, they are not ordered any more.
  * P3.5 Point 13, most likely due my wrong usage of the code (see points above), I got different results. So I tested it on the tutorial (5) file and that gave a similar result as the picture.

**Extra issues (more like things I encountered):**
  * My version of VirtualLeaf makes an directory (named after the used Model) if you want to save/read a leaf instead of going to the data directory (where all the leaves are placed). Is there (or could there be) a way to configure a standard path for this?
> _RM: This may have been solved in [v1.0.2](https://drive.google.com/folderview?id=0B4SMVyYUsosrbVY3LTRXUHd5WWs&usp=sharing)._
  * Why does the normal click of the mouse start some red trajectory line, I can't seem to get rid of once drawn?
> _RM:  You have discovered our undocumented ```leaf cutter''! You can cut off part of a tissue, turning the cut line into a new boundary.  It's how we produced the initial condition for our ```traveling wave model'' in Merks et al. Trends Plant Sci 2007. It's not failsafe though, and can make VirtualLeaf crash._
  * I like the fact that you can check your work with the pictures, it shows whether or not you're doing it right or wrong.
> _RM: Thanks :-) If you need to do some more statistics, though, please have a look at the book chapter by Margriet M. Palm and me, that should out soon in Meth. Mol. Biol. See the main page for a full reference._
  * Perhaps, mentioning the version of QT creator would help with installation.
> _RM: I typically do not use QT Creator are any other IDE, but use the command line tools. A short manual for how to compile VirtualLeaf using Qt Creator would be welcome, though.._