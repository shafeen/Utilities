#!/usr/bin/env python

# Author : Shafeen M.

#
# This file demonstrates how you can encrypt plaintext passwords
# and verify plaintext passwords against stored encrypted passwords 
# 
# We will be using the py-bcrypt module (must be available)
# For more information on bcrypt, feel free to google it!
# 

import getpass
import bcrypt

passwordPrompt = "Please type in a password of your choice:"
print "\n%s" % (passwordPrompt)

# the line below allows you to input text without echo-ing it
password = getpass.getpass() 
print "Thank you for choosing a password!"

# the password will now be one-way hashed into a digest
# 
# if we were storing any verification information for the future
# this "passwordDigest" is what we would store in our database
passwordDigest = bcrypt.hashpw(password, bcrypt.gensalt())

# now we will keep asking for passwords until we get the correct password
# users can exit out of this loop using Ctrl + C (quitting the program)
correctPassword = False
while not correctPassword:
	print "\n%s" % ("Enter password: "),
	enteredPassword = getpass.getpass()
	correctPassword = bcrypt.checkpw(enteredPassword, passwordDigest)

	if not correctPassword:
		print "Incorrect Password Entered!"
	else:
		print "PASSWORD ACCEPTED!!!"





