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
    confirmMsg = "Confirmed" if confirmed else "Cancelling"
    print confirmMsg
    return confirmed


# filerename(currentDirFiles[2], 'renamed.py')

def run():
    currentDirFiles = getOnlyFilesInDir(getcwd())
    print currentDirFiles

    prefix = getPrefixArg()
    if not confirmWithMsg("Use prefix: '%s'? Y/n:" % prefix):
        exit()

    filesWithPrefix = getFilesWithPrefix(currentDirFiles, prefix)
    print "All files in directory with prefix '%s': %s" % (prefix, filesWithPrefix)
    if not confirmWithMsg('Continue? (Y/n): '):
        exit()

    commonFragmentCounts = {}

    # find common string fragments in the list of files
    for myfile in filesWithPrefix:
        filenameSplit = myfile.split('.')
        fileExt = filenameSplit[-1]
        filenameMinusExt = strjoin(filenameSplit[:-1], '.')

        commonDelimiters = ['.', '_', ' ']
        filenameFragments = {()}
        for delimiter in commonDelimiters:
            filenameSplit = filenameMinusExt.split(delimiter)
            print 'split %s into ' % filenameMinusExt, filenameSplit, 'using %s' % delimiter
            for filenameFragment in filenameSplit:
                filenameFragments.add(filenameFragment)

        print 'all fragments found in file: %s' % myfile, filenameFragments

        for filenameFragment in filenameFragments:
            if type(filenameFragment) != str:
                continue
            if filenameFragment in commonFragmentCounts:
                commonFragmentCounts[filenameFragment] += 1
            else:
                print 'saving fragment %s' % filenameFragment
                commonFragmentCounts[filenameFragment] = 1

    print 'common fragment counts (> 1):'
    # form a list of potential fragments to eliminate
    potentialFragmentsToDelete = []
    for fragment, count in commonFragmentCounts.iteritems():
        if count > 1:
            print fragment, count
            potentialFragmentsToDelete.append(fragment)

    # ask the user to create the final list of fragments to eliminate
    fragmentsToDelete = []
    fragmentsToDeletePrompt = 'Fragment to eliminate (q to stop): '
    userStr = raw_input(fragmentsToDeletePrompt)
    while userStr != 'q':
        fragmentsToDelete.append(userStr)
        print fragmentsToDelete
        userStr = raw_input('Fragment to eliminate (q to stop): ')

    if not confirmWithMsg('delete the following fragments? %s (Y/n):' % fragmentsToDelete):
        exit()

    # eliminate the fragments from each of the relevant files
    for myfile in filesWithPrefix:
        filenameSplit = myfile.split('.')
        fileExt = '.' + filenameSplit[-1]
        oldFilenameMinusExt = strjoin(filenameSplit[:-1], '.')
        newFilenameMinusExt = oldFilenameMinusExt
        for fragment in fragmentsToDelete:
            newFilenameMinusExt = strjoin(newFilenameMinusExt.split(fragment), '').strip()
        print 'renaming %s to %s' % (oldFilenameMinusExt+fileExt, newFilenameMinusExt+fileExt)
        # TODO: do the actual rename operation here when production ready!

# TODO: take in a delimiter as well as a prefix using '--split='
run()



