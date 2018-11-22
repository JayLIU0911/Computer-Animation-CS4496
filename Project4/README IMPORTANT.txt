You need to copy the code in this zip to your DART directories.

Let's say you installed DART to c:\CS4496_DART, and you followed 
the directions given in the bonus project instructions.

Let's call this directory <DART_ROOT> 

Your file structure should look like :
c:\CS4496_DART (== <DART_ROOT> ): 
	a directory with one subdirectory within it, named dart
c:\CS4496_DART\dart (== <DART_ROOT>\dart) : 
	a directory with many subdirectories within it 
	(including one named dart) and also including (if you 
	have built the project using CMAKE), a 'build' directory.

There are 2 components in this archive that need to be 
copied to specific locations within the <DART_ROOT>\dart hierarchy.


1. pinata.skel.  
	This file needs to be copied to '<DART_ROOT>\dart\data\skel'
2. rigidBodies directory.  
	This entire directory needs to be copied to '<DART_ROOT>\dart\apps'

	NOTE : if you do have a '<DART_ROOT>\dart\build' directory, do not 
put either of these components anywhere in '<DART_ROOT>\dart\build'.  
This directory gets rebuilt by CMAKE, and should never be written to manually.

once you have done this, re-run CMAKE, following the 
directions given in the bonus project instructions.  

For windows users :  a Visual Studio solution file (dart.sln) will 
appear automagically in the '<DART_ROOT>\dart\build' directory, 
built by CMAKE.  Clicking on this solution file will open VS2015
and load all the myriad DART apps, including the template code 
for the 'rigidBodies' project.  

Set the 'rigidBodies' project as startup project and build.  
You should see a box with two little objects inside, one a 
cube and one a sphere.  
Hitting the space bar should have both objects fall through 
the box and off the screen 