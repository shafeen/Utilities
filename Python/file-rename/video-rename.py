#!/usr/bin/python

import sys
from os import listdir, getcwd, rename as filerename
from os.path import isfile, join as pathjoin
from string import join as strjoin

argv = sys.argv


def getPrefixFilter(testPrefix):
    def filterFunc(fileName):
        try:
            return fileName.index(testPrefix) == 0
        except ValueError:
            return False
    return filterFunc


def getPrefixArg():
    PREFIX_ARG = '--prefix='
    prefix = ''
    errMsg = 'You must specify: %s!' % PREFIX_ARG
    if len(argv) != 2:
        raise RuntimeError(errMsg)
    elif not getPrefixFilter(PREFIX_ARG)(argv[1]):
        raise RuntimeError(errMsg)
    else:
        prefix = strjoin(argv[1].split(PREFIX_ARG), '')
        if len(prefix) == 0:
            raise RuntimeError('the prefix cannot be empty')
        else:
            return prefix


def getOnlyFilesInDir(dirPath):
    onlyfiles = [f for f in listdir(dirPath) if isfile(pathjoin(dirPath, f))]
    return onlyfiles


def getFilesWithPrefix(fileList, prefix):
    return filter(getPrefixFilter(prefix), fileList)


def confirmWithMsg(msg):
    confirmed = raw_input(msg) == "Y"
    confirmMsg = "Confirmed" if confirmed else "Canceling"
    print confirmMsg
    return confirmed


# filerename(currentDirFiles[2], 'renamed.py')

def run():
    currentDirFiles = getOnlyFilesInDir(getcwd())
    print currentDirFiles

    prefix = getPrefixArg()

    if confirmWithMsg("Use prefix: '%s'? Y/n:" % prefix):
        filesWithPrefix = getFilesWithPrefix(currentDirFiles, prefix)
        print "All files in directory with prefix '%s':" % prefix,
        print filesWithPrefix



run()



