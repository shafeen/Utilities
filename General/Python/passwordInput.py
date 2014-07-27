#!/usr/bin/env python

# Author : Shafeen M.

#
# This file demonstrates how you can create a secure
# password input prompt for command line programs
# 

import getpass

passwordPrompt = "Please type in a password of your choice:"
print "\n%s" % (passwordPrompt)

# the line below allows you to input text without echo-ing it
password = getpass.getpass() 

print "Thank you! You entered : %s\n" % (password)

