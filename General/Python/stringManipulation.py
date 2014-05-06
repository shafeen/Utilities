#!/usr/bin/env python

# Author: Shafeen M.

# 
# This file demonstrates some ways python
# can perform useful string manipulations. 
#

# sample strings we will be manipulating
str1 = "Hello.World.This.Is.A.Python.String"
str2 = "Hello World This Is A Python String"


# string subscripting --> [] operator
# ------------------------------------
# print 1 character in the string at a time
for index in range(0,len(str1)):
	print str1[index],
print '\n'

# accessing substrings with the [:] operator
# -------------------------------------------
print str1[0:5],
print str1[6:11]
print str1[:],
print '\n'  

# find() on a string object
# ---------------------------
# find returns the first index of the substring
# if substring isn't found --> find returns -1
print str1.find("Hello"),
print str1.find("World"),
print str1.find("This"),
print str1.find("Is"),
print str1.find("A"),
print str1.find("Python"),
print str1.find("String"),
print str1.find("HELLO"),
print '\n'


# replace() on a string object
# ------------------------------
# replaces ALL occurences of the substring
# with the string given as the second argument
# if substring isn't found --> returns original string
print str1.replace("Hello", "     ")
print str1.replace("World", "     ")
print str1.replace("BEARS", "     ")
print '\n',


# chaining multiple calls on a string object
# -------------------------------------------
print str1.replace("This", "    ").replace("Is", "  ")
print str1.replace("World", "BEARS").find("BEARS")
print '\n',


# using strip() to remove characters
# ------------------------------------
# characters to strip are passed in as args
# there are a few variants: strip() / lstrip() / rstrip()
# going thru specifically how strip works is important
# if strip fails --> returns original string
print str1.lstrip("Hello")
print str1.rstrip("String")
print str1.strip("HelloString")
print '\n',


# using split() to split up strings into a list
# ----------------------------------------------
# splits up the string into a list using the delimiter
# provided to split(..) as an argument
# if no delimiter provided, whitespace will be used
print str1.split('.')
print str2.split()
print '\n'



# Other useful utility functions for strings 
# -------------------------------------------
print str1.upper()
print str1.lower()





